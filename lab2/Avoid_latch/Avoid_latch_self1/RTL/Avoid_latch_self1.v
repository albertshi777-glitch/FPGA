module Avoid_latch_self1
(
input wire in1,
input wire in2,
input wire in3,
output reg [7:0] out
);

always@(*)
if({in1,in2,in3}==3'b000)
out=8'b000_0001;
else if({in1,in2,in3}==3'b001)
out=8'b000_0010;
else if({in1,in2,in3}==3'b010)
out=8'b000_0100;
else if({in1,in2,in3}==3'b011)
out=8'b000_1000;
else if({in1,in2,in3}==3'b100)
out=8'b000_0000;
else if({in1,in2,in3}==3'b101)
out=8'b000_0000;
else if({in1,in2,in3}==3'b110)
out=8'b000_0000;
else if({in1,in2,in3}==3'b111)
out=8'b000_0000;
else 
out=8'b000_0001;
endmodule