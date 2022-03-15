function [ Jx,Jq,Jxq ] = Jacobian( SG,P,aRb ) %#codegen
%JACOBIAN Summary of this function goes here
%   Detailed explanation goes here
[~,Si]=InverseKinematics(SG,P,aRb );

bi=SG.bi;
Jx = zeros(6,6);
for i=1:6
    Jx(i,:)=[Si(:,i)' (cross(aRb*bi(:,i),Si(:,i)))'];
end

Jq=eye(6,6);
Jxq=Jx\Jq;

%Jxq=inv(Jx)*Jq;

end

