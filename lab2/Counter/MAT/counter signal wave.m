N = 4;                 
cycles = 30;           
t = 0:cycles-1;        

sys_clk   = zeros(1, cycles);
sys_rst_n = ones(1, cycles);
cnt       = zeros(1, cycles);
led_out   = zeros(1, cycles);

for i = 1:cycles
    sys_clk(i) = mod(i,2); 
end

sys_rst_n(8:9) = 0;   
sys_rst_n(20:21) = 0; 

cnt_val   = 0;
led_state = 0;   

for i = 2:cycles
    if sys_rst_n(i) == 0
        cnt_val   = 0;
        led_state = 0;
    else
        if sys_clk(i) == 1 && sys_clk(i-1) == 0 
            if cnt_val == N-1
                cnt_val   = 0;
                led_state = ~led_state; 
            else
                cnt_val = cnt_val + 1;
            end
        end
    end
    cnt(i)     = cnt_val;
    led_out(i) = led_state;
end

figure;
signals = {sys_clk, sys_rst_n, cnt, led_out};
names   = {'sys\_clk','sys\_rst\_n','cnt','led\_out'};
colors  = {[0.6 1 0.6],[0.6 1 0.6],[1 1 0.2],[1 0.4 0.4]};

for k = 1:4
    subplot(4,1,k);
    stairs(t, signals{k}, 'k','LineWidth',1.5); 
    ylim([-0.2 max(signals{k})+1]); 
    xlim([0 cycles])
    grid on;
    set(gca,'YTick',[],'XTick',0:5:cycles);
    
    yl = ylim; xl = xlim;
    patch([xl(1), xl(1)+5, xl(1)+5, xl(1)], ...
          [yl(2)-0.3, yl(2)-0.3, yl(2), yl(2)], ...
          colors{k}, 'EdgeColor','none');
    text(xl(1)+2.5, yl(2)-0.15, names{k}, ...
        'HorizontalAlignment','center','VerticalAlignment','middle', ...
        'FontWeight','bold','Interpreter','none');
end