function [iniCon] = exportFile2XPc(FileName)
%EXPORTFILE2XPC Summary of this function goes here
%   Detailed explanation goes here

ReadMatrix = csvread(FileName);
tgPC104 = xpctarget.xpc;

tr = zeros(length(ReadMatrix),2,6);
trP = zeros(length(ReadMatrix),2,6);
trPP = zeros(length(ReadMatrix),2,6);

for i=1:6
    tr(:,1,i) = ReadMatrix(:,end);
    tr(:,2,i) = ReadMatrix(:,i*3-2);
    trP(:,1,i) = ReadMatrix(:,end);
    trP(:,2,i) = ReadMatrix(:,i*3-1);
    trPP(:,1,i) = ReadMatrix(:,end);
    trPP(:,2,i) = ReadMatrix(:,i*3);
end
iniCon(:,1) = tr(1,2,:);
fileXPC='Trajec2.dat';
A1(:,:) = tr(:,2,:);                                    %Setting data to a specific format
A1P(:,:) = trP(:,2,:);                                  %Setting data to a specific format
A1PP(:,:) = trPP(:,2,:);                                %Setting data to a specific format
xpcbytes2file(fileXPC, A1',A1P',A1PP')                  %Creating the file for xPC format
PC104=xpctarget.ftp('TCPIP','192.168.1.12','22222');    %Creating ftp object

if (strcmp(tgPC104.Application,'loader'))    
    msgbox('Transfering file ... please wait','Export Status','help');
    PC104.cd('C:\XPCFILES\')    
    PC104.put(fileXPC)                                      %Put file into target PC.
    PC104.cd('C:\')
    msgbox(['Successful transfer of ',FileName],'Export Status','help','replace');
elseif (strcmp(tgPC104.Status,'stopped'))
    msgbox('Transfering file ... please wait','Export Status','help');
    PC104.cd('C:\XPCFILES\')    
    PC104.put(fileXPC)                                      %Put file into target PC.
    PC104.cd('C:\')
    msgbox(['Successful transfer of ',FileName],'Export Status','help','replace');
elseif (strcmp(tgPC104.Status,'running'))
    msgbox('Transfering file ... please wait','Export Status','help');
    tgPC104.stop;
    PC104.cd('C:\XPCFILES\')    
    PC104.put(fileXPC)                                       %Put file into target PC.
    PC104.cd('C:\')
    tgPC104.start;
    msgbox(['Successful transfer of ',FileName],'Export Status','help','replace');
else
    msgbox(['Impossible to transfer \n',FileName],'Export Status','error');
end



