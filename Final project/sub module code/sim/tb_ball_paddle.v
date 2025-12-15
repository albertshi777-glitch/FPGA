`timescale 1ns/1ps
module tb_ball_paddle();

    //------------------------------------------------------------
    // 信号定义
    //------------------------------------------------------------
    reg  artificial_vga_clk;
    reg  artificial_sys_rst_n;

    reg  signed [10:0] artificial_ball_x_in;
    reg  signed [10:0] artificial_ball_y_in;
    reg  signed [5:0]  artificial_vx_in;
    reg  signed [5:0]  artificial_vy_in;

    reg  [9:0] artificial_paddle_x_in;
    reg  [9:0] artificial_paddle_w_in;

    wire signed [10:0] recorder_ball_x_out;
    wire signed [10:0] recorder_ball_y_out;
    wire signed [5:0]  recorder_vx_out;
    wire signed [5:0]  recorder_vy_out;
    wire [9:0]          recorder_paddle_w_out;
    wire                recorder_hit_flag;

    //------------------------------------------------------------
    // 实例化 DUT （被测模块）
    //------------------------------------------------------------
    ball_paddle uut (
        .clk          (artificial_vga_clk),
        .rst_n        (artificial_sys_rst_n),
        .ball_x_in    (artificial_ball_x_in),
        .ball_y_in    (artificial_ball_y_in),
        .vx_in        (artificial_vx_in),
        .vy_in        (artificial_vy_in),
        .paddle_x_in  (artificial_paddle_x_in),
        .paddle_w_in  (artificial_paddle_w_in),
        .ball_x_out   (recorder_ball_x_out),
        .ball_y_out   (recorder_ball_y_out),
        .vx_out       (recorder_vx_out),
        .vy_out       (recorder_vy_out),
        .paddle_w_out (recorder_paddle_w_out),
        .hit_flag     (recorder_hit_flag)
    );

    //------------------------------------------------------------
    // 时钟与复位
    //------------------------------------------------------------
    initial begin
        artificial_vga_clk   = 1'b0;
        artificial_sys_rst_n = 1'b0;
        #100;
        artificial_sys_rst_n = 1'b1;
    end

    always #10 artificial_vga_clk = ~artificial_vga_clk;  // 50 MHz 时钟


    //------------------------------------------------------------
    // 初始化与测试序列：
    // 1. 中心撞击
    // 2. 左侧撞击
    // 3. 右侧撞击
    // 4. 未命中（Miss）
    //------------------------------------------------------------
    initial begin
        // 初始化小球与挡板
        artificial_ball_x_in  = 11'd320;
        artificial_ball_y_in  = 11'd200;
        artificial_vx_in      = 6'd0;
        artificial_vy_in      = 6'd4;
        artificial_paddle_x_in = 10'd320;
        artificial_paddle_w_in = 10'd120;  // 初始宽度

        // 等待复位释放
        wait (artificial_sys_rst_n == 1);

        //------------------------------------------------
        // Case 1：中心撞击（垂直反弹）
        //------------------------------------------------
        #20000;  // 20 µs 下落到挡板位置
        artificial_ball_x_in  = 11'd320;
        artificial_vy_in      = 6'd4;
        #40000;  // 40 µs 模拟反弹周期

        //------------------------------------------------
        // Case 2：左侧撞击
        //------------------------------------------------
        artificial_ball_x_in  = 11'd270;   // 偏左
        artificial_vy_in      = 6'd4;
        #40000;

        //------------------------------------------------
        // Case 3：右侧撞击
        //------------------------------------------------
        artificial_ball_x_in  = 11'd370;   // 偏右
        artificial_vy_in      = 6'd4;
        #40000;

        //------------------------------------------------
        // Case 4：未命中
        //------------------------------------------------
        artificial_ball_x_in  = 11'd460;   // 右外侧，不命中
        artificial_vy_in      = 6'd4;
        #40000;

        //------------------------------------------------
        // 结束仿真
        //------------------------------------------------
        #20000;
        $stop;
    end

    //------------------------------------------------------------
    // 连续更新输入 —— 让下一拍位置接前一拍输出
    //------------------------------------------------------------
    always @(posedge artificial_vga_clk or negedge artificial_sys_rst_n) begin
        if (!artificial_sys_rst_n) begin
            artificial_ball_x_in   <= 11'd320;
            artificial_ball_y_in   <= 11'd200;
            artificial_paddle_w_in <= 10'd120;
        end else begin
            artificial_ball_x_in   <= recorder_ball_x_out;
            artificial_ball_y_in   <= recorder_ball_y_out;
            artificial_paddle_w_in <= recorder_paddle_w_out; // 挡板长度跟随递减
        end
    end

endmodule