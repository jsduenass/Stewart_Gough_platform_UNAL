clear, clc, close all
%% Set up
% If deault is configured  
tg = xpctarget.xpc;
modelName = 'motionControlModel';
 
connectivity = tg.targetping;           % check conectivity
if strcmp(connectivity,'success')
    %rtwbuild(modelName);    
    tg.load(modelName);
    %open_system(modelName);
    tg.stop;
    tg.ShowSignals ='off';
%     tg.ShowParameters ='off';
else
    disp('Failed connection');
end

% create scopes
% 'target' 'host' 'file'
sc1 = addscope(tg,'target',1)
sc2 = addscope(tg,'target',2)
sc3 = addscope(tg,'target',3)
sc4 = addscope(tg,'target',4)
%% Input signal id
id_input=[];

for k=1:12
    name = ['MM-16-AT Analog Input/p',num2str(k)];
    id_input(k)=getsignalid(tg,name);
end

id_distance= id_input(1:2:11);   
id_currents = id_input(2:2:12);

%% PWM signal id 
id_PWM=[];

for k=1:6
    %name = ['Motors - F4 STM - PWM/If Action Subsystem6/Referece/From File1/s',num2str(k)]
    name = ['Multiport Switch/s',num2str(k)]      
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
sc4.addsignal(id_PWM);
%sc4.DisplayMode = 'Numerical';
sc4.start;

Constant1 = 0;
tg.start
%% Get IDs
id_mode = tg.getparamid('Mode','Value');
tg.setparam(id_mode,0);

id_kp = tg.getparamid('Discrete PID Controller/Proportional Gain','Gain');
id_ki = tg.getparamid('Discrete PID Controller/Integral Gain','Gain');


id_ref = tg.getparamid('Reference','Value');


%% Run movements
X=0,        Y=0,        Z=0.9;
Roll=-0,  Pitch=-0,   Yaw=0;

% measured distance
id_dist_m = tg.getsignalidsfromlabel('dist_input');
d_measured = tg.getsignal(id_dist_m)'

% based on modified MoveSG function 
[d,~] = inverse_kinematics([X Y Z]', [Roll Pitch Yaw])
tg.setparam(id_ref, d); 

tg.setparam(id_mode,1);      % enable movement
input('Presione Enter para terminar')
tg.setparam(id_mode,0);      % stop movement 

%% log
saveData=false;

if saveData
    
prefix=datestr( now ,'mm_dd_HH_MM_');
title='data.mat';
fileName=['./dumpOutput/', prefix , title]

end
