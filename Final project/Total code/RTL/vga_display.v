
module vga_display(
input wire sys_clk,
input wire sys_rst_n, 
input  wire [1:0]  mode_sel, 
input wire B3,  // D -> 右移
input wire B4,  // F -> 左移
output wire hsync, 
output wire vsync, 
output wire [15:0] rgb,
    output wire led1,
    output wire led2,
    output wire led3,
    output wire led4,
    output wire led5

);

 wire vga_clk ; 
 wire [9:0] pix_x ; 
 wire [9:0] pix_y ; 
 wire [15:0] pix_data; 
 wire game_over_flag_pic;
 

 
 pll pll_inst
 (
 .sys_clk(sys_clk),
 .sys_rst_n(sys_rst_n),

 .vga_clk(vga_clk)
 );

 vga_pic vga_pic_inst
 (
 .vga_clk (vga_clk ), 
 .sys_rst_n (sys_rst_n ), 
 .pix_x (pix_x ), 
 .pix_y (pix_y ),
 .B3  (B3),
 .B4  (B4),
 .mode_sel  (mode_sel),
 .pix_data (pix_data ),
     .led1(led1),
    .led2(led2),
    .led3(led3),
    .led4(led4),
    .led5(led5)
 );

 vga_ctrl vga_ctrl_inst
 (
 .vga_clk (vga_clk ), 
 .sys_rst_n (sys_rst_n ), 
 .pix_data (pix_data ),
 .pix_x (pix_x ), 
 .pix_y (pix_y ), 
 .hsync (hsync ), 
 .vsync (vsync ), 
 .rgb (rgb ) 
 );

 endmodule
