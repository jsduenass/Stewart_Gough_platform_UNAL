clc, clear, close all

X=0;
Y=0;
Z=0;
Roll=pi/3;
Pitch=0;
Yaw=0;

[d,ActuatorsIndx] =MoveSG( X,Y,Z,Roll,Pitch,Yaw)

%%


getxpcenv
setxpcenv('CCompiler', 'VisualC')
xpcgetCC('supported')
setxpcenv('CompilerPath','C:\Program Files\Microsoft Visual Studio\2022\Community')

%%
getxpcenv

 xpcgetCC

 xpcsetCC('setup')
%%
 setxpcenv('CCompiler', 'VisualC')

setxpcenv('CCompiler','Watcom')


xpcgetCC

xpcgetCC('installed')


%%

slrtExplorer

 xpcexplr

 %% Imporrtant commands 
 % stablish  connection  with xpc target
 tg = xpctarget.xpc('TCPIP','192.168.1.12','22222')
 
tg.targetping
tg.Application

tg.load('Code2XPCtarget\GUI_User_V1_3')
%%
tg.StateLog
tg.Status
tg.StopTime
tg.start
 