
# Stewart Gough platform project analysis
This repo documents the updating process of PRISMMATIC(Parallel Robot Interface for Simulation of Machining Multi-Axis Trajectories and Integral Control), an Stewart Gough platform at Universidad Nacional de Colombia. This work is done as part of the final project of the class _Sensors and Actuators_ Semester 2021-II. 

## Table of contents

* [Process](#process)
* [Inquires](#inquiries) 
* [Information about legacy system](#information-about-legacy-system)
* [Components](#components)
* [References and resources](#references-and-resources)

## (Tentative) Objectives
The project has the following objectives:
* Update the platform and make it's system requirements compatible with a modern system (Windows 10 - MATLAB r2021a).
* Moving the platform using open source software (Python 3.7 or higher).
* Evaluate the impact of sensor quality on the performance of the system.


## Process

### Getting to know the system
The process started by getting acquaintance with the platform. After an onsite visit of the platform, the team received the corresponding documentation and produced a [file](project_structure.txt) containing a log with every one of the files received.

```
tree /f > project_structure.txt
```
Note: this file is encoded in windows 1252 encoding


This analysis proof fruitful and provided a starting path '/Software' to begin the search.

### First contact with the platform software
In order to check the correct operation of the hardware, the procedure indicated in the user manual provided in the previously received files was followed.

#### Installation of drivers and programs
Initially the platform was connected with MATLAB R2011a using the xPCTarget toolbox, as this toolbox was discontinued and replaced by Simulink Real Time, version r2011a was downloaded to be able to use it and configure the platform.


In order for the platform communication card to connect with xPCTarget, it is necessary to add the drivers from the '\Software\thirdpartydrivers' folder to the toolbox drivers folder. In addition, the 'Software\Stewart_Gough_library' library is also added to the MATLAB path to be able to use it.

With the software configured it is necessary to install a C compiler; testing with several compilers we found that the version of MATLAB used only recognizes the compilers installed by __Visual Studio 2010 Professional__ (recommended software in the original documentation), this version of Visual Studio was difficult to find as an online installation did not work since Microsoft servers are available, therefore, it was necessary to look for the version in the iso file (packaged with all the files necessary for installation). This program was found at the following [link](https://51-68-135-147.xyz/Getintopc.com/Visual_Studio2010_Professional_x86_x16-81637.iso?md5=m66_WqpIkGd_2yU8rFLZyg&expires=1645586596).

Once the C compiler was installed, MATLAB recognized it and proceeded with the network configuration of the card.

```
tgs = xpctarget.targets;
tgs.makeDefault('TargetPC1');
env.TargetBoot = 'DOSLoader';
env.TcpIpTargetAddress = '192.168.1.12';
env.TcpIpSubNetMask = '255.255.255.0';
```

The next step is to set the IP address of the host PC to 192.168.1.13 with subnet mask 255.255.255.0. Finally, to move the platform, run the *GUI_V3.m* file from the 'Software\GUI_V3' folder.

#### Testing the connection



#### First steps of editing
To find out how it works, instances of the XPCTarget toolbox were searched for in the 'Software\GUI_V3' folder. The matches found are in the [xpcMatch](xpcMatch.txt) file.

```
findstr /i /n /s "xpc" *.m > xpcMatch.txt
```
This information allow us to understand how and where the deprecated _xPC Target_  library was used, identifying './GUI_V3/BuildXPC.m:15:tgPC104 = xpctarget.xpc' as a starting point to understand the code. 




## Inquiries 

* Software license the project is licensed under.
* History, participants and their contributions.
* Components and system architecture.
* Is Matlab 2017a compatible? 

<!-- Hoja de ruta -->



## Information about legacy system 

### System requirements
* Matlab 2011a  [download] (https://www.mathworks.com/downloads/?release=R2011a) 

*  __xPC Target (deprecated)__: Mathworks  toolbox for real time model  HIL (Hardware in the Loop) simulation.  produces __.dlm__ files. [1](#references-and-resources)



### Components:

* Single board computer (SBC) PCM-4153.
* Diamond MM 16-AT.
* STM32F407 microcontroller.

![system architecture](media/imgs/system_architecure.png)


### (work in progress) Parties involved 
* Edgar Bolivar
* DIMAUN (Grupo de Trabajo en Nuevas Tecnologías Diseño, Manufactura y Automatización)

## References and Resources

1. [Forum xPC question](https://www.mathworks.com/matlabcentral/answers/479843-about-xpc-target-and-supproted-ioboard).
2. [MATLAB real time/xPC successor](https://www.mathworks.com/products/simulink-real-time.html?s_tid=FX_PR_info).
3. [Real time MATLAB laboratory](http://tsakalis.faculty.asu.edu/coursea/481LAB2015.pdf).
4. Frank González-Morphy (2022). [xPC Target Quick Reference Guide](https://www.mathworks.com/matlabcentral/fileexchange/6414-xpc-target-quick-reference-guide), MATLAB Central File Exchange. Retrieved January 23, 2022. 
5. [xPC target User guide Version 2](http://www.bmed.mcgill.ca/reklab/manual/common/xpc/documentation/xpc_target_ug%5B1%5D.pdf). Retrieved January 23, 2022.
6. [MATLAB Real time documentation](https://www.mathworks.com/help/pdf_doc/slrealtime/index.html).
7. [STM32 Microcontroller Support ](https://www.mathworks.com/products/hardware/stmicroelectronics.html)

