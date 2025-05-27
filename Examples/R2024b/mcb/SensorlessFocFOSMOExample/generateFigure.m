% Se hai salvato le velocità con To Workspace
t1 = Speed_fb.time;
y1 = Speed_fb.signals.values;
t2 = Speed_ref.time;
r1 = Speed_ref.signals.values;

figure;
plot(t1, y1(:,1), 'b', 'DisplayName', 'Speed\_fb'); hold on;
plot(t2, r1(:,:), '--r', 'DisplayName', 'Speed\_ref');
legend show;
grid;
xlabel('Tempo (s)');
ylabel('Velocità (rad/s)');
title('Andamento velocità Motore');