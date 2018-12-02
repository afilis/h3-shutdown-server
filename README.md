AllWinner H2+/H3 system shutdown (server part)  
---

The program is intended for prevention of overheating of Orange Pi 
(H2+/H3 based) after switching off. Overheating usually happens if 
you are using Armbian stretch (mainline) on it.  

Build
---
1. Download and unpack or1k toolchain (for x86_64/amd64) from here:  
https://github.com/openrisc/newlib/releases  
  wget https://github.com/openrisc/newlib/releases/download/v2.4.0/or1k-elf_gcc5.3.0_binutils2.26_newlib2.4.0_gdb7.11.tgz  
  tar xf or1k-elf_gcc5.3.0_binutils2.26_newlib2.4.0_gdb7.11.tgz  

2. Download and build the program:  
  git clone https://github.com/afilis/h3-shutdown-server.git  
  cd h3-shutdown-server  
  make  

Install
---
1. Copy files: arisc-fw.code, loader/* to /boot directory of a target device.  
2. Reboot your target device.
Note: You should install the client part of the program too.  

Info
---
This program based on these projects:  
https://github.com/orangecnc/h3_arisc_firmware  
https://github.com/orangecnc/h3_arisc_api  
https://github.com/Icenowy/h3-arisc-shutdown  


