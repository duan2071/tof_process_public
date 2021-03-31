### Recording captures
Open a Terminal window.
To start the record application type:
```
/opt/robotics-ai/[Installed product]/run_record.sh
```
Installed product can be box-measure or door-sense.

This will start the application and show two windows with the IR image and the depth image. 
The application will not start recording until it receives a "start record command".

To start recording open a new Terminal window and type:
```
/opt/robotics-ai/[Installed product]/run_conf.sh
```
![Display Image](https://github.com/robotics-ai/tof_process_public/blob/main/box_measure/Doc/Images/record.png)

In the rqt_reconfigure_rai window select tof_record.

Enter a destination folder where the application will write the capture file. Make sure you have write access in that folder. Your best bet is somewhere in the home folder for the current user.

To start recording click on the unchecked box next to the record label. To stop recording click the box again.
