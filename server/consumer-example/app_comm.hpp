#pragma once
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <boost/date_time/posix_time/conversion.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <chrono>
#include <vector>
#include <atomic>

class AppCommunicator {
public:
    AppCommunicator();
    virtual ~AppCommunicator();

protected:
    struct BufferHeader {
        BufferHeader(size_t size);
        boost::interprocess::interprocess_semaphore     data_sem;
        boost::interprocess::interprocess_semaphore     buffer_sem;

        size_t                                          size;
        volatile std::atomic_size_t                     free_size;
        unsigned int                                    read_idx;
        unsigned int                                    write_idx;
        uint8_t                                         data[0];
    };
    struct __attribute__((__packed__)) DataHeader {
        DataHeader(size_t size, uint64_t time_stamp);
        size_t                                          size;
        uint64_t                                        time_stamp;
        uint8_t                                         data[0];
    };

    bool init(const char *name, BufferHeader *buffer);
    inline bool isInit() const { return _buffer != nullptr; }
    void release();
    inline BufferHeader *get() { return _buffer; }
    inline size_t &getSize() { return _buffer->size; }
    inline unsigned int &getReadIdx() { return _buffer->read_idx; }
    inline unsigned int &getWriteIdx() { return _buffer->write_idx; }
    inline void updateFreeSize(int size) { _buffer->free_size += size; }
    inline size_t getFreeSize() { return _buffer->free_size; }
    inline const char *getName() const { return _name.c_str(); }

    template <typename Duration>
    inline static boost::posix_time::ptime convert(const Duration& from) {
        return boost::posix_time::microsec_clock::universal_time() + boost::posix_time::microseconds(std::chrono::duration_cast<std::chrono::microseconds>(from).count());
    } 

private:
    BufferHeader                                        *_buffer;
    std::string                                         _name;
};

class AppCommunicatorConsumer: public AppCommunicator {
public:
    AppCommunicatorConsumer() = default;
    virtual ~AppCommunicatorConsumer();

    bool init(size_t buffer_size, const char *name);
    void release();

    template <typename Duration>
    bool read(uint64_t &time_stamp, std::vector<uint8_t> &data, Duration timeout) {
        return readData(time_stamp, data, convert(timeout));
    }

private:
    bool readData(uint64_t &time_stamp, std::vector<uint8_t> &data, const boost::posix_time::ptime &time);
    boost::interprocess::shared_memory_object       _shm;
    boost::interprocess::mapped_region              _region;
};

class AppCommunicatorProducer: public AppCommunicator {
public:
    AppCommunicatorProducer() = default;
    virtual ~AppCommunicatorProducer();

    template <typename Duration>
    bool init(const char *name, Duration timeout) {
        return initWait(name, convert(timeout));
    }
    void release();

    template <typename Duration>
    bool write(uint64_t time_stamp, const void *data, size_t data_size, Duration timeout) {
        return writeData(time_stamp, data, data_size, convert(timeout));
    }

private:
    bool initWait(const char *name, const boost::posix_time::ptime &time);
    bool writeData(uint64_t time_stamp, const void *data, size_t data_size, const boost::posix_time::ptime &time);
    boost::interprocess::shared_memory_object       _shm;
    boost::interprocess::mapped_region              _region;
};
