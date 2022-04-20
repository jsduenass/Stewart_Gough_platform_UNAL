# Set up xpc target (PCM-4153) 
MATLAB uses a xpc target computing device in order to control the SG platform. This guide will help you configure the PCM-4153 Single Board Computer (SBC) so it can be used by MATLAB as xpc target.


install XPCTarget OS on the SBC.


The MATLAB's _XPCTarget_ allows several boot options:
 
you to generate a boot image in any of the following formats:

* DOSLoader
* BootFloppy
* CDBoot
* DOSLoader
* NetworkBoot
* StandAlone
 

toolbox has several boot device options available, but 



Of these, the SBC permits use _DOSLoader_, _CDBoot_ or _NetworkBoot_. However, the DOSLoader is the easiest and most common way to create the boot SBC, therefore this guide tells how to boot the SBC with __DOSLoader__ method.
> To view another boot method, see the _Getting Started guide_ typing `doc xpc` in the MATLAB command window.

## Boot install guide

### Create a bootable device
To boot the PCM-4153 through the a Compact Flash card, you must first make it a __freeDOS bootable device__, this may be done by [rufus](https://rufus.ie/en/), a utility that helps format and create bootable flash drives[^ruf].

<p align="center">
    <img atl="compact flash card" src="https://upload.wikimedia.org/wikipedia/commons/thumb/3/3b/Compactflash.jpg/800px-Compactflash.jpg" width="250px"/>
</p>

Using the configurations shown in the image, you can create a bootable device.

<p align="center">
    <img atl="rufus config" src="https://user-images.githubusercontent.com/30636259/164293491-dc89631f-1680-4c1a-a55a-65331764f7d8.png" />
    <br>
    <b>Rufus 3.18 configuration</b>
</p>

### Target default configuration
To install the XPCTarget OS on the SBC, first you need to create or edit a target in the host PC. For this, first you must list the targets in the host PC.

```matlab
tgs = xpctarget.targets
```

if you want edit a pre-existent target, you can use the following command:

```matlab
env = tgs.Item('target_name');
```
or to add a new target:
```matlab
env = tgs.Add('target_name');
```

once created the target, you can edit the target properties. First, assign an IP address to the target, indicating its subnet mask, port and gateway ip.

```matlab
env.TcpIpTargetAddress = '168.176.26.12';
env.TcpIpGateway = '168.176.26.1';
env.TcpIpSubNetMask = '255.255.254.0';
env.TcpIpTargetPort='22222';
```

Lastly, to obtain the boot files, you must specify the path to the boot files and the type target Boot (in this case _DOSLoader_).

```matlab
env.TargetBoot = 'DOSLoader';
dirName = 'any_folder_path';
env.DOSLoaderLocation = dirName;
```	

To verify that all configurations are well indicates, you can use `getxpcenv`. Finally, the files will copy to the destination folder running the foollowing command:

```matlab
xpcbootdisk
```

When you create a _DOSLoader_ bootable device, you obtain a folder with the files necessary to run XPCTarget OS in the PCM-4153 but these are not in the Compact Flash card yet.

```matlab
copyfile(dirname, 'FlashCard_letter_path');
```

### Plug and play
For the PCM-4153 to read the files from the Compact Flash card as the first boot option, you must follow the next steps:

1. Power off the PCM-4153.
1. Connect the Compact flash card to the PCM-4153.
1. Enter the bios of the SBC (by pressing <kbd>del</kbd> key at startup) and opening the list of boot options in the menu `Advanced BIOS features > First Boot Device` and select the _HDD_ slot in where is the compact flash.
    <p align="center">
        <img src="https://user-images.githubusercontent.com/30636259/164299896-938cb499-1903-4524-8690-66ac255c47a5.jpeg" alt="bios config" width="550px"/>
    </p>
1. Reboot the PCM-4153.


## References
[^ruf]: [Rufus](https://rufus.ie/en/)