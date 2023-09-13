%% State Space Controller emulation

% Define auxilliary parameters
paramP.Jeq = real.Jeq;
paramP.Beq = real.Beq;

% Define state space parameters
paramP.Req = mot.R + sens.curr.Rs;
paramP.km = mot.Kt*drv.dcgain/(paramP.Req*paramP.Beq+mot.Kt*mot.Ke);
paramP.Tm = paramP.Req*paramP.Jeq/(paramP.Req*paramP.Beq+mot.Kt*mot.Ke);

%% Define performance indexes for pole placement

perf.ts5 = 0.2;
perf.mp = 0.1;

perf.d = log(1/perf.mp)/sqrt(pi^2+log(1/perf.mp)^2);
perf.wg = 3/(perf.d*perf.ts5);
perf.phi = 100*perf.d;              %[deg] approximation for phi<70 deg

% Specifications for pole Placement
perf.sigmamin = 3/perf.ts5;
perf.wn = 3/(perf.ts5*perf.d);

%% Define continous State-Space for nominal controller (simplified plant model)

ssP.A = [0, 1; 0 -1/paramP.Tm];
ssP.B = [0; paramP.km/(gbox.N*paramP.Tm)];
ssP.C = [1 0];
ssP.D = 0;

% Calculate prefilter gains for both nominal and robust
ssNominal.N = [ssP.A ssP.B; ssP.C ssP.D]\[zeros(2,1); 1];
ssNominal.Nx = ssNominal.N(1:2);
ssNominal.Nu = ssNominal.N(3);

%% Place Poles for nominal controller

% Define poles postitions
ssNominal.poles = [-perf.d*perf.wn+1i*perf.wn*sqrt(1-perf.d^2), -perf.d*perf.wn-1i*perf.wn*sqrt(1-perf.d^2)];

% Find gains for pole placement
ssNominal.K = place(ssP.A, ssP.B, ssNominal.poles);

%% Define extended continous State-Space for robust controller (simplified plant model)

ssP.Ae = [0, ssP.C; zeros(2,1), ssP.A];
ssP.Be = [0; ssP.B];

%% Place Poles for robust controller
 
% define auxilliary performance index
perf.wdmax = perf.sigmamin/perf.d * sqrt(1-perf.d^2);

% Define poles postitions
ssRobust.poles = [-2*perf.sigmamin + 1i*perf.wdmax, -2*perf.sigmamin - 1i*perf.wdmax, -3*perf.sigmamin];

% Find gains for pole placement
ssRobust.Ke = place(ssP.Ae, ssP.Be, ssRobust.poles);

ssRobust.Ki = ssRobust.Ke(1);
ssRobust.K = ssRobust.Ke(2:3);

%% Reduced order Observer
% defining contrinous reduced order observer
redObs.L = 4/paramP.Tm;                     % defyning observer gain manually
redObs.A0 = -(1/paramP.Tm + redObs.L);      % Manually placing EV to -5/paramP.Tm
redObs.B0 = [paramP.km/(gbox.N*paramP.Tm), -(1/paramP.Tm + redObs.L)*redObs.L];
redObs.C0 = [0; 1];
redObs.D0 = [0 1; 0 redObs.L];

% Define a sampling time
Ts=0.001;

% Forward Euler Discretization
redObs.Ph0 = 1+ redObs.A0*Ts;
redObs.Gamma0 = redObs.B0*Ts;
redObs.H0 = redObs.C0;
redObs.J0 = redObs.D0;

% Backward Euler Discretization
redObs.Ph0 = inv(1 - redObs.A0*Ts);
redObs.Gamma0 = (1 - redObs.A0*Ts)\redObs.B0*Ts;
redObs.H0 = redObs.C0/(1 - redObs.A0*Ts);
redObs.J0 = redObs.D0 + redObs.C0/(1 - redObs.A0*Ts)*redObs.B0*Ts;