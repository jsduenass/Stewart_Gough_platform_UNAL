
# Stewart Gough platform project analysis
This repo documents the updating process of PRISMMATIC(Parallel Robot Interface for Simulation of Machining Multi-Axis Trajectories and Integral Control), an Stewart Gough platform at Universidad Nacional de Colombia. This work is done as part of the final project of the class _Sensors and Actuators_ Semester 2021-II. 

## (Tentative) Objectives
The project has the following objectives:
* Update the platform and make it's system requirements compatible with a modern system (Windows 10 - MATLAB r2021a).
* Moving the platform using open source software (Python 3.7 or higher).
* Evaluate the impact of sensor quality on the performance of the system.


## Process

### Getting to know the system
The process started by getting acquaintance with the platform. After an onsite visit of the platform, the team received the corresponding documentation and produced a [file](project_structure.txt) containing a log with every one of the files received.

```
tree /f >  project_structure.txt
```

This analysis proof fruitful and provided a starting path '/ENTREGA-FINAL-RC-380-2011/CONTROLADORES/PRISMMATIC/cd/Software' to begin the search.

The file 'MoveSG.m' under '\ENTREGA-FINAL-RC-380-2011\CONTROLADORES\PRISMMATIC\cd\Software\GUI_V3\' becomes a starting point to test the Software 

find xpc dependencies and usage 

```
findstr /i /n /s "xpc" *.m > xpcMatch.txt
```

## Inquiries 

* Software license the project is licensed under.
* History, participants and their contributions.
* Components and system architecture.

<!-- Hoja de ruta -->



## Information about legacy system 

### System requirements

<<<<<<< HEAD
**xPC Target (deprecated)**: Mathworks toolbox for real time model HIL (Hardware in the Loop) simulation. produces __.dlm__ files.
=======
**xPC Target (deprecated)**: Mathworks  toolbox for real time model  HIL (Hardware in the Loop) simulation.  produces __.dlm__ files. [1](#references-and-resources)

>>>>>>> 1239ae6a630799ca9220814644a2e80cb1ec227e

![system architecture](media/imgs/system_architecure.png)

### Components:

* Single board computer (SBC) PCM-4153.
* Diamond MM 16-AT.
* STM32F407 microcontroller.

### (work in progress) Parties involved 
* Edgar Bolivar
* DIMAUN (Grupo de Trabajo en Nuevas Tecnologías Diseño, Manufactura y Automatización)

## References and Resources

1 [forum question](https://www.mathworks.com/matlabcentral/answers/479843-about-xpc-target-and-supproted-ioboard)

2 [matlab real time / xPC successor](https://www.mathworks.com/products/simulink-real-time.html?s_tid=FX_PR_info)

3 [Real time matlab laboratory](http://tsakalis.faculty.asu.edu/coursea/481LAB2015.pdf)

4 Frank González-Morphy (2022). [xPC Target Quick Reference Guide](https://www.mathworks.com/matlabcentral/fileexchange/6414-xpc-target-quick-reference-guide), MATLAB Central File Exchange. Retrieved January 23, 2022. 

5 [xpc target User guide Version 2](http://www.bmed.mcgill.ca/reklab/manual/common/xpc/documentation/xpc_target_ug%5B1%5D.pdf). Retrieved January 23, 2022.

6 [MATLAB Real time documetation](https://www.mathworks.com/help/pdf_doc/slrealtime/index.html)