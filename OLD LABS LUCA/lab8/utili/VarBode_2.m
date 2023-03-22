
N=14;
kdrv = 0.6;
kt =7.68e-3;
Ra=2.6;
Rs=0.5;
Req = Ra + Rs;
Bm=0;
Bl=0;
Beq = Bm +Bl/N^2;
Jm=3.90e-7;
Jl= 1.4e-6 + 3.0e-5; 
Jeq = Jm + Jl/N^2;
ke=7.68e-3;
km = kdrv*kt/(Req*Beq + kt*ke);
Tm =Req*Jeq/(Req*Beq + kt*ke);


s=tf('s');
C=1/s*(1+s/16.0)*4;
P =(1/N)*km/(Tm*s + 1);
G=P*C;
bode(G);
%step(G);
grid on;