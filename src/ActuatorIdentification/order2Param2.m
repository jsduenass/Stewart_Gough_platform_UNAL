function [dx, y] = order2Param2(t, x, u, tau,Kdc2, varargin)
  % Output equations.
  y = [x(1)];
  % State equations.
  dx = [x(2);                        ... % Angular position.
        -tau*x(2)+Kdc2*u(1)             ... % Angular velocity.
       ];