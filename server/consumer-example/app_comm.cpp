#include "app_comm.hpp"
#include <thread>

AppCommunicator::BufferHeader::BufferHeader(size_t size)
: size(size), free_size(size), read_idx(0), write_idx(0), data_sem(0), buffer_sem(0) {
}

AppCommunicator::DataHeader::DataHeader(size_t size, uint64_t time_stamp)
: size(size), time_stamp(time_stamp) {
}

AppCommunicator::AppCommunicator()
: _buffer(nullptr) {
}

AppCommunicator::~AppCommunicator() {
    release();
}

bool AppCommunicator::init(const char *name, BufferHeader *buffer) {
    release();
    _buffer = buffer;
    return true;
}

void AppCommunicator::release() {
    _buffer = nullptr;
    _name.clear();
}

AppCommunicatorConsumer::~AppCommunicatorConsumer() {
    release();
}

bool AppCommunicatorConsumer::init(size_t buffer_size, const char *name) {
    release();
    try {
        boost::interprocess::shared_memory_object::remove(name);
        // Create a shared memory object.
        _shm = boost::interprocess::shared_memory_object(
            boost::interprocess::create_only,               // Create
            name,                                           // Name
            boost::interprocess::read_write                 // Read-write mode
        );
        // Set size
        _shm.truncate(sizeof(BufferHeader) + buffer_size);
        // Map the whole shared memory in this process
        _region = boost::interprocess::mapped_region(
            _shm,                                           // What to map
            boost::interprocess::read_write                 // Map it as read-write
        );
        // Get the address of the mapped region
        void *addr = _region.get_address();
        // Construct the shared structure in memory
        BufferHeader *buffer = new (addr) BufferHeader(buffer_size);
        if (!AppCommunicator::init(name, buffer)) {
            boost::interprocess::shared_memory_object::remove(name);
            return false;
        }
    } catch (boost::interprocess::interprocess_exception &ex) {
        boost::interprocess::shared_memory_object::remove(name);
        return false;
    }
    return true;
}

void AppCommunicatorConsumer::release() {
    if (isInit()) {
        boost::interprocess::shared_memory_object::remove(getName());
        AppCommunicator::release();
    }
}

bool AppCommunicatorConsumer::readData(uint64_t &time_stamp, std::vector<uint8_t> &data, const boost::posix_time::ptime &time) {
    if (!isInit()) {
        return false;
    }
    if (!get()->data_sem.timed_wait(time)) {
        return false;
    }
    DataHeader *data_header = reinterpret_cast<DataHeader *>(&get()->data[getReadIdx()]);
    data.reserve(data_header->size);
    data.clear();
    time_stamp = data_header->time_stamp;
    getReadIdx() += sizeof(DataHeader);
    size_t space = getSize() - getReadIdx();
    if (space >= data_header->size) {
        // One chunk
        std::copy(&data_header->data[0], &data_header->data[data_header->size], std::back_inserter(data));
        // Update read index
        getReadIdx() += data_header->size;
    } else {
        // Two chunks
        std::copy(&data_header->data[0], &data_header->data[space], std::back_inserter(data));
        std::copy(&get()->data[0], &get()->data[data_header->size - space], std::back_inserter(data));
        getReadIdx() = data_header->size - space;
    }
    // Check is enough space for data header
    if (getReadIdx() > getSize() - sizeof(DataHeader)) {
        getReadIdx() = 0;
    }
    // Update free size
    updateFreeSize(sizeof(DataHeader) + data_header->size);
    // Signal buffer free
    get()->buffer_sem.post();
    return true;
}

AppCommunicatorProducer::~AppCommunicatorProducer() {
    release();
}

void AppCommunicatorProducer::release() {
    if (isInit()) {
        boost::interprocess::shared_memory_object::remove(getName());
        AppCommunicator::release();
    }
}

bool AppCommunicatorProducer::initWait(const char *name, const boost::posix_time::ptime &time) {
    do {
        try {
            // Create a shared memory object.
            _shm = boost::interprocess::shared_memory_object(
                boost::interprocess::open_only,                 // Open
                name,                                           // Name
                boost::interprocess::read_write                 // Read-write mode
            );
            // Map the whole shared memory in this process
            _region = boost::interprocess::mapped_region(
                _shm,                                           // What to map
                boost::interprocess::read_write                 // Map it as read-write
            );
            // Get the address of the mapped region
            BufferHeader *buffer = reinterpret_cast<BufferHeader *>(_region.get_address());
            if (!AppCommunicator::init(name, buffer)) {
                boost::interprocess::shared_memory_object::remove(name);
                return false;
            }
            return true;
        } catch (boost::interprocess::interprocess_exception &ex) {
            boost::interprocess::shared_memory_object::remove(name);
        }
        std::this_thread::sleep_for(std::chrono::microseconds(500));
    } while (boost::posix_time::microsec_clock::universal_time() < time);
    return false;
}

bool AppCommunicatorProducer::writeData(uint64_t time_stamp, const void *data, size_t data_size, const boost::posix_time::ptime &time) {
    if (!isInit()) {
        return false;
    }
    if (sizeof(DataHeader) + data_size > getSize()) {
        return false;
    }
    while (true) {
        if (getFreeSize() >= sizeof(DataHeader) + data_size) {
            DataHeader *data_header = new (&get()->data[getWriteIdx()]) DataHeader(data_size, time_stamp);
            getWriteIdx() += sizeof(DataHeader);
            size_t space = getSize() - getWriteIdx();
            if (space >= data_header->size) {
                // One chunk
                std::memcpy(data_header->data, data, data_size);
                // Update write index
                getWriteIdx() += data_header->size;
            } else {
                // Two chunks
                std::memcpy(&data_header->data[0], data, space);
                std::memcpy(&get()->data[0], &reinterpret_cast<const uint8_t *>(data)[space], data_header->size - space);
                getWriteIdx() = data_header->size - space;
            }
            // Check is enough space for data header
            if (getWriteIdx() > getSize() - sizeof(DataHeader)) {
                getWriteIdx() = 0;
            }
            // Update buffer free size
            updateFreeSize(-(sizeof(DataHeader) + data_header->size));
            // Signal new data buffer
            get()->data_sem.post();
            break;
        }
        // Not enough free space, wait for buffers
        if (!get()->buffer_sem.timed_wait(time)) {
            return false;
        }
    }
    return true;
}
