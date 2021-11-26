# Door sense app
Public documentation and releases for tof door sense project.

## Introduction
This application demonstrates how ADI's ToF technology can be used for people detection.

## Hardware and software setup

PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Xavier-NX/README.md)

ADI Smart Camera
[ADI Smart Camera specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/ADI-Smart-Camera/README.md)

## Running the demo
### Position the camera.
For best results the camera should be placed similar to the positions represented in the image below.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/fig1.png)

The camera should be positioned about two meter from the ground.

The detection range is determined by the "mode" the ToF camera is set to. This will impact the way persons, the ground and walls are detected.

For the "far" mode the detection range is between 3m and 6m.

For the "medium" mode the detection range is between 1m and 4.5m;

Please watch the live demo video to see an example of how the camera should be placed.
[Demo video](https://www.youtube.com/watch?v=-CErH6ROli8&ab_channel=RoboticsAI)

### Run the door sense app.

#### Running the application in live mode

There are three applications available ("Door Sense Fx" in not availible on PC).

- "Door Sense" is intended to be used with the AD-96TOF1-EBZ camera module in "far" mode
- "Door Sense Med" is intended to be used with the AD-96TOF1-EBZ camera module in "med" mode
- "Door Sense Fx" is intended to be used with the AD-FXTOF1-EBZ camera module which can only run in "med" mode

Please select the application that is appropriate for the setup that you have.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/run_app.png)

The application will open two windows:
- an image window showing the input from the camera and the detected elements (persons in the detection area and any ground and walls inside the detection area).
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/app_results.png)

 - video showing a live demo
 [Demo video](https://www.youtube.com/watch?v=-CErH6ROli8&ab_channel=RoboticsAI)

### Running the application from command line

To start the application with the AD-96TOF1-EBZ camera module in "far" mode open a Terminal window and type in the command below.
```
/opt/robotics-ai/door-sense/run.sh
```
To start the application with the AD-96TOF1-EBZ camera module from the command line in "med" mode you can use the command line below.
```
/opt/robotics-ai/door-sense/run_med.sh
```
To start the application with the AD-FXTOF1-EBZ camera module from the command line you can use the command line below.
```
/opt/robotics-ai/door-sense/run_fx.sh
```

The image may be too dark or too saturated. To mitigate this issue an auto gain feature has been implemented.
Unfortunately auto gain does not work on Xavier AGX and Xavier NX. The brightness of the image can be adjusted by passing a parameter in the command line. The parameter that controls the image saturation is called "gamma" and is in the range 0.1 to 5.0. 0.1 is the most saturated while 5.0 is the darkest.
To set the gamma correction parameter to 0.5 you should use the command line:
```
/opt/robotics-ai/door-sense/run.sh gamma:=0.5
```
or
```
/opt/robotics-ai/door-sense/run_med.sh gamma:=0.5
```
or
```
/opt/robotics-ai/door-sense/run_fx.sh gamma:=0.5
```
Different values for the gamma parameter can be tested to see which generates the best results.

The gamma parameter can also be set by using the configuration tool.
To start the configuration tool open a new Terminal window and type:
```
/opt/robotics-ai/[Installed product]/run_conf.sh
```
The gamma parameter can be found in the tof_source panel. (Setting the gamma parameter too often on AGX/NX boards may lead to a freeze in the camera driver).

#### Running the application in offline mode:

The application can be started in offline mode by using the command line:
```
/opt/robotics-ai/door-sense/run_capture.sh [full path for the capture file]
```

### Recording captures

[Record captures](https://github.com/robotics-ai/tof_process_public/blob/main/recording/README.md)

## Uninstalling the app
To uninstall the door sense application open a terminal window and type.
```
sudo apt purge door-sense
```
## Troubleshooting
PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Xavier-NX/README.md)
