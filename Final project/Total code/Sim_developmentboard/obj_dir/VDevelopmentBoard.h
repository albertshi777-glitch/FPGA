// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VDEVELOPMENTBOARD_H_
#define _VDEVELOPMENTBOARD_H_  // guard

#include "verilated.h"

//==========

class VDevelopmentBoard__Syms;

//----------

VL_MODULE(VDevelopmentBoard) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(B2,0,0);
    VL_IN8(B3,0,0);
    VL_IN8(B4,0,0);
    VL_IN8(B5,0,0);
    VL_OUT8(h_sync,0,0);
    VL_OUT8(v_sync,0,0);
    VL_OUT8(led1,0,0);
    VL_OUT8(led2,0,0);
    VL_OUT8(led3,0,0);
    VL_OUT8(led4,0,0);
    VL_OUT8(led5,0,0);
    VL_OUT16(rgb,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
    CData/*1:0*/ DevelopmentBoard__DOT__st_cur;
    CData/*1:0*/ DevelopmentBoard__DOT__st_next;
    CData/*0:0*/ DevelopmentBoard__DOT__button_prev;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__all_clear;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag;
    CData/*7:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_prev;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_prev;
    CData/*1:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel;
    CData/*5:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx;
    CData/*5:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag;
    CData/*3:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on;
    CData/*1:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y;
    SData/*15:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1;
    SData/*10:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w;
    SData/*15:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt;
    SData/*10:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x;
    SData/*10:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y;
    SData/*15:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx1;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by1;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    SData/*9:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v;
    IData/*23:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat;
    IData/*19:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left;
    IData/*19:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left;
    IData/*19:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right;
    IData/*19:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right;
    IData/*31:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index;
    IData/*31:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index;
    IData/*31:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx;
    IData/*31:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx;
    IData/*31:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index;
    QData/*47:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1;
    CData/*1:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3;
    CData/*1:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4;
    CData/*1:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5;
    CData/*1:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6;
    CData/*0:0*/ DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7;
    CData/*3:0*/ __Vtableidx1;
    CData/*0:0*/ __VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__reset;
    CData/*0:0*/ __Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
    CData/*0:0*/ __Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
    static CData/*1:0*/ __Vtable1_DevelopmentBoard__DOT__st_next[16];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VDevelopmentBoard__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VDevelopmentBoard);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VDevelopmentBoard(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VDevelopmentBoard();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VDevelopmentBoard__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VDevelopmentBoard__Syms* symsp, bool first);
  private:
    static QData _change_request(VDevelopmentBoard__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__6(VDevelopmentBoard__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VDevelopmentBoard__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VDevelopmentBoard__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VDevelopmentBoard__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VDevelopmentBoard__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VDevelopmentBoard__Syms* __restrict vlSymsp);
    static void _sequent__TOP__4(VDevelopmentBoard__Syms* __restrict vlSymsp);
    static void _sequent__TOP__5(VDevelopmentBoard__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VDevelopmentBoard__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
