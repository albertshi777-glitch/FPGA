`timescale 1ns/1ps
module ball_wall_collision #(
    parameter H_VALID   = 640,    // 屏幕宽度
    parameter V_VALID   = 480,    // 屏幕高度
    parameter BALL_SIZE = 8,
    parameter BALL_SPEED = 4
)(
    input  wire        vga_clk,
    input  wire        sys_rst_n,
    input  wire signed [10:0] ball_x_in,
    input  wire signed [10:0] ball_y_in,
    input  wire signed [5:0]  vx_in,
    input  wire signed [5:0]  vy_in,
    output reg  signed [10:0] ball_x_out,
    output reg  signed [10:0] ball_y_out,
    output reg  signed [5:0]  vx_out,
    output reg  signed [5:0]  vy_out
);

    // 状态标志：是否已经结束
    reg game_over;

    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n) begin
            ball_x_out <= H_VALID / 2;
            ball_y_out <= V_VALID / 2;
            vx_out     <= BALL_SPEED;
            vy_out     <= BALL_SPEED;
            game_over  <= 1'b0;
        end 
        else begin
            // 若游戏结束则冻结球
            if (game_over) begin
                ball_x_out <= ball_x_out;
                ball_y_out <= ball_y_out;
                vx_out     <= 0;
                vy_out     <= 0;
            end
            else begin
                // 默认更新
                ball_x_out <= ball_x_in + vx_in;
                ball_y_out <= ball_y_in + vy_in;
                vx_out <= vx_in;
                vy_out <= vy_in;

                //--- 左右墙反弹 ---
                if (ball_x_in <= BALL_SIZE/2) begin
                    ball_x_out <= BALL_SIZE/2 + 1;
                    vx_out <= BALL_SPEED; // 向右
                end
                else if (ball_x_in >= (H_VALID - BALL_SIZE/2)) begin
                    ball_x_out <= H_VALID - BALL_SIZE/2 - 1;
                    vx_out <= -BALL_SPEED; // 向左
                end

                //--- 上墙反弹 ---
                if (ball_y_in <= BALL_SIZE/2) begin
                    ball_y_out <= BALL_SIZE/2 + 1;
                    vy_out <= BALL_SPEED;
                end

                //--- 下墙逻辑：失败，不反弹 ---
                if (ball_y_in >= (V_VALID - BALL_SIZE/2)) begin
                    ball_y_out <= V_VALID - BALL_SIZE/2;  // 停在底部
                    vx_out <= 0;  // 停止运动
                    vy_out <= 0;
                    game_over <= 1'b1;  // 标志游戏结束
                end
            end
        end
    end
endmodule