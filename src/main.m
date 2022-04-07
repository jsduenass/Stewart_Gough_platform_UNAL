clear, clc, close all

run 'xpcSetupSG'
%% Get simulation parameters IDs and set values
id_mode = tg.getparamid('Mode','Value');
tg.setparam(id_mode,0);

id_kp = tg.getparamid('Controller/Discrete PID Controller/Proportional Gain','Gain');
id_ki = tg.getparamid('Controller/Discrete PID Controller/Integral Gain','Gain');
id_kd = tg.getparamid('Controller/Discrete PID Controller/Derivative Gain','Gain');

id_kb = tg.getparamid('Controller/Discrete PID Controller/Kb','Gain');

kp=15; ki=6; kd=0.1;

kb=0.7*ki;

kPID=[kp,ki,kd];
tg.setparam(id_kp, kp);
tg.setparam(id_ki,ki);
tg.setparam(id_kd,kd);
tg.setparam(id_kb,kb);

id_ref = tg.getparamid('Reference pose','Value');

%% Run movements

X=0.0;        Y=0.0;        Z=0.8;
Roll=-20;  Pitch=10;   Yaw=0;
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
command = input('Presione Enter para terminar, [1] para guardar\n')
tg.setparam(id_mode,0);      % stop movement 

%% log
tg.stop

saveData = command==1;


fid = filesys.fopen(sc_file.FileName);
BinaryData = filesys.fread(fid);
% Close the file
filesys.fclose(fid);
% Convert to MATLAB format
MLData = readxpcfile(BinaryData);
data = MLData.data;
t=data(:,end);

control=data(:,1:6);
e=data(:,7:12);
dist_input=data(:,13:18);
current_input=data(:,19:24);
v_input = data(:,25:30);
a_input = data(:,31:36);

v_input(1,:)=zeros(1,6);

a_input(1,:)=zeros(1,6);
dt=t(2)-t(1);

dist_filtered=dist_input;
vel=gradient(dist_input,dt);
%%
if saveData
    
    sc_file.stop;
    tg.stop

    prefix = datestr( now ,'mm_dd_HH_MM_');
    title='data.mat';
    fileName=['./dumpOutput/', prefix , title]
    save(fileName,'t','control','e','dist_input','v_input','kPID','pose','current_input','v_input','a_input')
    
   

end

%% Plot logged data
run 'plot_log_info'

