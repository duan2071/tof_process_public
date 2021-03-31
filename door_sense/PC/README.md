# Door sense app for Linux PC
## Hardware setup
Please follow these instructions.

[PC hardware setup]https://wiki.analog.com/resources/eval/user-guides/ad-96tof1-ebz/ug_linux

## Software setup
The first step is to download and install the door sense installer.

Two installers are provided for Linux PC. One using Cuda acceleration and one using only CPU processing.

[Door sense PC installer Ubuntu 20.04](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/PC/install_door-sense_focal_amd64_0.0.2.sh)

[Door sense PC installer Ubuntu 20.04 with cuda](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/PC/install_door-sense_focal_amd64_cuda_0.0.2.sh)

Install the app using: (you may need to set execute permisions for the file)
```
./install_door-sense_focal_amd64_0.0.2.sh
```
or
```
./install_door-sense_focal_amd64_cuda_0.0.2.sh
```

## Troubleshooting
### known issues
-
### solutions to common problems
- if the camera stops providing frames to the application then you should unplug the power from the dragon board and restart the camera system.
