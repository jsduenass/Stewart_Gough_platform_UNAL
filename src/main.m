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
    name = ['Multiport Switch1/s',num2str(k)];    
    id_PWM(k) = getsignalid(tg,name);
end
%% error signal id 
id_error = zeros(6,1);

for k=1:6
    name = ['m2cm/s',num2str(k)];    
    id_error(k) = getsignalid(tg,name);
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
sc3.DisplayMode = 'Numerical';
sc3.start;

sc4.addsignal(id_error);
sc4.DisplayMode = 'Numerical';
sc4.start;

Constant1 = 0;
tg.start
%% Get simulation parameters IDs and set values
id_mode = tg.getparamid('Mode','Value');
tg.setparam(id_mode,0);

id_kp = tg.getparamid('Discrete PID Controller/Proportional Gain','Gain');
id_ki = tg.getparamid('Discrete PID Controller/Integral Gain','Gain');
id_kd = tg.getparamid('Discrete PID Controller/Derivative Gain','Gain');

kp=5; ki=0.5; kd=0.1;

kPID=[kp,ki,kd];
tg.setparam(id_kp, kp);
tg.setparam(id_ki,ki);
tg.setparam(id_kd,kd);

id_ref = tg.getparamid('Reference pose','Value');

%% Spy
%xpctargetspy
%xpcwwwenable

%% Run movements

X=0.05;        Y=0.05;        Z=0.78;
Roll=0;  Pitch=-0;   Yaw=0;
pose= [X Y Z Roll Pitch Yaw];
home= [0 0 0.7 0 0 0];
pose= home

% measured distance
id_dist_m = tg.getsignalidsfromlabel('dist_input');
d_measured = tg.getsignal(id_dist_m)'

% based on modified MoveSG function 
tg.setparam(id_ref, pose); 

input('Empezar?')

tg.start;
tg.setparam(id_mode,1);      % enable movement
command = input('Presione Enter para terminar [1] para guardar ')
tg.setparam(id_mode,0);      % stop movement 

%% log
close all 
tg.stop
saveData = command==1;

data = tg.OutputLog;

control=data(:,1:6);
error=data(:,7:12);
dist_input=data(:,13:18);
v_input=gradient(dist_input);
subplot(2,1,1)
plot( error,control)
subplot(2,1,2)

plot(control,v_input)
legend;

if saveData
    
    prefix = datestr( now ,'mm_dd_HH_MM_');
    title='data.mat';
    fileName=['./dumpOutput/', prefix , title]
    save(fileName,'control','error','dist_input','v_input','kPID','pose')
    
    
    tg.stop;

end

