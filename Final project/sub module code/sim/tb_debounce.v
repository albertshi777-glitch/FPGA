`timescale 1ns/1ps

module tb_debounce();

    // 信号定义
    reg artificial_vga_clk;       // 时钟信号
    reg artificial_sys_rst_n;     // 复位信号
    reg artificial_B3;            // 左键输入
    reg artificial_B4;            // 右键输入

    wire recorder_left_key_flag;      // 左键稳定状态
    wire recorder_right_key_flag;     // 右键稳定状态
    wire recorder_left_falling_edge;  // 左键下降沿
    wire recorder_right_falling_edge; // 右键下降沿

    // 观察内部计数器（层次化访问）
    wire [19:0] recorder_cnt_press_left;
    wire [19:0] recorder_cnt_release_left;
    wire [19:0] recorder_cnt_press_right;
    wire [19:0] recorder_cnt_release_right;

    // 初始条件设定
    initial begin
        artificial_vga_clk   <= 1'b0;
        artificial_sys_rst_n <= 1'b0;
        artificial_B3        <= 1'b1; // 默认未按下（高）
        artificial_B4        <= 1'b1; // 默认未按下（高）
        #200;
        artificial_sys_rst_n <= 1'b1;
    end

    // 25MHz VGA 时钟
    always begin
        #20 artificial_vga_clk <= ~artificial_vga_clk;
    end

    // B3 / B4 按键激励
    initial begin
        #1000;

        // ---------- B3 抖动阶段 ----------
        repeat (6) begin
            #1000 artificial_B3 <= ~artificial_B3;
        end
        artificial_B3 <= 1'b0;   // 稳定按下
        #40_000_000;             // 40ms
        artificial_B3 <= 1'b1;   // 松开
        #40_000_000;             // 40ms 保持

        // ---------- B4 抖动阶段 ----------
        repeat (6) begin
            #1000 artificial_B4 <= ~artificial_B4;
        end
        artificial_B4 <= 1'b0;   // 稳定按下
        #40_000_000;
        artificial_B4 <= 1'b1;   // 松开
        #40_000_000;

        #20_000_000;
        $finish;
    end

    // 实例化被测模块
    debounce debounce_inst(
        .vga_clk            (artificial_vga_clk),
        .sys_rst_n          (artificial_sys_rst_n),
        .B3                 (artificial_B3),
        .B4                 (artificial_B4),
        .left_key_flag      (recorder_left_key_flag),
        .right_key_flag     (recorder_right_key_flag),
        .left_falling_edge  (recorder_left_falling_edge),
        .right_falling_edge (recorder_right_falling_edge)
    );

    // 层次化信号映射 (用于波形观察)
    assign recorder_cnt_press_left   = debounce_inst.cnt_press_left;
    assign recorder_cnt_release_left = debounce_inst.cnt_release_left;
    assign recorder_cnt_press_right  = debounce_inst.cnt_press_right;
    assign recorder_cnt_release_right= debounce_inst.cnt_release_right;

endmodule