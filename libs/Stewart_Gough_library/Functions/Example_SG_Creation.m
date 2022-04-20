%% PARAMETERS SG
clc, clear all, close all
%-----------------------------------------Base ring
tmpAngl=[10;110;130;230;250;350]*pi/180;    %Angular distribution joint Ai
tmpRadBase=0.150;                           %Radious of base (m)
tmpAz=0.038;                                %Initial offset of joints (z direction)
%-----------------------------------------Moving ring
tmpAngl2=[45;75;165;195;285;315]*pi/180;    %Angular distribution joint Bi
%tmpAngl=[105;135;225;255;345;15]*pi/180;
tmpRadBase2=0.090;                          %Radious of moving ring (m)
tmpBz=-0.0520;                              %Offset joints Bi along z axe.
%-----------------------------------------Distance to center of mass
SG.e1=(155)*1e-3;                   %Distance from A to center of mass cylinder along S axis
SG.e2=(181)*1e-3;                   %Distance from B to center of mass piston along S axis

%-----------------------------------------Mass
SG.m1=1.313;                %Kg
SG.m2=0.233;                %Kg
SG.mMo=2.146;               %Kg
%-----------------------------------------Inertia tensors
SG.ciI1=[0.05 0 0; 0 0.05 0; 0 0 0];         %Kg*m^2
SG.ciI2=[0.02 0 0; 0 0.02 0; 0 0 0];         %Kg*m^2
SG.bIMo=[0.009 0 0; 0 0.009 0; 0 0 0.018];  %Kg*m^2

tmpaA(3,6)=0;                             %Matrix initialization
for i=1:6
    tmpaA(:,i)=[sin(tmpAngl(i))*tmpRadBase;cos(tmpAngl(i))*tmpRadBase; tmpAz];
end
tmpbB(3,6)=0;                               %Matrix initialization
for i=1:6
    tmpbB(:,i)=[sin(tmpAngl2(i))*tmpRadBase2;cos(tmpAngl2(i))*tmpRadBase2; tmpBz]; %Distance from frame B to joint bi. From reference frame B       
end

SG.bB=tmpbB;                                 %Vector bi defined in frame B
SG.aA=tmpaA;                                 %Vector ai defined in frame A
clear tmp* i;
%% Trajectory
% LINE

tmpTrajectory1.IniPos=[0;0;0.8];                 %Initial position (m)
tmpTrajectory1.IniAngle=[0;0;0]*pi/180;          %Initial R-P-Y angles (rad)
tmpTrajectory1.FinalPos=[0;0;0.8];           %Final position (m)
tmpTrajectory1.FinalAngle=[0;0;0]*pi/180;        %Final R-P-Y angles (rad)
tmpTrajectory1.samTime=0.001;                    %Sample time
tmpTrajectory1.Time=5;                           %Motion time
tmpTrajectory1.interpolation='Quintic';          %Kind of interpolation between points

[tmpaPb,tmpaRb,tmpaVp,tmpaWb,tmpaVpP,tmpaWbP,tmpAngles,tmpTime] = TrajectoryGeneratorSG( tmpTrajectory1.IniPos,tmpTrajectory1.IniAngle,tmpTrajectory1.FinalPos,tmpTrajectory1.FinalAngle, tmpTrajectory1.Time,tmpTrajectory1.samTime,tmpTrajectory1.interpolation);

Efector.aPb=tmpaPb;
Efector.aRb=tmpaRb;
Efector.aVp=tmpaVp;
Efector.aWb=tmpaWb;
Efector.aVpP=tmpaVpP;
Efector.aWbP=tmpaWbP;
Efector.Angles=tmpAngles;
Efector.time=tmpTime;

clear  tmp*
%% Dynamic model
tic
[Forces]=DynamicModel_SG_Inverse(Efector, SG);
toc
