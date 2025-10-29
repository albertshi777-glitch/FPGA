
`timescale 1ns/1ps

module tb_vga_display();
reg artificial_sys_clk;
reg artificial_sys_rst_n;
reg [1:0] artificial_mode_sel;

wire recorder_hsync;
wire recorder_vsync;
wire [15:0] recorder_rgb;

initial begin
    artificial_sys_clk   <= 1'b0;
    artificial_sys_rst_n <= 1'b0;

    #200;
    artificial_sys_rst_n <= 1'b1;
end

always begin
    #10 artificial_sys_clk <= ~artificial_sys_clk;
end

    initial begin
        #50000  artificial_mode_sel <= 2'd0; // 彩条
        #100000 artificial_mode_sel <= 2'd1; // MUST
        #100000 artificial_mode_sel <= 2'd2; // END
        #100000 artificial_mode_sel <= 2'd3; // 备用
        #100000 $finish;
    end

vga_display vga_display_inst (
    .sys_clk   (artificial_sys_clk),
    .sys_rst_n (artificial_sys_rst_n),
	 .mode_sel  (artificial_mode_sel),
    .hsync     (recorder_hsync),
    .vsync     (recorder_vsync),
    .rgb       (recorder_rgb)
);


				 
endmodule
