# Door sense app for ADI Smart Camera

## Hardware setup AD-3DSMARTCAM1-PRZ
Required hardware AD-3DSMARTCAM1-PRZ:
 - AD-3DSMARTCAM1-PRZ camera
 - WiFi/ETH connection
 
![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/Doc/Images/adi_smart.png)

For additions info please see: 
[ADI Smart Camera](https://wiki.analog.com/resources/eval/user-guides/ad-3dsmartcam1-prz)

## Software setup

The first step is to download scripts and deb packages:
- [external dependencies installer script](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/ADI-Smart-Camera/install_door-sense_dependencies_bionic.sh)

- [AD-3DSMARTCAM1-PRZ camera deb package](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/ADI-Smart-Camera/aditof-camera-AD-3DSMARTCAM1-PRZ_0.0.1_arm64_nano.deb)

- [deb package](https://github.com/robotics-ai/tof_process_public/blob/main/door_sense/ADI-Smart-Camera/door-sense_0.0.4_arm64_nano.deb)

Install the app external dependencies using: (you may need to set execute permissions for the file)
```
./install_door-sense_dependencies_bionic.sh
```

Install camera deb package:
```
sudo apt install ./aditof-camera-AD-3DSMARTCAM1-PRZ_0.0.1_arm64_nano.deb
```

This step installs the modules required to run the camera and needs to be done only once per system.

Install Door Sense deb package:
```
sudo apt install ./door-sense_0.0.4_arm64_nano.deb
```
This will install one linux application called Door Sense FX v04.

## Troubleshooting
### solutions to common problems
   - if the camera stops providing frames to the application the ADI Smart Camera needs to be restarted.
