%{
Laboratorio 2 29/3/2022

______________ESERCIZIO 4_________________
%}
T =1/(2*pi*50);
omegac = 2*pi*50;
delta = 1/sqrt(2);

s=tf('s');
H=s;

H1=s/(T*s + 1);
%{
H1 =
        s
  --------------
  0.003183 s + 1
%}

H2= (omegac^2*s)/(s^2+2*delta*omegac*s +omegac^2);
%{
H2 = 
         9.87e04 s
  -----------------------
  s^2 + 444.3 s + 9.87e04
%}

%{
_____________________________PUNTO 1_______________________________________
%}
Ts=1e-3;
Ht=c2d(H, Ts, 'tustin');
figure;
bode(Ht);

z=tf('z', Ts);

s=(z-1)/Ts;
HBE=s;
hold on;
bode(HBE);

s=(1-z^-1)/Ts;
HFE=s;
hold on;
bode(HFE);
legend("H1 tustin", "H1 BackEulero", "H1 ForwardEulero");
%{
_____________________________PUNTO 2_______________________________________
%}
Ts=1e-3;
Ht=c2d(H1, Ts, 'tustin');
figure;
bode(Ht);

z=tf('z', Ts);

s=(z-1)/Ts;
HBE=s/(T*s + 1);
hold on;
bode(HBE);

s=(1-z^-1)/Ts;
HFE=s/(T*s + 1);
hold on;
bode(HFE);
legend("H1 tustin", "H1 BackEulero", "H1 ForwardEulero");

%{
_____________________________PUNTO 3_______________________________________
%}
Ts=1e-3;
Ht=c2d(H2, Ts, 'tustin');
figure;
bode(Ht);

z=tf('z', Ts);

s=(omegac^2*s)/(s^2+2*delta*omegac*s +omegac^2);
HBE=s/(T*s + 1);
hold on;
bode(HBE);

s=(1-z^-1)/Ts;
HFE=(omegac^2*s)/(s^2+2*delta*omegac*s +omegac^2);
hold on;
bode(HFE);
legend("H1 tustin", "H1 BackEulero", "H1 ForwardEulero");

%{
_____________________________PUNTO 4_______________________________________
%}
figure;
N=4;
H3 = (1 - z^(-1*N))/(N*Ts);
bode(H3);
hold on;
bode(Ht, '--');
legend("H3", "Theorical");

%{
_____________________________PUNTO 5_______________________________________
%}
figure;
H4 = 1/(6*Ts)*(1 + 3*z^(-1) - 3*z^(-2) - z^(-3));
bode(H4);
hold on;
bode(Ht, '--');
legend("H4", "Theorical");

%{
_____________________________PUNTO 6_______________________________________
%}
t=0:1*10^-3:4;
a = 0.001;

n=a*(rand(1,length(t))-0.5);
r = 25*t;
u=r+n;
figure;
lsim(H4, u, t, 0);