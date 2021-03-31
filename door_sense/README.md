# Door sense app
public documentation and releases for tof door sense project

## Introduction
This application demonstrates how ADI's ToF technology can be used for people detection.

## Hardware and software setup

PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Xavier-NX/README.md)

 
## Running the demo
### Position the camera.
For best results the camera should be placed similar to the positions represented in the image below.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/fig1.png)

The camera should be positioned about two meter from the ground.

The camera is set by default in "medium" mode which means that the range of the detection is limited to 6m. This may impact the way the ground and walls are detected.

Please watch the live demo video to see an example of how the camera should be placed.

### Run the door sense app.

#### Running the aplication in live mode

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/run_app.png)

The application will open two windows:
- an image window showing the input from the camera and the results of the people detection overlayed on top
- a console window

Alternetly the application can be started in live mode by using the command line:
```
/opt/robotics-ai/door-sense/run.sh
```

#### Running the aplication in offline mode:

The application can be started in offline mode by using the command line:
```
/opt/robotics-ai/door-sense/run.sh [full path to the capture file]
```


The application will open two windows:
- an image window showing the input from the camera and the detected elements (persons in the detection area and any ground and walls inside the detection area).
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/app_results.png)

 - video showing a live demo

#### Create recordings for offline mode:
```
cd tof_process_public/recording
source /opt/ros/noetic/setup.bash
source /opt/robotics-ai/door-sense/setup.bash
ROS_HOME=`pwd` roslaunch ./run-adi-record.launch capture_name:=[absolute/relative path to recording folder]
```
A series of recording files, having ".raw" extension, will be created into the specified recording folder. The recorded data can be later used as input for running the application in offline mode (see above section).

## Troubleshooting
 - known issues
 - solutions to common problems
