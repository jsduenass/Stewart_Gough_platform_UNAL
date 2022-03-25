clear, clc, close all
%% Set up
% If deault is configured  
tg = xpctarget.xpc;
modelName = 'motionControlModel';
 
connectivity = tg.targetping;           % check conectivity
if strcmp(connectivity,'success')
    rtwbuild(modelName);    
    tg.load(modelName);
    %open_system(modelName);
    tg.stop;
    tg.ShowSignals ='off';
    tg.ShowParameters ='off';
else
    error('Failed connection');
end

% create scopes
% 'target' 'host' 'file'
sc1 = addscope(tg,'target',1);
sc2 = addscope(tg,'target',2);
sc3 = addscope(tg,'target',3);
sc4 = addscope(tg,'target',4);

sc5 = addscope(tg,'host',5);
sc6 = addscope(tg,'host',6);
%% Input signal id
id_input = zeros(12,1);

for k=1:12
    name = ['MM-16-AT Analog Input/p',num2str(k)];
    id_input(k)=getsignalid(tg,name);
end

id_distance= id_input(1:2:11);   
id_currents = id_input(2:2:12);
%% PWM signal id 
id_PWM = zeros(6,1);

for k=1:6
    name = ['Multiport Switch/s',num2str(k)];    
    id_PWM(k) = getsignalid(tg,name);
end
%% Read signals into scopes 
sc1.addsignal (id_distance);
sc1.DisplayMode = 'Numerical';
sc1.start;

sc2.set('Grid', 'on')
sc2.addsignal(id_currents)
sc2.YLimit = [0 5];
sc2.start;

sc3.addsignal(id_PWM);
%sc4.DisplayMode = 'Numerical';
sc3.start;

sc4.addsignal(id_PWM);
sc4.DisplayMode = 'Numerical';
sc4.start;

Constant1 = 0;
tg.start
%% Get simulation parameters IDs and set values
id_mode = tg.getparamid('Mode','Value');
tg.setparam(id_mode,0);

id_kp = tg.getparamid('Discrete PID Controller/Proportional Gain','Gain');
id_ki = tg.getparamid('Discrete PID Controller/Integral Gain','Gain');

tg.setparam(id_kp, 3);
tg.setparam(id_ki,0.01);
%tg.setparam(id_ki,0.01);

id_ref = tg.getparamid('Reference pose','Value');

%% Spy
%xpctargetspy
%xpcwwwenable

%% Run movements
tg.start;
input('Empezar?')
X=0;        Y=0;        Z=0.7;
Roll=0;  Pitch=-0;   Yaw=0;
pose= [X Y Z Roll Pitch Yaw];

% measured distance
id_dist_m = tg.getsignalidsfromlabel('dist_input');
d_measured = tg.getsignal(id_dist_m)'

% based on modified MoveSG function 
tg.setparam(id_ref, pose); 

tg.setparam(id_mode,1);      % enable movement
input('Presione Enter para terminar')
tg.setparam(id_mode,0);      % stop movement 

%% log
saveData=false;

data = tg.OutputLog(:,2:7)-50;

if saveData
    
    prefix=datestr( now ,'mm_dd_HH_MM_');
    title='data.mat';
    fileName=['./dumpOutput/', prefix , title]
    save(fileName,data)
    
    plot(data)
    legend('1','2','3','4','5','6')
    
    tg.stop;

end

