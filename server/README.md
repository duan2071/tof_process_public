# Server app
Public documentation and releases for tof server project

## Software setup
PC running Ubuntu 20.04

## Software setup
The first step is to download scripts and deb packages:
- [external dependencies installer script](https://github.com/robotics-ai/tof_process_public/blob/main/server/install_dependencies_focal.sh)
- [deb package using CUDA](https://github.com/robotics-ai/tof_process_public/blob/main/server/door-sense_0.0.4_amd64_cuda.deb)

Install the app external dependencies using: (you may need to set execute permissions for the file)
```
./install_dependencies_focal.sh
```

Install deb package:
```
sudo apt install ./door-sense_0.0.4_amd64_cuda.deb
```

## Running the server application
Always start the consumer application before runnning the server app.
### Running the example data consumer for Door Sense
Open a terminal for each of the following commands:
```
shared_mem_consumer "ir_shared" [memory size in bytes] [Output folder] "png"
shared_mem_consumer "detect2d_shared" [memory size in bytes] [Output folder] "png"
shared_mem_consumer "output_shared" [memory size in bytes] [Output folder] "png"
```

### Run the door sense app.
Start server with a recording from a AD96ToF1 camera:
```
/opt/robotics-ai/door-sense/run_capture.sh [full path for the capture file] [other parameters]
```

Start server with a recording from a ADFXToF1 camera:
```
/opt/robotics-ai/door-sense/run_capture_fx.sh [full path for the capture file] [other parameters]
```
## Uninstalling the app
To uninstall the door sense application open a terminal window and type.
```
sudo apt purge door-sense
```