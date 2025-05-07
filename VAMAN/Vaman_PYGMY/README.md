# This consists of files in order to upload to Vaman_PYGMY
## Steps to follow:
1) Open termux and follow installation steps from **vaman/installation/termuxdebian/termuxdebian_arm.txt**
2) open main.c to edit the code to your preferences. The file main.c is available in **/data/data/com.termux/files/home/arm-examples/blink/src/main.c**
3) After making necessary modifications, **save** your file and exit.
4) To execute and **generate bin** file: Move to path **blink/GCC_Project**
5) Type **make -j4** to generate bin file.
6) **Path** for blink.bin **GCC_Project/output/bin/blink.bin**
7) **In PC Open terminal** and be in the home directory:
   Perform these installations<br>
   #Download the pygmy-sdk<br>
   cd /data/data/com.termux/files/home/ <br>
   git clone --recursive https://github.com/optimuslogic/pygmy-dev<br>

   #If Tinyfpga is not installed <br>
  git clone --recursive https://github.com/QuickLogic-Corp/TinyFPGA-Programmer-Application.git<br>
  sudo apt install python3-pip<br>
  sudo pip3 install tinyfpgab pyserial<br>
  sudo reboot<br>
8) Transfer the dot bin file to the pc along with the files that are included in the git.**Make sure that all the files are in the same location example :home**
9) **Update flash.sh:** sudo python3 /home/**Username**/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0  --appfpga top.bin --m4app  blink.bin --mode m4-fpga --reset. (Replace Username with your pc's username)
10) To get the pc's username type **whoami** in terminal, After editing save the file and exit.
11) Now **connect the vaman to pc**.
12) Make sure that vaman is in **Download mode**, i.e Green Led must be blinking.
13) **To enable Download Mode**: Press **RST** button once and then press **USR** button twice, this should do the job.
14) The code gets Successfully Booted.
15) **Error:** CLI mode, No port Found - Kindly change the cable, board and retry
