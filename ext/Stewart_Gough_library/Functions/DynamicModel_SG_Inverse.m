function [ForceActuators]=DynamicModel_SG_Inverse(Trajectory, SG)

nSamples=length(Trajectory.time);
aPb=Trajectory.aPb;
aRb=Trajectory.aRb;
aVp=Trajectory.aVp;
aWb=Trajectory.aWb;
aVpP=Trajectory.aVpP;
aWbP=Trajectory.aWbP;
% Angles=Trajectory.Angles;

aA=SG.aA;
bB=SG.bB;
e1=SG.e1;           %Distance from A to center of mass cylinder along S axis
e2=SG.e2;           %Distance from B to center of mass piston along S axis
%% Kinematic analysis
%---------------------------------Initialization of vectors for speed
d(6,nSamples)=0;
aSi(3,6,nSamples)=0;
aRci(3,3,6,nSamples)=0;
bRci(3,3,6,nSamples)=0;
bWb(3,6,nSamples)=0;
bWbP(3,6,nSamples)=0;
theta(6,nSamples)=0;
phi(6,nSamples)=0;
r1(3,6,nSamples)=0;
r2(3,6,nSamples)=0;
aB(3,6,nSamples)=0;

aVb(3,6,nSamples)=0;
ciVb(3,6,nSamples)=0; 
ciWi(3,6,nSamples)=0;
ciV1(3,6,nSamples)=0;
ciV2(3,6,nSamples)=0;

aVbP(3,6,nSamples)=0;
ciVbP(3,6,nSamples)=0; 
ciWiP(3,6,nSamples)=0;
ciV1P(3,6,nSamples)=0;
ciV2P(3,6,nSamples)=0;

for j=1:nSamples            %j time instant index             
    for i=1:6               %i limb index
        %---------------------------------------POSITION ANALYSIS
        aB(:,i,j)=aRb(:,:,j)*bB(:,i);                      %Vector B defined in reference frame A
        d(i,j)=norm(aPb(:,j)+aB(:,i,j)-aA(:,i),2);         %Lenght limbn i at moment j
        aSi(:,i,j)=(aPb(:,j)+aB(:,i,j)-aA(:,i))/d(i,j);    %Direction of limb i at moment j
        W=aSi(:,i,j);
        V=cross([0;0;1],W);
        V=V/norm(V);
        U=cross(V,W);
        aRci(:,:,i,j)=[U V W];
        theta(i,j)=acos(aSi(3,i,j));                                %(Rad)
        phi(i,j)=asin(aSi(2,i,j)/sqrt(aSi(1,i,j)^2+aSi(2,i,j)^2));  %(Rad)
        bRci(:,:,i,j)=aRb(:,:,j)'*aRci(:,:,i,j);        
        %RotationMatrix actuator i at moment j
        r1(:,i,j)=aA(:,i)+e1*aSi(:,i,j);                            %Position vector to center of mass cilinder (i at moment j) 
        r2(:,i,j)=aA(:,i)+(d(i,j)-e2)*aSi(:,i,j);                   %Position vector to center of mass rod (i at moment j)
        %---------------------------------------VELOCITY ANALYSIS
        aVb(:,i,j)=aVp(:,j)+cross(aWb(:,j),aB(:,i,j));              %Velocity of joint B described in reference frame A
        ciVb(:,i,j)=aRci(:,:,i,j)'*aVb(:,i,j);                      %Velocity of joint B described in reference frame C of limb i
        ciWi(:,i,j)=1/d(i,j)*[-ciVb(2,i,j); ciVb(1,i,j);0];         %Angular velocity of limb i described in reference frame C of limb i
        ciV1(:,i,j)=e1/d(i,j)*[ciVb(1,i,j); ciVb(2,i,j);0];         %Linear velocity of center of mass e1 decribed in reference frame C of limb i
        ciV2(:,i,j)=1/d(i,j)*[(d(i,j)-e2)*ciVb(1,i,j); (d(i,j)-e2)*ciVb(2,i,j); d(i,j)*ciVb(3,i,j)];    %Linear velocity of center of mass e2 decribed in reference frame C of limb i        
        %---------------------------------------ACCELERATION ANALYSIS
        aVbP(:,i,j)=aVpP(:,j)+cross(aWbP(:,j),aB(:,i,j))+cross(aWb(:,j),cross(aWb(:,j),aB(:,i,j)));
        ciVbP(:,i,j)=aRci(:,:,i,j)'*aVbP(:,i,j);
        ciWiP(:,i,j)=1/d(i,j)*[-ciVbP(2,i,j)+(2*ciVb(3,i,j)*ciVb(2,i,j))/d(i,j);...
                                ciVbP(1,i,j)-(2*ciVb(3,i,j)*ciVb(1,i,j))/d(i,j);...
                                0];
        ciV1P(:,i,j)=e1/d(i,j)*[ciVbP(1,i,j)-(2*ciVb(3,i,j)*ciVb(1,i,j))/d(i,j);...
                                ciVbP(2,i,j)-(2*ciVb(3,i,j)*ciVb(2,i,j))/d(i,j);...
                                -(ciVb(1,i,j)^2+ciVb(2,i,j)^2)/d(i,j)];
        ciV2P(:,i,j)=1/d(i,j)*[(d(i,j)-e2)*ciVbP(1,i,j)+(2*e2*ciVb(3,i,j)*ciVb(1,i,j))/d(i,j);...
                               (d(i,j)-e2)*ciVbP(2,i,j)+(2*e2*ciVb(3,i,j)*ciVb(2,i,j))/d(i,j);...
                                d(i,j)*ciVbP(3,i,j)+(e2*(ciVb(1,i,j)^2+ciVb(2,i,j)^2)/d(i,j))];   
    end
    bWb(:,j)=aRb(:,:,j)'*aWb(:,j);
    bWbP(:,j)=aRb(:,:,j)'*aWbP(:,j);
end
%% Dynamic analysis
m1=SG.m1;                                   %Kg
m2=SG.m2;                                   %Kg
mp=SG.mMo;                                   %Kg, Mass moving ring

%-----------------------------------------Inertia tensors
ciI1=SG.ciI1;                               %Kg*m^2
ciI2=SG.ciI2;                               %Kg*m^2
bIm=SG.bIMo;                                %Kg*m^2 Inertia tensor, moving ring


gc=9.8;                                     %m/s^2

ciFbx=zeros(6,nSamples);
ciFby=zeros(6,nSamples);
ciFbz=zeros(6,nSamples);
B=zeros(6,nSamples);
A=zeros(6,6,nSamples);
tau=zeros(6,nSamples);

for j=1:nSamples            %j time instant index  
    sum=zeros(6,1);
    for i=1:6               %i limb index
        %---------------------------------Force analisis
        ciFbx(i,j)=1/d(i,j)*(m1*e1*gc*sin(theta(i,j))+...
                             m2*(d(i,j)-e2)*gc*sin(theta(i,j))-...
                             m1*e1*ciV1P(1,i,j)-...
                             m2*(d(i,j)-e2)*ciV2P(1,i,j)-...
                             ciI1(2,2)*ciWiP(2,i,j)-...
                             ciI2(2,2)*ciWiP(2,i,j));
        ciFby(i,j)=1/d(i,j)*(-m1*e1*ciV1P(2,i,j)-...
                             m2*(d(i,j)-e2)*ciV2P(2,i,j)+...
                             ciI1(1,1)*ciWiP(1,i,j)+...
                             ciI2(1,1)*ciWiP(1,i,j));
        sum(1,1)=sum(1,1)+ciFbx(i,j)*cos(phi(i,j))*cos(theta(i,j))-ciFby(i,j)*sin(phi(i,j));
        sum(2,1)=sum(2,1)+ciFbx(i,j)*sin(phi(i,j))*cos(theta(i,j))+ciFby(i,j)*cos(phi(i,j));
        sum(3,1)=sum(3,1)-ciFbx(i,j)*sin(theta(i,j));
        sum(4,1)=sum(4,1)+bB(2,i)*(bRci(3,1,i,j)*ciFbx(i,j)+bRci(3,2,i,j)*ciFby(i,j));        
        sum(5,1)=sum(5,1)-bB(1,i)*(bRci(3,1,i,j)*ciFbx(i,j)+bRci(3,2,i,j)*ciFby(i,j));                                                              %Check
        sum(6,1)=sum(6,1)+bB(1,i)*(bRci(2,1,i,j)*ciFbx(i,j)+bRci(2,2,i,j)*ciFby(i,j))-bB(2,i)*(bRci(1,1,i,j)*ciFbx(i,j)+bRci(1,2,i,j)*ciFby(i,j));  %check
    end
    B(:,j)=[-sum(1,1)+mp*aVpP(1,j);...
            -sum(2,1)+mp*aVpP(2,j);...
            -sum(3,1)+mp*aVpP(3,j)+mp*gc;...
            -sum(4,1)+bIm(1,1)*bWbP(1,j)-bWb(2,j)*bWb(3,j)*(bIm(2,2)-bIm(3,3));...
            -sum(5,1)+bIm(2,2)*bWbP(2,j)-bWb(3,j)*bWb(1,j)*(bIm(3,3)-bIm(1,1));...
            -sum(6,1)+bIm(3,3)*bWbP(3,j)];
    A(:,:,j)= [cos(phi(1,j))*sin(theta(1,j)) cos(phi(2,j))*sin(theta(2,j)) cos(phi(3,j))*sin(theta(3,j)) cos(phi(4,j))*sin(theta(4,j)) cos(phi(5,j))*sin(theta(5,j)) cos(phi(6,j))*sin(theta(6,j));...
               sin(phi(1,j))*sin(theta(1,j)) sin(phi(2,j))*sin(theta(2,j)) sin(phi(3,j))*sin(theta(3,j)) sin(phi(4,j))*sin(theta(4,j)) sin(phi(5,j))*sin(theta(5,j)) sin(phi(6,j))*sin(theta(6,j));...
               cos(theta(1,j)) cos(theta(2,j)) cos(theta(3,j)) cos(theta(4,j)) cos(theta(5,j)) cos(theta(6,j));...
               bB(2,1)*bRci(3,3,1,j) bB(2,2)*bRci(3,3,2,j) bB(2,3)*bRci(3,3,3,j) bB(2,4)*bRci(3,3,4,j) bB(2,5)*bRci(3,3,5,j) bB(2,6)*bRci(3,3,6,j);...
               -bB(1,1)*bRci(3,3,1,j) -bB(1,2)*bRci(3,3,2,j) -bB(1,3)*bRci(3,3,3,j) -bB(1,4)*bRci(3,3,4,j) -bB(1,5)*bRci(3,3,5,j) -bB(1,6)*bRci(3,3,6,j);...
               bB(1,1)*bRci(2,3,1,j)-bB(2,1)*bRci(1,3,1,j) bB(1,2)*bRci(2,3,2,j)-bB(2,2)*bRci(1,3,2,j) bB(1,3)*bRci(2,3,3,j)-bB(2,3)*bRci(1,3,3,j) bB(1,4)*bRci(2,3,4,j)-bB(2,4)*bRci(1,3,4,j) bB(1,5)*bRci(2,3,5,j)-bB(2,5)*bRci(1,3,5,j) bB(1,6)*bRci(2,3,6,j)-bB(2,6)*bRci(1,3,6,j);...
               ];
    %ciFbz(:,j)=A(:,:,j)\B(:,j);        
    ciFbz(:,j)=pinv(A(:,:,j))*B(:,j);
    for i=1:6
        tau(i,j)=ciFbz(i,j)+m2*gc*cos(theta(i,j))+m2*ciV2P(3,i,j);
    end
end

%%
ForceActuators=tau;