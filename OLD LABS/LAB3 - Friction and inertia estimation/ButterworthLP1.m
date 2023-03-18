clear all
clc

load('data_triang.mat')
load('parametri.mat')
load('stima.mat')

%% Hi low-pass
Ts = 1e-3;
wci = 2*pi*20;
di = 1/sqrt(2);
sysHi = tf(wci^2,[1 2*di*wci wci^2]);
sysHi = c2d(sysHi, Ts, 'tustin');
[numHi, denHi] =tfdata(sysHi, 'v');

% filtraggio
ia = filter(numHi, denHi, ia);
plot(t,ia)
grid on

%% Ha low-pass

wca = 2*pi*20;
da = 1/sqrt(2);
sysFa = tf([wca^2 0],[1 2*da*wca wca^2]);
sysFa = c2d(sysFa, Ts, 'tustin');
[numFa, denFa] =tfdata(sysFa, 'v');


% filtraggio
al = filter(numFa, denFa, wm);
am = gbox.N*al;

%% Calcolo delle medie di interesse [a]

amean = zeros(20,1);
for i = 0:19
    amean(i+1) = mean(am(1000*i+200:1000*i+800));
end

%%

taum_k = mot.Kt*ia;

%tau_f = thetaLSopt(1)*3*wm/rpm2rads+thetaLSopt(2)/N*sign(wm)*10;
tau_f = LSopt(1)*wm/rads2rpm + LSopt(2)/gbox.N;

tau_i = taum_k - tau_f;

%%
figure
subplot(2,2,1)
plot(wm*gbox.N)
ylabel('\omega_{m}')
axis([0 8000 0 7000])
grid on

subplot(2,2,2)
plot(am)
ylabel('a_{m}')
axis([0 8000 -12000 12000])
grid on

subplot(2,2,3)
plot(ia)
%hold on
%plot(tau_f/mot.Kt)
ylabel('i_{a}')
axis([0 8000 -0.1 0.25])
grid on

subplot(2,2,4)
plot(tau_i)
ylabel('\tau_{i}')
axis([0 8000 -0.0008 0.0008])
grid on

%%
% 
% wm_plot=[50 100 150 200 250 300 350 400 450]*N;
% figure
% stem(wm_plot,tau_m_k)
% hold on
% plot(wm_plot, theta(1)*wm_plot+1/N*0.01)