function [ Output, time ] = Quintic_Inter(p1,v1,a1,t1,p2,v2,a2,t2,sT)
%QUINTIC_INTER Summary of this function goes here
%   Detailed explanation goes here

T=[1 t1 t1^2 t1^3 t1^4 t1^5;
       0 1 2*t1 3*t1^2 4*t1^3 5*t1^4;       
       0 0 2 6*t1 12*t1^2 20*t1^3;
       1 t2 t2^2 t2^3 t2^4 t2^5;
       0 1 2*t2 3*t2^2 4*t2^3 5*t2^4;       
       0 0 2 6*t2 12*t2^2 20*t2^3];
T=inv(T);
Tra=[p1,v1,a1,p2,v2,a2]';
As=T*Tra;
Nsamples=(t2-t1)/sT+1;
for i=1:Nsamples
    if i==1
        time(i)=0;
    else
        time(i)=time(i-1)+sT;
    end
    Output(i)=As(1)+As(2)*time(i)+As(3)*time(i)^2+As(4)*time(i)^3+As(5)*time(i)^4+As(6)*time(i)^5;
end


