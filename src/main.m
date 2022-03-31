clear, clc, close all

run 'xpcSetupSG'
%% Get simulation parameters IDs and set values
id_mode = tg.getparamid('Mode','Value');
tg.setparam(id_mode,0);

id_kp = tg.getparamid('Controller/Discrete PID Controller/Proportional Gain','Gain');
id_ki = tg.getparamid('Controller/Discrete PID Controller/Integral Gain','Gain');
id_kd = tg.getparamid('Controller/Discrete PID Controller/Derivative Gain','Gain');

kp=5; ki=0.5; kd=0.1;

kp=10; ki=1; kd=1;

kPID=[kp,ki,kd];
tg.setparam(id_kp, kp);
tg.setparam(id_ki,ki);
tg.setparam(id_kd,kd);

id_ref = tg.getparamid('Reference pose','Value');

%% Run movements

X=0.0;        Y=0.0;        Z=0.78;
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
tg.stop
saveData = command==1;

data = tg.OutputLog;
dt=0.1;
control=data(:,1:6);
e=data(:,7:12);
dist_input=data(:,13:18);
current_input=data(:,19:24);

v_input=gradient(dist_input,dt);
N = size(e,1);
t= 0:dt:(dt*(N-1));

if saveData
    
    prefix = datestr( now ,'mm_dd_HH_MM_');
    title='data.mat';
    fileName=['./dumpOutput/', prefix , title]
    save(fileName,'t','control','e','dist_input','v_input','kPID','pose','current_input')
    
    
    tg.stop;

end


%%
run 'plot_log_info'
