# Door sense app for Xavier NX

## Hardware setup
Required hardware:
 - AD-96TOF1-EBZ development kit
 - Nvidia Xavier NX development kit
 - Flex cable for connection between Xavier NX and AD-96TOF1-EBZ
 - HDMI monitor and cable
 - USB keyboard and mouse
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/xavier-nx-ad96tof1.jpg)

For additions info plese see: 
[Xavier NX setup](https://wiki.analog.com/resources/eval/user-guides/ad-96tof1-ebz/ug_xavier_nx)

## Software setup

The first step is to download and install the door sense installer. [Door sense Xavier NX installer Ubuntu 18.04](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Xavier-NX/install_door-sense_bionic_arm64_nx_cuda_0.0.2.sh)
Install the app using: (Note: you may need to set execute permissions for the file)
```
./install_door-sense_bionic_arm64_nx_cuda_0.0.2.sh
```
This will install a linux app called Door Sense.

**The board needs to be restarted before the application can be used.**

**Also make sure the AGX board is set to run in mode 2.**

This application uses NVidia Cuda to run. Make sure Cuda is instaled on the Xavier NX board. If it is not already installed. please install NVidia Cuda on the Xavier NX board using the NVidia SDK Manager.
 
## Troubleshooting
### known issues
   - Auto gain is disabled on NVidia NX because currently there are some issues with setting the gamma parameter too often.
### solutions to common problems
   - if the image seems to dark or to saturated then the door sense application can be run from the command line and the parameter that controls the image saturation can be set manually in the command line.
   - if the camera stops providing frames to the application the the NX board needs to be restarted.
