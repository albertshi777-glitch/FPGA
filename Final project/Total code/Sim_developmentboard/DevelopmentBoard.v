`timescale 1ns / 1ns

module DevelopmentBoard(
    input  wire clk, // 50MHz
    input  wire reset, B2, B3, B4, B5,
    output wire h_sync, v_sync,
    output wire [15:0] rgb,
    output wire led1, led2, led3, led4, led5
);

    // 状态定义
    parameter GET_START = 2'd0;
    parameter GET_GAME  = 2'd1;
    parameter GET_END   = 2'd2;

    reg [1:0] st_cur = GET_START;
    reg [1:0] st_next = GET_START;

    // ---- 按键检测 (S键按下) ----
    reg button_prev = 1'b1;
    always @(posedge clk or negedge reset) begin
        if (!reset)
            button_prev <= 1'b1;
        else
            button_prev <= B2;
    end

    wire button_falling = (button_prev == 1'b1 && B2 == 1'b0);

    // ---- 状态寄存 ----
    always @(posedge clk or negedge reset) begin
        if (!reset)
            st_cur <= GET_START;  //  默认进入 START
        else
            st_cur <= st_next;
    end

    // ---- 状态转移 ----
    always @(*) begin
        st_next = st_cur;
        if (!reset)
            st_next = GET_START;  //  reset 总是回到 START
        else begin
            case (st_cur)
                GET_START: if (button_falling) st_next = GET_GAME;
                GET_GAME:  if (button_falling) st_next = GET_END;
                GET_END:   if (button_falling) st_next = GET_START;
                default:   st_next = GET_START;
            endcase
        end
    end

    // ---- 输出当前模式 ----
    wire [1:0] mode_sel = st_cur;

    // ---- VGA显示接口 ----
    vga_display vga_display_inst(
        .sys_clk(clk),
        .sys_rst_n(reset),
        .B3(B3),
        .B4(B4),
        .mode_sel(mode_sel),
        .hsync(h_sync),
        .vsync(v_sync),
        .led1(led1),
        .led2(led2),
        .led3(led3),
        .led4(led4),
        .led5(led5),
        .rgb(rgb)
    );

endmodule