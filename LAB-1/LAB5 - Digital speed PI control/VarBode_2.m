
N=14;
kdrv = 0.6;
kt =7.68e-3;
Ra=2.6;
Rs=0.5;
Req = Ra + Rs;
Bm=0;
Bl=0;
Jm=3.90e-7;
Jl= 1.4e-6 + 3.0e-5; 
% Jeq = Jm + Jl/N^2;
% Beq = Bm +Bl/N^2;
ke=7.68e-3;
Ts = 2e-2;

Beq = LSopt(1);
Jeq = LSopt(3);
tausf = LSopt(2);

km = kdrv*kt/(Req*Beq + kt*ke);
Tm =Req*Jeq/(Req*Beq + kt*ke);

s=tf('s');
P =(1/N)*km/(Tm*s + 1);

sysP = c2d(P, Ts, 'zoh')
