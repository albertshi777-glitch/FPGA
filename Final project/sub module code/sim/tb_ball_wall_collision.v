`timescale 1ns/1ps
module tb_ball_wall_collision();

    //------------------------------------------------------------
    // 信号定义
    //------------------------------------------------------------
    reg  artificial_vga_clk;
    reg  artificial_sys_rst_n;

    reg  signed [10:0] artificial_ball_x_in;
    reg  signed [10:0] artificial_ball_y_in;
    reg  signed [5:0]  artificial_vx_in;
    reg  signed [5:0]  artificial_vy_in;

    wire signed [10:0] recorder_ball_x_out;
    wire signed [10:0] recorder_ball_y_out;
    wire signed [5:0]  recorder_vx_out;
    wire signed [5:0]  recorder_vy_out;

    //------------------------------------------------------------
    // 实例化被测模块 DUT
    //------------------------------------------------------------
    ball_wall_collision uut (
        .vga_clk   (artificial_vga_clk),
        .sys_rst_n (artificial_sys_rst_n),
        .ball_x_in (artificial_ball_x_in),
        .ball_y_in (artificial_ball_y_in),
        .vx_in     (artificial_vx_in),
        .vy_in     (artificial_vy_in),
        .ball_x_out(recorder_ball_x_out),
        .ball_y_out(recorder_ball_y_out),
        .vx_out    (recorder_vx_out),
        .vy_out    (recorder_vy_out)
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

    always #10 artificial_vga_clk = ~artificial_vga_clk; // 50MHz 时钟

    //------------------------------------------------------------
    // 初始化运动方案
    // 依次测试：右墙→左墙→上墙→下墙（结束）
    //------------------------------------------------------------
    initial begin
        // 初始位置在屏幕中央
        artificial_ball_x_in = 11'd320;
        artificial_ball_y_in = 11'd240;
        artificial_vx_in = 6'd4;   // 向右
        artificial_vy_in = 6'd0;
        wait (artificial_sys_rst_n == 1);

        // -------- 阶段 1: 向右撞墙 --------
        repeat (200) @(posedge artificial_vga_clk);

        // -------- 阶段 2: 向左撞墙 --------
        artificial_vx_in = -6'd4;
        artificial_vy_in = 6'd0;
        repeat (400) @(posedge artificial_vga_clk);

        // -------- 阶段 3: 向上撞墙 --------
        artificial_vx_in = 6'd0;
        artificial_vy_in = -6'd4;
        repeat (300) @(posedge artificial_vga_clk);

        // -------- 阶段 4: 向下撞墙（触底停止）--------
        artificial_vx_in = 6'd0;
        artificial_vy_in = 6'd4;
        repeat (600) @(posedge artificial_vga_clk);

        // -------- 结束 --------
        $stop;
    end

    //------------------------------------------------------------
    // 连续更新输入坐标
    //------------------------------------------------------------
    always @(posedge artificial_vga_clk or negedge artificial_sys_rst_n) begin
        if(!artificial_sys_rst_n) begin
            artificial_ball_x_in <= 11'd320;
            artificial_ball_y_in <= 11'd240;
        end else begin
            artificial_ball_x_in <= recorder_ball_x_out;
            artificial_ball_y_in <= recorder_ball_y_out;
        end
    end

endmodule