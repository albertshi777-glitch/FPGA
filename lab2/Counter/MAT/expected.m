
f_clk = 10;       
T_clk = 1/f_clk;  

f_led = 1;         
T_led = 1/f_led;   

t = 0:0.001:5;   

sys_clk = square(2*pi*f_clk*t, 50);
sys_clk = (sys_clk+1)/2;

led_out = square(2*pi*f_led*t, 50);
led_out = (led_out+1)/2;

sys_rst_n = ones(size(t));
sys_rst_n(t < 0.2) = 0;

figure;
subplot(3,1,1);
plot(t, sys_clk, 'k-', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('sys\_clk', 'Color', [0 0.6 0]); 
ylim([-0.2 1.2]);
grid on;

subplot(3,1,2);
plot(t, sys_rst_n, 'k--', 'LineWidth', 1.5);
xlabel('Time (s)');
ylabel('reset', 'Color', [0 0.6 0]);    
ylim([-0.2 1.2]);
grid on;

subplot(3,1,3);
plot(t, led_out, 'k-.', 'LineWidth', 2);
xlabel('Time (s)');
ylabel('LED', 'Color', [1 0 0]);       
ylim([-0.2 1.2]);
grid on;

sgtitle('Counter', 'Color', 'k');