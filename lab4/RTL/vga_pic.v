module vga_pic(
    input wire        vga_clk ,    
    input wire        sys_rst_n,
    input wire [9:0]  pix_x,     
    input wire [9:0]  pix_y, 
	 input wire [1:0]  mode_sel,	 
    output reg [15:0] pix_data   
);



    parameter H_VALID = 10'd640;
    parameter V_VALID = 10'd480; 

    parameter RED     = 16'hF800;
    parameter ORANGE  = 16'hFC00; 
    parameter YELLOW  = 16'hFFE0;
    parameter GREEN   = 16'h07E0;
    parameter CYAN    = 16'h07FF;
    parameter BLUE    = 16'h001F;
    parameter PURPPLE = 16'hF81F;
    parameter BLACK   = 16'h0000;
    parameter WHITE   = 16'hFFFF;
    parameter GRAY    = 16'hD69A;
    parameter CHAR_W = 90;    
    parameter CHAR_H = 180;   
    parameter GAP    = 20;   
    parameter TOTAL_W = 4*CHAR_W + 3*GAP;
    parameter START_X = (H_VALID - TOTAL_W)/2;
    parameter START_Y = (V_VALID - CHAR_H)/2;
    parameter X_M = START_X;
    parameter X_U = START_X + (CHAR_W + GAP);
    parameter X_S = START_X + 2*(CHAR_W + GAP);
    parameter X_T = START_X + 3*(CHAR_W + GAP);
	 localparam BAR_WIDTH = H_VALID / 10;
	 
	 // ===== END pattern coordinates =====
	parameter TOTAL_W_END = 3*CHAR_W + 2*GAP;
	parameter START_X_END = (H_VALID - TOTAL_W_END)/2;
	parameter START_Y_END = (V_VALID - CHAR_H)/2;
	
	parameter X_E = START_X_END;
	parameter X_N = START_X_END + (CHAR_W + GAP);
	parameter X_D = START_X_END + 2*(CHAR_W + GAP);

	wire in_E, in_N, in_D;

    wire in_M, in_U, in_S, in_T;
    assign in_M =
        (pix_x >= X_M) && (pix_x < X_M + CHAR_W) &&
        (pix_y >= START_Y) && (pix_y < START_Y + CHAR_H) &&
        (
           
            (pix_x < X_M + 10) ||
          
            (pix_x > X_M + CHAR_W - 10) ||
           
            (((pix_x >= X_M + 10) && (pix_x <= X_M + CHAR_W/2)) &&
             ((pix_y - START_Y) >= (pix_x - (X_M+10))/2 - 5) &&
             ((pix_y - START_Y) <= (pix_x - (X_M+10))/2 + 5)) ||
           
            (((pix_x >= X_M + CHAR_W/2) && (pix_x <= X_M + CHAR_W - 10)) &&
             ((pix_y - START_Y) >= (X_M + CHAR_W - 10 - pix_x)/2 - 5) &&
             ((pix_y - START_Y) <= (X_M + CHAR_W - 10 - pix_x)/2 + 5))
        );
    assign in_U =
        (pix_x >= X_U) && (pix_x < X_U + CHAR_W) &&
        (pix_y >= START_Y) && (pix_y < START_Y + CHAR_H) &&
        (
            (pix_x < X_U + 10) ||                       
            (pix_x > X_U + CHAR_W - 10) ||       
            (pix_y > START_Y + CHAR_H - 10)                
        );
    assign in_S =
        (pix_x >= X_S) && (pix_x < X_S + CHAR_W) &&
        (pix_y >= START_Y) && (pix_y < START_Y + CHAR_H) &&
        (
            (pix_y < START_Y + 10) ||                                      
            (pix_y > START_Y + CHAR_H - 10) ||                             
            ((pix_y > START_Y + CHAR_H/2 - 5) && (pix_y < START_Y + CHAR_H/2 + 5)) || 
            ((pix_y < START_Y + CHAR_H/2) && (pix_x < X_S + 10)) ||         
            ((pix_y > START_Y + CHAR_H/2) && (pix_x > X_S + CHAR_W - 10))   
        );

    assign in_T =
        (pix_x >= X_T) && (pix_x < X_T + CHAR_W) &&
        (pix_y >= START_Y) && (pix_y < START_Y + CHAR_H) &&
        (
            (pix_y < START_Y + 10) ||                                
            (pix_x > X_T + CHAR_W/2 - 5 && pix_x < X_T + CHAR_W/2 + 5)     
        );

		  
		  
		  // ----- E -----
assign in_E =
    (pix_x >= X_E) && (pix_x < X_E + CHAR_W) &&
    (pix_y >= START_Y_END) && (pix_y < START_Y_END + CHAR_H) &&
    (
        (pix_x < X_E + 10) ||                                             // 左竖线
        (pix_y < START_Y_END + 10) ||                                     // 顶横线
        (pix_y > START_Y_END + CHAR_H - 10) ||                            // 底横线
        ((pix_y > START_Y_END + CHAR_H/2 - 5) && (pix_y < START_Y_END + CHAR_H/2 + 5)) // 中横线
    );

// ----- N -----
assign in_N =
    (pix_x >= X_N) && (pix_x < X_N + CHAR_W) &&
    (pix_y >= START_Y_END) && (pix_y < START_Y_END + CHAR_H) &&
    (
        (pix_x < X_N + 10) ||                                             // 左竖线
        (pix_x > X_N + CHAR_W - 10) ||                                    // 右竖线
        (((pix_x - X_N) >= ((pix_y - START_Y_END)/2 - 5)) &&              // 左下到右上斜线
         ((pix_x - X_N) <= ((pix_y - START_Y_END)/2 + 5)))
    );

// ----- D -----
assign in_D =
    (pix_x >= X_D) && (pix_x < X_D + CHAR_W) &&
    (pix_y >= START_Y_END) && (pix_y < START_Y_END + CHAR_H) &&
    (
        (pix_x < X_D + 10) ||                                             // 左竖线
        ( (pix_x > X_D + CHAR_W - 10) &&                                  // 右曲线外沿
          ((pix_y - START_Y_END) > 10) &&
          ((pix_y - START_Y_END) < CHAR_H - 10)) ||
        (((pix_y < START_Y_END + 10) ||                                   // 顶边
          (pix_y > START_Y_END + CHAR_H - 10)) && 
          (pix_x > X_D + CHAR_W/3))                                       // 顶底边外弧部分
    );
		  
		  

	
	
	
    always @(posedge vga_clk or negedge sys_rst_n) begin
    if (!sys_rst_n)
        pix_data <= 16'd0;
    else begin
        case (mode_sel)  // 由外部状态机控制
            2'd0: begin
                // 彩条
                if (pix_x < BAR_WIDTH)
                    pix_data <= RED;         // 0-63
                else if (pix_x < BAR_WIDTH * 2)
                    pix_data <= ORANGE;      // 64-127
                else if (pix_x < BAR_WIDTH * 3)
                    pix_data <= YELLOW;      // 128-191
                else if (pix_x < BAR_WIDTH * 4)
                    pix_data <= GREEN;       // 192-255
                else if (pix_x < BAR_WIDTH * 5)
                    pix_data <= CYAN;        // 256-319
                else if (pix_x < BAR_WIDTH * 6)
                    pix_data <= BLUE;        // 320-383
                else if (pix_x < BAR_WIDTH * 7)
                    pix_data <= PURPPLE;     // 384-447
                else if (pix_x < BAR_WIDTH * 8)
                    pix_data <= BLACK;       // 448-511
                else if (pix_x < BAR_WIDTH * 9)
                    pix_data <= WHITE;       // 512-575
                else
                    pix_data <= GRAY;        // 576-639
            end
            2'd1: begin
                // MUST
                if (in_M)
                    pix_data <= RED;
                else if (in_U)
                    pix_data <= GREEN;
                else if (in_S)
                    pix_data <= BLUE;
                else if (in_T)
                    pix_data <= YELLOW;
                else
                    pix_data <= BLACK;
            end

            2'd2: begin
                // END
                if (in_E)
                    pix_data <= CYAN;
                else if (in_N)
                    pix_data <= PURPPLE;
                else if (in_D)
                    pix_data <= YELLOW;
                else
                    pix_data <= BLACK;
            end

            default: pix_data <= BLACK;
        endcase
    end
end
endmodule