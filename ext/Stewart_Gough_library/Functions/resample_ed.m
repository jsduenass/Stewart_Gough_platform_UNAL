function [ Output,time ] = resample_ed( inVec,Factor,Samtime)
%RESAMPLE_ED Summary of this function goes here
%   Detailed explanation goes here
si=size(inVec,1);
Samtime=Samtime*Factor;
for i=1:round(size(inVec,1)/Factor)
    Output(i,1)=inVec(i*Factor-Factor+1); 
    time(i,1)=i*Samtime-Samtime;
end

