figure; 
%subplot(2,1,1)
plot(t, w*rads2rpm, 'b');
hold on;
plot(t, wm*rads2rpm, 'r');
plot([t(1), t(end)], [300, 300], 'k--');
legend('w', 'wm', 'wref');
grid on;
xlabel('Time [s]');
ylabel('Speed [rpm]');
ylim([0, 500]);