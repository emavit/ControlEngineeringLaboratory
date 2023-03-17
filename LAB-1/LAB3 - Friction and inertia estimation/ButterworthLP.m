clear all
clc

load('data_gradini.mat')
load('parametri.mat')

%% Hi low-pass
Ts = 1e-3;
wci = 2*pi*20;
di = 1/sqrt(2);
sysHi = tf(wci^2,[1 2*di*wci wci^2]);
sysHi = c2d(sysHi, Ts, 'tustin');
[numHi, denHi] =tfdata(sysHi, 'v');

% filtraggio
iap = filter(numHi, denHi, iap);
ian = filter(numHi, denHi, ian);


%% Calcolo delle medie di interesse [1]

iapm = zeros(9,1);
ianm = zeros(9,1);
for i = 1:9
    iapm(i) = mean(iap(5000*(i-1)+200:5000*(i-1)+800));
    ianm(i) = mean(ian(5000*(i-1)+200:5000*(i-1)+800));
end

taump = mot.Kt*iapm;
taumn = mot.Kt*ianm;

% Dal momento che i dati presi non vanno bene escludiamo la parte sbagliata
taumn = taumn(2:9);

%% Calcolo delle medie di interesse [2]

wmpk = gbox.N*wmp;
wmnk = gbox.N*wmn;

wmpm = zeros(9,1);
wmnm = zeros(9,1);

for i = 1:9
    wmpm(i) = mean(wmpk(5000*(i-1)+200:5000*(i-1)+800));
    wmnm(i) = mean(wmnk(5000*(i-1)+200:5000*(i-1)+800));
end

wmnm = wmnm(2:9);

wmpm = wmpm*rpm2rads;
wmnm = wmnm*rpm2rads;

%%

Phip = [wmpm 1/gbox.N*ones(9,1)];
Phin = [wmnm 1/gbox.N*ones(8,1)];

thetaLSp = Phip\taump
thetaLSn = Phin\taumn

