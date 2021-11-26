# Box measurement app

## Introduction
This application demonstrates how ADI's ToF technology can be used for measuring the dimensions of boxes.

## Hardware and software setup

PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/README.md)

ADI Smart Camera
[ADI Smart Camera specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/ADI-Smart-Camera/README.md)

## Running the demo
### Position the camera and the box.
For best results the camera and the box should be placed similar to the positions represented in the image below. Plane brown boxes work best.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/fig1.png)

The camera should be positioned about one meter from the ground.

The box needs to be between 1 meter and 3 meters from the camera. These limitations are due to the camera running in the medium range mode.

The box should be centered in the field of view of the camera.

The box dimensions should be between 20 cm and 90 cm.

Please watch the live demo video to see an example of how the camera and the box should be placed. [Demo video](https://www.youtube.com/watch?v=G-9UfaZXUCk)

### Run the box measure app.
There are two applications available (Box Measure FX is not availible on PC). 
- Box Measure v0.5 is intended to be used with the AD-96TOF1-EBZ camera module
- Box Measure FX v0.5 is intended to be used with the AD-FXTOF1-EBZ camera module

Please select the application that is appropriate for the setup that you have.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/run_app_nx.png)

The application will open two windows:
- an image window showing the input from the camera and the box measurement results overlayed on top
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/app_results_xavier.png)

 - video showing a live demo
 [Demo video](https://www.youtube.com/watch?v=G-9UfaZXUCk)

### Running the application from command line
Open a Terminal window.
```
/opt/robotics-ai/box-measure/run.sh
```
or

```
/opt/robotics-ai/box-measure/run_fx.sh
```
The image may be too dark or too saturated. To mitigate this issue an auto gain feature has been implemented.
Unfortunately auto gain does not work on Xavier AGX and Xavier NX. The brightness of the image can be adjusted by passing a parameter in the command line. The parameter that controls the image saturation is called "gamma" and is in the range 0.1 to 5.0. 0.1 is the most saturated while 5.0 is the darkest.
To set the gamma correction parameter to 0.5 you should use the command line:
```
/opt/robotics-ai/box-measure/run.sh gamma:=0.5
```
or

```
/opt/robotics-ai/box-measure/run_fx.sh gamma:=0.5
```

Different values for the gamma parameter can be tested to see which generates the best results.

The gamma parameter can also be set by using the configuration tool.
To start the configuration tool open a new Terminal window and type:
```
/opt/robotics-ai/[Installed product]/run_conf.sh
```
The gamma parameter can be found in the tof_source panel. (Setting the gamma parameter too often on AGX/NX boards may lead to a freeze in the camera driver).

### Running the application using a capture file
Open a Terminal window.
```
/opt/robotics-ai/box-measure/run_capture.sh [full path for the capture file]
```
or

```
/opt/robotics-ai/box-measure/run_capture_fx.sh [full path for the capture file]
```

### Recording captures

[Record captures](https://github.com/robotics-ai/tof_process_public/blob/main/recording/README.md)


## Uninstalling the app
To uninstall the box measure application open a terminal window and type.
```
sudo apt purge box-measure
```
## Troubleshooting
PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/README.md)
