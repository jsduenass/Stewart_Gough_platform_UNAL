function [ Output,time ] = resample_edV2( inVec, timeIni,Factor)
%RESAMPLE_ED Summary of this function goes here
%   Detailed explanation goes here
si=length(inVec);

for i=1:round(si/Factor)
    Output(i,1)=inVec(i*Factor-Factor+1); 
    time(i)=timeIni(i*Factor-Factor+1);
end

time = time-time(1)+timeIni(1);