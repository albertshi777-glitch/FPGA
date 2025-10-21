% ============================================================
% File: expected_pll_subplot_style.m
% 描述: 绘制 expected PLL 输出波形 (subplot + 彩色标签条)
% ------------------------------------------------------------
%  - sys_clk   = 50 MHz 方波     (绿色)
%  - sys_rst_n = 前40ns低电平   (绿色)
%  - vga_clk   = 25 MHz 方波     (红色)
% ============================================================

clear; clc; close all;

%% 参数定义
sys_freq = 50e6;          % 50 MHz
vga_freq = 25e6;
sim_time = 200e-9;        % 仿真时间 200 ns
t_step   = 1e-9;          % 1 ns
t = 0:t_step:sim_time;
cycles = sim_time*1e9;    % 用ns表示横轴范围

%% 信号生成
sys_clk   = square(2*pi*sys_freq*t) > 0;
sys_rst_n = double(t >= 40e-9);  % 前40ns拉低
vga_clk   = square(2*pi*vga_freq*t) > 0;

%% 信号集合（对应名称与颜色）
signals = {sys_clk, sys_rst_n, vga_clk};
names   = {'sys\_clk', 'sys\_rst\_n', 'vga\_clk'};
colors  = {[0.6 1.0 0.6], [0.6 1.0 0.6], [1.0 0.5 0.5]};

%% 绘制
figure('Color','w','Position',[100 100 1100 600]);

for k = 1:3
    subplot(3,1,k);
    hold on; grid on; box on;
    
    % 方波 (黑色stairs)
    stairs(t*1e9, signals{k}, 'k', 'LineWidth', 1.5);
    ylim([-0.2 1.2]);
    xlim([0 cycles]);
    
    set(gca,'YTick',[],'XTick',0:20:cycles);
    xlabel('Time / ns');
    
    % ==== 顶部彩色标签条 ====
    yl = ylim; xl = xlim;
    bar_h = 0.25;  % 条高度
    patch([xl(1) xl(1)+20 xl(1)+20 xl(1)], ...
          [yl(2)-bar_h yl(2)-bar_h yl(2) yl(2)], ...
          colors{k}, 'EdgeColor','none');
    
    % 名称文字（居中位于色块中）
    text(xl(1)+10, yl(2)-bar_h/2, names{k}, ...
        'HorizontalAlignment','center', 'VerticalAlignment','middle', ...
        'FontWeight','bold', 'FontSize',10, 'Interpreter','none');
    
    if k < 3
        set(gca,'XTickLabel',[]);
    end
end

sgtitle('Expected PLL Waveform ');