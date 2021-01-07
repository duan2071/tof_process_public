# Box measurement app for Xavier AGX

## Introduction
This application demonstrates how ADI's ToF technology can be used for measuring the dimensions of boxes.

## Hardware setup
Required hardware:
 - AD-96TOF1-EBZ development kit
 - Nvidia Xavier AGX development kit
 - Flex cable for connection between Xavier AGX and AD-96TOF1-EBZ
 - HDMI monitor and cable
 - USB keyboard and mouse
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/xavier-agx-ad96tof1.jpg)

## Software setup
The first step is to download and install the box measurement installer. [Box measurement Xavier AGX installer Ubuntu 20.04](https://github.com/robotics-ai/tof_process_public/box_measure/Xavier/install_ubuntu_18.04.sh)
Install the app using: (you may need to set execute permisions for the file)
```
./install_ubuntu_18.04.sh	
```
This will install a linux app called Box Measure
 
## Running the demo
Run the box measure app.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/run_app_xavier.png)

The application will open two windows:
- an image window showing the input from the camera and the box measurement results overlayed on top
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/app_results_xavier.png)

 - video showing a live demo
## Troubleshooting
 - known issues
 - solutions to common problems
