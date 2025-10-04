`timescale 1ps/1ps
module tb_counter();

reg sys_clk;
reg sys_rst_n;       
wire led_out;            
wire [24:0] cnt;

counter counter_instance (
     .sys_clk(sys_clk),
     .sys_rst_n(sys_rst_n),
     .led_out(led_out),
     .cnt(cnt)
);

 initial begin
   sys_clk = 1'b0;
   sys_rst_n = 1'b0;	
	#2000 sys_rst_n = 1'b1;
	
 end

always begin
	#10 sys_clk = ~sys_clk;
	 
end


initial begin
	$timeformat(-12, 0, " ps", 6); 
   $monitor("@time %t: sys_clk= %b sys_rst_n=%b cnt=%d led_out= %b", $time , sys_clk, sys_rst_n, cnt, led_out);
end


endmodule