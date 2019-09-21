This folder cntains the following 


1-Bit_Math.h file that contains basic mathematical MACROS

2-std_types.h that contains the basic type def since I am using u8 (unsigned char), u16 ...

3-Release hex files

4-Proteus test file 

5-Config.h file that contains the basic configurations such as which pins are set as inputs and which pins are set as output
6-Int.h file that contains the interfacign btween the hardware and software such as function prototype, which pin macros correponds to which pin ...
7-priv.h that contains some program definitions that should not be shared but I will share because I am a kind person
8-prog.c that contains the files implementation
9-And finally main.c that is the application layer. you should edit this file as much as you want


Steps to do BVT
1-Open the driver folder from any IDE (my version was eclipse 2019)
2-click build

Steps to test on proteus
1-Run proteus (I run it as administrator before using it because of a weird bug)
2-double click on the microcontroller on program file click on the DIO.hex path from the release folder in the library 
3-Click on play