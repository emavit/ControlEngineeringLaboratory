wc = 2*pi*50;
d = 1/sqrt(2);
sysF = tf([wc^2 0],[1 2*d*wc wc^2]);
sysF = c2d(sysF, Ts, 'tustin');
[numF, denF] =tfdata(sysF, 'v');