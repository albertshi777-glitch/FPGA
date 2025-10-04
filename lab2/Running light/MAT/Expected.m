clear; clc;

f_clk = 10;                 
T_sim = 5;                  
t = 0:0.001:T_sim;           

sys_clk = square(2*pi*f_clk*t, 50);
sys_clk = (sys_clk + 1)/2;

sys_rst_n = ones(size(t));
sys_rst_n(t < 0.2) = 0;

cnt = zeros(size(t));
tau = t - 0.2;
idx = tau >= 0;
cnt(idx) = mod(tau(idx) * 100, 50);  

led0 = zeros(size(t)); led1 = led0; led2 = led0; led3 = led0;
k = floor(mod(tau(idx) / 0.5, 4));  
led0(idx) = (k == 0);
led1(idx) = (k == 1);
led2(idx) = (k == 2);
led3(idx) = (k == 3);

figure;

subplot(7,1,1);
plot(t, sys_clk, 'k-', 'LineWidth', 1.2);
ylabel('sys\_clk', 'Color', [0 0.6 0]); ylim([-0.2 1.2]); grid on;

subplot(7,1,2);
plot(t, sys_rst_n, 'k--', 'LineWidth', 1.2);
ylabel('reset', 'Color', [0 0.6 0]); ylim([-0.2 1.2]); grid on;

subplot(7,1,3);
plot(t, cnt, 'k-', 'LineWidth', 1.2);
ylabel('cnt', 'Color', [0.9 0.8 0]); grid on;

subplot(7,1,4);
plot(t, led3, 'k-', 'LineWidth', 1.6);
ylabel('LED3', 'Color', [1 0 0]); ylim([-0.2 1.2]); grid on;

subplot(7,1,5);
plot(t, led2, 'k--', 'LineWidth', 1.6);
ylabel('LED2', 'Color', [1 0 0]); ylim([-0.2 1.2]); grid on;

subplot(7,1,6);
plot(t, led1, 'k-.', 'LineWidth', 1.6);
ylabel('LED1', 'Color', [1 0 0]); ylim([-0.2 1.2]); grid on;

subplot(7,1,7);
plot(t, led0, ':k', 'LineWidth', 1.6);
ylabel('LED0', 'Color', [1 0 0]); xlabel('Time (s)'); ylim([-0.2 1.2]); grid on;

sgtitle('Running Light (Expected)', 'Color', 'k');