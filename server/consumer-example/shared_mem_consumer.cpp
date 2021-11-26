#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include <signal.h>
#include "app_comm.hpp"

AppCommunicatorConsumer _consumer;

void intHandler(int) {
    std::cout << "Destroy shared memory" << std::endl;
    _consumer.release();
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        std::cout << "Invalid number of arguments" << std::endl;
        return -EINVAL;
    }
    std::string name(argv[1]);
    size_t size = std::stoi(argv[2]);
    std::string dst_folder(argv[3]);
    std::string ext(argv[4]);
    if (ext[0] != '.') {
        ext = std::string(".") + ext;
    }
    boost::filesystem::path dir(dst_folder);
    boost::filesystem::path file(std::string("*") + ext);
    boost::filesystem::path full_path = dir / file;
    std::cout << "Start shared memory consumer using name " << name << " and size " << size << "with output " << full_path << std::endl;
    if (!_consumer.init(size, name.c_str())) {
        std::cout << "Failed to init shared memory" << std::endl;
        return -EINVAL;
    }
    struct sigaction act;
    act.sa_handler = intHandler;
    sigaction(SIGINT, &act, NULL);
    std::vector<uint8_t> data;
    char file_name[124];
    uint64_t time_stamp;
    while (true) {
        if (_consumer.read(time_stamp, data, std::chrono::seconds(10))) {
            snprintf(file_name, sizeof(file_name), "%06lu%s", time_stamp, ext.c_str());
            file_name[sizeof(file_name) - 1] = '\0';
            full_path = dir / boost::filesystem::path(file_name);
            auto output_file = std::fstream(full_path.c_str(), std::ios::out | std::ios::binary | std::ios::trunc);
            output_file.write(reinterpret_cast<const char *>(data.data()), data.size());
            output_file.close();
        } else {
            std::cout << "No data available. Retry..." << std::endl;
        }
    }
    intHandler(0);
    return 0;
}
