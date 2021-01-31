# Door sense app for PC
public documentation and releases for tof door sense project for PC platform

## Introduction
This application demonstrates how ADI's ToF technology can be used for people detection.

## Hardware setup
Required hardware:
 - AD-96TOF1-EBZ development kit
 - PC running Ubuntu linux 20.04
 
## Software setup
The first step is to download and install the door sense installer. [Door sense PC installer Ubuntu 20.04](https://github.com/robotics-ai/tof_process_public/box_measure/PC/install_door-sense_ubuntu_20.04_amd64_0.0.1.sh)
Install the app using: (you may need to set execute permisions for the file)
```
./install_door-sense_ubuntu_20.04_amd64_0.0.1.sh
```
This will install a linux app called Door Sense
 
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
## Troubleshooting
 - known issues
 - solutions to common problems
