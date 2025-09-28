
`timescale 1ns/1ns
module tb_comparator();

reg Button1, Button2;
wire Led1, Led2, Led3;

comparator comparator_instance(
	.A(Button1),
	.B(Button2),
	.L1(Led1),
	.L2(Led2),
	.L3(Led3)
);

initial begin
    Button1 <= 1'b0;
    Button2 <= 1'b0;
end

always begin
    #10 Button1 <= $random % 2;
    #10 Button2 <= $random % 2;
end

endmodule