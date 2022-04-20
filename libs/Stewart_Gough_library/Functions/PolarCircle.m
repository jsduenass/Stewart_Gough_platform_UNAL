function [ x, y , time ] = PolarCircle(a,xc,yc,theta1,theta2,time,samTime)
%a=1;
theta1=theta1+pi;
theta2=theta2+pi;
%phi=atan2(yc,xc);
phi=0;
r0=0;
[theta, time ] = Quintic_Inter(theta1,0,0,0,theta2,0,0,time,samTime);
for i=1:length(theta)
    r(i)=r0*cos(theta(i)-phi)-sqrt(a^2-r0^2*sin(theta(i)-phi)^2);
    %r(i)=sqrt(2*a*r0*cos(theta(i)-phi)-r0^2+a^2);
    x(i)=cos(theta(i))*r(i)+xc;
    y(i)=sin(theta(i))*r(i)+yc;
end




% polar(theta,r)
% figure, hold on, grid on
% plot(x,y)
% axis equal
% figure, hold on, grid on
% plot(time,x)
% plot(time,y,'g')
% plot(time,theta,'r')
% legend('x','y','theta')