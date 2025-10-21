% ============================================
% VGA 参数
% ============================================
H_SYNC  = 96;      % 同步脉冲
H_BACK  = 48;      % 消隐后沿
H_VALID = 640;     % 有效区
H_FRONT = 16;      % 消隐前沿
H_TOTAL = H_SYNC + H_BACK + H_VALID + H_FRONT;

V_SYNC  = 2;
V_BACK  = 33;
V_VALID = 480;
V_FRONT = 10;
V_TOTAL = V_SYNC + V_BACK + V_VALID + V_FRONT;

% 模拟时钟周期
clk_period = 40e-9; % 25MHz
num_cycles = H_TOTAL * 3; % 模拟3行

% ============================================
% 生成行扫描信号
% ============================================
cnt_h = 0:H_TOTAL-1;
cnt_v = [0 1 2]; % 模拟3行

% 时钟波形
t = (0:length(cnt_h)*length(cnt_v)-1) * clk_period;
vga_clk = repmat([0 1], 1, length(t)/2);

% 生成 hsync 信号 (低有效)
hsync_line = zeros(1, length(cnt_h));
hsync_line(1:H_SYNC) = 1;
hsync = repmat(hsync_line, 1, length(cnt_v));

% 生成 vsync 信号 (低有效)
vsync = zeros(1, length(t));
vsync(1:V_SYNC*H_TOTAL) = 1;

% 生成有效显示区标志
rgb_valid_line = zeros(1, length(cnt_h));
rgb_valid_line(H_SYNC+H_BACK+1:H_SYNC+H_BACK+H_VALID) = 1;
rgb_valid = repmat(rgb_valid_line, 1, length(cnt_v));

% 生成 pix_x / pix_y
pix_x = repmat(0:H_TOTAL-1, 1, length(cnt_v));
pix_y = repelem(cnt_v, H_TOTAL);

pix_x(~rgb_valid) = NaN; % 无效区不显示
pix_y(~rgb_valid) = NaN;

% 生成 pix_data (模拟输出)
pix_data = zeros(size(rgb_valid));
pix_data(rgb_valid == 1) = randi([0, 65535], [1, sum(rgb_valid)]); % 模拟色彩数据

% ============================================
% 绘图
% ============================================
figure('Color','w','Position',[100 100 1000 700]);

subplot(6,1,1);
plot(t*1e6, vga_clk(1:length(t)),'k');
title('vga\_clk (25MHz)');
ylabel('clk'); grid on; ylim([-0.5,1.5]);

subplot(6,1,2);
plot(t*1e6, hsync,'LineWidth',1.5);
title('hsync'); ylabel('hsync'); ylim([-0.2,1.2]); grid on;

subplot(6,1,3);
plot(t*1e6, vsync,'LineWidth',1.5);
title('vsync'); ylabel('vsync'); ylim([-0.2,1.2]); grid on;

subplot(6,1,4);
plot(t*1e6, rgb_valid,'g','LineWidth',1.5);
title('rgb\_valid'); ylabel('valid'); ylim([-0.2,1.2]); grid on;

subplot(6,1,5);
plot(t*1e6, pix_x,'b'); hold on;
plot(t*1e6, pix_y,'r');
legend('pix\_x','pix\_y');
title('像素扫描坐标');
ylabel('坐标值'); grid on;

subplot(6,1,6);
plot(t*1e6, pix_data,'m');
title('pix\_data[15:0]');
xlabel('时间 (\mus)'); ylabel('RGB565'); grid on;