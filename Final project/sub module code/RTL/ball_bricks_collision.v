`timescale 1ns / 1ps
module ball_bricks_collision #(
    parameter H_VALID     = 640,
    parameter V_VALID     = 480,
    parameter BALL_SIZE   = 8,
    parameter BALL_SPEED  = 4,
    parameter BRICK_ROWS  = 3,
    parameter BRICK_COLS  = 8,
    parameter BRICK_W     = (H_VALID - (BRICK_COLS-1)*6) / BRICK_COLS,
    parameter BRICK_H     = 20,
    parameter BRICK_TOP   = 40,
    parameter BRICK_HGAP  = 6,
    parameter BRICK_VGAP  = 6
)(
    input  wire             clk,
    input  wire             rst_n,
    input  wire signed [10:0] ball_x_in,
    input  wire signed [10:0] ball_y_in,
    input  wire signed [5:0]  vx_in,
    input  wire signed [5:0]  vy_in,
    output reg  signed [10:0] ball_x_out,
    output reg  signed [10:0] ball_y_out,
    output reg  signed [5:0]  vx_out,
    output reg  signed [5:0]  vy_out,
    output reg                hit_flag,
    output reg  [BRICK_ROWS*BRICK_COLS-1:0] bricks_flat,     // 每砖 1bit 存在标志
    output reg  [(BRICK_ROWS*BRICK_COLS*2)-1:0] brick_hp_flat// 每砖 2bit HP
);

    //------------------------------------------------------------
    // LFSR 随机生成砖块 (复位时)
    //------------------------------------------------------------
    reg [7:0] lfsr;
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            lfsr <= 8'hA5;
        else
            lfsr <= {lfsr[6:0], lfsr[7]^lfsr[5]^lfsr[4]^lfsr[3]};
    end

    //------------------------------------------------------------
    // 内部变量（全部提前声明，避免局部声明错误）
    //------------------------------------------------------------
    integer i, j, idx, index;
    reg signed [10:0] bx0, by0, bx1, by1;
    reg signed [10:0] prev_x, prev_y;
    reg [1:0] hp;
    reg [15:0] bounce_cd;

    //------------------------------------------------------------
    // 主逻辑
    //------------------------------------------------------------
    always @(posedge clk or negedge rst_n) begin
        if(!rst_n) begin
            ball_x_out <= H_VALID/2;
            ball_y_out <= V_VALID/2;
            vx_out     <= BALL_SPEED;
            vy_out     <= BALL_SPEED;
            hit_flag   <= 1'b0;
            bounce_cd  <= 16'd0;

            // 随机生成砖矩阵
            for (i = 0; i < BRICK_ROWS; i = i + 1)
                for (j = 0; j < BRICK_COLS; j = j + 1) begin
                    idx = i * BRICK_COLS + j;
                    if (lfsr[(i+j)%8] ^ lfsr[(i*j+3)%8]) begin
                        bricks_flat[idx] <= 1'b1;
                        brick_hp_flat[idx*2 +: 2] <=
                            (lfsr[(i+j+4)%8]) ? 2'd2 : 2'd1; // 蓝砖:2 红砖:1
                    end else begin
                        bricks_flat[idx] <= 1'b0;
                        brick_hp_flat[idx*2 +: 2] <= 2'd0;
                    end
                end
        end
        else begin
            hit_flag   <= 1'b0;
            ball_x_out <= ball_x_in + vx_in;
            ball_y_out <= ball_y_in + vy_in;
            vx_out     <= vx_in;
            vy_out     <= vy_in;

            if (bounce_cd > 0)
                bounce_cd <= bounce_cd - 1;

            prev_x <= ball_x_in;
            prev_y <= ball_y_in;

            //--------------------------------------------------------
            // 检测碰撞
            //--------------------------------------------------------
            for (i = 0; i < BRICK_ROWS; i = i + 1) begin
                for (j = 0; j < BRICK_COLS; j = j + 1) begin
                    index = i * BRICK_COLS + j;
                    if (bricks_flat[index]) begin
                        bx0 = j * (BRICK_W + BRICK_HGAP);
                        by0 = BRICK_TOP + i * (BRICK_H + BRICK_VGAP);
                        bx1 = bx0 + BRICK_W;
                        by1 = by0 + BRICK_H;

                        if (bounce_cd == 0 &&
                            (ball_x_in + BALL_SIZE/2 >= bx0) &&
                            (ball_x_in - BALL_SIZE/2 <= bx1) &&
                            (ball_y_in + BALL_SIZE/2 >= by0) &&
                            (ball_y_in - BALL_SIZE/2 <= by1) &&
                            (hit_flag == 1'b0))
                        begin
                            hit_flag  <= 1'b1;
                            bounce_cd <= 16'd5; // 冷却，防多次反弹

                            // 判断撞击方向(水平/垂直)
                            if ((prev_y + BALL_SIZE/2 < by0) ||
                                (prev_y - BALL_SIZE/2 > by1))
                                vy_out <= -vy_in;
                            else
                                vx_out <= -vx_in;

                            // 砖块 HP -1，HP<=0 则消失
                            hp = brick_hp_flat[index*2 +: 2];
                            if (hp > 2'd1)
                                brick_hp_flat[index*2 +: 2] <= hp - 1'b1; // 蓝->红
                            else begin
                                brick_hp_flat[index*2 +: 2] <= 2'd0;      // 清零
                                bricks_flat[index] <= 1'b0;               // 消失
                            end
                        end
                    end
                end
            end
        end
    end
endmodule