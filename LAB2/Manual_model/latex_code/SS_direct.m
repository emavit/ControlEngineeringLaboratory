%% State Space Controller direct figital design

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
ssNominalDT.SysCT = ss(ssP.A,ssP.B,ssP.C,ssP.D); 

%% Discretize the model
% Set a sampling time
Ts=0.001;

% exact discretization of the plant
ssNominalDT.SysD = c2d(ssNominalDT.SysCT,Ts,'zoh');

% Calculate prefilter gains for both nominal and robust
ssNominalDT.N = [ssNominalDT.SysD.A-eye(2), ssNominalDT.SysD.B; ssNominalDT.SysD.C, ssNominalDT.SysD.D]\[zeros(2,1); 1];
ssNominalDT.Nx = ssNominalDT.N(1:2); 
ssNominalDT.Nu = ssNominalDT.N(3); 

%% Place Poles for nominal controller

% Define poles postitions in continous time
ssNominal.poles = [-perf.d*perf.wn+1i*perf.wn*sqrt(1-perf.d^2), -perf.d*perf.wn-1i*perf.wn*sqrt(1-perf.d^2)];

% Translate poles in discrete time
ssNominalDT.poles = exp(ssNominal.poles*Ts);

% Find gains for pole placement
ssNominalDT.K = place(ssNominalDT.SysD.A, ssNominalDT.SysD.B, ssNominalDT.poles);

%% Define extended State-Space for robust controller (simplified plant model)

ssRobustDT.Phe = [1 ssRobustDT.SysD.C ;zeros(2, 1) ssRobustDT.SysD.A];
ssRobustDT.Gammae =[0; ssRobustDT.SysD.B];

%% Place Poles for robust controller

% Define poles postitions in continous time
ssRobust.poles = [-2*perf.sigmamin + 1i*perf.wdmax, -2*perf.sigmamin - 1i*perf.wdmax, -2*perf.sigmamin];

% Translate poles in discrete time
ssRobustDT.poles = exp(ssRobust.poles*Ts);

% Find gains for pole placement
ssRobustDT.Ke = place(ssRobustDT.Phe, ssRobustDT.Gammae, ssRobustDT.poles);

ssRobustDT.K = ssRobustDT.Ke(2:3);
ssRobustDT.Ki = ssRobustDT.Ke(1);

%% Reduced Order Observer

% Set poles 5 times faster than the faster set in the controller and discretize them
redObs.pole = exp(5*(-2*perf.sigmamin)*Ts);

% Placing observer poles
redObs.L = place(ssNominalDT.SysD.A(2,2)',ssNominalDT.SysD.A(1,2)',redObs.pole);

% Define Reduced order observer matrices
ssRobustDT.redObs.Ph0 = ssNominalDT.SysD.A(2,2) - redObs.L*ssNominalDT.SysD.A(1,2);
ssRobustDT.redObs.Gamma0 = [ssNominalDT.SysD.B(2)-redObs.L*ssNominalDT.SysD.B(1), redObs.Ph0*redObs.L+sssNominalDT.SysD.A(2,1)-redObs.L*ssNominalDT.SysD.A(1,1)];
ssRobustDT.redObs.C0 = [0; 1];
ssRobustDT.redObs.D0 = [0 1; 0 redObs.L];