# Slam app for Xavier AGX

## Hardware setup
Required hardware:
 - AD-96TOF1-EBZ development kit
 - Nvidia Xavier AGX development kit
 - Flex cable for connection between Xavier AGX and AD-96TOF1-EBZ
 - HDMI monitor and cable
 - USB keyboard and mouse
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/xavier-agx-ad96tof1.jpg)

**Please make sure that the power source is plugged into the camera module and the power switch for the camera module is in the ON position before powering up the AGX board.**

**Make sure the DIP switches on the mezzanine board are in the correct position**

**Orientation of the ribbon cable (conductors pointing down towards the lens on the mezzanine card and conductors pointing down towards the PCB surface on the interposer)**

 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/switches.jpeg)

For additions info please see: 
[Xavier AGX setup](https://wiki.analog.com/resources/eval/user-guides/ad-96tof1-ebz/ug_xavier_agx)

## Software setup

The first step is to download scripts and deb packages:
- [external dependencies installer script](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-AGX/install_slam_dependencies_bionic.sh)
- [ADI camera deb package](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-AGX/aditof-camera-AD-96TOF1-EBZ_0.0.1_arm64_agx.deb)
- [deb package](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-AGX/slam_0.0.1_arm64_agx.deb)

Install the app external dependencies using: (you may need to set execute permissions for the file)
```
./install_box-measure_dependencies_bionic.sh
```

Install deb packages:
```
sudo apt install ./aditof-camera-AD-96TOF1-EBZ_0.0.1_arm64_agx.deb
```
This step installs the modules required to run the camera and needs to be done only once per system.

```
sudo apt install ./slam_0.0.1_arm64_agx_cuda.deb
```
This will install a linux app called Slam.

**The board needs to be restarted before the application can be used.**

**Also make sure the AGX board is set to run in mode 0 (MAXN).**

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/set_mode.png)

This application uses Nvidia Cuda to run. Make sure Cuda is instaled on the Xavier AGX board. If it is not already installed. please install Nvidia Cuda on the Xavier AGX board using the Nvidia SDK Manager.
 
## Troubleshooting
### known issues
   - Auto gain is disabled on Nvidia AGX because currently there are some issues with setting the gamma parameter too often.
### solutions to common problems
   - if the image seems to dark or to saturated then the slam application can be run from the command line and the parameter that controls the image saturation can be set manually in the command line.
   - if the camera stops providing frames to the application the the AGX board needs to be restarted.
