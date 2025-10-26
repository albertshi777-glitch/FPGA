/* verilator lint_off UNUSED */
/* verilator lint_off UNDRIVEN */
`timescale 1ns / 1ns

module DevelopmentBoard(
    input wire clk, //50MHz
    input wire reset,B2, B3, B4, B5,
	 // reset is "a"
	 // B2 is "s"
	 // B3 is "d"
	 // B4 is "f"
	 // B5 is "g"
    output wire h_sync, v_sync,
    output wire [15:0] rgb,
	
	output wire led1,
	output wire led2,
	output wire led3,
	output wire led4,
	output wire led5
);

	// Instantiate your model
	 vga_display vga_display_inst(
		.sys_clk(clk),
		.sys_rst_n(reset),
		.hsync(h_sync),
		.vsync(v_sync),
		.rgb(rgb)
	 	//.up(B2),
	 	//.down(B3),
		//.left(B4),
	 	//.right(B5),
	 	//.led1(led1),
		//.led2(led2),
	 	//.led3(led3),
	 	//.led4(led4),
	 	//.led5(led5)
	 );
    
assign led1 = 1'b0;
assign led2 = 1'b0;
assign led3 = 1'b0;
assign led4 = 1'b0;
assign led5 = 1'b0;

endmodule
/* verilator lint_on UNUSED */
/* verilator lint_on UNDRIVEN */