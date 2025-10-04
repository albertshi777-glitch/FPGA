module counter
(
	input wire sys_clk,
	input wire sys_rst_n,
	output reg led_out,
	output reg [24:0] cnt
);

always@(posedge sys_clk or negedge sys_rst_n)begin
	if(sys_rst_n == 1'b0)
		led_out <= 1'b0;
	else if(cnt ==25000000-1)
		 led_out <=~led_out;
end

always@(posedge sys_clk or negedge sys_rst_n)begin
	if(sys_rst_n == 1'b0)
		cnt<=0;
	else if (cnt== 25000000-1)
				cnt<=0;
	else
		cnt <= cnt+1;
end

endmodule