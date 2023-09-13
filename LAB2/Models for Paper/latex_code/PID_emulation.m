%% PID controllers emulation

% Define auxilliary parameters
paramP.Jeq = real.Jeq;
paramP.Beq = real.Beq;

% Define transfer function parameters
paramP.Req = mot.R + sens.curr.Rs;
paramP.km = mot.Kt*drv.dcgain/(paramP.Req*paramP.Beq+mot.Kt*mot.Ke);
paramP.Tm = paramP.Req*paramP.Jeq/(paramP.Req*paramP.Beq+mot.Kt*mot.Ke);

%% Define performace indexes

perf.ts5 = 0.2;
perf.mp = 0.1;

perf.d = log(1/perf.mp)/sqrt(pi^2+log(1/perf.mp)^2);
perf.wg = 3/(perf.d*perf.ts5);
perf.phi = 100*perf.d;              %[deg] approximation for phi<70 deg

%% Design controllers using different discretization for Ts = 1ms

Ts = 0.001;

z = tf('z',Ts);
% define transfer function with delay
Pdelay = exp(-s*Ts/2)*(paramP.km/(gbox.N*s*(paramP.Tm*s+1)));

% Get magnitue and phase at the desired frequency
[magPwg, phasePwg] = bode(Pdelay, perf.wg);

dK = abs(magPwg)^-1;
dPh = -pi + perf.phi*deg2rad - phasePwg*deg2rad;

% Estimation of the paramters of the PID-discrete time controller (system with time delay)
a = 4000; 
pidz.K = dK * cos(dPh);

Td = (tan(dPh)+sqrt(tan(dPh)^2+4/a))/(2*perf.wg);
Ti = a*Td;
pidz.T_l = 1/(2*perf.wg);

pidz.Kd = pidz.K*Td;
pidz.Ki = pidz.K/Ti;
% Define discretization variables
s_forward = (z-1)/Ts;
s_backward = (z-1)/(Ts*z);

% Define PID controller continous transfer function
s = tf('s');
pidz.C = pidz.K + pidz.Ki*(1/s) + pidz.Kd * (s/(pidz.T_l*s + 1)); 

% Forward Euler Discretization
pidz.Cf = pidz.K + pidz.Ki*(1/s_forward) + pidz.Kd * (s_forward/(pidz.T_l*s_forward + 1)); 
% Backward Euler Discretization
pidz.Cb = pidz.K + pidz.Ki*(1/s_backward) + pidz.Kd * (s_backward/(pidz.T_l*s_backward + 1)); 
% Tustin/Trapezoidal Discretization
pidz.Ctust = c2d(pidz.C,Ts,'tustin'); 
% Exact Discretization
pidz.Czoh = c2d(pidz.C,Ts,'zoh'); 

% Transfer functions of controllers for different discretizations used in PID-emulation.
pidz.controllers = [pidz.Cf, pidz.Cb, pidz.Ctust, pidz.Czoh];

% get numerator and denominator for simulations
% in this case for Forward Euler 
[pidz.Cnum, pidz.Cdenom] = tfdata(pidz.controllers(1), 'v');

%% Anti-Wind-UP

% define the anti-wind-up gain
pidz.Kw = 5/perf.ts5; 