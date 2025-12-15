// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard.h"
#include "VDevelopmentBoard__Syms.h"

//==========
CData/*1:0*/ VDevelopmentBoard::__Vtable1_DevelopmentBoard__DOT__st_next[16];

VL_CTOR_IMP(VDevelopmentBoard) {
    VDevelopmentBoard__Syms* __restrict vlSymsp = __VlSymsp = new VDevelopmentBoard__Syms(this, name());
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VDevelopmentBoard::__Vconfigure(VDevelopmentBoard__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VDevelopmentBoard::~VDevelopmentBoard() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VDevelopmentBoard::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VDevelopmentBoard::eval\n"); );
    VDevelopmentBoard__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/mnt/hgfs/project_test/Sim_developmentboard/DevelopmentBoard.v", 3, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDevelopmentBoard::_eval_initial_loop(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("/mnt/hgfs/project_test/Sim_developmentboard/DevelopmentBoard.v", 3, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VDevelopmentBoard::_initial__TOP__1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_initial__TOP__1\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__button_prev = 1U;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_prev = 1U;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_prev = 1U;
    vlTOPp->DevelopmentBoard__DOT__st_cur = 0U;
    vlTOPp->DevelopmentBoard__DOT__st_next = 0U;
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__2(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__2\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__button_prev = (1U 
                                                  & ((~ (IData)(vlTOPp->reset)) 
                                                     | (IData)(vlTOPp->B2)));
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 
        = ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25)));
}

void VDevelopmentBoard::_settle__TOP__3(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_settle__TOP__3\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->h_sync = (0x5fU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h));
    vlTOPp->v_sync = (1U >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v));
    vlTOPp->rgb = ((((0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
                     & (0x310U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) 
                    & ((0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v)) 
                       & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v))))
                    ? (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data)
                    : 0U);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req 
        = (((0x8fU <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
            & (0x30fU > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) 
           & ((0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v)) 
              & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v))));
    vlTOPp->__Vtableidx1 = ((((IData)(vlTOPp->DevelopmentBoard__DOT__button_prev) 
                              & (~ (IData)(vlTOPp->B2))) 
                             << 3U) | (((IData)(vlTOPp->reset) 
                                        << 2U) | (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur)));
    vlTOPp->DevelopmentBoard__DOT__st_next = vlTOPp->__Vtable1_DevelopmentBoard__DOT__st_next
        [vlTOPp->__Vtableidx1];
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h) 
                         - (IData)(0x8fU))) : 0x3ffU);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v) 
                         - (IData)(0x23U))) : 0x3ffU);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on = 0U;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp = 0U;
    if (((0x28U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
         & (0x76U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))) {
        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx 
            = VL_DIV_III(32, ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                              - (IData)(0x28U)), (IData)(0x1aU));
        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx 
            = VL_DIV_III(32, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x), (IData)(0x50U));
        if ((VL_GTS_III(1,32,32, 3U, vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx) 
             & VL_GTS_III(1,32,32, 8U, vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx))) {
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0 
                = (0x3ffU & ((IData)(0x50U) * vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx));
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0 
                = (0x3ffU & ((IData)(0x28U) + VL_MULS_III(10,32,32, (IData)(0x1aU), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx)));
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx1 
                = (0x3ffU & ((IData)(0x4aU) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0)));
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by1 
                = (0x3ffU & ((IData)(0x14U) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0)));
            if ((((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                    >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0)) 
                   & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx1))) 
                  & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                     >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0))) 
                 & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                    < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by1)))) {
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index 
                    = (VL_MULS_III(32,32,32, (IData)(8U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx) 
                       + vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx);
                if (((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)) 
                     & (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                        >> (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on = 1U;
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp 
                        = ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)))
                            ? (3U & (IData)((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                             >> (0x3fU 
                                                 & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)))))
                            : 0U);
                }
            }
        }
    }
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__4(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__4\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*7:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr;
    CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag;
    CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag;
    CData/*5:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx;
    CData/*5:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy;
    CData/*0:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag;
    CData/*3:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd;
    SData/*15:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt;
    SData/*15:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt;
    SData/*10:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x;
    SData/*10:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y;
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x;
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w;
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    IData/*19:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left;
    IData/*19:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left;
    IData/*19:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right;
    IData/*19:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right;
    IData/*23:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat;
    QData/*47:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat;
    // Body
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt 
        = ((IData)(vlTOPp->reset) ? (0xffffU & ((IData)(1U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt)))
            : 0U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt 
        = ((IData)(vlTOPp->reset) ? (0xffffU & ((IData)(1U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt)))
            : 0U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr 
        = ((IData)(vlTOPp->reset) ? ((0xfeU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                               << 1U)) 
                                     | (1U & (((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                                 >> 7U) 
                                                ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                                   >> 5U)) 
                                               ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                                  >> 4U)) 
                                              ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                                 >> 3U))))
            : 0xa5U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right 
        = ((IData)(vlTOPp->reset) ? ((IData)(vlTOPp->B4)
                                      ? (0xfffffU & 
                                         (((0x1e848U 
                                            == vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right) 
                                           & (IData)(vlTOPp->B4))
                                           ? vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right
                                           : ((IData)(1U) 
                                              + vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right)))
                                      : 0U) : 0U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right 
        = ((IData)(vlTOPp->reset) ? ((IData)(vlTOPp->B4)
                                      ? 0U : (0xfffffU 
                                              & (((0x1e848U 
                                                   == vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right) 
                                                  & (~ (IData)(vlTOPp->B4)))
                                                  ? vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right
                                                  : 
                                                 ((IData)(1U) 
                                                  + vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right))))
            : 0U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left 
        = ((IData)(vlTOPp->reset) ? ((IData)(vlTOPp->B3)
                                      ? (0xfffffU & 
                                         (((0x1e848U 
                                            == vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left) 
                                           & (IData)(vlTOPp->B3))
                                           ? vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left
                                           : ((IData)(1U) 
                                              + vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left)))
                                      : 0U) : 0U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left 
        = ((IData)(vlTOPp->reset) ? ((IData)(vlTOPp->B3)
                                      ? 0U : (0xfffffU 
                                              & (((0x1e848U 
                                                   == vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left) 
                                                  & (~ (IData)(vlTOPp->B3)))
                                                  ? vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left
                                                  : 
                                                 ((IData)(1U) 
                                                  + vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left))))
            : 0U);
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag 
        = (1U & ((~ (IData)(vlTOPp->reset)) | ((0x1e847U 
                                                > vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right) 
                                               & ((0x1e847U 
                                                   <= vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right) 
                                                  | (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag)))));
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag 
        = (1U & ((~ (IData)(vlTOPp->reset)) | ((0x1e847U 
                                                > vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left) 
                                               & ((0x1e847U 
                                                   <= vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left) 
                                                  | (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag)))));
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data 
        = ((IData)(vlTOPp->reset) ? ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel))
                                      ? ((((((((((0x37U 
                                                  <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                 & (0x91U 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                & (0x96U 
                                                   <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                               & (0x14aU 
                                                  > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                              & (((((0xa0U 
                                                     > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                    | (0x140U 
                                                       < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                   | ((0xebU 
                                                       < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                      & (0xf5U 
                                                         > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))) 
                                                  | ((0xf0U 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                     & (0x41U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))) 
                                                 | ((0xf0U 
                                                     < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                    & (0x87U 
                                                       < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))))) 
                                             | (((((0xa5U 
                                                    <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                   & (0xffU 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                  & (0x96U 
                                                     <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                 & (0x14aU 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                & ((0xa0U 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                   | ((0xcdU 
                                                       < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                      & (0xd7U 
                                                         > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))))) 
                                            | (((((0x113U 
                                                   <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                  & (0x16dU 
                                                     > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                 & (0x96U 
                                                    <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                & (0x14aU 
                                                   > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                               & ((((0x11dU 
                                                     > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                    | (0x163U 
                                                       < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                   | (0xa0U 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                  | ((0xebU 
                                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                     & (0xf5U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))))) 
                                           | (((((0x181U 
                                                  <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                 & (0x1dbU 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                & (0x96U 
                                                   <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                               & (0x14aU 
                                                  > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                              & (((((0x18bU 
                                                     > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                    | (0xa0U 
                                                       > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                   | ((0xebU 
                                                       < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                      & (0xf5U 
                                                         > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))) 
                                                  | ((0x1d1U 
                                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                     & (0xf0U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))) 
                                                 | ((((0xf0U 
                                                       <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                      & (0x14aU 
                                                         >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                     & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                         - (IData)(0xf0U)) 
                                                        > 
                                                        VL_DIV_III(32, 
                                                                   (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                                     - (IData)(0x19fU)) 
                                                                    << 2U), (IData)(5U)))) 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                        - (IData)(0xf0U)) 
                                                       < 
                                                       VL_DIV_III(32, 
                                                                  ((IData)(0xbU) 
                                                                   * 
                                                                   ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                                    - (IData)(0x186U))), (IData)(0xaU))))))) 
                                          | (((((0x1efU 
                                                 <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                & (0x249U 
                                                   > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                               & (0x96U 
                                                  <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                              & (0x14aU 
                                                 > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                             & ((0xa0U 
                                                 > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                | ((0x217U 
                                                    < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                   & (0x221U 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))))))
                                          ? 0xffffU
                                          : 0U) : (
                                                   (1U 
                                                    == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel))
                                                    ? 
                                                   ((((((1U 
                                                         == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel)) 
                                                        & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                           >= 
                                                           ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                            - (IData)(4U)))) 
                                                       & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                          <= 
                                                          ((IData)(4U) 
                                                           + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                                      & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                         >= 
                                                         ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                          - (IData)(4U)))) 
                                                     & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                        <= 
                                                        ((IData)(4U) 
                                                         + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y))))
                                                     ? 0xffffU
                                                     : 
                                                    ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on)
                                                      ? 
                                                     ((2U 
                                                       == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp))
                                                       ? 0x1fU
                                                       : 
                                                      ((1U 
                                                        == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp))
                                                        ? 0xf800U
                                                        : 0U))
                                                      : 
                                                     (((((0x1b8U 
                                                          <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                         & (0x1c2U 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                        & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                           >= 
                                                           ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                                            - 
                                                            ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                                             >> 1U)))) 
                                                       & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                          < 
                                                          ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                                           + 
                                                           ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                                            >> 1U))))
                                                       ? 0x7e0U
                                                       : 0U)))
                                                    : 
                                                   ((2U 
                                                     == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel))
                                                     ? 
                                                    ((((((0xa5U 
                                                          <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                         & (0xffU 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                        & (0x96U 
                                                           <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                       & (0x14aU 
                                                          > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                      & ((((0xafU 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                           | (0xa0U 
                                                              > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                          | (0x140U 
                                                             < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                         | ((0xebU 
                                                             < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                            & (0xf5U 
                                                               > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))))
                                                      ? 0x7ffU
                                                      : 
                                                     ((((((0x113U 
                                                           <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                          & (0x16dU 
                                                             > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                         & (0x96U 
                                                            <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                        & (0x14aU 
                                                           > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                       & (((0x11dU 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                           | (0x163U 
                                                              < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                          | ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                               - (IData)(0x113U)) 
                                                              >= 
                                                              ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                                 - (IData)(0x96U)) 
                                                                >> 1U) 
                                                               - (IData)(5U))) 
                                                             & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                                 - (IData)(0x113U)) 
                                                                <= 
                                                                ((IData)(5U) 
                                                                 + 
                                                                 (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                                   - (IData)(0x96U)) 
                                                                  >> 1U))))))
                                                       ? 0xf81fU
                                                       : 
                                                      ((((((0x181U 
                                                            <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                           & (0x1dbU 
                                                              > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                          & (0x96U 
                                                             <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                         & (0x14aU 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                        & (((0x18bU 
                                                             > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                            | (((0x1d1U 
                                                                 < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                                & (0xaU 
                                                                   < 
                                                                   ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                                    - (IData)(0x96U)))) 
                                                               & (0xaaU 
                                                                  > 
                                                                  ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                                   - (IData)(0x96U))))) 
                                                           | (((0xa0U 
                                                                > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                               | (0x140U 
                                                                  < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                              & (0x19fU 
                                                                 < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))))
                                                        ? 0xffe0U
                                                        : 0U)))
                                                     : 0U)))
            : 0U);
    if (vlTOPp->reset) {
        if ((2U != (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel))) {
            if ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur))) {
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x = 0x140U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y = 0x187U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx = 0U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = 4U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag = 1U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x = 0x140U;
                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w = 0x8cU;
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = 0U;
                if ((1U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                           ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                              >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x10U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 1U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 1U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x20U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 2U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 2U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x40U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 3U;
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                            & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                           | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                              << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                        = (((~ (VL_ULL(3) << (0x3fU 
                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                            & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                           | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                              << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 4U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 4U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 5U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 5U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 6U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 6U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 7U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 7U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((8U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 8U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 1U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x20U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 9U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 2U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 4U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x40U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0xaU;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 3U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 5U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x80U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0xbU;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 4U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 6U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0xcU;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 5U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 7U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0xdU;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 6U) ^ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0xeU;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 7U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 1U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((8U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0xfU;
                if ((1U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                           ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                              >> 2U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x10U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x10U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 2U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x40U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x11U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 3U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 5U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x80U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x12U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 4U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 7U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((1U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x13U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 5U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 1U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((2U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x14U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 6U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 3U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((4U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x15U;
                if ((1U & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                            >> 7U) ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                                      >> 5U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((8U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x16U;
                if ((1U & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                           ^ ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr) 
                              >> 7U)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = 1U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 
                        = ((0x10U & (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr))
                            ? 2U : 1U);
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                } else {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                    if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                            = (((~ ((IData)(1U) << 
                                    (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                                  << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                    }
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                    if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                            = (((~ (VL_ULL(3) << (0x3fU 
                                                  & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                                  << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                    }
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = 0x17U;
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = 0U;
                if ((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) {
                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                        = (((~ ((IData)(1U) << (0x1fU 
                                                & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))) 
                            & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                           | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3) 
                              << (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)));
                }
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = 0U;
                if ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) {
                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                        = (((~ (VL_ULL(3) << (0x3fU 
                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index)))) 
                            & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                           | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4)) 
                              << (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index))));
                }
            } else {
                if ((1U == (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = 1U;
                    if ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_prev) 
                          & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag))) 
                         | ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt)) 
                            & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag))))) {
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x 
                            = (0x3ffU & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                          > ((IData)(0xaU) 
                                             + ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                                >> 1U)))
                                          ? ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                             - (IData)(0xaU))
                                          : ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                             >> 1U)));
                    } else {
                        if ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_prev) 
                              & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag))) 
                             | ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt)) 
                                & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag))))) {
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x 
                                = (0x3ffU & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                              < (((IData)(0x280U) 
                                                  - 
                                                  ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                                   >> 1U)) 
                                                 - (IData)(0xaU)))
                                              ? ((IData)(0xaU) 
                                                 + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x))
                                              : ((IData)(0x280U) 
                                                 - 
                                                 ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                                  >> 1U))));
                        }
                    }
                    if ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt))) {
                        if ((0U < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd))) {
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd 
                                = (0xfU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd) 
                                           - (IData)(1U)));
                        }
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x 
                            = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                         + VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx))));
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y 
                            = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                         + VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                        if (((((VL_LTES_III(1,32,32, 0x1b8U, 
                                            ((IData)(4U) 
                                             + VL_EXTENDS_II(32,11, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                & VL_GTES_III(1,32,32, 0x1c2U, 
                                              (VL_EXTENDS_II(32,11, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)) 
                                               - (IData)(4U)))) 
                               & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                  >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                      - ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                         >> 1U)))) 
                              & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                 <= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                     + ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                        >> 1U)))) & 
                             VL_LTS_III(1,32,32, 0U, 
                                        VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))))) {
                            if (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag) {
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = 0x3cU;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx = 0U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag = 0U;
                            } else {
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = 0x3cU;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                    = (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                        < ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                           - ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                              >> 2U)))
                                        ? 0x3bU : (
                                                   ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                    < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x))
                                                    ? 0x3cU
                                                    : 
                                                   (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                     > 
                                                     ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x) 
                                                      + 
                                                      ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                                       >> 2U)))
                                                     ? 5U
                                                     : 4U)));
                                if ((0x28U < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w 
                                        = (0x3ffU & 
                                           ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w) 
                                            - (IData)(0x14U)));
                                }
                            }
                        }
                        if (VL_GTES_III(1,32,32, 4U, 
                                        VL_EXTENDS_II(32,11, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) {
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                = (VL_GTES_III(1,32,32, 0U, 
                                               VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)))
                                    ? 4U : (0x3fU & 
                                            VL_NEGATE_I(
                                                        VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)))));
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x = 5U;
                        } else {
                            if ((0x27cU <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x))) {
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                    = (VL_LTES_III(1,32,32, 0U, 
                                                   VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)))
                                        ? 0x3cU : (0x3fU 
                                                   & VL_NEGATE_I(
                                                                 VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)))));
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x = 0x27bU;
                            }
                        }
                        if (VL_GTES_III(1,32,32, 4U, 
                                        VL_EXTENDS_II(32,11, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) {
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                = (VL_GTES_III(1,32,32, 0U, 
                                               VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)))
                                    ? 4U : (0x3fU & 
                                            VL_NEGATE_I(
                                                        VL_EXTENDS_II(32,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)))));
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y = 5U;
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 0U;
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0U;
                        if ((1U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if ((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                    & (0x4aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 1U;
                        if ((2U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x50U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x9aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 2U;
                        if ((4U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0xa0U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0xeaU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 3U;
                        if ((8U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0xf0U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x13aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 4U;
                        if ((0x10U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x140U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x18aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 5U;
                        if ((0x20U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x190U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x1daU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 6U;
                        if ((0x40U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x1e0U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x22aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 7U;
                        if ((0x80U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x28U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x3cU;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x230U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x27aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x28U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x3cU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 8U;
                        if ((0x100U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if ((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                    & (0x4aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 9U;
                        if ((0x200U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x50U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x9aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0xaU;
                        if ((0x400U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0xa0U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0xeaU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0xbU;
                        if ((0x800U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0xf0U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x13aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0xcU;
                        if ((0x1000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x140U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x18aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0xdU;
                        if ((0x2000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x190U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x1daU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0xeU;
                        if ((0x4000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x1e0U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x22aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0xfU;
                        if ((0x8000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x42U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x56U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x230U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x27aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x42U <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x56U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x10U;
                        if ((0x10000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if ((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                    & (0x4aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x11U;
                        if ((0x20000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x50U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x9aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x12U;
                        if ((0x40000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0xa0U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0xeaU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                 - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x13U;
                        if ((0x80000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0xf0U <= ((IData)(4U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x13aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x14U;
                        if ((0x100000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x140U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x18aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x15U;
                        if ((0x200000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x190U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x1daU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x16U;
                        if ((0x400000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x1e0U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x22aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = 0x17U;
                        if ((0x800000U & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat)) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = 0x5cU;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = 0x70U;
                            if (((((((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd)) 
                                     & (0x230U <= ((IData)(4U) 
                                                   + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x)))) 
                                    & (0x27aU >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x) 
                                                  - (IData)(4U)))) 
                                   & (0x5cU <= ((IData)(4U) 
                                                + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y)))) 
                                  & (0x70U >= ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                               - (IData)(4U)))) 
                                 & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag)))) {
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp 
                                    = (0x7ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y) 
                                                 - 
                                                 VL_EXTENDS_II(11,6, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy))));
                                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = 1U;
                                __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 4U;
                                if ((1U < ((0x2fU >= 
                                            (0x3fU 
                                             & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                            ? (3U & (IData)(
                                                            (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                             >> 
                                                             (0x3fU 
                                                              & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))))
                                            : 0U))) {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 
                                        = (3U & (((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))
                                                   ? (IData)(
                                                             (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                                              >> 
                                                              (0x3fU 
                                                               & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))))
                                                   : 0U) 
                                                 - (IData)(1U)));
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                } else {
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = 0U;
                                    if ((0x2fU >= (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                            = (((~ 
                                                 (VL_ULL(3) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat) 
                                               | ((QData)((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6)) 
                                                  << 
                                                  (0x3fU 
                                                   & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))));
                                    }
                                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = 0U;
                                    if ((0x17U >= (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) {
                                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                                            = (((~ 
                                                 ((IData)(1U) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index))) 
                                                & __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat) 
                                               | ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7) 
                                                  << 
                                                  (0x1fU 
                                                   & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index)));
                                    }
                                }
                                if (((((IData)(4U) 
                                       + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp)) 
                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0)) 
                                     | (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp) 
                                         - (IData)(4U)) 
                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1)))) {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy)));
                                } else {
                                    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
                                        = (0x3fU & 
                                           VL_NEGATE_I((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx)));
                                }
                            }
                        }
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__all_clear 
                            = (0U == vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat);
                        if (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__all_clear) {
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = 2U;
                        }
                        if ((0x1dcU <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y))) {
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y = 0x1dcU;
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx = 0U;
                            __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = 0U;
                            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = 2U;
                        }
                    }
                } else {
                    if ((2U == (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur))) {
                        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = 2U;
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx = 0U;
                        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = 0U;
                    }
                }
            }
        }
    } else {
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x = 0x140U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y = 0x187U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx = 0U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = 4U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag = 1U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = 0U;
        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = 0U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat = 0U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat = VL_ULL(0);
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x = 0x140U;
        __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w = 0x8cU;
    }
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = ((IData)(vlTOPp->reset) ? ((0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))
                                      ? 0U : (0x3ffU 
                                              & ((IData)(1U) 
                                                 + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))))
            : 0U);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v 
        = ((IData)(vlTOPp->reset) ? (((0x20cU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v)) 
                                      & (0x31fU == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h)))
                                      ? 0U : (0x3ffU 
                                              & ((0x31fU 
                                                  == (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))
                                                  ? 
                                                 ((IData)(1U) 
                                                  + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v))
                                                  : (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v))))
            : 0U);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_prev 
        = (1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag)));
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_prev 
        = (1U & ((~ (IData)(vlTOPp->reset)) | (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag)));
    vlTOPp->h_sync = (0x5fU >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h));
    vlTOPp->v_sync = (1U >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v));
    vlTOPp->rgb = ((((0x90U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
                     & (0x310U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) 
                    & ((0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v)) 
                       & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v))))
                    ? (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data)
                    : 0U);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req 
        = (((0x8fU <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h)) 
            & (0x30fU > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h))) 
           & ((0x23U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v)) 
              & (0x203U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v))));
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h) 
                         - (IData)(0x8fU))) : 0x3ffU);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v) 
                         - (IData)(0x23U))) : 0x3ffU);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on = 0U;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp = 0U;
    if (((0x28U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
         & (0x76U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))) {
        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx 
            = VL_DIV_III(32, ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                              - (IData)(0x28U)), (IData)(0x1aU));
        vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx 
            = VL_DIV_III(32, (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x), (IData)(0x50U));
        if ((VL_GTS_III(1,32,32, 3U, vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx) 
             & VL_GTS_III(1,32,32, 8U, vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx))) {
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0 
                = (0x3ffU & ((IData)(0x50U) * vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx));
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0 
                = (0x3ffU & ((IData)(0x28U) + VL_MULS_III(10,32,32, (IData)(0x1aU), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx)));
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx1 
                = (0x3ffU & ((IData)(0x4aU) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0)));
            vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by1 
                = (0x3ffU & ((IData)(0x14U) + (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0)));
            if ((((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                    >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0)) 
                   & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx1))) 
                  & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                     >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0))) 
                 & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                    < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by1)))) {
                vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index 
                    = (VL_MULS_III(32,32,32, (IData)(8U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx) 
                       + vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx);
                if (((0x17U >= (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)) 
                     & (vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat 
                        >> (0x1fU & vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)))) {
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on = 1U;
                    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp 
                        = ((0x2fU >= (0x3fU & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)))
                            ? (3U & (IData)((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat 
                                             >> (0x3fU 
                                                 & VL_MULS_III(6,32,32, (IData)(2U), vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index)))))
                            : 0U);
                }
            }
        }
    }
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__5(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__5\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__st_cur = ((IData)(vlTOPp->reset)
                                              ? (IData)(vlTOPp->DevelopmentBoard__DOT__st_next)
                                              : 0U);
}

VL_INLINE_OPT void VDevelopmentBoard::_combo__TOP__6(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_combo__TOP__6\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vtableidx1 = ((((IData)(vlTOPp->DevelopmentBoard__DOT__button_prev) 
                              & (~ (IData)(vlTOPp->B2))) 
                             << 3U) | (((IData)(vlTOPp->reset) 
                                        << 2U) | (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur)));
    vlTOPp->DevelopmentBoard__DOT__st_next = vlTOPp->__Vtable1_DevelopmentBoard__DOT__st_next
        [vlTOPp->__Vtableidx1];
}

void VDevelopmentBoard::_eval(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__5(vlSymsp);
    }
    vlTOPp->_combo__TOP__6(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 
        = vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
    vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
}

void VDevelopmentBoard::_eval_initial(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_initial\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
    vlTOPp->__Vclklast__TOP__reset = vlTOPp->reset;
    vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 
        = vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
}

void VDevelopmentBoard::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::final\n"); );
    // Variables
    VDevelopmentBoard__Syms* __restrict vlSymsp = this->__VlSymsp;
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VDevelopmentBoard::_eval_settle(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_settle\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25));
    VL_DEBUG_IF( if(__req && ((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25))) VL_DBG_MSGF("        CHANGE: /mnt/hgfs/project_test/Sim_developmentboard/../RTL/pll.v:7: DevelopmentBoard.vga_display_inst.pll_inst.clk_25\n"); );
    // Final
    vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25;
    return __req;
}

#ifdef VL_DEBUG
void VDevelopmentBoard::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((B2 & 0xfeU))) {
        Verilated::overWidthError("B2");}
    if (VL_UNLIKELY((B3 & 0xfeU))) {
        Verilated::overWidthError("B3");}
    if (VL_UNLIKELY((B4 & 0xfeU))) {
        Verilated::overWidthError("B4");}
    if (VL_UNLIKELY((B5 & 0xfeU))) {
        Verilated::overWidthError("B5");}
}
#endif  // VL_DEBUG

void VDevelopmentBoard::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    B2 = VL_RAND_RESET_I(1);
    B3 = VL_RAND_RESET_I(1);
    B4 = VL_RAND_RESET_I(1);
    B5 = VL_RAND_RESET_I(1);
    h_sync = VL_RAND_RESET_I(1);
    v_sync = VL_RAND_RESET_I(1);
    rgb = VL_RAND_RESET_I(16);
    led1 = VL_RAND_RESET_I(1);
    led2 = VL_RAND_RESET_I(1);
    led3 = VL_RAND_RESET_I(1);
    led4 = VL_RAND_RESET_I(1);
    led5 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__st_cur = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__st_next = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__button_prev = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data = VL_RAND_RESET_I(16);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by0 = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__by1 = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__all_clear = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__hit_flag = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__prev_ball_y_temp = VL_RAND_RESET_I(11);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__lfsr = VL_RAND_RESET_I(8);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bricks_flat = VL_RAND_RESET_I(24);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__brick_hp_flat = VL_RAND_RESET_Q(48);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_x = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__paddle_w = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_left = VL_RAND_RESET_I(20);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_left = VL_RAND_RESET_I(20);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_key_flag = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_press_right = VL_RAND_RESET_I(20);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__cnt_release_right = VL_RAND_RESET_I(20);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_key_flag = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__left_prev = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__right_prev = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__move_cnt = VL_RAND_RESET_I(16);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__local_mode_sel = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_x = VL_RAND_RESET_I(11);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_y = VL_RAND_RESET_I(11);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vx = VL_RAND_RESET_I(6);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__vy = VL_RAND_RESET_I(6);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__first_drop_flag = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__bounce_cd = VL_RAND_RESET_I(4);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__ball_cnt = VL_RAND_RESET_I(16);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_on = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__current_brick_hp = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk1__DOT__index = VL_RAND_RESET_I(32);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk2__DOT__index = VL_RAND_RESET_I(32);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_row_idx = VL_RAND_RESET_I(32);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__pix_col_idx = VL_RAND_RESET_I(32);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__index = VL_RAND_RESET_I(32);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx0 = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by0 = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_bx1 = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT__unnamedblk3__DOT__check_by1 = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound1 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound2 = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound3 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound4 = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound5 = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound6 = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_pic_inst__DOT____Vlvbound7 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v = VL_RAND_RESET_I(10);
    __Vtableidx1 = 0;
    __Vtable1_DevelopmentBoard__DOT__st_next[0] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[1] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[2] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[3] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[4] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[5] = 1U;
    __Vtable1_DevelopmentBoard__DOT__st_next[6] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[7] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[8] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[9] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[10] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[11] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[12] = 1U;
    __Vtable1_DevelopmentBoard__DOT__st_next[13] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[14] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[15] = 0U;
    __VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
}
