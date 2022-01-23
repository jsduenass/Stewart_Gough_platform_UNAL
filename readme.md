
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

'''
grep -r -n  --include=\*.m 'xpc' './ENTREGA-FINAL-RC-380-2011/CONTROLADORES/PRISMMATIC/cd' > ../xpcMatch.txt

'''

## Inquiries 

* Software license the project is licensed under.
* History, participants and their contributions.
* Components and system architecture.

<!-- Hoja de ruta -->



## Information about legacy system 

### System requirements

**xPC Target (deprecated)**: Mathworks  toolbox for real time model  HIL (Hardware in the Loop) simulation. . produces __.dlm__
 files 

![system architecture](media/imgs/system_architecure.png)

### Components:

* Single board computer (SBC) PCM-4153
* Diamond MM 16-AT
* STM32F407 microcontroller

### (work in progress) Parties involved 
* Edgar Bolivar
* DIMAUN (Grupo de Trabajo en Nuevas Tecnologías Diseño, Manufactura y Automatización)

## References and Resources
[forum question](https://www.mathworks.com/matlabcentral/answers/479843-about-xpc-target-and-supproted-ioboard)

[matlab real time / xPC successor](https://www.mathworks.com/products/simulink-real-time.html?s_tid=FX_PR_info)