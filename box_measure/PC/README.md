# Box measurement app for PC
public documentation and releases for tof box measure project for PC platform

## Introduction
 - describes the scope of the demo and intended setup
## Hardware setup
 - lists all the neccessary hardware elements
 - shows how to connect everything together
## Software setup
The first step is to download and install the box measurement installer. [Box measurement PC installer Ubuntu 20.04](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/PC/install_box-measure_focal_amd64_0.0.2.sh)
Install the app using: (you may need to set execute permisions for the file)
```
./install_box-measure_focal_amd64_0.0.2.sh
```
This will install a linux app called Box Measure
 
## Running the demo
### Position the camera and the box.
For best results the camera and the box should be placed similar to the positions represented in the image below. Plane brown boxes work best.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/fig1.png)

The camera should be positioned about one meter from the ground.

The box needs to be netween 1 meter and 3 meters from the camera. These limitations are due to the camera running in the medium range mode.

The box shoul be centered in the field of view of the camera.

The box dimensions should be between 20 cm and 90 cm.

Please watch the live demo video to see an example of how the camera and the box should be placed.

### Run the box measure app.

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/run_app.png)

The application will open two windows:
- an image window showing the input from the camera and the box measurement results overlayed on top
- a console window

![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/app_results.png)

 - video showing a live demo
## Troubleshooting
 - known issues
 - solutions to common problems
