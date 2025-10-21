%% ============================================
% 模块: VGA Display expected waveform (两帧周期)
% 作者: ChatGPT
% 功能: 绘制 vga_display 模块主要信号波形
%% ============================================
clear; clc; close all;

%% ===== VGA 参数 =====
H_SYNC  = 96;
H_BACK  = 40;
H_LEFT  = 8;
H_VALID = 640;
H_TOTAL = 800;

V_SYNC  = 2;
V_BACK  = 25;
V_TOP   = 8;
V_VALID = 480;
V_TOTAL = 525;

vga_clk_freq = 25e6;      % 25 MHz
t_step = 1 / vga_clk_freq;

% 仿真两帧时间
frame_time = H_TOTAL * V_TOTAL * t_step;   % 一帧 ≈ 16.8 ms
sim_time = 2 * frame_time;                 % 两帧 ≈ 33.6 ms
t = 0:t_step:sim_time;
N = length(t);

%% ===== 初始化 =====
cnt_h = zeros(1,N);
cnt_v = zeros(1,N);
hsync = zeros(1,N);
vsync = zeros(1,N);
pix_x = zeros(1,N);
pix_y = zeros(1,N);
pix_data = zeros(1,N);

%% ===== VGA 控制时序仿真 =====
for i = 2:N
    % 水平扫描计数
    if cnt_h(i-1) == H_TOTAL-1
        cnt_h(i) = 0;
        % 垂直扫描计数
        if cnt_v(i-1) == V_TOTAL-1
            cnt_v(i) = 0;
        else
            cnt_v(i) = cnt_v(i-1) + 1;
        end
    else
        cnt_h(i) = cnt_h(i-1) + 1;
        cnt_v(i) = cnt_v(i-1);
    end
    
    % 行同步
    hsync(i) = double(cnt_h(i) < H_SYNC);
    % 场同步
    vsync(i) = double(cnt_v(i) < V_SYNC);

    % 有效区判断
    rgb_valid = (cnt_h(i) >= (H_SYNC + H_BACK + H_LEFT)) && ...
                (cnt_h(i) <  (H_SYNC + H_BACK + H_LEFT + H_VALID)) && ...
                (cnt_v(i) >= (V_SYNC + V_BACK + V_TOP)) && ...
                (cnt_v(i) <  (V_SYNC + V_BACK + V_TOP + V_VALID));

    % 坐标输出
    if rgb_valid
        pix_x(i) = cnt_h(i) - (H_SYNC + H_BACK + H_LEFT);
        pix_y(i) = cnt_v(i) - (V_SYNC + V_BACK + V_TOP);
    else
        pix_x(i) = 1023;
        pix_y(i) = 1023;
    end

    % 简化的 VGA_PIC 彩条逻辑
    if rgb_valid
        region = floor(pix_x(i)/80);
        colors = [hex2dec('F800'); hex2dec('07E0'); hex2dec('001F'); ...
                  hex2dec('FFE0'); hex2dec('F81F'); hex2dec('07FF'); ...
                  hex2dec('FFFF'); hex2dec('0000')];
        pix_data(i) = colors(mod(region,8)+1);
    else
        pix_data(i) = 0;
    end
end

vga_clk = square(2*pi*vga_clk_freq*t);

%% ===== 绘制波形 =====
figure('Position',[100 100 1000 900]);

subplot(6,1,1);
plot(t*1e3, vga_clk, 'k');
ylim([-1.5 1.5]); ylabel('vga\_clk');
title('像素时钟 (25 MHz)');
grid on;

subplot(6,1,2);
plot(t*1e3, hsync, 'b');
ylim([-0.2 1.2]); ylabel('hsync');
title('行同步信号');
grid on;

subplot(6,1,3);
plot(t*1e3, vsync, 'c');
ylim([-0.2 1.2]); ylabel('vsync');
title('场同步信号');
grid on;

subplot(6,1,4);
plot(t*1e3, pix_x, 'b');
ylabel('pix\_x');
title('像素 X 坐标扫描');
grid on;

subplot(6,1,5);
plot(t*1e3, pix_y, 'r');
ylabel('pix\_y');
title('像素 Y 坐标扫描');
grid on;

subplot(6,1,6);
plot(t*1e3, pix_data, 'm');
ylabel('pix\_data');
xlabel('时间 (ms)');
title('RGB565');
grid on;

sgtitle('VGA expected output');