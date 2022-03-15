%% Motor identification Routine
clc, clear all, close all
%% ----------------------------------LOAD INPUT SIGNAL AND RUN SIMULATION
load u_motor            % Load input signal
cd XPC_Code
open_system('IdentificationMotor2Order');                               % Open .mdl
rtwbuild('IdentificationMotor2Order');                                  % Build .mdl into target PC, remember to set up your host IP address
set_param('IdentificationMotor2Order','SimulationMode','external');     % Set simulation mode
set_param('IdentificationMotor2Order','SimulationCommand','connect');   % Connect to target PC
set_param('IdentificationMotor2Order','SimulationCommand','start');     % Start Simulation
pause(signal(end,1))                                                    % Wait for identification
set_param('IdentificationMotor2Order','SimulationCommand','stop');     % Start Simulation
cd ..
%% --------------------------------READ EXPERIMENTAL DATA AND SETUP IDENTIFICATION
% Initial Parameter Estimation
tau = 11;
Kdc2 = 35.3;

u=tg.OutputLog(:,7)*14.14/100;      % Control input (Volts) pwm2volt
y=tg.OutputLog(:,2);                % Position Output (mm), configure to desirable motor
tSimu=tg.TimeLog;

[u1,t]=resample_edV2( u(1000:end), tSimu(1000:end), 50 ); % custom made function resample
[y1,t]=resample_edV2( y(1000:end), tSimu(1000:end), 50 );

figure, hold on, grid on
plot(t,y1)
plot(tSimu(1000:end),y(1000:end),'r')
legend('Resampled','Normal')
clear signal tSimu u y

%% --------------------------------System identification

z = iddata(y1, u1, t(2)-t(1), 'Name', 'DC-motor');
%z=idresamp(z1,2);
set(z, 'InputName', 'Voltage', 'InputUnit', 'V');
set(z, 'OutputName', 'Rod큦 position');
set(z, 'OutputUnit', 'mm');
set(z, 'Tstart', 0, 'TimeUnit', 's');
                                        % Plots
figure('Name', [z.Name ': Voltage input -> Linear position output']);
plot(z(:, 1, 1));   % Plot first input-output pair (Voltage -> Angular position).
clear u y

FileName      = 'order2Param2';       % File describing the model structure.
Order         = [1 1 2];            % Model orders [ny nu nx].
Parameters    = [tau; Kdc2];
InitialStates = [y1(1);0];            % Initial states.
Ts            = 0;                 % Time-continuous system.
nlgr = idnlgrey(FileName, Order, Parameters, InitialStates, Ts,'Name', 'DC-motor'); 
clear FileName InitialStates Order Ts

set(nlgr, 'InputName', 'Voltage', 'InputUnit', 'V',...
          'OutputName', 'Rod큦 position', ...
          'OutputUnit', 'mm',...
          'TimeUnit', 's');
size(nlgr)            
%   Initial conditions
setinit(nlgr, 'Name', {'Rod큦 position' 'Rod큦 velocity'});
setinit(nlgr, 'Unit', {'mm' 'mm/s'});

%-------------------------------------Estimation
setinit(nlgr, 'Fixed', {true false})
nlgr.Algorithm.SimulationOptions.AbsTol = 1e-6;
nlgr.Algorithm.SimulationOptions.RelTol = 1e-5;
figure;
title('Fit before estimation')
compare(z, nlgr);
% A. Model computed with first-order Euler forward ODE solver.
nlgref = nlgr;
nlgref.Algorithm.SimulationOptions.Solver = 'ode1';        % Euler forward.
nlgref.Algorithm.SimulationOptions.FixedStep = z.Ts*0.01;   % Step size.

% B. Model computed with adaptive Runge-Kutta 23 ODE solver.
nlgrrk23 = nlgr;
nlgrrk23.Algorithm.SimulationOptions.Solver = 'ode23';     % Runge-Kutta 23.

% C. Model computed with adaptive Runge-Kutta 45 ODE solver.
nlgrrk45 = nlgr;
nlgrrk45.Algorithm.SimulationOptions.Solver = 'ode45';     % Runge-Kutta 45.

setpar(nlgref, 'Fixed', {false false});
setpar(nlgrrk23, 'Fixed', {false false});
setpar(nlgrrk45, 'Fixed', {false false});

tef = clock;
nlgref = pem(z, nlgref, 'Display', 'Full');   % Perform parameter estimation.
tef = etime(clock, tef);

trk23 = clock;
nlgrrk23 = pem(z, nlgrrk23, 'Display', 'Full');   % Perform parameter estimation.
trk23 = etime(clock, trk23);

trk45 = clock;
nlgrrk45 = pem(z, nlgrrk45, 'Display', 'Full');   % Perform parameter estimation.
trk45 = etime(clock, trk45);

%---------------------------------------Compare
clc
disp('           Estimation time   Estimated tau value   Estimated Kdc2 value ');
fprintf('   ode1 :  %3.1f               %3.1f              %1.3f\n', tef, nlgref.Parameters(1).Value,nlgref.Parameters(2).Value);
fprintf('   ode23:  %3.1f               %3.1f              %1.3f\n', trk23, nlgrrk23.Parameters(1).Value,nlgrrk23.Parameters(2).Value);
fprintf('   ode45:  %3.1f               %3.1f              %1.3f\n', trk45, nlgrrk45.Parameters(1).Value,nlgrrk45.Parameters(2).Value);
fprintf('   Initial:%3.1f               %3.1f              %1.3f\n', 0,Parameters(1),Parameters(2));

figure
compare(z, nlgref, nlgrrk23, nlgrrk45);
