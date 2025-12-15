`timescale 1ns/1ps

module tb_vga_pic();
reg artificial_vga_clk;
reg artificial_sys_rst_n;
reg [9:0] artificial_pix_x;
reg [9:0] artificial_pix_y;
reg [1:0] artificial_mode_sel;
wire [15:0] recorder_pix_data;

initial begin
    artificial_vga_clk   <= 1'b0;
    artificial_sys_rst_n <= 1'b0;
    artificial_pix_x     <= 10'd0;
    artificial_pix_y     <= 10'd0;
	 artificial_mode_sel  <= 2'd0;

    #200;
    artificial_sys_rst_n <= 1'b1;
end

always begin
    #20 artificial_vga_clk <= ~artificial_vga_clk;
end

always @(posedge artificial_vga_clk or negedge artificial_sys_rst_n) begin
    if (!artificial_sys_rst_n) begin
        artificial_pix_x <= 10'd0;
        artificial_pix_y <= 10'd0;
    end
    else if (artificial_pix_x == 10'd639) begin
        artificial_pix_x <= 10'd0;
        if (artificial_pix_y == 10'd479)
            artificial_pix_y <= 10'd0;
        else
            artificial_pix_y <= artificial_pix_y + 1'd1;
    end
    else begin
        artificial_pix_x <= artificial_pix_x + 1'd1;
    end
end

    initial begin
        // 在仿真过程切换不同显示内容
        #50000   artificial_mode_sel <= 2'd0;   // 彩条
        #200000  artificial_mode_sel <= 2'd1;   // Game
        #200000  artificial_mode_sel <= 2'd2;   // END
        #200000  $finish;
    end



vga_pic vga_pic_inst(
    .vga_clk  (artificial_vga_clk),
    .sys_rst_n(artificial_sys_rst_n),
    .pix_x    (artificial_pix_x),
    .pix_y    (artificial_pix_y),
	 .mode_sel  (artificial_mode_sel),
    .pix_data (recorder_pix_data)
);

endmodule