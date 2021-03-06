%LSPB  Linear segment with parabolic blend
%
% [S,SD,SDD] = LSPB(S0, SF, N) is a scalar trajectory that varies 
% smoothly from S0 to SF in N steps using a constant velocity segment and 
% parabolic blends (a trapezoidal path).  Velocity and acceleration can be
% optionally returned as SD and SDD.  The trajectory S, SD and SDD 
% are N-vectors.
%
% [S,SD,SDD] = LSPB(S0, SF, T) as above but specifies the trajectory in 
% terms of the length of the time vector T.
%
% [S,SD,SDD] = LSPB(S0, SF, N, V) as above but specifies the velocity of 
% the linear segment which is normally computed automatically.
%
% [S,SD,SDD] = LSPB(S0, SF, T, V) as above but specifies the velocity of 
% the linear segment which is normally computed automatically and a time
% vector.
%
% Notes::
% - in all cases if no output arguments are specified S, SD, and SDD are plotted 
%   against time.
% - for some values of V no solution is possible and an error is flagged.
%
% See also TPOLY, JTRAJ.

% Copyright (C) 1993-2011, by Peter I. Corke
%
% This file is part of The Robotics Toolbox for Matlab (RTB).
% 
% RTB is free software: you can redistribute it and/or modify
% it under the terms of the GNU Lesser General Public License as published by
% the Free Software Foundation, either version 3 of the License, or
% (at your option) any later version.
% 
% RTB is distributed in the hope that it will be useful,
% but WITHOUT ANY WARRANTY; without even the implied warranty of
% MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
% GNU Lesser General Public License for more details.
% 
% You should have received a copy of the GNU Leser General Public License
% along with RTB.  If not, see <http://www.gnu.org/licenses/>.

function [s,sd,sdd] = Trapezo_Inter(q0, q1, t, V)

	if size(t) == [1 1]
		t = [0:t-1]';
	end

	tf = max(t(:));

	if nargin < 4
        % if velocity not specified, compute it
		V = (q1-q0)/tf * 1.5;
	else
		if V < (q1-q0)/tf
			error('V too small\n');
		elseif V > 2*(q1-q0)/tf
			error('V too big\n');
		end
    end

    if q0 == q1
        s = ones(size(t)) * q0;
        sd = zeros(size(t));
        sdd = zeros(size(t));
        return
    end

	tb = (q0 - q1 + V*tf)./V;
	a = V./tb;

    p = zeros(length(t), 1);
    pd = p;
    pdd = p;
    
	for i = 1:length(t)
		tt = t(i);

		if tt <= tb
            % initial blend
			p(i) = q0 + a/2*tt^2;
            pd(i) = a*tt;
            pdd(i) = a;
		elseif tt <= (tf-tb)
            % linear motion
			p(i) = (q1+q0-V*tf)/2 + V*tt;
            pd(i) = V;
            pdd(i) = 0;
        else
            % final blend
			p(i) = q1 - a/2*tf^2 + a*tf*tt - a/2*tt^2;
            pd(i) = a*tf - a*tt;
            pdd(i) = -a;
		end
	end

    switch nargout
        case 0
            clf
            subplot(311)
            hold on
            k = t<= tb;
            plot(t(k), p(k), 'r-o');
            k = (t>=tb) & (t<= (tf-tb));
            plot(t(k), p(k), 'b-o');
            k = t>= (tf-tb);
            plot(t(k), p(k), 'g-o');
            grid; ylabel('s');
            hold off

            subplot(312)
            plot(t, pd); grid; ylabel('sd');
            
            subplot(313)
            plot(t, pdd); grid; ylabel('sdd');
            xlabel('time')
            shg
        case 1
            s = p;
        case 2
            s = p;
            sd = pd;
        case 3
            s = p;
            sd = pd;
            sdd = pdd;
    end
    
	if nargout == 0
	else
		tg = p;
	end
