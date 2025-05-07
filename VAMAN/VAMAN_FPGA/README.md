This contains steps to install fpga and run successfully
Steps to follow:
1) Install the zip provided i.e **fpga.zip** onto **Desktop**
2) now open terminal and go to the fpga folder
3) In here **/Desktop/fpga** type: **chmod +x setup.sh** --> This command is particularly useful for making scripts and programs executable. In this way, users can run them without typing their full path or using a dot slash (./) before their name.
4) **sudo bash setup.sh**
5) After running the above command, Go to: **file Manager --> Other Locations --> Computer --> root** . Copy the files **Symbiflow** and **Pygmy-dev** paste them in **"/desktop/fpga"**
6) Now download **arch.tar.gz** using this below link and also place it in **/desktop/fpga**:
   <pre>https://iith-my.sharepoint.com/:u:/g/personal/gadepall_ee_iith_ac_in/Ebot5QHEYXBAo-7n4hnvJu0B8vMrTIdj_COHJC2cmDY1ww?e=bqDxHI</pre>
7) Make sure that **/desktop/fpga** contains **pygmy-dev**, **setup.sh** and **symbiflow** and zip file **arch.tar.gz**<br>
8) Next:
   At Home:
   <pre>
   sudo apt update -y <br>
   sudo apt upgrade -y<br>
   sudo apt install openssh-server sshpass build-essential libssl-dev libffi-dev python3-dev bison flex git tcl-dev tcl tcl-tclreadline libreadline-dev  autoconf libtool make automake texinfo pkg-config libusb-1.0-0 libusb-1.0-0-dev gcc-arm-none-eabi libnewlib-arm-none-eabi telnet python3 apt-utils libxslt-dev cmake curl python3-pip python3-venv -y<br>
   pip3 install gdown lxml simplejson<br>
   sudo apt install openssh-server sshpass<br>
   sudo apt install build-essential libssl-dev libffi-dev python3-dev bison flex git tcl-dev tcl tcl-tclreadline libreadline-dev  autoconf libtool make automake texinfo pkg-config libusb-1.0-0 libusb-1.0-0-dev gcc-arm-none-eabi libnewlib-arm-none-eabi telnet python3 apt-utils libxslt-dev python3-lxml python3-simplejson cmake curl  python3-setuptools python3-pip<br>
   cp arch.tar.gz /home/sujith/Desktop/fpga/arch.tar.gz<br>
   export INSTALL_DIR=/home/sujith/Desktop/fpga/symbiflow<br>
   tar -C $INSTALL_DIR  -xvf /home/sujith/Desktop/fpga/arch.tar.gz<br>
   export PATH="$INSTALL_DIR/quicklogic-arch-defs/bin:$INSTALL_DIR/quicklogic-arch-defs/bin/python3:$PATH"<br>
   cd /home/nikhil/Desktop/fpga/pygmy-dev/tools/quicklogic-fasm<br>
   nvim requirements.txt<br>
      Replace contents with these lines:
         -e git+https://github.com/symbiflow/fasm.git#egg=fasm
         -e git+https://github.com/antmicro/quicklogic-fasm-utils.git#egg=fasm-utils<br>
      
   python3 -m venv venv<br>
   source venv/bin/activate<br>

   pip3 install -r requirements.txt<br>
   sudo python3 setup.py install<br>
   cd /home/sujith/Desktop/fpga/pygmy-dev/tools/quicklogic-yosys<br>
   make config-gcc<br>
   make -j4 install PREFIX=$INSTALL_DIR<br>
   cd /home/sujith/Desktop/fpga/pygmy-dev/tools/yosys-symbiflow-plugins<br>
   export PATH=$INSTALL_DIR/bin:$PATH<br>
   make -j4 install<br>
   cd /home/sujith/Desktop/fpga/pygmy-dev/tools/vtr-verilog-to-routing<br>
   make -j4<br>
   nvim ~/.bashrc<br>
   #paste the following 3 lines at the end of the file
   export  INSTALL_DIR=/home/sujith/Desktop/fpga/symbiflow
   export PATH="$INSTALL_DIR/quicklogic-arch-defs/bin:$INSTALL_DIR/quicklogic-arch-defs/bin/python3:$PATH"
   export PATH=/home/sujith/Desktop/fpga/symbiflow/bin:$PATH
      
   source ~/.bashrc<br>
   vpr -h<br>
   yosys -h<br>
   qlfasm -h<br>
   ql_symbiflow -h<br>
   cd $INSTALL_DIR/quicklogic-arch-defs/tests/counter_16bit<br>
   ls<br>
   ql_symbiflow -compile -d ql-eos-s3 -P pd64 -v counter_16bit.v -t top -p chandalar.pcf -dump binary<br>
   pip3 install gdown lxml simplejson<br>
   ql_symbiflow -compile -d ql-eos-s3 -P pd64 -v counter_16bit.v -t top -p chandalar.pcf -dump binary<br>
   ls<br>
   cd /home/sujith/Desktop/fpga<br>
   ls<br>
   mkdir fpga-examples<br>
   cd fpga-examples<br>
   svn co https://github.com/gadepall/vaman/trunk/fpga/setup/codes/blink<br>
   cd blink<br>
   ls<br>
   
   <b>Command to compile code:
      
   ql_symbiflow -compile -src /home/sujith/Desktop/fpga/fpga-examples/blink -d ql-eos-s3 -P PU64 -v helloworldfpga.v -t helloworldfpga -p quickfeather.pcf -dump binary</b><br>
   
   ls<br>
   nvim helloworldfpga.v --> This file contains the code<br> 
   nvim quickfeather.pcf --> This file contains pin configurations<br>
   <b>Make sure to compile the file after modifying .v or .pcf file </b><br>
   
   <b>Command to upload code to vaman:</b><br> 
   #Make sure that vaman is in upload mode(i.e Green Light)<br>
   # After Compiling the code make sure to copy the bin file and paste it in home and perform the upload command <br>
   <b>sudo python3 /home/sujith/TinyFPGA-Programmer-Application/tinyfpga-programmer-gui.py --port /dev/ttyACM0 --appfpga /home/nikhil/helloworldfpga.bin --mode fpga</b>
   </pre>
