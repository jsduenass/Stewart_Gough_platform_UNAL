function [d, S] = inverse_kinematics(P, R)
% INVERSEKINEMATICS Inverse kinematics of PRISMMATIC, a SG platform of 
% the Universidad Nacional de Colombia
%
% [d,S] = inverseKinematics(P, aRb) returns the length and direction of 
% each actuator so that the mobile base reaches a desired position P and 
% orientation aRb.
    a = [0.0260    0.1410    0.1149   -0.1149   -0.1410   -0.0260;...
         0.1477   -0.0513   -0.0964   -0.0964   -0.0513    0.1477;...
         0.0380    0.0380    0.0380    0.0380    0.0380    0.0380];
   
    b = [0.0636    0.0869    0.0233   -0.0233   -0.0869   -0.0636;...
         0.0636    0.0233   -0.0869   -0.0869    0.0233    0.0636;...
        -0.0620   -0.0620   -0.0620   -0.0620   -0.0620   -0.0620];

    d = zeros(6,1);
    S = zeros(3,6);
    
    Rz = [cos(R(3)) -sin(R(3)) 0;
          sin(R(3))  cos(R(3)) 0;
                  0          0 1];
    Ry = [cos(R(3)) 0 sin(R(3));
                  0 1         0;
         -sin(R(3)) 0 cos(R(3))];
    Rx = [1         0          0;
          0 cos(R(3)) -sin(R(3));
          0 sin(R(3))  cos(R(3))];
    aRb = Rz*Ry*Rx;

    for i=1:6
        AB = P+aRb*b(:,i)-a(:,i);
        d(i) = norm(AB);
        S(:,i) = AB/d(i);
    end
end