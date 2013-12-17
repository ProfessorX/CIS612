%% Introduction
% 20131217 Lab 12:40
% 20131217 Lab 16:40
times = 20;
x = 0: 0.001: 1;
y = 1 - (1-x).^(times);
x1 = x;
y1 = x1;
% A naive plot
plot(x,y)
axis([0,1.1,0,1.1])
hold on;
plot(x1, y1)

