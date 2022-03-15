function move( X,Y,Z,Roll,Pitch,Yaw)
%MOVESG Summary of this function goes here
%   Detailed explanation goes here

%0      0                  DOUBLE    Scalar  Value                         ControlConstant
%222    68.317             DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi1Free
%223    68.3214            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi2Free
%224    68.3123            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi3Free
%225    68.3123            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi4Free
%226    68.3214            DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi5Free
%227    68.317             DOUBLE    Scalar  Value                         If Action Subsystem5/Set1/FeedForwardController/Posi6Free

ActuatorsIndx = [222; 223; 224; 225; 226; 227];
Constant1 = 0;

i=1;
phi(i)=Yaw*pi/180;
theta(i)=Pitch*pi/180;
psii(i)=Roll*pi/180;
aRb(:,:,i)=[cos(phi(i))*cos(theta(i)) cos(phi(i))*sin(theta(i))*sin(psii(i))-sin(phi(i))*cos(psii(i)) cos(phi(i))*sin(theta(i))*cos(psii(i))+sin(phi(i))*sin(psii(i));...
                    sin(phi(i))*cos(theta(i)) sin(phi(i))*sin(theta(i))*sin(psii(i))+cos(phi(i))*cos(psii(i)) sin(phi(i))*sin(theta(i))*cos(psii(i))-cos(phi(i))*sin(psii(i));...
                    -sin(theta(i)) cos(theta(i))*sin(psii(i)) cos(theta(i))*cos(psii(i));];   %Rotation of reference frame B (Moving platform)
P=[X;Y;Z]/1000;
SG.ai=[0.0260    0.1410    0.1149   -0.1149   -0.1410   -0.0260;...
       0.1477   -0.0513   -0.0964   -0.0964   -0.0513    0.1477;...
       0.0380    0.0380    0.0380    0.0380    0.0380    0.0380];
   
SG.bi=[0.0636    0.0869    0.0233   -0.0233   -0.0869   -0.0636;...
       0.0636    0.0233   -0.0869   -0.0869    0.0233    0.0636;...
       -0.0520   -0.0520   -0.0520   -0.0520   -0.0520   -0.0520];
[d,S] = InverseKinematics(SG,P,aRb(:,:,i));
%ActLength=424+110;                              %Sum of the actuator case plus distance from joints
ActLength=548.6;
d=d*1000-ActLength;
%---------------------------------PERFORM MOTION
tgPC104 = xpctarget.xpc;

tgPC104.targetping


for j=1:6
    tgPC104.setparam(ActuatorsIndx(j),d(j));      %set_param('GUI_User_V1_3/If Action Subsystem5/Set1','ActLen',['[',num2str(d'),']']);
end

tgPC104.setparam(Constant1,1);              %set_param('GUI_User_V1_3/Constant1','Value','1');      


end

