clear var;

M=0.455; %[kg] Cart mass
m=0.21; %[kg] Pendulum mass
l=0.305; %[m] Pendulum half-length 
I=1/3*m*l^2; %[kg*m^2]Pendulum moment of inertia 
b=1.0; %[N*s/m] Cart viscous friction coefficient
Ie=I+m*l^2;
Me=m+M;
g=9.8;
k=10;

s=tf('s');
%{
GuTH = m*l*s/((Me*Ie- m^2*l^2)*s^3 + (b*Ie)*s^2 - (Me*m*g*l)*s -(b*m*g*l));
GuX = (Ie*s^2 -m*g*l)/(s*((Me*Ie -m^2*l^2)*s^3 + (b*Ie)*s^2 - (Me*m*g*l)*s - (b*m*g*l)));
%}


A = [0 1 0 0 ; 0 (-1)*(b*Ie)/(Me*Ie-m^2*l^2) (m^2*l^2*g)/(Me*Ie-m^2*l^2) 0 ; 0 0 0 1 ; 0 (-1)*(m*l*b)/(Me*Ie-m^2*l^2) (m*g*l*Me)/(Me*Ie-m^2*l^2) 0];

B = [0 ; Ie/(Me*Ie*m^2*l^2) ; 0 ; m*l/(Me*Ie-m^2*l^2)];


C = [0 0 1 0 ; 1 0 0 0];

D = [0;0];
sys=ss(A, B, C, D);

%{
e=eig(A);
figure;
plot(real(e), imag(e), '*');
xlabel("Real");
ylabel("Imag");
%}

systf=tf(sys);

%{
figure;
pzmap(sys, 'r')
hold on;
pzmap(systf, 'y')
%}

%{
____________________PUNTO 1____________________________
%}
D=[(M*m*l^2 + Me*I), b*Ie , (-1)*Me*m*g*l, (-1)*b*m*g*l];
sysD=tf(D, 1);

Pth = m*l*s/sysD;
Px = (Ie*s^2 - m*g*l)/(s*sysD);
%figure;
rlocus(Pth);

%{
____________________PUNTO 2____________________________
%}
PthComp1 = Pth/s;
%figure;
rlocus(PthComp1);

%{
____________________PUNTO 3____________________________
%}

PthComp2=Pth*(s + 10)/s;
%figure;
rlocus(PthComp2);

%{
____________________PUNTO 4____________________________
%}
PthComp3=Pth*(s + 4)/s;
%figure;
rlocus(PthComp3);
%{
____________________PUNTO 5____________________________
%}
PthComp4=Pth*(s + 1)/s;
%figure;
rlocus(PthComp4);

%{
____________________PUNTO 6____________________________
%}
PthComp5=Pth*(s + 3)*(s + 1)/(s*(s + 10));
%figure;
rlocus(PthComp5);

%{
____________________PUNTO 7____________________________
%}
%kControl=140;
x = [0, 0, pi/8, 0];