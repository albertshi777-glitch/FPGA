A  = [0 0 1 1]';
B  = [0 1 0 1]';

L1 = A | ~B;
L2 = xor(A, B);
L3 = ~A | B;
st = @(v) [v; v(end)];
x  = 0:numel(A);

figure('Color','w','Name','Digital Square (Truth Sequence)');
sgtitle('Expected Outputs');  

subplot(5,1,1); stairs(x, st(A ), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('A');  grid on; set(gca,'XTickLabel',[]);

subplot(5,1,2); stairs(x, st(B ), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('B');  grid on; set(gca,'XTickLabel',[]);

subplot(5,1,3); stairs(x, st(L1), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('L1'); grid on; set(gca,'XTickLabel',[]);

subplot(5,1,4); stairs(x, st(L2), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('L2'); grid on; set(gca,'XTickLabel',[]);

subplot(5,1,5); stairs(x, st(L3), 'k','LineWidth',1.6);
ylim([-0.2 1.2]); ylabel('L3'); grid on; 