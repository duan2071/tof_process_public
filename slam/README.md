# SLAM (Simultaneous localization and mapping)
Public documentation and releases for tof SLAM project.

## Introduction
This application demonstrates how ADI's ToF technology can be used for SLAM processing.

## Hardware and software setup

PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-NX/README.md)

ADI Smart Camera
[ADI Smart Camera specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/ADI-Smart-Camera/README.md)

## Running the demo
### Position the camera.
For best results the camera should be placed similar to the positions represented in the image below.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Doc/Images/fig1.png)

The camera should be positioned in the range 1 meter to 1.5 meters from the ground. The roll of the camera should close to 0. (The view of the camera should be parralel to the ground) The camera should have a good view of the ground.

The detection range is determined by the "mode" the ToF camera is set to. This will impact the way objects, the ground and walls are detected.

For the "far" mode the detection range is between 3m and 6m.

For the "medium" mode the detection range is between 1m and 4.5m;

Please watch the live demo video to see an example of how the camera should be placed.
[Demo video](https://www.youtube.com/watch?v=XKTGsVNyvrg&ab_channel=RoboticsAI)

### Run the SLAM app.

#### Running the application in live mode

There are three applications available ("Slam Fx" in not available on PC).

- "Slam" is intended to be used with the AD-96TOF1-EBZ camera module in "far" mode
- "Slam Med" is intended to be used with the AD-96TOF1-EBZ camera module in "med" mode
- "Slam Fx" is intended to be used with the AD-FXTOF1-EBZ camera module and AD-3DSMARTCAM1-PRZ camera which can only run in "med" mode

Please select the application that is appropriate for the setup that you have.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Doc/Images/run_app.png)

The application will open four windows:
- an image window showing the input from the camera and the detected objects.
- an image showing a top view of the scene seen by the camera
- a window containing a list of detected objects with their position relative to the camera
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Doc/Images/app_results.png)

 - video showing a live demo
 [Demo video](https://www.youtube.com/watch?v=XKTGsVNyvrg&ab_channel=RoboticsAI)

### Running the application from command line

To start the application with the AD-96TOF1-EBZ camera module in "far" mode open a Terminal window and type in the command below.
```
/opt/robotics-ai/slam/run.sh
```
To start the application with the AD-96TOF1-EBZ camera module from the command line in "med" mode you can use the command line below.
```
/opt/robotics-ai/slam/run_med.sh
```
To start the application with the AD-FXTOF1-EBZ camera module or the AD-3DSMARTCAM1-PRZ camera from the command line you can use the command line below.
```
/opt/robotics-ai/slam/run_fx.sh
```

The image may be too dark or too saturated. To mitigate this issue an auto gain feature has been implemented. (Unfortunately auto gain does not work on Xavier AGX and Xavier NX.)
The brightness of the image can be adjusted by passing a parameter in the command line. The parameter that controls the image saturation is called "gamma" and is in the range 0.1 to 5.0. 0.1 is the most saturated while 5.0 is the darkest.
To set the gamma correction parameter to 0.5 you should use the command line:
```
/opt/robotics-ai/slam/run.sh gamma:=0.5
```
or
```
/opt/robotics-ai/slam/run_med.sh gamma:=0.5
```
or
```
/opt/robotics-ai/slam/run_fx.sh gamma:=0.5
```
Different values for the gamma parameter can be tested to see which generates the best results.

The gamma parameter can also be set by using the configuration tool.
To start the configuration tool open a new Terminal window and type:
```
/opt/robotics-ai/[Installed application]/run_conf.sh
```
The gamma parameter can be found in the tof_source panel. (Setting the gamma parameter too often on AGX/NX boards may lead to a freeze in the camera driver).

#### Running the application in offline mode:

The application can be started in offline mode by using the command line:
```
/opt/robotics-ai/slam/run_capture.sh capture_name:=[full path for the capture file]
```

### Recording captures

[Record captures](https://github.com/robotics-ai/tof_process_public/blob/main/recording/README.md)

## Uninstalling the app
To uninstall the SLAM application open a terminal window and type.
```
sudo apt purge slam
```
## Troubleshooting
PC
[Linux PC specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/PC/README.md)

Xavier AGX
[Linux Xavier AGX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-AGX/README.md)

Xavier NX
[Linux Xavier NX specific info](https://github.com/robotics-ai/tof_process_public/blob/main/slam/Xavier-NX/README.md)
