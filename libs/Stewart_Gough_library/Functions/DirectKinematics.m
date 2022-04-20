function [ C_aRb, C_P, C_Angles ] = DirectKinematics( SG, P, aRb, Angles,di_ta ) %#codegen
%DIRECTKINEMATICS Summary of this function goes here
%   Detailed explanation goes here
[di,~]=InverseKinematics(SG,P,aRb); 
%[di,Si]=InverseKinematics(SG,[0;0;0.4],[1,0,0;0,1,0;0,0,1]);
Angles=Angles';
di_act=di;
errorA=di_ta-di_act;
Accuracy=1e-009;

phi=Angles(3);
theta=Angles(2);
psii=Angles(1);

while (norm(errorA)>Accuracy)
    [~,~,Jxq] = Jacobian(SG,P,aRb);
    errorA=(di_ta-di_act);
    if (norm(errorA)<Accuracy)
        break;
    end   
    DX=Jxq*errorA;
    P=P+DX(1:3);
    Angles=Angles+DX(4:6);        % Atention to angle addition
    %Nomenclature for operation
    phi=Angles(3);
    theta=Angles(2);
    psii=Angles(1);
    %Rotation matrix based on Roll-Pitch-Yaw angles, review eq 1.48 TSAI
    aRb(:,:)=[cos(phi)*cos(theta) cos(phi)*sin(theta)*sin(psii)-sin(phi)*cos(psii) cos(phi)*sin(theta)*cos(psii)+sin(phi)*sin(psii);...
              sin(phi)*cos(theta) sin(phi)*sin(theta)*sin(psii)+cos(phi)*cos(psii) sin(phi)*sin(theta)*cos(psii)-cos(phi)*sin(psii);...
              -sin(theta) cos(theta)*sin(psii) cos(theta)*cos(psii);];
    [di,~] = InverseKinematics(SG,P,aRb);
    di_act=di;   
end

C_aRb=aRb;
C_P=P;
C_Angles=[psii,theta,phi];
end

