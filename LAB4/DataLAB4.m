%% General parameters and conversion gains

% controller sampling time
Ts = 1e-2;

% gravity acc [m/s^2]
g = 9.81;

% conversion gains
rpm2rads = 2*pi/60; % [rpm] -> [rad/s]
rads2rpm = 60/2/pi; % [rad/s] -> [rpm]
rpm2degs = 360/60; % [rpm] -> [deg/s]
degs2rpm = 60/360; % [deg/s] -> [rpm]
deg2rad = pi/180; % [deg] -> [rad]
rad2deg = 180/pi; % [rad] -> [deg]
g2ms2 = g; % [acc_g] -> [m/s^2]
ms22g = 1/g; % [m/s^2] -> [acc_g]
ozin2Nm = 0.706e-2; % [oz*inch] -> [N*m]

% robot initial condition
x0 =[ ...
0; ... % gam(0)
pi/36; ... % th(0)
0; ... % dot_gam(0)
0]; % dot_th(0)

%5*deg2rad; ... % th(0)

%% DC motor data

% motor id: brushed DC gearmotor Pololu 30:1 37Dx68L mm

% electromechanical params
mot.UN = 12; % nominal voltage
mot.taus = 110/30 * ozin2Nm; % stall torque @ nom voltage
mot.Is = 5; % stall current @ nom voltage
mot.w0 = 350 * 30 * rpm2rads; % no-load speed @ nom voltage
mot.I0 = 0.3; % no-load current @ nom voltage
mot.R = mot.UN/mot.Is; % armature resistance
mot.L = NaN; % armature inductance
mot.Kt = mot.taus/mot.Is; % torque constant
mot.Ke = (mot.UN - mot.R*mot.I0)/(mot.w0); % backEMF constant
mot.eta = NaN; % motor efficiency
mot.PN = NaN; % nominal output power
mot.IN = NaN; % nominal current
mot.tauN = NaN; % nominal torque

% Dimensions
mot.rot.h = 30.7e-3; % rotor height
mot.rot.r = 0.9 * 17e-3; % rotor radius

mot.stat.h = 68.1e-3; % stator height
mot.stat.r = 17e-3; % stator radius

% Center of mass (CoM) position
mot.rot.xb = 0; % (left) rot CoM x-pos in body frame
mot.rot.yb = 42.7e-3; % (left) rot CoM y-pos in body frame
mot.rot.zb = -7e-3; % (left) rot CoM z-pos in body frame

mot.stat.xb = 0; % (left) stat CoM x-pos in body frame
mot.stat.yb = 52.1e-3; % (left) stat CoM y-pos in body frame
mot.stat.zb = -7e-3; % (left) stat CoM z-pos in body frame

% Mass
mot.m = 0.215; % total motor mass
mot.rot.m = 0.35 * mot.m; % rotor mass
mot.stat.m = mot.m - mot.rot.m; % stator mass

% Moment of inertias (MoI) wrt principal axes
mot.rot.Ixx = mot.rot.m/12 * (3*mot.rot.r^2 + mot.rot.h^2); % MoI along r dir
mot.rot.Iyy = mot.rot.m/2 * mot.rot.r^2; % MoI along h dim
mot.rot.Izz = mot.rot.Ixx; % MoI along r dir

mot.stat.Ixx = mot.stat.m/12 * (3*mot.stat.r^2 + mot.stat.h^2); % MoI along r dir
mot.stat.Iyy = mot.stat.m/2 * mot.stat.r^2; % MoI along h dir
mot.stat.Izz = mot.stat.Ixx; % MoI along r dir

% viscous friction coeff (motor side)
mot.B = mot.Kt*mot.I0/mot.w0;

%% Gearbox data

gbox.N = 30; % reduction ratio
gbox.B = 0.025; % viscous friction coeff (load side)

%% Battery data

% electrical data
batt.UN = 11.1; % nominal voltage

% Dimensions
batt.w = 136e-3; % battery pack width
batt.h = 26e-3; % battery pack height
batt.d = 44e-3; % battery pack depth

% Center of mass (CoM) position
batt.xb = 0; % CoM x-pos in body frame
batt.yb = 0; % CoM y-pos in body frame
batt.zb = 44e-3; % CoM z-pos in body frame

% Mass
batt.m = 0.320;

% moment of inertias (MoI) wrt principal axes
batt.Ixx = batt.m/12 * (batt.w^2 + batt.h^2); % MoI along d dim
batt.Iyy = batt.m/12 * (batt.d^2 + batt.h^2); % MoI along w dim
batt.Izz = batt.m/12 * (batt.w^2 + batt.d^2); % MoI along h dim

%% Hbridge PWM voltage driver data

drv.Vbus = batt.UN; % H-bridge DC bus voltage
drv.pwm.bits = 8; % PWM resolution [bits]
drv.pwm.levels = 2^drv.pwm.bits; % PWM levels
drv.dutymax = drv.pwm.levels-1; % max duty cycle code
drv.duty2V = drv.Vbus/drv.dutymax; % duty cycle code (0255) to voltage
drv.V2duty = drv.dutymax/drv.Vbus; % voltage to duty cycle code (0-255)

%% Wheel data

% dimensions
wheel.h = 26e-3; % wheel height
wheel.r = 68e-3/2; % wheel radius

% center of mass (CoM) position
wheel.xb = 0; % (left) wheel CoM x-pos in body frame
wheel.yb = 100e-3; % (left) wheel CoM y-pos in body frame
wheel.zb = 0; % (left) wheel CoM z-pos in body frame

% mass
wheel.m = 50e-3;

% moment of inertias (MoI) wrt principal axes
wheel.Ixx = wheel.m/12 * (3*wheel.r^2 + wheel.h^2); % MoI along r dim
wheel.Iyy = wheel.m/2 * wheel.r^2; % MoI along h dim
wheel.Izz = wheel.Ixx; % MoI along r dim

% viscous friction coeff
wheel.B = 0.0015;

%% Chassis data

% dimensions
chassis.w = 160e-3; % frame width
chassis.h = 119e-3; % frame height
chassis.d = 80e-3; % frame depth

 %c Center of mass (CoM) position
chassis.xb = 0; % CoM x-pos in body frame
chassis.yb = 0; % CoM x-ppos in body frame
chassis.zb = 80e-3; % CoM x-pos in body frame

% mass
chassis.m = 0.456;

%moment of inertias (MoI) wrt principal axes
chassis.Ixx = chassis.m/12 * (chassis.w^2 + chassis.h^2); % MoI along d dim
chassis.Iyy = chassis.m/12 * (chassis.d^2 + chassis.h^2); % MoI along w dim
chassis.Izz = chassis.m/12 * (chassis.w^2 + chassis.d^2); % MoI along h dim

%% Body data

% mass
body.m = chassis.m + batt.m + 2*mot.stat.m;
% center of mass (CoM) position
body.xb = 0; % CoM x-pos in body frame
body.yb = 0; % CoM y-pos in body frame
body.zb = (1/body.m) * (chassis.m*chassis.zb + ... % CoM z-pos in body frame
batt.m*batt.zb + 2*mot.stat.m*mot.stat.zb);

% moment of inertias (MoI) wrt principal axes
body.Ixx = chassis.Ixx + chassis.m*(body.zb - chassis.zb)^2 + ... % MoI along d dim
batt.Ixx + batt.m*(body.zb - batt.zb)^2 + ...
2*mot.stat.Ixx + ...
2*mot.stat.m*(mot.stat.yb^2 + (body.zb - mot.stat.zb)^2);

body.Iyy = chassis.Iyy + chassis.m*(body.zb - chassis.zb)^2 + ... % MoI along w dim
batt.Iyy + batt.m*(body.zb - batt.zb)^2 + ...
2*mot.stat.Iyy + ...
2*mot.stat.m*(body.zb - mot.stat.zb)^2;

body.Izz = chassis.Izz + batt.Izz + ... % MoI along h dim
2*mot.stat.Izz + 2*mot.stat.m*mot.stat.yb^2;

%% Sensors data - Halleffect encoder

% Halleffect encoder
sens.enc.ppr = 16*4; % pulses per rotation at motor side (w/ quadrature decoding)
sens.enc.pulse2deg = 360/sens.enc.ppr;
sens.enc.pulse2rad = 2*pi/sens.enc.ppr;
sens.enc.deg2pulse = sens.enc.ppr/360;
sens.enc.rad2pulse = sens.enc.ppr/2/pi;

%% Sensors data - MPU6050 (accelerometer + gyro)

% center of mass (CoM) position
sens.mpu.xb = 0;
sens.mpu.yb = 0;
sens.mpu.zb = 13.5e-3;

% MPU6050 embedded accelerometer specs
sens.mpu.acc.bits = 16;
sens.mpu.acc.fs_g = 16; % full-scale in "g" units
sens.mpu.acc.fs = sens.mpu.acc.fs_g * g2ms2; % full-scale in [m/s^2]
sens.mpu.acc.g2LSB = floor(2^(sens.mpu.acc.bits-1)/sens.mpu.acc.fs_g); % sensitivity [LSB/g]
sens.mpu.acc.ms22LSB = sens.mpu.acc.g2LSB * ms22g; % sensitvity [LSB/(m/s^2)]
sens.mpu.acc.LSB2g = sens.mpu.acc.fs_g/2^(sens.mpu.acc.bits-1); % out quantization [g/LSB]
sens.mpu.acc.LSB2ms2 = sens.mpu.acc.LSB2g * g2ms2; % out quantization [ms2/LSB]
sens.mpu.acc.bw = 94; % out lowpass filter BW [Hz]
sens.mpu.acc.noisestd = 400e-6*sqrt(100); % output noise std [g-rms]
sens.mpu.acc.noisevar = sens.mpu.acc.noisestd^2; % output noise var [g^2]

% MPU6050 embdedded gyroscope specs
sens.mpu.gyro.bits = 16;
sens.mpu.gyro.fs_degs = 250; % full scale in [deg/s (dps)]
sens.mpu.gyro.fs = sens.mpu.gyro.fs_degs * deg2rad; % full scale in [rad/s]
sens.mpu.gyro.degs2LSB = floor(2^(sens.mpu.gyro.bits-1)/sens.mpu.gyro.fs_degs); % sensitivity [LSB/degs]
sens.mpu.gyro.rads2LSB = sens.mpu.gyro.degs2LSB * rad2deg; % sensitivity [LSB/rads]
sens.mpu.gyro.LSB2degs = sens.mpu.gyro.fs_degs/2^(sens.mpu.gyro.bits-1); % out quantization [degs/LSB]
sens.mpu.gyro.LSB2rads = sens.mpu.gyro.LSB2degs * deg2rad; % out quantization [rads/LSB]
sens.mpu.gyro.bw = 98; % out lowpass filter BW [Hz]
sens.mpu.gyro.noisestd = 5e-3*sqrt(100); % output noise std [degs-rms]
sens.mpu.gyro.noisevar = sens.mpu.acc.noisestd ^2; % output noise var [degs^2]