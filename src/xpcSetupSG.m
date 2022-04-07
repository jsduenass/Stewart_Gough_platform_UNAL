%% Set up
% If deault is configured  
tg = xpctarget.xpc('TCPIP','168.176.26.12','22222');
modelName = 'motionControlModel';
%        set_param(hSrcPort,'ShowPropagatedSignals','on');

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


%%  signal id
% Input
id_distance= tg.getsignalidsfromlabel('dist_input');

id_vel= tg.getsignalidsfromlabel('vel_input');

id_acel= tg.getsignalidsfromlabel('acel_input');
id_currents = tg.getsignalidsfromlabel('current_input');

for k=1:12
    name = ['MM-16-AT Analog Input/p',num2str(k)];
    id_input(k)=getsignalid(tg,name);
end
  
id_currents = id_input(2:2:12);

% PWM signal id 
id_PWM = tg.getsignalidsfromlabel('control_sig');

% e signal id 
id_e = tg.getsignalidsfromlabel('e');

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
id_all=[ id_PWM id_e id_distance  id_currents id_vel id_acel];
    

sc_file.addsignal(id_all);
sc_file.NumSamples=10000;
sc_file.Decimation=10;       % down sampling 10x
sc_file.FileName='log.dat';

sc_file.start;

%sc_file.DynamicFileMode

filesys = tg.fs;
filesys.dir

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