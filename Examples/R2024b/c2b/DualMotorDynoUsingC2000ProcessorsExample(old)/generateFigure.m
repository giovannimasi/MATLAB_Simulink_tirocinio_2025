% Se hai salvato le velocità con To Workspace
t1 = Mtr1_Speed_feedback.time;
y1 = Mtr1_Speed_feedback.signals.values;
t2 = Mtr1_Speed_feedback.time;
r1 = Mtr1_Speed_reference.signals.values;
t3 = Iq_ref.time;
i1 = Iq_ref.signals.values;

%t2 = velocita_motore2.time;
%y2 = velocita_motore2.signals.values;

figure;
subplot('211'),
plot(t1, y1, 'b', 'DisplayName', 'Speed\_fb'); hold on;
plot(t2, r1, '--r', 'DisplayName', 'Speed\_ref');
legend show;
grid;
xlabel('Tempo (s)');
ylabel('Velocità (rad/s)');
title('Andamento velocità Motore 1');
subplot('212'),
plot(t3,i1(:,:), 'k', 'DisplayName','Iq\_ref');
legend show;
hold on;
grid;
%plot(t2, y2, 'r', 'DisplayName', 'Motore 2');
xlabel('Tempo (s)');
ylabel('Riferimento corrente/coppia Motore 2')
legend;