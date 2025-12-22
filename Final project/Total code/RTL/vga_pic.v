module vga_pic(
    input  wire        vga_clk,    
    input  wire        sys_rst_n,
    input  wire [9:0]  pix_x,     
    input  wire [9:0]  pix_y,
    input  wire [1:0]  mode_sel,	 
	input  wire        B3,   // D -> 左移
    input  wire        B4,   // F -> 右移
	output reg         led1,
	output reg         led2,
	output reg         led3,
	output reg         led4,
	output reg         led5,
    output reg [15:0]  pix_data
);

//======================================================================
// 状态机参数
//======================================================================
parameter GET_START = 2'b00;
parameter GET_GAME  = 2'b01;
parameter GET_END   = 2'b10;

//======================================================================
// VGA 显示参数
//======================================================================
parameter H_VALID = 10'd640;
parameter V_VALID = 10'd480; 

//======================================================================
// 颜色定义 (RGB565)
//======================================================================
parameter BLACK   = 16'h0000;
parameter WHITE   = 16'hFFFF;
parameter GREEN   = 16'h07E0;
parameter CYAN    = 16'h07FF;
parameter PURPLE  = 16'hF81F;
parameter YELLOW  = 16'hFFE0;
parameter RED     = 16'hF800; // 红砖颜色
parameter BLUE    = 16'h001F; // 蓝砖颜色

//======================================================================
// 字符显示参数
//======================================================================
parameter CHAR_W = 90;    
parameter CHAR_H = 180;   
parameter GAP    = 20; 

//======================================================================
// 游戏逻辑变量
//======================================================================
integer i, j;                  // 循环变量
reg [9:0] bx0, by0, bx1, by1;   // 用于碰撞检测的砖块边界坐标
reg all_clear;                 // 标志所有砖块是否都被打完
reg hit_flag;                  // 用于防止同一帧多次反弹
reg signed [10:0] prev_ball_x_temp;
reg signed [10:0] prev_ball_y_temp;


//======================================================================
// 砖块参数
//======================================================================
parameter BRICK_ROWS = 3;
parameter BRICK_COLS = 8;
parameter BRICK_W = (H_VALID - (BRICK_COLS-1)*6) / BRICK_COLS;
parameter BRICK_H = 20;
parameter BRICK_TOP = 40;
parameter BRICK_HGAP = 6;
parameter BRICK_VGAP = 6;

//======================================================================
// LFSR 伪随机数生成器
//======================================================================
reg [7:0] lfsr;
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        lfsr <= 8'hA5;
    else
        lfsr <= {lfsr[6:0], lfsr[7]^lfsr[5]^lfsr[4]^lfsr[3]};
end

//======================================================================
// 砖块数据存储 (扁平化一维数组)
//======================================================================
reg [BRICK_ROWS * BRICK_COLS - 1 : 0] bricks_flat;
reg [(BRICK_ROWS * BRICK_COLS * 2) - 1 : 0] brick_hp_flat;
	 
//======================================================================
// START 界面字符坐标
//======================================================================
parameter TOTAL_W_START = 5*CHAR_W + 4*GAP;
parameter START_X_START = (H_VALID - TOTAL_W_START)/2;
parameter START_Y_START = (V_VALID - CHAR_H)/2;

parameter X_S  = START_X_START;
parameter X_T  = X_S + (CHAR_W + GAP);
parameter X_A  = X_S + 2*(CHAR_W + GAP);
parameter X_R  = X_S + 3*(CHAR_W + GAP);
parameter X_T2 = X_S + 4*(CHAR_W + GAP);

wire in_S_start, in_T_start, in_A_start, in_R_start, in_T2_start;

//======================================================================
// END 界面字符坐标
//======================================================================
parameter TOTAL_W_END = 3*CHAR_W + 2*GAP;
parameter START_X_END = (H_VALID - TOTAL_W_END)/2;
parameter START_Y_END = (V_VALID - CHAR_H)/2;

parameter X_E = START_X_END;
parameter X_N = START_X_END + (CHAR_W + GAP);
parameter X_D = START_X_END + 2*(CHAR_W + GAP);
wire in_E, in_N, in_D;

//======================================================================
// 挡板参数与逻辑
//======================================================================
parameter PADDLE_W_INIT = 140;
parameter PADDLE_W_MIN  = 40;
parameter PADDLE_SHRINK = 20;
parameter PADDLE_H      = 10;
parameter PADDLE_Y      = 440;

reg [9:0] paddle_x;
reg [9:0] paddle_w;
reg [7:0] paddle_hit_cnt;
	
wire paddle_on;
assign paddle_on = (pix_y >= PADDLE_Y) && (pix_y < PADDLE_Y + PADDLE_H) &&
                   (pix_x >= paddle_x - paddle_w/2) && 
                   (pix_x < paddle_x + paddle_w/2);

//======================================================================
// 字符形状定义
//======================================================================
assign in_S_start =
    (pix_x >= X_S) && (pix_x < X_S + CHAR_W) &&
    (pix_y >= START_Y_START) && (pix_y < START_Y_START + CHAR_H) &&
    (
        (pix_y < START_Y_START + 10) ||
        (pix_y > START_Y_START + CHAR_H - 10) ||
        ((pix_y > START_Y_START + CHAR_H/2 - 5) && 
         (pix_y < START_Y_START + CHAR_H/2 + 5)) ||
        ((pix_y < START_Y_START + CHAR_H/2) && (pix_x < X_S + 10)) ||
        ((pix_y > START_Y_START + CHAR_H/2) && (pix_x > X_S + CHAR_W - 10))
    );

assign in_T_start =
    (pix_x >= X_T) && (pix_x < X_T + CHAR_W) &&
    (pix_y >= START_Y_START) && (pix_y < START_Y_START + CHAR_H) &&
    (
        (pix_y < START_Y_START + 10) ||
        (pix_x > X_T + CHAR_W/2 - 5 && pix_x < X_T + CHAR_W/2 + 5)
    );

assign in_A_start =
    (pix_x >= X_A) && (pix_x < X_A + CHAR_W) &&
    (pix_y >= START_Y_START) && (pix_y < START_Y_START + CHAR_H) &&
    (
        (pix_x < X_A + 10) ||
        (pix_x > X_A + CHAR_W - 10) ||
        (pix_y < START_Y_START + 10) ||
        ((pix_y > START_Y_START + CHAR_H/2 - 5) && 
         (pix_y < START_Y_START + CHAR_H/2 + 5))
    );

assign in_R_start =
    (pix_x >= X_R) && (pix_x < X_R + CHAR_W) &&
    (pix_y >= START_Y_START) && (pix_y < START_Y_START + CHAR_H) && (
        (pix_x < X_R + 10) ||
        (pix_y < START_Y_START + 10) ||
        ((pix_y > START_Y_START + CHAR_H/2 - 5) &&
         (pix_y < START_Y_START + CHAR_H/2 + 5)) ||
        ((pix_x > X_R + CHAR_W - 10) &&
         (pix_y < START_Y_START + CHAR_H/2)) ||
        ((pix_y >= START_Y_START + CHAR_H/2) &&
         (pix_x >= X_R + 10) && 
         ((pix_x - (X_R + 10)) >= (pix_y - (START_Y_START + CHAR_H/2))) &&
         ((pix_x - (X_R + 10)) <= (pix_y - (START_Y_START + CHAR_H/2) + 10))
        )
    );
	 
assign in_T2_start =
    (pix_x >= X_T2) && (pix_x < X_T2 + CHAR_W) &&
    (pix_y >= START_Y_START) && (pix_y < START_Y_START + CHAR_H) &&
    (
        (pix_y < START_Y_START + 10) ||
        (pix_x > X_T2 + CHAR_W/2 - 5 && pix_x < X_T2 + CHAR_W/2 + 5)
    );

assign in_E =
    (pix_x >= X_E) && (pix_x < X_E + CHAR_W) &&
    (pix_y >= START_Y_END) && (pix_y < START_Y_END + CHAR_H) &&
    (
        (pix_x < X_E + 10) ||
        (pix_y < START_Y_END + 10) ||
        (pix_y > START_Y_END + CHAR_H - 10) ||
        ((pix_y > START_Y_END + CHAR_H/2 - 5) && 
         (pix_y < START_Y_END + CHAR_H/2 + 5))
    );

assign in_N =
    (pix_x >= X_N) && (pix_x < X_N + CHAR_W) &&
    (pix_y >= START_Y_END) && (pix_y < START_Y_END + CHAR_H) &&
    (
        (pix_x < X_N + 10) ||
        (pix_x > X_N + CHAR_W - 10) ||
        (((pix_x - X_N) >= ((pix_y - START_Y_END)/2 - 5)) &&
         ((pix_x - X_N) <= ((pix_y - START_Y_END)/2 + 5)))
    );

assign in_D =
    (pix_x >= X_D) && (pix_x < X_D + CHAR_W) &&
    (pix_y >= START_Y_END) && (pix_y < START_Y_END + CHAR_H) &&
    (
        (pix_x < X_D + 10) ||
        ((pix_x > X_D + CHAR_W - 10) &&
         ((pix_y - START_Y_END) > 10) &&
         ((pix_y - START_Y_END) < CHAR_H - 10)) ||
        (((pix_y < START_Y_END + 10) || 
          (pix_y > START_Y_END + CHAR_H - 10)) && 
         (pix_x < X_D + CHAR_W - 10)) 
    );


// 按键去抖 (Key Debounce)

parameter CNT_20MS_MAX = 20'd125_000; 


// 左移键(D键, B3)去抖

reg [19:0] cnt_press_left;
reg [19:0] cnt_release_left;
reg left_key_flag; 

// counter for press
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        cnt_press_left <= 20'b0;
    end else if (B3) begin 
        cnt_press_left <= 20'b0;
    end else if (cnt_press_left == CNT_20MS_MAX && !B3) begin
        cnt_press_left <= cnt_press_left;
    end else begin 
        cnt_press_left <= cnt_press_left + 1'b1;
    end
end

// counter for release
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        cnt_release_left <= 20'b0;
    end else if (!B3) begin 
        cnt_release_left <= 20'b0;
    end else if (cnt_release_left == CNT_20MS_MAX && B3) begin 
        cnt_release_left <= cnt_release_left;
    end else begin 
        cnt_release_left <= cnt_release_left + 1'b1;
    end
end

// update left_key_flag
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        left_key_flag <= 1'b1; 
    end else if (cnt_press_left >= CNT_20MS_MAX - 1'd1) begin 
        left_key_flag <= 1'b0;
    end else if (cnt_release_left >= CNT_20MS_MAX - 1'd1) begin 
        left_key_flag <= 1'b1;
    end else begin
        left_key_flag <= left_key_flag; 
    end
end


// 右移键(F键, B4)去抖

reg [19:0] cnt_press_right;
reg [19:0] cnt_release_right;
reg right_key_flag; 

// counter for press
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        cnt_press_right <= 20'b0;
    end else if (B4) begin 
        cnt_press_right <= 20'b0;
    end else if (cnt_press_right == CNT_20MS_MAX && !B4) begin 
        cnt_press_right <= cnt_press_right;
    end else begin 
        cnt_press_right <= cnt_press_right + 1'b1;
    end
end

// counter for release
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        cnt_release_right <= 20'b0;
    end else if (!B4) begin 
        cnt_release_right <= 20'b0;
    end else if (cnt_release_right == CNT_20MS_MAX && B4) begin 
        cnt_release_right <= cnt_release_right;
    end else begin 
        cnt_release_right <= cnt_release_right + 1'b1;
    end
end

// update right_key_flag
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        right_key_flag <= 1'b1;
    end else if (cnt_press_right >= CNT_20MS_MAX - 1'd1) begin 
        right_key_flag <= 1'b0;
    end else if (cnt_release_right >= CNT_20MS_MAX - 1'd1) begin 
        right_key_flag <= 1'b1;
    end else begin
        right_key_flag <= right_key_flag; 
    end
end

//Edge Detection

reg left_prev = 1'b1;
reg right_prev = 1'b1;
wire left_falling_edge;
wire right_falling_edge;

// detect edge of left button
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        left_prev <= 1'b1;
    else
        left_prev <= left_key_flag;
end
assign left_falling_edge = (left_prev == 1'b1 && left_key_flag == 1'b0);

// detect edge of right button
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        right_prev <= 1'b1;
    else
        right_prev <= right_key_flag;
end
assign right_falling_edge = (right_prev == 1'b1 && right_key_flag == 1'b0);

//======================================================================
// 挡板移动和游戏节拍参数
//======================================================================
parameter MOVE_STEP = 10;

// 连发节拍 (控制长按速度)
reg [15:0] move_cnt;
wire move_tick = (move_cnt == 16'd0);

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        move_cnt <= 16'd0;
    else
        move_cnt <= move_cnt + 1'b1;
end

//======================================================================
// 小球参数与状态
//======================================================================
parameter BALL_SIZE = 8;  
parameter BALL_SPEED = 4; 
parameter BALL_START_GAP = 40; 
reg [1:0] local_mode_sel;
reg signed [10:0] ball_x, ball_y;  
reg signed [5:0]  vx, vy;           
reg first_drop_flag;
reg [3:0] bounce_cd; // 碰撞冷却，防止一次碰撞多次反弹

// 小球移动节拍
reg [15:0] ball_cnt;
wire ball_tick = (ball_cnt == 16'd0);

always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) ball_cnt <= 16'd0;
    else ball_cnt <= ball_cnt + 1'b1;
end

//======================================================================
// 游戏核心状态机 
//======================================================================
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n) begin
        ball_x <= H_VALID / 2;
        ball_y <= PADDLE_Y - (PADDLE_H/2) - (BALL_SIZE/2) - BALL_START_GAP;
        vx <= 0;               
        vy <= BALL_SPEED;      
        first_drop_flag <= 1'b1; 
		bounce_cd <= 4'd0;
        local_mode_sel <= GET_START;
        bricks_flat <= {(BRICK_ROWS * BRICK_COLS){1'b0}};
		brick_hp_flat <= {(BRICK_ROWS * BRICK_COLS * 2){1'b0}};
        paddle_x <= H_VALID / 2;
        paddle_w <= PADDLE_W_INIT;
        paddle_hit_cnt <= 0;
    end
    // 根据游戏模式 (mode_sel) 更新状态
    else begin
        // 优先处理游戏结束状态的锁存
        if (local_mode_sel == GET_END) begin
            // 一旦游戏结束，冻结所有状态，直到外部复位
        end
        // 根据外部模式选择执行不同逻辑
        else begin
            case (mode_sel)
                // 模式一：开始界面 & 游戏初始化
                GET_START: begin
                    // 重置小球和挡板状态
                    ball_x <= H_VALID / 2;
                    ball_y <= PADDLE_Y - (PADDLE_H/2) - (BALL_SIZE/2) - BALL_START_GAP;
                    vx <= 0;
                    vy <= BALL_SPEED;
                    first_drop_flag <= 1'b1;
                    paddle_x <= H_VALID / 2;
                    paddle_w <= PADDLE_W_INIT;
                    paddle_hit_cnt <= 0;
                    local_mode_sel <= GET_START;

                    // 初始化随机砖块 (注意: 此逻辑会在GET_START状态下每帧都执行)
                    for (i = 0; i < BRICK_ROWS; i = i + 1) begin
                        for (j = 0; j < BRICK_COLS; j = j + 1) begin
                            integer index = i * BRICK_COLS + j;
                            if (lfsr[(i + j) % 8] ^ lfsr[(i * j + 3) % 8]) begin
                                bricks_flat[index] <= 1'b1;
                                if (lfsr[(i + j + 4) % 8])
                                    brick_hp_flat[index*2 +: 2] <= 2'd2; // 蓝砖 (2HP)
                                else
                                    brick_hp_flat[index*2 +: 2] <= 2'd1; // 红砖 (1HP)
                            end else begin
                                bricks_flat[index] <= 1'b0;
                                brick_hp_flat[index*2 +: 2] <= 2'd0;
                            end
                        end
                    end
                end

                // 模式二：游戏进行
                GET_GAME: begin
                    local_mode_sel <= GET_GAME;
                 
                    // 左移: 由 B3 (D键) -> left_key_flag 触发
                    if (left_falling_edge || (move_tick && !left_key_flag)) begin
                        if (paddle_x > (paddle_w/2 + MOVE_STEP))
                            paddle_x <= paddle_x - MOVE_STEP;
                        else
                            paddle_x <= paddle_w / 2;
                    end
                    // 右移: 由 B4 (F键) -> right_key_flag 触发
                    else if (right_falling_edge || (move_tick && !right_key_flag)) begin
                        if (paddle_x < (H_VALID - paddle_w/2 - MOVE_STEP))
                            paddle_x <= paddle_x + MOVE_STEP;
                        else
                            paddle_x <= H_VALID - paddle_w/2;
                    end

                    // 根据小球节拍更新游戏逻辑
                    if (ball_tick) begin
                        if (bounce_cd > 0)
                            bounce_cd <= bounce_cd - 1'b1;
                        
                        ball_x <= ball_x + vx;
                        ball_y <= ball_y + vy;

                        // 碰撞检测: 挡板
                        if ((ball_y + BALL_SIZE/2 >= PADDLE_Y) &&
                            (ball_y - BALL_SIZE/2 <= PADDLE_Y + PADDLE_H) &&
                            (ball_x >= paddle_x - paddle_w/2) &&
                            (ball_x <= paddle_x + paddle_w/2) &&
                            (vy > 0)) begin

                            if (first_drop_flag) begin
                                vy <= -BALL_SPEED;
                                vx <= 0;
                                first_drop_flag <= 1'b0; 
                            end
                            else begin
                                vy <= -BALL_SPEED;
                                if (ball_x < paddle_x - paddle_w/4)      vx <= -BALL_SPEED - 1;
                                else if (ball_x < paddle_x)              vx <= -BALL_SPEED;
                                else if (ball_x > paddle_x + paddle_w/4) vx <= BALL_SPEED + 1;
                                else                                     vx <= BALL_SPEED;

                                // 更新挡板宽度
                                if (paddle_w > PADDLE_W_MIN) begin
											paddle_w <= paddle_w - PADDLE_SHRINK;
											end
                            end
                        end

                        // 碰撞检测: 左右墙壁
                        if (ball_x <= BALL_SIZE/2) begin
                            ball_x <= BALL_SIZE/2 + 1;
                            vx <= (vx <= 0) ? BALL_SPEED : -vx;
                        end
                        else if (ball_x >= (H_VALID - BALL_SIZE/2)) begin
                            ball_x <= H_VALID - BALL_SIZE/2 - 1;
                            vx <= (vx >= 0) ? -BALL_SPEED : -vx;
                        end

                        // 碰撞检测: 上墙壁
                        if (ball_y <= BALL_SIZE/2) begin
                            ball_y <= BALL_SIZE/2 + 1;
                            vy <= (vy <= 0) ? BALL_SPEED : -vy;
                        end
                          
                        // 碰撞检测: 砖块
                        hit_flag = 1'b0;
                        for (i = 0; i < BRICK_ROWS; i = i + 1) begin
                            for (j = 0; j < BRICK_COLS; j = j + 1) begin
                                integer index = i * BRICK_COLS + j;
                                if (bricks_flat[index]) begin
                                    bx0 = j * (BRICK_W + BRICK_HGAP);
                                    by0 = BRICK_TOP + i * (BRICK_H + BRICK_VGAP);
                                    bx1 = bx0 + BRICK_W;
                                    by1 = by0 + BRICK_H;

                                    if ((bounce_cd == 0) &&
                                        (ball_x + BALL_SIZE/2 >= bx0) && (ball_x - BALL_SIZE/2 <= bx1) &&
                                        (ball_y + BALL_SIZE/2 >= by0) && (ball_y - BALL_SIZE/2 <= by1) &&
                                        (hit_flag == 1'b0)) begin
                                        
                                        hit_flag = 1'b1;
                                        bounce_cd <= 4'd4;

                                        prev_ball_x_temp = ball_x - vx;
                                        prev_ball_y_temp = ball_y - vy;
                                        
                                        if ((prev_ball_y_temp + BALL_SIZE/2 < by0) || (prev_ball_y_temp - BALL_SIZE/2 > by1)) begin
                                            vy <= -vy; 
                                        end else begin 
                                            vx <= -vx; 
                                        end

                                        // 更新砖块状态
                                        if (brick_hp_flat[index*2 +: 2] > 2'd1) begin
                                            brick_hp_flat[index*2 +: 2] <= brick_hp_flat[index*2 +: 2] - 1'b1;
                                        end else begin
                                            brick_hp_flat[index*2 +: 2] <= 2'd0;
                                            bricks_flat[index] <= 1'b0;
                                        end
                                    end
                                end
                            end
                        end

                        // 胜利/失败条件判断
                        all_clear = (bricks_flat == 0);
                        if (all_clear)
                            local_mode_sel <= GET_END;

                        if (ball_y >= (V_VALID - BALL_SIZE/2)) begin
                            ball_y <= V_VALID - BALL_SIZE/2;
                            vx <= 0;
                            vy <= 0;
                            local_mode_sel <= GET_END;
                        end
                    end
                end

                // 模式三：结束界面
                GET_END: begin
                    local_mode_sel <= GET_END;
                    // 冻结小球
                    vx <= 0;
                    vy <= 0;
                end
            endcase
        end
    end
end

//======================================================================
// 像素显示判断逻辑
//======================================================================
wire show_ball = (local_mode_sel == GET_GAME) && 
                 (pix_x >= ball_x - BALL_SIZE/2) && (pix_x <= ball_x + BALL_SIZE/2) &&
                 (pix_y >= ball_y - BALL_SIZE/2) && (pix_y <= ball_y + BALL_SIZE/2);

reg current_brick_on;
reg [1:0] current_brick_hp;

always @(*) begin
    integer pix_row_idx, pix_col_idx, index;
    reg [9:0] check_bx0, check_by0, check_bx1, check_by1;

    current_brick_on = 1'b0;
    current_brick_hp = 2'd0;

    if (pix_y >= BRICK_TOP && pix_y < BRICK_TOP + BRICK_ROWS * (BRICK_H + BRICK_VGAP)) begin
        pix_row_idx = (pix_y - BRICK_TOP) / (BRICK_H + BRICK_VGAP);
        pix_col_idx = pix_x / (BRICK_W + BRICK_HGAP);

        if (pix_row_idx < BRICK_ROWS && pix_col_idx < BRICK_COLS) begin
            check_bx0 = pix_col_idx * (BRICK_W + BRICK_HGAP);
            check_by0 = BRICK_TOP + pix_row_idx * (BRICK_H + BRICK_VGAP);
            check_bx1 = check_bx0 + BRICK_W;
            check_by1 = check_by0 + BRICK_H;

            if (pix_x >= check_bx0 && pix_x < check_bx1 && pix_y >= check_by0 && pix_y < check_by1) begin
                index = pix_row_idx * BRICK_COLS + pix_col_idx;
                
                if (bricks_flat[index]) begin
                    current_brick_on = 1'b1;
                    current_brick_hp = brick_hp_flat[index*2 +: 2];
                end
            end
        end
    end
end

//======================================================================
// 主像素输出逻辑
//======================================================================
always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        pix_data <= 16'd0;
    else begin
        case (local_mode_sel)
            GET_START: begin
                if (in_S_start || in_T_start || in_A_start || in_R_start || in_T2_start)
                    pix_data <= WHITE;
                else
                    pix_data <= BLACK;
            end

            GET_GAME: begin
                if (show_ball)
                    pix_data <= WHITE; 
                else if (current_brick_on) begin
                    case (current_brick_hp)
                        2'd2:    pix_data <= BLUE;
                        2'd1:    pix_data <= RED;
                        default: pix_data <= BLACK;
                    endcase
                end
                else if (paddle_on)
                    pix_data <= GREEN;       
                else
                    pix_data <= BLACK;       
            end

            GET_END: begin
                if (in_E) pix_data <= CYAN;
                else if (in_N) pix_data <= PURPLE;
                else if (in_D) pix_data <= YELLOW;
                else pix_data <= BLACK;
            end
					 
            default: pix_data <= BLACK;
        endcase
    end
end

endmodule