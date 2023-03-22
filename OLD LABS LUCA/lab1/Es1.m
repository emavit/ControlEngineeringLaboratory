%{
Laboratorio 1 22/3/2022

______________ESERCIZIO 1_________________
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

figure('Name','Bode');
bode(H1, 'r');
hold on;
bode(H2, 'b');
hold on;
bode(H, 'g');
legend("H1", "H2", "H");
grid on

%{
_____________________________PUNTO 2_______________________________________
%}
t=0:1*10^-3:4;
A = 1;
omega = 2*pi* 0.5;
x0=0;
u = A*sin(omega*t);

figure('Name','Time response');
lsim(H1, u, t, x0, 'r');
hold on;
lsim(H2, u, t, x0, 'b');
hold on;
plot(t, u, 'g');
grid on;
legend("h1(t)", "h2(t)", "u(t)");

%{
_____________________________PUNTO 3_______________________________________
%}
omega = 2*pi* 20;
Fs = 10*omega;            % Sampling frequency                    
T = 1/Fs;             % Sampling period       
L = 1500;             % Length of signal
t = (0:L-1)*T;        % Time vector
A = 1;
x0=0;
u = A*sin(omega*t);

figure('Name','time response high frequency');
y1=lsim(H1, u, t, x0, 'r');
plot(t, y1, 'r' );
hold on;
y2=lsim(H2, u, t, x0, 'b');
plot(t, y1, 'b' );
hold on;
plot(t, u, 'g');
grid on;
legend("h1(t)", "h2(t)", "u(t)");


%FFT y1
Y1 = fft(y1);
P2 = abs(Y1/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);

figure('Name','time response high frequency FFT');
f = Fs*(0:(L/2))/L;
plot(f,P1, 'r');
title('Single-Sided Amplitude Spectrum of X(t)');
xlabel('f (Hz)');
ylabel('|P1(f)|');
hold on

%FFT y1
Y2 = fft(y2);
P2 = abs(Y2/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
plot(f,P1, 'b');

legend("y1", "y2");

%{
_____________________________PUNTO 4_______________________________________
%}

t=0:1*10^-3:4;
a = 0.001;

n=a*(rand(1,length(t))-0.5);
r = 25*t;
u=r+n;


figure('Name','Time response for ramp');
lsim(H1, u, t, x0, 'r');
hold on;
lsim(H2, u, t, x0, 'b');
hold on;
plot(t, u, 'g');
grid on;
legend("h1(t)", "h2(t)", "u(t)");