`timescale 1ns/1ns
module tb_full_adder();

reg Button1, Button2, Button3;
wire Led1, Led2;

Full_Adder Full_Adder_instance(
    .addend(Button1),
    .augend(Button2),
    .carry1(Button3),
    .sum(Led1),
    .carry2(Led2)
);

initial begin
    Button1 <= 1'b0;
    Button2 <= 1'b0;
    Button3 <= 1'b0;
end

always begin
    #10 Button1 <= $random % 2;
    #10 Button2 <= $random % 2;
    #10 Button3 <= $random % 2;
end

endmodule
