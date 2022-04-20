function [ di,Si ] = InverseKinematics(SG,P,aRb) %#codegen
% The inverse kinematics provides the actuator's length, given the end
% efector's position.
ai=SG.ai;
bi=SG.bi;

di = zeros(6,1);
Si = zeros(3,6);

for i=1:6
    S=P+aRb*bi(:,i)-ai(:,i);
    di(i)=norm(S);
    Si(:,i)=S/di(i);
end

