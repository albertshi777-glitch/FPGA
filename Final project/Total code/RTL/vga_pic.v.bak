module vga_pic(
    input wire        vga_clk ,    
    input wire        sys_rst_n,
    input wire [9:0]  pix_x,     
    input wire [9:0]  pix_y,       
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

    always @(posedge vga_clk or negedge sys_rst_n) begin
        if (!sys_rst_n)
            pix_data <= 16'd0;
        else begin
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
    end
endmodule