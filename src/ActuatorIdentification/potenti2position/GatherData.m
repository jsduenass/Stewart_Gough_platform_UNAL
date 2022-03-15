%% Code to read data from XPC target and measured position for later interpretation
clc, close all
%--------------Run this code once for each motor after simulation
actuator='Actuator_2';      %Actuator name for furhter reference
Output=tg.Outputlog;        %Measured voltage value
time=tg.TimeLog;            %Time log
%%
for i=1:2
    figure
    hold on
    grid on
    plot(time,Output(:,i),'r');
    plot(time,Output(:,i+6),'b');
    title(['Actuator ',num2str(i)]);
    legend('Measured','Filtered');
end
%%
PosMo1=[31.6; 73.9;97.6;124.6];     %Measured position in milimeters of the actuator's rod
Vol1=[4.617;3.998;3.647;3.249];     %Measured voltage from ADC in Volts
fit1=[-67.69;343.12];                % Data of equation sople(m) first and then y intercept

PosMo2=[29.1;61.9;89;123.4];        %Measured position in milimeters of the actuator's rod
Vol2=[4.667;4.183;3.779;3.268];     %Measured voltage from ADC in Volts
PosMo3=[34.6;57;83.2;127.5];        %Measured position in milimeters of the actuator's rod
Vol3=[4.552;4.225;3.837;3.183];     %Measured voltage from ADC in Volts
PosMo4=[26.9;48;73.4;120.5];        %Measured position in milimeters of the actuator's rod
Vol4=[4.669;4.338;3.963;3.269];     %Measured voltage from ADC in Volts
PosMo5=[27.4;46;71.6;96.1];         %Measured position in milimeters of the actuator's rod
Vol5=[4.682;4.412;4.032;3.684];     %Measured voltage from ADC in Volts
PosMo6=[25.7;48.3;79.6;122.5];      %Measured position in milimeters of the actuator's rod
Vol6=[4.693;4.35;3.894;3.26];       %Measured voltage from ADC in Volts

figure
hold on, grid on
plot(Vol6,PosMo6)
xlabel('Voltage (V)')
ylabel('Position (mm)')

%% New motors
PosMo584 = [38.9;77.3;121.3;142.7];
VolMo584 = [4.589;4.029;3.3775;3.0625];
figure
hold on, grid on
plot(VolMo584,PosMo584)
xlabel('Voltage (V)')
ylabel('Position (mm)')
% %Filter design
% n=2;
% Wn=20/500;          %Sampled to 1kHz and cutof frequency of 20Hz
% [A,B,C,D]=butter(n,Wn,'low')

%%
csvwrite('Actuator1_Grados.txt',[tr(:,1,1),tr(:,2,1)]);