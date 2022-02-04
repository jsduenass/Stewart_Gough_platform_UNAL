clc, clear, close all
%% setup xpc Compiler
xpcgetCC('supported')       % get suppoerted Compiler list
xpcgetCC('installed')       % get list of compilers available in your machine
getxpcenv                   % get xpc enviroment properties
xpcgetCC                    % get compiler
xpcsetCC('setup')           % choose from list of valid compilers
doc xpctarget               % open the documentation on xpc target    

%% Setup  the default xpc target properties           
tgs = xpctarget.targets;
tgs.makeDefault('TargetPC1');
env.TargetBoot = 'DOSLoader';
env.TcpIpTargetAddress = '192.168.1.12';
env.TcpIpSubNetMask = '255.255.255.0';

tgs.DefaultTarget                       % check properties of the default target

%%   stablish  connection  with xpc target
% If deault is not configured 
tg = xpctarget.xpc('TCPIP','192.168.1.12','22222')  %defined the properties in the xpc target 
% If deault is configured  
tg = xpctarget.xpc;
 
tg.targetping           % check conectivity
tg.Application          % check application status
% check other properties 
tg.StateLog
tg.Status
tg.StopTime

%% Run the application 
tg.load('Code2XPCtarget\GUI_User_V1_3')
tg.start
%% test generated position signals 
X=0,        Y=0,        Z=0;
Roll=pi/3,  Pitch=0;,   Yaw=0;
% based on modified MoveSG function 
[d,ActuatorsIndx] =MoveSG( X,Y,Z,Roll,Pitch,Yaw)










 