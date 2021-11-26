# Consumer example app
## Build
PC running Ubuntu 20.04
```
g++ -std=c++14 -g shared_mem_consumer.cpp app_comm.cpp -o shared_mem_consumer -lboost_filesystem -lboost_system -pthread -lrt
```
## Running the consumer application
```
shared_mem_consumer [name of the shared memory] [memory size in bytes] [output folder] [file extension to use]
```
The output folder must be created before running the consumer application.