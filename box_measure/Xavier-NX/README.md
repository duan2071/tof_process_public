# Box measurement app for Xavier NX

## Hardware setup
Required hardware:
 - AD-96TOF1-EBZ development kit
 - Nvidia Xavier NX development kit
 - Flex cable for connection between Xavier NX and AD-96TOF1-EBZ
 - HDMI monitor and cable
 - USB keyboard and mouse
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/xavier-nx-ad96tof1.jpg)

**Please make sure that the power source is plugged into the camera module and the power switch for the camera module is in the ON position before powering up the AGX board.**

For additions info plese see: 
[Xavier NX setup](https://wiki.analog.com/resources/eval/user-guides/ad-96tof1-ebz/ug_xavier_nx)

## Software setup

The first step is to download and install the box measurement installer. [Box measurement Xavier NX installer Ubuntu 18.04](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/install_box-measure_bionic_arm64_nx_0.0.3.sh)
Install the app using: (Note: you may need to set execute permissions for the file)
```
./install_box-measure_bionic_arm64_nx_0.0.3.sh
```
This will install a linux app called Box Measure.

**The board needs to be restarted before the application can be used.**

**Also make sure the NX board is set to run in mode 2.**
 
## Troubleshooting
### known issues
   - Auto gain is disabled on NVidia NX because currently there are some issues with setting the gamma parameter too often.
### solutions to common problems
   - if the image seems to dark or to saturated then the box measurement application can be run from the command line and the parameter that controls the image saturation can be set manually in the command line.
   - if the camera stops providing frames to the application the the NX board needs to be restarted.
