`timescale 1ns / 1ps
module ball_paddle #(
    parameter H_VALID       = 640,
    parameter BALL_SIZE     = 8,
    parameter BALL_SPEED    = 4,
    parameter PADDLE_H      = 10,
    parameter PADDLE_W_INIT = 120,
    parameter PADDLE_W_MIN  = 40,
    parameter SHRINK_STEP   = 20,
    parameter PADDLE_Y      = 440
)(
    input  wire        clk,
    input  wire        rst_n,

    // 小球输入状态
    input  wire signed [10:0] ball_x_in,
    input  wire signed [10:0] ball_y_in,
    input  wire signed [5:0]  vx_in,
    input  wire signed [5:0]  vy_in,

    // 挡板输入状态
    input  wire [9:0] paddle_x_in,
    input  wire [9:0] paddle_w_in,

    // 输出结果
    output reg signed [10:0] ball_x_out,
    output reg signed [10:0] ball_y_out,
    output reg signed [5:0]  vx_out,
    output reg signed [5:0]  vy_out,
    output reg [9:0]          paddle_w_out,
    output reg                hit_flag
);
    //------------------------------------------------------------
    // 主逻辑
    //------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            ball_x_out   <= H_VALID/2;
            ball_y_out   <= 200;
            vx_out       <= 0;
            vy_out       <= BALL_SPEED;
            paddle_w_out <= PADDLE_W_INIT;
            hit_flag     <= 1'b0;
        end
        else begin
            hit_flag <= 1'b0; // 默认无撞击
            // 默认前进
            ball_x_out <= ball_x_in + vx_in;
            ball_y_out <= ball_y_in + vy_in;
            vx_out     <= vx_in;
            vy_out     <= vy_in;
            paddle_w_out <= paddle_w_in;

            // 撞击检测
            if ((ball_y_in + BALL_SIZE/2 >= PADDLE_Y) &&               
                (ball_y_in - BALL_SIZE/2 <= PADDLE_Y + PADDLE_H) &&
                (ball_x_in >= paddle_x_in - paddle_w_in/2) &&
                (ball_x_in <= paddle_x_in + paddle_w_in/2) &&
                (vy_in > 0)) begin

                hit_flag <= 1'b1;

                // 垂直反弹
                vy_out <= -BALL_SPEED;

                // 根据撞击点调整水平速度
                if (ball_x_in < paddle_x_in - paddle_w_in/4)
                    vx_out <= -BALL_SPEED - 1;
                else if (ball_x_in < paddle_x_in)
                    vx_out <= -BALL_SPEED;
                else if (ball_x_in > paddle_x_in + paddle_w_in/4)
                    vx_out <= BALL_SPEED + 1;
                else
                    vx_out <= BALL_SPEED;

                // 挡板长度递减
                if (paddle_w_in > PADDLE_W_MIN + SHRINK_STEP)
                    paddle_w_out <= paddle_w_in - SHRINK_STEP;
                else
                    paddle_w_out <= PADDLE_W_MIN;
            end
        end
    end
endmodule