function [ aPb,aRb,aVp,aWb,aVpP,aWbP,Angles,time ] = Circle_Primitive (circle,iniY,tmpIniAngle,finalY,tmpFinalAngle,Time,samTime)
%CIRCLE_PRIMITIVE Summary of this function goes here
%   Detailed explanation goes here

[y,time] = Quintic_Inter(iniY,0,0,0,finalY,0,0,Time,samTime);
[x, z , time ] = PolarCircle(circle(1),circle(2),circle(3),circle(4),circle(5),Time,samTime);

%circle(1)=radious, circle(2)=ini X, circle(3)=ini y, circle(4)=ini circle angle, circle(5)=final circle angle;

% Interpolar angulos y generar matrices homogeneas de transformacion, luego
% generar la cinematica inversa para tener los actuadores y luego derivar
% para tener los requrimeintos del diseño.

[psii,time] =  Quintic_Inter(tmpIniAngle(1),0,0,0,tmpFinalAngle(1),0,0,Time,samTime);
[theta,time] = Quintic_Inter(tmpIniAngle(2),0,0,0,tmpFinalAngle(2),0,0,Time,samTime);
[phi,time] =   Quintic_Inter(tmpIniAngle(3),0,0,0,tmpFinalAngle(3),0,0,Time,samTime);

for i=1:size(time,2)
    if i==1
        aPb(:,i)=[x(i);y(i);z(i)];
        aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                            sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                            -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i))];   %Rotation of reference frame B (Moving platform)
        aVp(:,i)=[0;0;0];  %INITIAL CONDITIONS
        aWb(:,i)=[0;0;0];
        aVpP(:,i)=[0;0;0];
        aWbP(:,i)=[0;0;0];
        
        phiP(i)=0;
        thetaP(i)=0;
        psiP(i)=0;

        phiPP(i)=0;
        psiPP(i)=0;
        thetaPP(i)=0;
        
    else
        phiP(i)=(phi(i)-phi(i-1))/samTime;
        thetaP(i)=(theta(i)-theta(i-1))/samTime;
        psiP(i)=(psii(i)-psii(i-1))/samTime; 

        phiPP(i)=(phiP(i)-phiP(i-1))/samTime;
        thetaPP(i)=(thetaP(i)-thetaP(i-1))/samTime;
        psiPP(i)=(psiP(i)-psiP(i-1))/samTime; 

        aPb(:,i)=[x(i);y(i);z(i)];      
        aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                        sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                        -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i));];  %Rotation of reference frame B (Moving platform)
        aVp(:,i)=(aPb(:,i)-aPb(:,i-1))/samTime;
        aWb(:,i)=[psiP(i); thetaP(i); phiP(i)];
        aVpP(:,i)=(aVp(:,i)-aVp(:,i-1))/samTime;
        aWbP(:,i)=[psiPP(i); thetaPP(i); phiPP(i)];
    end
end
Angles=[psii', theta',phi'];
end

