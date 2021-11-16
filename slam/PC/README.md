# SLAM app for Linux PC
## Hardware setup
Please follow these instructions.

[PC hardware setup](https://wiki.analog.com/resources/eval/user-guides/ad-96tof1-ebz/ug_linux)

## Software setup

The first step is to download scripts and deb packages:
- [external dependencies installer script](https://github.com/robotics-ai/tof_process_public/blob/main/slam/PC/install_slam_dependencies_focal.sh)
- [deb package](https://github.com/robotics-ai/tof_process_public/blob/main/slam/PC/slam_0.0.1_amd64.deb)

Install the app external dependencies using: (you may need to set execute permissions for the file)
```
./install_box-measure_dependencies_focal.sh
```

Install deb package:
```
sudo apt install ./slam_0.0.1_amd64.deb
```
## Troubleshooting
### known issues
-
### solutions to common problems
- if the camera stops providing frames to the application then you should unplug the power from the dragon board and restart the camera system.
