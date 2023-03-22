M=0.455; %[kg] Cart mass
m=0.21; %[kg] Pendulum mass
l=0.305; %[m] Pendulum half-length 
I=1/3*m*l^2; %[kg*m^2]Pendulum moment of inertia 
b=1.0; %[N*s/m] Cart viscous friction coefficient
Ie=I+m*l^2;
Me=m+M;
g=9.8;
k=10;
 x = [0, 0, pi/8, 0];
%x = [x, dx, θ, dθ]

%{
s=tf('s');
GuTH = m*l*s/((Me*Ie- m^2*l^2)*s^3 + (b*Ie)*s^2 - (Me*m*g*l)*s -(b*m*g*l));
GuX = (Ie*s^2 -m*g*l)/(s*((Me*Ie -m^2*l^2)*s^3 + (b*Ie)*s^2 - (Me*m*g*l)*s - (b*m*g*l)));
%}


A = [0 1 0 0 ; 0 (-1)*(b*Ie)/(Me*Ie-m^2*l^2) (m^2*l^2*g)/(Me*Ie-m^2*l^2) 0 ; 0 0 0 1 ; 0 (-1)*(m*l*b)/(Me*Ie-m^2*l^2) (m*g*l*Me)/(Me*Ie-m^2*l^2) 0];

B = [0 ; Ie/(Me*Ie*m^2*l^2) ; 0 ; m*l/(Me*Ie-m^2*l^2)];


C = [0 0 1 0 ; 1 0 0 0];

D = [0;0];
sys=ss(A, B, C, D);

e=eig(A);

figure;
plot(real(e), imag(e), '*');
xlabel("Real");
ylabel("Imag");

[num,den] = ss2tf(A,B,C,D);
num1=num(1, :);
num2=num(2, :);
den;
sys1=tf(num1, den);
sys2=tf(num2, den);
figure;
pzmap(sys1, 'b')
hold on;
pzmap(sys2, 'r')
hold on;
pzmap(sys, 'g')




K = [-0.02, -1.1, 7.5, 0.7];

%F = −K x = −(k1 x + k2 dx + k3 θ + k4 dθ)