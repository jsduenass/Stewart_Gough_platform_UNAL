%% plot
close all


logDir='./dumpOutput/'
logData = ls(logDir);
logData = logData(3:end,:)
n=0;
load([logDir,logData(end-n,:)]);


subplot(2,2,1)
plot(t,10*dist_input)
xlabel('t [seg]')
ylabel('actuator distance [cm]')
xlim([0,t(end)])    
line([0,0],[0,0.32])
line([0,t(end)],[0,0])
grid on

subplot(2,2,2)
plot( t,control)
xlabel('t [s]')
ylabel('PWM [%]')
line([0,0],[-100,100])
ylim([-100,100])
legend({'M1','M2','M3','M4','M5','M6'});
grid on


subplot(2,2,3)
plot(t,v_input)
xlabel('t [seg]')
ylabel('velocity [cm/s]')
line([0,0],[-1,1])
line([0,t(end)],[0,0])
xlim([0,t(end)])    
ylim([-1,1])
grid on

subplot(2,2,4)
plot(t,e)
xlabel('t [s]')
ylabel('e [cm]')
grid on

legend({'M1','M2','M3','M4','M5','M6'});


figure(2)

subplot(2,1,1)
plot( e,control)
xlabel('e [cm]')
ylabel('PWM [%]')
line([0,0],[-100,100])
line([-30,30],[0,0])
ylim([-100,100])
xlim([-30,30])
grid on

subplot(2,1,2)
plot(control,v_input)
xlabel('PWM [%]')
ylabel('velocity [cm/s]')
line([0,0],[-1,1])
line([-100,100],[0,0])
xlim([-100,100])    
ylim([-1,1])
grid on

legend({'M1','M2','M3','M4','M5','M6'});

mean(abs(control))
%% animate 


command= input('animate [1]')
if command==1
    close all
    for k=1:length(t)
        subplot(2,1,1)
        plot(e(1:k,:),control(1:k,:))
        xlabel('e [cm]')
        ylabel('PWM [%]')
        line([0,0],[-100,100])
        line([-30,30],[0,0])
        ylim([-100,100])
        xlim([-30,30])

        legend({'M1','M2','M3','M4','M5','M6'});

        subplot(2,1,2)
        plot(control(1:k,:),v_input(1:k,:))
        xlabel('PWM [%]')
        ylabel('velocity [cm/s]')
        line([-100,100],[0,0])
        line([0,0],[-1,1])    
        xlim([-100,100])
        ylim([-1,1])
        legend({'M1','M2','M3','M4','M5','M6'});


        pause(0.01)

    end
    
end
