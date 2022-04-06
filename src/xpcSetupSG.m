%% Set up
% If deault is configured  
tg = xpctarget.xpc('TCPIP','168.176.26.12','22222');
modelName = 'motionControlModel';

connectivity = tg.targetping;           % check conectivity
if strcmp(connectivity,'success')
    %rtwbuild(modelName);   
    
    %open_system(modelName);
    load_system(modelName);
    
    tg.ShowSignals ='off';
    tg.ShowParameters ='off';
    tg.load(modelName);         %load model after setting up all configurations

else
    error('Failed connection');
end

% create scopes
% 'target' 'host' 'file'
sc1 = addscope(tg,'target',1);
%sc1= getscope(tg,1);
sc2 = addscope(tg,'target',2);
sc3 = addscope(tg,'target',3);
sc4 = addscope(tg,'target',4);
sc5 = addscope(tg,'host',5);
sc6 = addscope(tg,'host',6);
sc_file = addscope(tg,'file',7);


sc_file.FileName='log2.dat';
sc_file.Decimation=100;

filesys = tg.fs;

filesys.dir
% tg.start
% 
% input('wait')
% tg.stop
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
%% e signal id 
id_e = zeros(6,1);

for k=1:6
    name = ['m2cm/s',num2str(k)];    
    id_e(k) = getsignalid(tg,name);
end

%% Read signals into scopes
%sc1.addsignal (id_distance);
sc1.DisplayMode = 'Numerical';
sc1.start;

sc2.set('Grid', 'on')
sc2.addsignal(id_currents)
sc2.YLimit = [0 5];
sc2.start;

sc3.addsignal(id_PWM);
sc3.DisplayMode = 'Numerical';
sc3.start;

sc4.addsignal(id_e);
sc4.DisplayMode = 'Numerical';
sc4.start;

Constant1 = 0;

%% Scope file
%sc_file.NumSamples=
id_all=[id_e; id_distance ; id_currents; id_PWM];

sc_file.addsignal(id_all);
sc_file.Decimation=10;       % down sampling 10x

%sc_file.DynamicFileMode
sc_file.start;
%sc_file.FileName='log.dat';
%fileName=sc_file.FileName

filesys = tg.fs;

%fid = filesys.fopen(fileName);


 %%
% tg = xpctarget.xpc('TCPIP','168.176.26.12','22222');
% 
% f=xpctarget.ftp()
% %f=xpctarget.ftp('TCPIP','1168.176.26.12','22222')
% f.dir
% 
% f.pwd
% f.get('LOGDIST.dat')
%% Spy
%xpctargetspy
%xpcwwwenable