# Box measurement app for ADI Smart Camera

## Hardware setup AD-3DSMARTCAM1-PRZ
Required hardware AD-3DSMARTCAM1-PRZ:
 - AD-3DSMARTCAM1-PRZ camera
 - WiFi/ETH connection
 
 ![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/adi_smart.png)

For additions info please see: 
[ADI Smart Camera](https://wiki.analog.com/resources/eval/user-guides/ad-3dsmartcam1-prz)

## Software setup

The first step is to download scripts and deb packages:
- [external dependencies installer script](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/ADI-Smart-Camera/install_box-measure_dependencies_bionic.sh)

- [AD-3DSMARTCAM1-PRZ camera deb package](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/ADI-Smart-Camera/aditof-camera-AD-3DSMARTCAM1-PRZ_0.0.1_arm64_nano.deb)

- [Box measure deb package](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/ADI-Smart-Camera/box-measure_0.0.5_arm64_nano.deb)

Install the app and external dependencies using: (you may need to set execute permissions for the file)
```
./install_box-measure_dependencies_bionic.sh
```
 
## Troubleshooting
### solutions to common problems
   - if the camera stops providing frames to the application the the NX board needs to be restarted.
