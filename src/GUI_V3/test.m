clear, clc, close all
%% Set up
tg = xpctarget.xpc;
 
connectivity= tg.targetping           % check conectivity
if connectivity =='success'
    tg.Application          % check application status
    tg.load('Code2XPCtarget\GUI_User_V1_3');
    %open_system('Code2XPCtarget\GUI_User_V1_3');

    % check other properties 
    tg.StateLog
    tg.Status
    
    tg.StopTime
end

% create scopes
% 'target' 'host' 'file'
sc1 = addscope(tg,'target',1)
sc2 = addscope(tg,'target',2)
sc3 = addscope(tg,'target',3)
sc4 = addscope(tg,'target',4)



%% input signal id
id_input=[];

for k=1:12
    name = ['SG-ADC Sensors/MM-16-AT Analog Input/p',num2str(k)];
    id_input(k)=getsignalid(tg,name);
end

id_distance= id_input(1:2:11);   
id_currents = id_input(2:2:12);

%% PWM signal id 
id_PWM=[];

for k=2:7
    name = ['If Action Subsystem6/Referece/From File1/s',num2str(k)];
    id_PWM(k)=getsignalid(tg,name);
end


%% Read signals into scopes 
sc1=tg.getscope(1)
sc1.set('Grid', 'on')
sc1.addsignal(id_distance)
sc1.YLimit = [0 5];
sc1.start;

sc2 = tg.getscope(2);
sc2.addsignal (id_distance);
sc2.DisplayMode = 'Numerical';
sc2.start;

sc3=tg.getscope(3)
sc3.set('Grid', 'on')
sc3.addsignal(id_currents)
sc3.YLimit = [0 5];
sc3.start;

sc4 = tg.getscope(4);
sc4.addsignal (id_PWM);
%sc4.DisplayMode = 'Numerical';
sc4.start;

Constant1 = 0;
tg.start

%% run movements

X=0,        Y=0,        Z=750;
Roll=-40,  Pitch=-40,   Yaw=0;

% based on modified MoveSG function 
[d,id_PWM] = move( X,Y,Z,Roll,Pitch,Yaw)


for j=1:6
    tg.setparam(id_PWM(j),d(j));      %set_param('GUI_User_V1_3/If Action Subsystem5/Set1','ActLen',['[',num2str(d'),']']);
end

%tg.setparam(0,1);              %set_param('GUI_User_V1_3/Constant1','Value','1');      

output=tg.OutputLog();
tg.setparam(Constant1,1);      % enable movement
input('Presione Enter para terminar')
tg.setparam(Constant1,0);      % stop movement 


%% log
saveData=false;

if saveData
    
prefix=datestr( now ,'mm_dd_HH_MM_');
title='data.mat';
fileName=['./dumpOutput/', prefix , title]

end
