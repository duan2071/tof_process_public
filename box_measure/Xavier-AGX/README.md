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

### XAVIER AGX
The first step is to download and install the box measurement installer. [Box measurement Xavier AGX installer Ubuntu 18.04](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier/install_box-measure_bionic_arm64_agx_0.0.3.sh)
Install the app using: (you may need to set execute permissions for the file)
```
./install_box-measure_bionic_arm64_agx_0.0.3.sh
```
This will install a linux app called Box Measure
 
## Running the demo
### Position the camera and the box.
For best results the camera and the box should be placed similar to the positions represented in the image below. Plane brown boxes work best.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/fig1.png)

The camera should be positioned about one meter from the ground.

The box needs to be between 1 meter and 3 meters from the camera. These limitations are due to the camera running in the medium range mode.

The box should be centered in the field of view of the camera.

The box dimensions should be between 20 cm and 90 cm.

Please watch the live demo video to see an example of how the camera and the box should be placed.

### Run the box measure app.
![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/run_app_xavier.png)

The application will open two windows:
- an image window showing the input from the camera and the box measurement results overlayed on top
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/app_results_xavier.png)

 - video showing a live demo

### Running the application from command line
Open a Terminal window.
```
/opt/robotics-ai/box-measure/run.sh
```
The image may be too dark or too saturated. Since auto gain unfortunately does not work on Nvidia AGX, the brightness of the image can be adjusted by passing a parameter in the command line. The parameter that controls the image saturation is called "gamma" and is in the range 0.1 to 5.0. 0.1 is the most saturated while 5.0 is the darkest.
To set the gamma correction parameter to 0.5 you should use the command line:
```
/opt/robotics-ai/box-measure/run.sh gamma:=0.5
```
You can test diffrent values for the gamma parameter to see which generates the best results.

### Running the application using a capture file
Open a Terminal window.
```
/opt/robotics-ai/box-measure/run_capture.sh capture_name:=[full path for the capture file]
```

### Recording captures

[Record captures](https://github.com/robotics-ai/tof_process_public/blob/main/recording/README.md)


## Uninstalling the app
To uninstall the box measure application open a termina window and type.
```
sudo apt purge box-measure
```
## Troubleshooting
 - ### known issues
   1. Auto gain is disabled on NVidia AGX because currently there are some issues with setting the gamma parameter too often.
 - ### solutions to common problems
   1. if the image seems to dark or to saturated then the box measurement application can be run from the command line and the parameter that controls the image saturation can be set manually in the command line.
   2. if the camera stops providing frames to the application the the AGX board needs to be restarted.
