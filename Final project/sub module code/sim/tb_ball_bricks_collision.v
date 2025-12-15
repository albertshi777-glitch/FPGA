`timescale 1ns/1ps
module tb_ball_bricks_collision();

    //------------------------------------------------------------
    // 信号定义
    //------------------------------------------------------------
    reg  artificial_clk;
    reg  artificial_sys_rst_n;

    reg  signed [10:0] artificial_ball_x_in;
    reg  signed [10:0] artificial_ball_y_in;
    reg  signed [5:0]  artificial_vx_in;
    reg  signed [5:0]  artificial_vy_in;

    wire signed [10:0] recorder_ball_x_out;
    wire signed [10:0] recorder_ball_y_out;
    wire signed [5:0]  recorder_vx_out;
    wire signed [5:0]  recorder_vy_out;
    wire                recorder_hit_flag;

    wire [23:0] bricks_flat;
    wire [47:0] brick_hp_flat;


    //------------------------------------------------------------
    // 实例化被测模块（DUT）
    //------------------------------------------------------------
    ball_bricks_collision uut (
        .clk           (artificial_clk),
        .rst_n         (artificial_sys_rst_n),
        .ball_x_in     (artificial_ball_x_in),
        .ball_y_in     (artificial_ball_y_in),
        .vx_in         (artificial_vx_in),
        .vy_in         (artificial_vy_in),
        .ball_x_out    (recorder_ball_x_out),
        .ball_y_out    (recorder_ball_y_out),
        .vx_out        (recorder_vx_out),
        .vy_out        (recorder_vy_out),
        .hit_flag      (recorder_hit_flag),
        .bricks_flat   (bricks_flat),
        .brick_hp_flat (brick_hp_flat)
    );


    //------------------------------------------------------------
    // 时钟与复位
    //------------------------------------------------------------
    initial begin
        artificial_clk   = 1'b0;
        artificial_sys_rst_n = 1'b0;
        #100;
        artificial_sys_rst_n = 1'b1;
    end

    always #10 artificial_clk = ~artificial_clk;  // 50 MHz 时钟


    //------------------------------------------------------------
    // 初始化与测试序列
    // Case 1：随机生成砖块矩阵
    // Case 2：蓝砖两次击打（蓝→红→消失）
    // Case 3：红砖一次击打消失
    //------------------------------------------------------------
    initial begin
        // 初始化小球坐标与速度
        artificial_ball_x_in = 11'd60;
        artificial_ball_y_in = 11'd30;
        artificial_vx_in     = 6'd4;
        artificial_vy_in     = 6'd3;

        // 等待复位释放
        wait (artificial_sys_rst_n == 1);

        //------------------------------------------------
        // Case 1：随机砖块生成阶段
        //------------------------------------------------
        #500; // 镜像时间100 ns + 400 ns稳定
        // 复位释放时，砖块随机矩阵已在被测模块中生成
        // 继续执行运动阶段

        //------------------------------------------------
        // Case 2：蓝砖两次击打演示
        //------------------------------------------------
        // 小球连续移动一段时间，保证打到同一砖块两次（蓝→红→消失）
        repeat(2000) @(posedge artificial_clk) begin
            artificial_ball_x_in <= recorder_ball_x_out;
            artificial_ball_y_in <= recorder_ball_y_out;
            artificial_vx_in     <= recorder_vx_out;
            artificial_vy_in     <= recorder_vy_out;
        end

        //------------------------------------------------
        // Case 3：其他红砖单次击打后消失
        //------------------------------------------------
        // 继续运行一定时间，击打更多砖块
        repeat(2000) @(posedge artificial_clk) begin
            artificial_ball_x_in <= recorder_ball_x_out;
            artificial_ball_y_in <= recorder_ball_y_out;
            artificial_vx_in     <= recorder_vx_out;
            artificial_vy_in     <= recorder_vy_out;
        end

        //------------------------------------------------
        // Case 4：结束仿真
        //------------------------------------------------
        #2000;
        $stop;
    end


    //------------------------------------------------------------
    // 连续更新输入 —— 让下一拍位置 = 上一拍输出
    //------------------------------------------------------------
    always @(posedge artificial_clk or negedge artificial_sys_rst_n) begin
        if (!artificial_sys_rst_n) begin
            artificial_ball_x_in <= 11'd60;
            artificial_ball_y_in <= 11'd30;
            artificial_vx_in     <= 6'd4;
            artificial_vy_in     <= 6'd3;
        end
        else begin
            artificial_ball_x_in <= recorder_ball_x_out;
            artificial_ball_y_in <= recorder_ball_y_out;
            artificial_vx_in     <= recorder_vx_out;
            artificial_vy_in     <= recorder_vy_out;
        end
    end

endmodule