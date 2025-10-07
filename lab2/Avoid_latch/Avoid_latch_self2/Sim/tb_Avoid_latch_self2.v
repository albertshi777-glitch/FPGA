`timescale 1ps/1ps 
module tb_Avoid_latch_self2;
    reg in1;
    reg in2;
    reg in3;
    wire [7:0] out;


Avoid_latch_self2 Avoid_latch_self2_instance (
        .in1(in1),
        .in2(in2),
        .in3(in3),
        .out(out)
);

 
integer i;
initial begin
$timeformat(-9,0,"ns",6);
		  $monitor("@time %4t:  in1=%b , in2=%b, in3= %b, out=%b", $time, in1, in2, in3, out);
#5;
for (i = 0; i < 8; i = i + 1) begin
{in1, in2, in3} = i[2:0];
#5;

end
end

endmodule