% 输入序列（000→111）
a   = [0 0 0 0 1 1 1 1]';   % addend
b   = [0 0 1 1 0 0 1 1]';   % augend
cin = [0 1 0 1 0 1 0 1]';   % carry1

% 反向输出
sum_inv  = ~(xor(a, ~xor(b, cin)));
cout_inv = (a & b) | (a & cin) | (b & cin);

% 绘图
x  = 0:8;
st = @(v) [v; v(end)];

figure('Color','w','Name','Expected Outputs ');
subplot(5,1,1);
stairs(x, st(a), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('addend'); grid on; set(gca,'XTickLabel',[]);
title('Expected Outputs ');

subplot(5,1,2);
stairs(x, st(b), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('augend'); grid on; set(gca,'XTickLabel',[]);

subplot(5,1,3);
stairs(x, st(cin), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('carry1'); grid on; set(gca,'XTickLabel',[]);

subplot(5,1,4);
stairs(x, st(sum_inv), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('sum'); grid on; set(gca,'XTickLabel',[]);

subplot(5,1,5);
stairs(x, st(cout_inv), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('carry2'); grid on;
