clc, clear, close all
%% setup xpc Compiler
xpcgetCC('supported')       % get suppoerted Compiler list
xpcgetCC('installed')       % get list of compilers available in your machine
getxpcenv                   % get xpc enviroment properties
xpcgetCC                    % get compiler
xpcsetCC('setup')           % choose from list of valid compilers
doc xpctarget.targets       % open the documentation on xpc target    

%% Setup  the default xpc target properties           
tgs = xpctarget.targets;
tgs.makeDefault('TargetPC2');
env.TargetBoot = 'DOSLoader';
env.TcpIpTargetAddress = '192.168.1.12';
env.TcpIpSubNetMask = '255.255.255.0';

tgs.DefaultTarget                       % check properties of the default target

%%   stablish  connection  with xpc target
% If deault is not configured 
tg = xpctarget.xpc('TCPIP','192.168.1.12','22222')  %defined the properties in the xpc target 
%%
% If deault is configured  
tg = xpctarget.xpc;
 
connectivity= tg.targetping           % check conectivity
if connectivity =='success'
    tg.Application          % check application status
    tg.load('Code2XPCtarget\GUI_User_V1_3')

    % check other properties 
    tg.StateLog
    tg.Status
    tg.StopTime
end
sc1 = addscope(tg,'target',1)
sc1.set('Grid', 'on')

fs= tg.fs

fs.dir
fs.pwd
fs.cd('C:\XPCFILES')
id=  fs.fopen('XPCBOOT.COM')
id=  fs.fopen('TRAJEC2.DAT')

text=fs.fread(id);

fs.dir
fs.cd('C:\')
%% test generated position signals

X=-20,        Y=0,        Z=0;
Roll=0,  Pitch=0;,   Yaw=0;
% based on modified MoveSG function 
%[d,ActuatorsIndx] =
[d,ActuatorsIndx]=move( X,Y,Z,Roll,Pitch,Yaw)
%d=[-319 ,-319,-319,-319,-319,-319];
%d=[0 ,0,0,0,0,0];
d=[419 ,419,419,419,419,419];

for j=1:6
    tg.setparam(ActuatorsIndx(j),d(j));      %set_param('GUI_User_V1_3/If Action Subsystem5/Set1','ActLen',['[',num2str(d'),']']);
end
d
%tg.setparam(0,1);              %set_param('GUI_User_V1_3/Constant1','Value','1');      

Constant1 = 0;
tg.start
output=tg.OutputLog();
tg.setparam(Constant1,1);
input('Presione Enter para terminar')
tg.setparam(Constant1,0);
%%
% signals id
m=100
id_distance=[99, 101, 103];  

n=length(id_distance);

for i=1:n
    disp(tg.getsignalname(id_distance(i)))
end

distance=zeros(m,n);
tic 
Ts=0.01
for k=1:m

    distance(k,:) = tg.getsignal(id_distance);

     pause(Ts)

end
toc 
%tg.stop
%%
close all
plot(distance)
%% useful commands 

xpctargetspy                    % replicate monitor into a window 
tg.getdisp                      % info    
% xpcwwwenable                  % web view in http://IP:port usually
% http://192.168.1.12:22222

%var=tg.getTargetNames()
tg.cd()
tg.cd('C:\XPCFILES\')    
tg.put(fileXPC)                                      %Put file into target PC.
tg.cd('C:\')


%%
close all

X=20,        Y=0,        Z=200;
Roll=0,  Pitch=0,   Yaw=0;

n=100
t= linspace(700,1000,n);
log= zeros(6,n);
for k=1:n
    Z = t(k)  
    [d,ActuatorsIndx]=move(X,Y,Z,Roll,Pitch,Yaw);
    log(:,k)=d;
    
end
plot(t,log)


log(:,1)

log(:,end)

 % 653 mm altura total Home 
 % 23 mm altura placas 
 
 %% 
clear
tau(1)=46.6 ;              
tau(2)=25.3 ;           
tau(3)=1330.7;
tau(4)=28.7;                                     
tau(5)=90.6;                           
tau(6)= 81;  		
kdc(1)=167.512;
kdc(2)=77.798;              
kdc(3)=4613.089;
kdc(4)=98.129;
kdc(5)=343.297;
kdc(6)=304.778;
