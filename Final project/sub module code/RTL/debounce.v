`timescale 1ns / 1ps
module debounce (
    input  wire vga_clk,      
    input  wire sys_rst_n,    
    input  wire B3,          
    input  wire B4,          
    output reg  left_key_flag,    
    output reg  right_key_flag,   
    output wire left_falling_edge, 
    output wire right_falling_edge  
);



    parameter CNT_20MS_MAX = 20'd125_000; 

    // 左移键(D键, B3)去抖

    reg [19:0] cnt_press_left;
    reg [19:0] cnt_release_left;

    // 按下计数器
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            cnt_press_left <= 20'd0;
        else if (B3)
            cnt_press_left <= 20'd0; 
        else if (cnt_press_left == CNT_20MS_MAX)
            cnt_press_left <= cnt_press_left;
        else
            cnt_press_left <= cnt_press_left + 1'd1;
    end

    // 释放计数器
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            cnt_release_left <= 20'd0;
        else if (!B3)
            cnt_release_left <= 20'd0; // 按下时清零
        else if (cnt_release_left == CNT_20MS_MAX)
            cnt_release_left <= cnt_release_left;
        else
            cnt_release_left <= cnt_release_left + 1'd1;
    end

    // 更新左移标志位
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            left_key_flag <= 1'b1;
        else if (cnt_press_left >= CNT_20MS_MAX - 1)
            left_key_flag <= 1'b0; // 确认按下
        else if (cnt_release_left >= CNT_20MS_MAX - 1)
            left_key_flag <= 1'b1; // 确认释放
        else
            left_key_flag <= left_key_flag;
    end


    // 右移键(F键, B4)去抖
  
    reg [19:0] cnt_press_right;
    reg [19:0] cnt_release_right;

    // 按下计数器
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            cnt_press_right <= 20'd0;
        else if (B4)
            cnt_press_right <= 20'd0;
        else if (cnt_press_right == CNT_20MS_MAX)
            cnt_press_right <= cnt_press_right;
        else
            cnt_press_right <= cnt_press_right + 1'd1;
    end

    // 释放计数器
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            cnt_release_right <= 20'd0;
        else if (!B4)
            cnt_release_right <= 20'd0;
        else if (cnt_release_right == CNT_20MS_MAX)
            cnt_release_right <= cnt_release_right;
        else
            cnt_release_right <= cnt_release_right + 1'd1;
    end

    // 更新右移标志位
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            right_key_flag <= 1'b1;
        else if (cnt_press_right >= CNT_20MS_MAX - 1)
            right_key_flag <= 1'b0;
        else if (cnt_release_right >= CNT_20MS_MAX - 1)
            right_key_flag <= 1'b1;
        else
            right_key_flag <= right_key_flag;
    end

    // 边沿检测 (Edge Detection)
    reg left_prev = 1'b1;
    reg right_prev = 1'b1;

    // 左键下降沿检测
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            left_prev <= 1'b1;
        else
            left_prev <= left_key_flag;
    end
    assign left_falling_edge = (left_prev == 1'b1 && left_key_flag == 1'b0);

    // 右键下降沿检测
    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            right_prev <= 1'b1;
        else
            right_prev <= right_key_flag;
    end
    assign right_falling_edge = (right_prev == 1'b1 && right_key_flag == 1'b0);

endmodule