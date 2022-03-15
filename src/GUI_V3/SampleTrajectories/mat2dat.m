clc, clear all, close all

load Cross
ActLength=548.6;  %Sum of the actuator case plus distance from joints

%--------------Reference trajectory
for i=1:6
    tr(:,:,i)=[Profile.Time' Profile.d(i,:)'*1000-ActLength];
    trP(:,:,i)=[Profile.Time' Profile.dP(i,:)'*1000];
    trPP(:,:,i)=[Profile.Time' Profile.dPP(i,:)'*1000];  
end

for i=1:6
    Actua(:,i*3-2) = tr(:,2,i);
    Actua(:,i*3-1) = trP(:,2,i);
    Actua(:,i*3) = trPP(:,2,i);
end
Actua(:,19) =  tr(:,1,1);
dlmwrite('Cross.dat', Actua, 'delimiter', ',', 'precision', 9);
%csvwrite('Triangle22s.dat',Actua)
%% 
ReadMatrix = csvread('Triangle22s.dat');
for i=1:6
    tr2(:,1,i) = ReadMatrix(:,end);
    tr2(:,2,i) = ReadMatrix(:,i*3-2);
    trP2(:,1,i) = ReadMatrix(:,end);
    trP2(:,2,i) = ReadMatrix(:,i*3-1);
    trPP2(:,1,i) = ReadMatrix(:,end);
    trPP2(:,2,i) = ReadMatrix(:,i*3);
end
diferen = tr-tr2;