`timescale 1ns / 1ns

module DevelopmentBoard(
    input wire clk, //50MHz
    input wire reset, B2, B3, B4, B5,
	 // reset is "a"
	 // B2 is "s"
	 // B3 is "d"
	 // B4 is "f"
	 // B5 is "g"
    output wire h_sync, v_sync,
    output wire [15:0] rgb
);


    parameter GET_COLORBAR = 2'd0;
    parameter GET_MUST     = 2'd1;
    parameter GET_END      = 2'd2;
    reg [1:0] st_cur = GET_COLORBAR;
    reg [1:0] st_next = GET_COLORBAR;
    reg button_prev=1'b1;

wire button_falling = (button_prev == 1'b1 && B2 == 1'b0);
always @(posedge clk or negedge reset) begin
        if (!reset)
            button_prev <= 1'b1;
        else
            button_prev <= B2;
    end

always @(posedge clk or negedge reset) begin
        if (!reset)
            st_cur <= GET_END;
        else
            st_cur <= st_next;
    end

    always @(*) begin
        st_next = st_cur;
        if (!reset)
        st_next = GET_COLORBAR;
        case (st_cur)
            GET_COLORBAR: if (button_falling) st_next = GET_MUST;
            GET_MUST:     if (button_falling) st_next = GET_END;
            GET_END:      if (button_falling) st_next = GET_COLORBAR;
            default:      st_next = GET_END;
        endcase
    end
wire [1:0] mode_sel = st_cur;

    vga_display vga_display_inst(
        .sys_clk(clk),
        .sys_rst_n(reset),
        .mode_sel(mode_sel),
        .hsync(h_sync),
        .vsync(v_sync),
        .rgb(rgb)
    );

    


endmodule
