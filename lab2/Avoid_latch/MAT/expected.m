clear; clc; close all;

codes = 0:7;
time_expand = 6;        
N = numel(codes);
M = N*time_expand;
t = 0:M-1;

bits = repelem(codes,time_expand);
in3 = bitget(bits,1);
in2 = bitget(bits,2);
in1 = bitget(bits,3);

ideal  = {'0','1','2','3','4','5','6','7'};
l1     = {'0','1','2','3','4','5','6','7'};
l2     = {'0','1','2','3','4','5','6','X'};
l3     = {'0','1','2','3','4','5','6','7'};
names  = {'Ideal Output','Latch_1','Latch_2','Latch_3'};
vals   = {ideal,l1,l2,l3};
lw = 1.4;
fontsz = 11;

figure('Color','w','Name','3‑8 Decoder – Inputs & Outputs');

subplot(5,1,1);
hold on; box on;
stairs(t,in1*0.2+0.8,'k','LineWidth',lw)
stairs(t,in2*0.2+0.45,'k','LineWidth',lw)
stairs(t,in3*0.2+0.1,'k','LineWidth',lw)
ylim([-0.1 1.2]); yticks([]); xticks([]); xlim([0 M]);

lb_w = 9; lb_h = 0.22; 
rectangle('Position',[1 1.0 lb_w lb_h],'FaceColor',[0 0.8 0.3],'EdgeColor','none','Curvature',0.05);
text(1+lb_w/2,1.0+lb_h/2,'Input (in1 in2 in3)', ...
     'HorizontalAlignment','center','VerticalAlignment','middle', ...
     'FontWeight','bold','FontSize',10,'Color','k');

lblColor = [1 0.3 0.3];     
block_h = 0.8; y0 = 0.1;

for i = 1:4
    subplot(5,1,i+1);
    hold on; box on;
    ylim([-0.1 1.2]); yticks([]); xticks([]); xlim([0 M]);
    v = vals{i};

y0 = 0.18;          
block_h = 0.55;     

for k = 1:N
    x0 = (k-1)*time_expand;
    x1 = k*time_expand;
    rectangle('Position',[x0 y0 (x1-x0) block_h], ...
              'EdgeColor','k','LineWidth',1.2,'FaceColor','none');
    text((x0+x1)/2, y0+block_h/2, v{k}, ...
         'HorizontalAlignment','center','VerticalAlignment','middle', ...
         'FontWeight','bold','FontSize',fontsz,'Color','k');
end
    rectangle('Position',[1 1.0 7 0.25], 'FaceColor', lblColor, 'EdgeColor','none','Curvature',0.05);
    text(1+3.5, 1.0+0.25/2, names{i}, ...
         'HorizontalAlignment','center','VerticalAlignment','middle', ...
         'FontWeight','bold','FontSize',10,'Color','k');
end