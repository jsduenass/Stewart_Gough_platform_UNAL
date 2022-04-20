# matlab raspbery pi experiment 

This is proof of concept that will use a raspberry pi connected with MATLAB  in order to control the Stewart Gough (SG) platform.


# Raspberry set up


Change hostname to _sg_
```
sudo nano /etc/hostname
sudo nano /etc/hosts

reboot
``` 

Configure ssh
activate ssh service

keybased authentification 
generate keys


## Process 
install MATLAB in raspbery 

configure MATLAB

```
sudo matlab-rpi-setup
```

MATLAB Online specified name: _rpiSG_

### Configure ssh

connect via ssh to the raspbery


```
git clone https://github.com/jsduenass/Stewart_Gough_platform_UNAL.git
``` 


