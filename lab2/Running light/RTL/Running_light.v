module Running_light
(
input wire sys_clk,
input wire sys_rst_n,
output reg led0,
output reg led1,
output reg led2,
output reg led3,
output reg [24:0] cnt
);

reg [3:0] LED;

always@(posedge sys_clk or negedge sys_rst_n)begin
if(sys_rst_n == 1'b0)
LED <= 4'b1110;
else if(cnt ==25000000-1)
LED<= {LED[2:0],LED[3]} ;

end

always@(posedge sys_clk or negedge sys_rst_n)begin
if(sys_rst_n == 1'b0)
cnt<=0;
else if (cnt== 25000000-1)
cnt<=0;
else
cnt <= cnt+1;
end

always@(posedge sys_clk or negedge sys_rst_n)begin
if(sys_rst_n == 1'b0)begin
led0<=1'b0;
led1<=1'b1;
led2<=1'b1;
led3<=1'b1;
end
else begin
led0 <= LED[0];
led1 <= LED[1];
led2 <= LED[2];
led3 <= LED[3];
end
end

endmodule