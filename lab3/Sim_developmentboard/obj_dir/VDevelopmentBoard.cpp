// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VDevelopmentBoard.h for the primary calling header

#include "VDevelopmentBoard.h"
#include "VDevelopmentBoard__Syms.h"

//==========

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
            VL_FATAL_MT("DevelopmentBoard.v", 5, "",
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
            VL_FATAL_MT("DevelopmentBoard.v", 5, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__1(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__1\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 
        = ((IData)(vlTOPp->reset) & (~ (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25)));
}

void VDevelopmentBoard::_settle__TOP__2(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_settle__TOP__2\n"); );
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
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h) 
                         - (IData)(0x8fU))) : 0x3ffU);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v) 
                         - (IData)(0x23U))) : 0x3ffU);
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__3(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__3\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    // Body
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data 
        = ((IData)(vlTOPp->reset) ? ((((((0x50U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                         & (0xa0U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                        & (0xa0U <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                       & (0x140U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                      & (((0x5aU > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                          | (0x96U 
                                             < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                         | ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                              - (IData)(0xa0U)) 
                                             < (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                 - (IData)(0x50U)) 
                                                >> 1U)) 
                                            & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                - (IData)(0xa0U)) 
                                               < (((IData)(0x9fU) 
                                                   - (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                  >> 1U)))))
                                      ? 0xf800U : (
                                                   (((((0xaaU 
                                                        <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                       & (0xfaU 
                                                          > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                      & (0xa0U 
                                                         <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                     & (0x140U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                    & (((0xb4U 
                                                         > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                        | (0xf0U 
                                                           < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                       | (0x136U 
                                                          < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))))
                                                    ? 0x7e0U
                                                    : 
                                                   ((((((0x104U 
                                                         <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                        & (0x154U 
                                                           > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                       & (0xa0U 
                                                          <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                      & (0x140U 
                                                         > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                     & (((((0xaaU 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                           | ((0xebU 
                                                               < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                              & (0xf5U 
                                                                 > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)))) 
                                                          | (0x136U 
                                                             < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                         | ((0xf0U 
                                                             > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                            & (0x10eU 
                                                               > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))) 
                                                        | ((0xf0U 
                                                            < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                           & (0x14aU 
                                                              < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))))
                                                     ? 0x1fU
                                                     : 
                                                    ((((((0x15eU 
                                                          <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                         & (0x1aeU 
                                                            > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                        & (0xa0U 
                                                           <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                       & (0x140U 
                                                          > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                      & ((0xaaU 
                                                          > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                         | ((0x181U 
                                                             < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                            & (0x18bU 
                                                               > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))))
                                                      ? 0xffe0U
                                                      : 0U))))
            : 0U);
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
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
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
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h) 
                         - (IData)(0x8fU))) : 0x3ffU);
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y 
        = ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req)
            ? (0x3ffU & ((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v) 
                         - (IData)(0x23U))) : 0x3ffU);
}

void VDevelopmentBoard::_eval(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_eval\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if ((((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    if ((((IData)(vlTOPp->__VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25) 
          & (~ (IData)(vlTOPp->__Vclklast__TOP____VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25))) 
         | ((~ (IData)(vlTOPp->reset)) & (IData)(vlTOPp->__Vclklast__TOP__reset)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
    }
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
    vlTOPp->_settle__TOP__2(vlSymsp);
}

VL_INLINE_OPT QData VDevelopmentBoard::_change_request(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_change_request\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    __req |= ((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25));
    VL_DEBUG_IF( if(__req && ((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25))) VL_DBG_MSGF("        CHANGE: ../RTL/pll.v:7: DevelopmentBoard.vga_display_inst.pll_inst.clk_25\n"); );
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
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data = VL_RAND_RESET_I(16);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v = VL_RAND_RESET_I(10);
    __VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
}
