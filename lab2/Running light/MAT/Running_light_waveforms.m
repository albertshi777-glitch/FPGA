
N = 3;             
cycles = 60;          
t = 0:cycles-1;       

sys_clk   = zeros(1, cycles);
sys_rst_n = ones(1, cycles);
cnt       = zeros(1, cycles);
led0      = ones(1, cycles); 
led1      = ones(1, cycles);
led2      = ones(1, cycles);
led3      = ones(1, cycles);

for i = 1:cycles
    sys_clk(i) = mod(i,2); 
end

sys_rst_n(20:22) = 0;  

cnt_val   = 0;
led_index = 0; 
for i = 2:cycles
    if sys_rst_n(i) == 0
        cnt_val   = 0;
        led_index = 0;
    else
        if sys_clk(i) == 1 && sys_clk(i-1) == 0 
            if cnt_val == N-1
                cnt_val   = 0;
                led_index = mod(led_index+1,4); 
            else
                cnt_val = cnt_val + 1;
            end
        end
    end

    cnt(i) = cnt_val;

    led0(i) = 1; led1(i) = 1; led2(i) = 1; led3(i) = 1;
    switch led_index
        case 0, led0(i) = 0;
        case 1, led1(i) = 0;
        case 2, led2(i) = 0;
        case 3, led3(i) = 0;
    end
end

figure;
signals = {sys_clk, sys_rst_n, cnt, led0, led1, led2, led3};
names   = {'sys_clk','sys_rst_n','cnt','led0','led1','led2','led3'};
colors  = {[0.6 1 0.6],[0.6 1 0.6],[1 1 0.2],...
           [1 0.4 0.4],[1 0.4 0.4],[1 0.4 0.4],[1 0.4 0.4]};

for k = 1:numel(signals)
    subplot(numel(signals),1,k);
    stairs(t, signals{k}, 'k','LineWidth',1.5); 
    ylim([-0.2 max(signals{k})+1]); xlim([0 cycles])
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