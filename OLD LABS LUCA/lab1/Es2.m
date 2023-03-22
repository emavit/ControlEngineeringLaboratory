%{
Laboratorio 1 22/3/2022

______________ESERCIZIO 2_________________
%}
s=tf('s');
km = 5.2;
Tm = 0.03;
P1=km/(Tm*s + 1); %sysP1
P=1/s *P1;        %sysP
%{
P = 
      5.2
  ------------
  0.03 s^2 + s
%}

%{
_____________________________PUNTO 1_______________________________________
%}
T =1/(2*pi*50);
omegac = 2*pi*50;
delta = 1/sqrt(2);
H2= (omegac^2*s)/(s^2+2*delta*omegac*s +omegac^2); %sysH
%{
H2 = 
         9.87e04 s
  -----------------------
  s^2 + 444.3 s + 9.87e04
%}
k=1;
C=k;
omegaStar=2;
n=0;
d=0;
sys=C*P*H2; %sysL

figure;
rlocus(sys);


%{
_____________________________PUNTO 2_______________________________________
%}
%   conversion gains
rads2rpm = 60/2/pi;
rpm2rads = 2*pi/60;


kStar=3;
k=kStar/4;
C=k;
%{
C =
    0.7500
%}
t=0:1*10^-4:0.1;
speed=300; %speed in [rpm]
speed=speed*rpm2rads;
omegaStar=ones(1, length(t))*speed;
n=0;
d=0;
x0=0;
%Y=  (omegaStar*C- n*H2*C+d)*P/(1+H2*C*P);

%   closed-loop tf from ref (w^*) to actual speed (w)
YrefToAct=feedback(C*P1, 1/s*H2);

%   closed-loop tf from ref (w^*) to measured speed (w_m)
YrefToMes = feedback(C*P*H2, 1);

%   closed-loop tf from ref (w^*) to control command (u)
YrefToContr = feedback(C, P*H2);

Y = feedback( C* (d+ P), H2);
figure;
out=lsim(YrefToAct, omegaStar, t, x0)*rads2rpm;
plot(t, out, 'r')
legend("closed-loop tf from ref (w^*) to actual speed (w)");
xlabel("time [s]");
ylabel("speed [rpm]");


%{

%   time array
t = linspace(0, 0.3, 200);

%   actual speed response 
opt = stepDataOptions('InputOffset', 0, 'StepAmplitude', 300*rpm2rads);
w = step(sysT, t, opt);

%   measured speed response
wm = step(sysCPHS, t, opt);

%   control command response
u = step(sysCS, t, opt);

%   plot results
figure; 
subplot(2,1,1)
plot(t, w*rads2rpm, 'b');
hold on;
plot(t, wm*rads2rpm, 'r');
plot([t(1), t(end)], [300, 300], 'k--');
legend('w', 'wm', 'wref');
grid on;
xlabel('Time [s]');
ylabel('Speed [rpm]');
ylim([0, 500]);

subplot(2,1,2);
plot(t, u, 'b');
grid on;
xlabel('Time [s]');
ylabel('Control command [V]');
%}