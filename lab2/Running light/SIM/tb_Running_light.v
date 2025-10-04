`timescale 1ps/1ps
module tb_Running_light();
reg sys_clk;
reg sys_rst_n;
wire led0, led1, led2, led3;
wire [24:0] cnt;

Running_light Running_light_instance (
   .sys_clk(sys_clk),
   .sys_rst_n(sys_rst_n),
   .led0(led0),
   .led1(led1),
   .led2(led2),
   .led3(led3),
   .cnt(cnt)
);

initial begin
   sys_clk = 1'b0; 
   sys_rst_n = 1'b0;       
   #100 sys_rst_n = 1'b1;  
end

always #10 sys_clk = ~sys_clk;

initial begin
   $timeformat(-12, 0, " ps", 6); 
   $monitor("time %t: sys_clk=%b sys_rst_n= %b cnt= %d led3= %b led2= %b led1= %b led0= %b",$time, sys_clk, sys_rst_n, cnt, led3, led2, led1, led0);
end

endmodule