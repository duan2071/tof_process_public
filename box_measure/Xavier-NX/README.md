# Box measurement app for Xavier NX

## Hardware setup AD-96TOF1-EBZ
Required hardware AD-96TOF1-EBZ:
 - AD-96TOF1-EBZ development kit
 - Nvidia Xavier NX development kit
 - Flex cable for connection between Xavier NX and AD-96TOF1-EBZ
 - HDMI monitor and cable
 - USB keyboard and mouse
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/xavier-nx-ad96tof1.jpg)

**Please make sure that the power source is plugged into the camera module and the power switch for the camera module is in the ON position before powering up the NX board.**

**Make sure the DIP switches on the mezzanine board are in the correct position**

**Orientation of the ribbon cable (conductors pointing down towards the lens on the mezzanine card and conductors pointing towards the heat sink on the NX board)**

 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/switches.jpeg)

For additions info please see: 
[Xavier NX setup](https://wiki.analog.com/resources/eval/user-guides/ad-96tof1-ebz/ug_xavier_nx)

## Hardware setup AD-FXTOF1-EBZ
Required hardware AD-FXTOF1-EBZ:
 - AD-FXTOF1-EBZ development kit
 - Nvidia Xavier NX development kit
 - Flex cable for connection between Xavier NX and AD-FXTOF1-EBZ
 - HDMI monitor and cable
 - USB keyboard and mouse
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/xavier-nx-adfxtof1.jpg)

**Please make sure that the power source is plugged into the camera module before powering up the NX board.**

**Orientation of the ribbon cable (conductors pointing away from the nearest edge on the camera module and conductors pointing towards the heat sink on the NX board)**

For additions info please see: 
[Xavier NX setup](https://wiki.analog.com/resources/eval/user-guides/ad-fxtof1-ebz/ug_jetson)

## Software setup

The first step is to download scripts and deb packages:
- [external dependencies installer script](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/install_box-measure_dependencies_bionic.sh)

- [ADI AD-96TOF1-EBZ camera deb package](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/aditof-camera-AD-96TOF1-EBZ_0.0.1_arm64_nx.deb)
or [ADI AD-FXTOF1-EBZ camera deb package](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/aditof-camera-AD-FXTOF1-EBZ_0.0.1_arm64_nx.deb)

- [Box measure deb package](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/box-measure_0.0.5_arm64_nx.deb)

Install the app external dependencies using: (you may need to set execute permissions for the file)
```
./install_box-measure_dependencies_bionic.sh
```

Install camera deb package (depending on the version of camera module you are using):
```
sudo apt install ./aditof-camera-AD-96TOF1-EBZ_0.0.1_arm64_nx.deb
```
or
```
sudo apt install ./aditof-camera-AD-FXTOF1-EBZ_0.0.1_arm64_nx.deb
```

This step installs the modules required to run the camera and needs to be done only once per system.

Install box measure deb package:
```
sudo apt install ./box-measure_0.0.5_arm64_nx.deb
```
This will install two linux applications called Box Measure v05 and Box Measure FX v05.

**The board needs to be restarted before the application can be used.**

**Also make sure the NX board is set to run in mode 2.**
 
## Troubleshooting
### known issues
   - Auto gain is disabled on NVidia NX because currently there are some issues with setting the gamma parameter too often.
### solutions to common problems
   - if the image seems to dark or to saturated then the box measurement application can be run from the command line and the parameter that controls the image saturation can be set manually in the command line.
   - if the camera stops providing frames to the application the the NX board needs to be restarted.
