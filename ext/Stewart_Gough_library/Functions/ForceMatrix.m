function [ Jf ] = ForceMatrix( SG,P,aRb )
%FORCEMATRIX Summary of this function goes here
%   Detailed explanation goes here

[di,Si]=InverseKinematics(SG,P,aRb );

bi=SG.bi;

Jf=zeros(6,6);
for i=1:6
    Jf(:,i)=[Si(:,i); ...
            cross(aRb*bi(:,i),Si(:,i))];
end


end






