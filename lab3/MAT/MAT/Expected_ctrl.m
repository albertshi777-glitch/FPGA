% ========================================================================
% File: draw_vga_ctrl_waveform_exact.m
% 功能: 完整还原 VGA 控制器理论波形图 (去除红色虚线，保持比例一致)
% 作者: GPT-5 Chat
% ========================================================================

clear; clc; close all;

%% ---------------- VGA Timing Parameters (比例依据) ----------------
% 各段逻辑长度
H_SYNC   = 96;
H_BACK   = 48;  % back + left margin
H_ACTIVE = 640;
H_FRONT  = 16;
H_TOTAL  = H_SYNC + H_BACK + H_ACTIVE + H_FRONT;

% 横向归一化比例
ratio = [H_SYNC, H_BACK, H_ACTIVE, H_FRONT] / H_TOTAL;
x_pos = [0 cumsum(ratio)];
% 对应段落：同步区、后沿区、有效显示、前沿区、下周期起点

%% ---------------- 信号排列及颜色 ----------------
signals = {'vga\_clk','sys\_rst\_n','pix\_data', ...
           'cnt\_h','cnt\_v','rgb\_valid','pix\_data\_req', ...
           'pix\_x','pix\_y','hsync','vsync','rgb'};

colors = { [0.4 1 0.4], [0.6 1 0.6], [0.6 1 0.6], ...   % green group
           [1 1 0.4], [1 1 0.4], [1 1 0.4], [1 1 0.4], ... % yellow group
           [1 0.4 0.4], [1 0.4 0.4], [1 0.4 0.4], [1 0.4 0.4], [1 0.4 0.4] }; % red group

nSig = numel(signals);
stepH = 1.5;
barW = 0.12; barX = -0.17;

%% ---------------- 基础绘图环境 ----------------
figure('Color','w','Position',[100 80 1600 950]); hold on;
axis off; 
xlim([-0.2 1.05]); 
ylim([-0.5 stepH*(nSig+0.5)]);

%% ---------------- 左侧信号栏 ----------------
for i = 1:nSig
    y = (nSig-i+1)*stepH;
    patch([barX barX+barW barX+barW barX], ...
          [y-0.45 y-0.45 y+0.45 y+0.45], colors{i}, 'EdgeColor','none');
    text(barX+barW/2, y, signals{i}, ...
         'HorizontalAlignment','center','FontWeight','bold', ...
         'Interpreter','none','FontSize',10);
end

%% ---------------- 波形绘制函数 (方波生成) ----------------
drawWave = @(x0,y0,pattern) ...
    arrayfun(@(k) plot([x0(k) x0(k+1)],y0+pattern(k)*[0 0],'k','LineWidth',1.6),1:length(x0)-1);

drawEdge = @(x,y0,y1) plot([x x],[y0 y1],'k','LineWidth',1.2);

%% ---------------- 绘制各信号 ----------------

% 1) vga_clk
y=(nSig-0)*stepH;
xx = linspace(x_pos(1), x_pos(4), 20);
clk_pattern = repmat([0 1],1,10);
for k=1:length(clk_pattern)-1
    yL = y-0.15 + 0.6*clk_pattern(k);
    plot([xx(k) xx(k+1)],[yL yL],'k','LineWidth',1.2);
    if clk_pattern(k)~=clk_pattern(k+1)
        drawEdge(xx(k+1), y-0.15, y+0.45);
    end
end

% 2) sys_rst_n
y=(nSig-1)*stepH;
plot([x_pos(1) x_pos(2)],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(end)],[y+0.4 y+0.4],'k','LineWidth',1.6);
drawEdge(x_pos(2),y-0.2,y+0.4);
text(x_pos(1)+0.02,y-0.4,'Reset low','FontSize',9);

% 3) pix_data
y=(nSig-2)*stepH;
plot([x_pos(1) x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);

% 4) cnt_h
y=(nSig-3)*stepH;
plot([x_pos(1) x_pos(2)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(3)],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(3) x_pos(4)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(4) x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text((x_pos(1)+x_pos(2))/2,y+0.5,'0–95','FontSize',9,'HorizontalAlignment','center');
text((x_pos(2)+x_pos(3))/2,y+0.5,'144–782','FontSize',9,'HorizontalAlignment','center');
text((x_pos(3)+x_pos(4))/2,y+0.5,'783–799','FontSize',9,'HorizontalAlignment','center');

% 5) cnt_v
y=(nSig-4)*stepH;
plot([x_pos(1) x_pos(2)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(4)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text((x_pos(1)+x_pos(2))/2,y+0.5,'0','FontSize',9,'HorizontalAlignment','center');
text((x_pos(2)+x_pos(4))/2,y+0.5,'1','FontSize',9,'HorizontalAlignment','center');

% 6) rgb_valid
y=(nSig-5)*stepH;
plot([x_pos(1) x_pos(2)],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(3)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(3) x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text((x_pos(2)+x_pos(3))/2,y+0.55,'有效显示区 (像素有效)','FontSize',9,'HorizontalAlignment','center');

% 7) pix_data_req
y=(nSig-6)*stepH;
shift = 0.015; % 提前1clk
plot([x_pos(1) x_pos(2)-shift],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(2)-shift x_pos(3)-shift],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(3)-shift x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text(x_pos(2)+0.03,y+0.55,'提前1clk触发','FontSize',9,'HorizontalAlignment','center');

% 8) pix_x
y=(nSig-7)*stepH;
plot([x_pos(1) x_pos(2)],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(3)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(3) x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text((x_pos(2)+x_pos(3))/2,y-0.55,'0–639','HorizontalAlignment','center');

% 9) pix_y
y=(nSig-8)*stepH;
plot([x_pos(1) x_pos(2)],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(3)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(3) x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text((x_pos(2)+x_pos(3))/2,y-0.55,'0–479','HorizontalAlignment','center');

% 10) hsync
y=(nSig-9)*stepH;
plot([x_pos(1) x_pos(1)+ratio(1)*0.6],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(1)+ratio(1)*0.6 x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);

% 11) vsync
y=(nSig-10)*stepH;
plot([x_pos(1) x_pos(1)+ratio(1)*0.4],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(1)+ratio(1)*0.4 x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);

% 12) rgb
y=(nSig-11)*stepH;
plot([x_pos(1) x_pos(2)],[y-0.2 y-0.2],'k','LineWidth',1.6);
plot([x_pos(2) x_pos(3)],[y+0.4 y+0.4],'k','LineWidth',1.6);
plot([x_pos(3) x_pos(end)],[y-0.2 y-0.2],'k','LineWidth',1.6);
text((x_pos(2)+x_pos(3))/2,y-0.55,'p1\_data','FontSize',9,'HorizontalAlignment','center');

%% ---------------- 底部说明 ----------------
text(0.5,-0.3,'每行包含：H\_SYNC、后沿、有效显示、前沿', ...
    'HorizontalAlignment','center','FontAngle','italic');
title('VGA 控制器理论输出时序 (去除红色虚线)','FontWeight','bold','FontSize',12);