# This code is for utilizing vaman by uploading wifi code into it using the arduino.

## Steps to follow:
1) Intially, Follow all the steps as given in **vaman/installation/termuxdebian/termuxubuntu_esp32.txt**
2) Find the circuit diagram i.e vaman_esp32 arduino connections at **gadepall/digital-design/main.pdf**
3) **Or** Download all the files that i provided and do the installations in <b> point3</b>
4) apt update && apt upgrade <br>
   apt install python3-pip <br>
   pip3 install platformio <br>
   pio lib --global install "stempedia/DabbleESP32" <br>
   .pio/build/esp32doit-devkit-v1/firmware.bin <br>
5) After **performing the first step**, a setup file will be created. or if you perform step 2 and 3 you can skip the 4th step.
6) In the **setup** file, we will get **4 files** inside it. <br>
   namely: src, .pio, platformio.ini, README.md
7) Remember to change the main.cpp that is in src folder<br>
   #define STASSID "Salient" **// Add your network username<br>**
   #define STAPSK  "12345678" **// Add your network password<br>**
8) Connect the arduino and vaman together, connect arduino to phone via otg and then vaman to arduino via the installation pdf. 
9) Now we have to be in the setup directory and run <b> pio run </b>.
10) Remember to remove enable pin <b>EN</b> as soon as it displays <b>Connecting...</b> and then remove <b>0</b> pin when it displays <b>writing 100%</b> and before           <b>Leaving...</b>
11) Once after succesfully uploading the code, we can upload new code using <b>pio run -t nobuild -t upload --upload-port 192.168.210.X </b>
