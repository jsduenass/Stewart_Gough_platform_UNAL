clc, clear, close all

%%  Install costum libraries

% Install thirdparydrivers
activeFilename = matlab.desktop.editor.getActiveFilename;
activePath = fileparts(activeFilename) 
cd(activePath)
driverSource='..\ext\thirdpartydrivers';
driverDestination=strcat(matlabroot,'\toolbox\rtw\targets\xpc\target\build\xpcblocks\thirdpartydrivers')

copyfile(driverSource,driverDestination)
rehash toolbox

% Add to search path  simulink's custom Stewart Gough library
savepath('..\ext\Stewart_Gough_library')
savepath('..\ext\Stewart_Gough_library\Trajectories')
savepath('..\ext\Stewart_Gough_library\Functions')

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
env.TcpIpTargetAddress = '168.176.26.12';
env.TcpIpSubNetMask = '255.255.254.0';

tgs.DefaultTarget                       % check properties of the default target

%%   stablish  connection  with xpc target
% If deault is not configured 
tg = xpctarget.xpc('TCPIP','1168.176.26.12','22222')  %defined the properties in the xpc target 

%%
% If deault is configured  
tg = xpctarget.xpc;
 
tg.targetping           % check conectivity
tg.Application          % check application status

% check other properties 
tg.StateLog
tg.Status
tg.StopTime
%% Compile  mex files
mex '../ext/thirdpartydrivers/addiamondmm16atcustom.c'
mex '../ext/thirdpartydrivers/dadiamondmm16at_custom.c'
mex '../ext/thirdpartydrivers/dodiamond16at_custom.c'


% dbstop if error
% dbquit
 