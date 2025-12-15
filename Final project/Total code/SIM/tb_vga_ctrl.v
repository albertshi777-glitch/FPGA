`timescale 1ns/1ps

module tb_vga_ctrl();
reg artificial_vga_clk;
reg artificial_sys_rst_n;
reg [15:0] artificial_pix_data;

wire [9:0] recorder_pix_x;
wire [9:0] recorder_pix_y;
wire recorder_hsync;
wire recorder_vsync;
wire [15:0] recorder_rgb;

initial begin
    artificial_vga_clk   <= 1'b0;
    artificial_sys_rst_n <= 1'b0;
    artificial_pix_data  <= 16'hF800; 
    #200;
    artificial_sys_rst_n <= 1'b1;
end

always begin
    #20 artificial_vga_clk <= ~artificial_vga_clk;
end

vga_ctrl vga_ctrl_inst(
    .vga_clk   (artificial_vga_clk),
    .sys_rst_n (artificial_sys_rst_n),
    .pix_data  (artificial_pix_data),
    .pix_x     (recorder_pix_x),
    .pix_y     (recorder_pix_y),
    .hsync     (recorder_hsync),
    .vsync     (recorder_vsync),
    .rgb       (recorder_rgb)
);





endmodule