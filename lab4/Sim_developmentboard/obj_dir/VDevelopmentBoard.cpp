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
            VL_FATAL_MT("/mnt/hgfs/Shared_lab4/Sim_developmentboard/DevelopmentBoard.v", 3, "",
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
            VL_FATAL_MT("/mnt/hgfs/Shared_lab4/Sim_developmentboard/DevelopmentBoard.v", 3, "",
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
}

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__4(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__4\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    SData/*9:0*/ __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    // Body
    __Vdly__DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h 
        = vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h;
    vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data 
        = ((IData)(vlTOPp->reset) ? ((0U == (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur))
                                      ? ((0x40U > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                          ? 0xf800U
                                          : ((0x80U 
                                              > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                              ? 0xfc00U
                                              : ((0xc0U 
                                                  > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                  ? 0xffe0U
                                                  : 
                                                 ((0x100U 
                                                   > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                   ? 0x7e0U
                                                   : 
                                                  ((0x140U 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                    ? 0x7ffU
                                                    : 
                                                   ((0x180U 
                                                     > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                     ? 0x1fU
                                                     : 
                                                    ((0x1c0U 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                      ? 0xf81fU
                                                      : 
                                                     ((0x200U 
                                                       > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                       ? 0U
                                                       : 
                                                      ((0x240U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))
                                                        ? 0xffffU
                                                        : 0xd69aU)))))))))
                                      : ((1U == (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur))
                                          ? ((((((0x6eU 
                                                  <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                 & (0xc8U 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                & (0x96U 
                                                   <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                               & (0x14aU 
                                                  > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                              & ((((0x78U 
                                                    > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                   | (0xbeU 
                                                      < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                  | ((((0x78U 
                                                        <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                       & (0x9bU 
                                                          >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                      & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                          - (IData)(0x96U)) 
                                                         >= 
                                                         ((((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                            - (IData)(0x78U)) 
                                                           >> 1U) 
                                                          - (IData)(5U)))) 
                                                     & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                         - (IData)(0x96U)) 
                                                        <= 
                                                        ((IData)(5U) 
                                                         + 
                                                         (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x) 
                                                           - (IData)(0x78U)) 
                                                          >> 1U))))) 
                                                 | ((((0x9bU 
                                                       <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                      & (0xbeU 
                                                         >= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                     & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                         - (IData)(0x96U)) 
                                                        >= 
                                                        ((((IData)(0xbeU) 
                                                           - (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                          >> 1U) 
                                                         - (IData)(5U)))) 
                                                    & (((IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y) 
                                                        - (IData)(0x96U)) 
                                                       <= 
                                                       ((IData)(5U) 
                                                        + 
                                                        (((IData)(0xbeU) 
                                                          - (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                         >> 1U))))))
                                              ? 0xf800U
                                              : (((
                                                   (((0xdcU 
                                                      <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                     & (0x136U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                    & (0x96U 
                                                       <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                   & (0x14aU 
                                                      > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                  & (((0xe6U 
                                                       > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                      | (0x12cU 
                                                         < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                     | (0x140U 
                                                        < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))))
                                                  ? 0x7e0U
                                                  : 
                                                 ((((((0x14aU 
                                                       <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                      & (0x1a4U 
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
                                                          & (0x154U 
                                                             > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))) 
                                                      | ((0xf0U 
                                                          < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                         & (0x19aU 
                                                            < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))))
                                                   ? 0x1fU
                                                   : 
                                                  ((((((0x1b8U 
                                                        <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                       & (0x212U 
                                                          > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x))) 
                                                      & (0x96U 
                                                         <= (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                     & (0x14aU 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y))) 
                                                    & ((0xa0U 
                                                        > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y)) 
                                                       | ((0x1e0U 
                                                           < (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)) 
                                                          & (0x1eaU 
                                                             > (IData)(vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x)))))
                                                    ? 0xffe0U
                                                    : 0U))))
                                          : ((2U == (IData)(vlTOPp->DevelopmentBoard__DOT__st_cur))
                                              ? (((
                                                   (((0xa5U 
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

VL_INLINE_OPT void VDevelopmentBoard::_sequent__TOP__5(VDevelopmentBoard__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VDevelopmentBoard::_sequent__TOP__5\n"); );
    VDevelopmentBoard* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->DevelopmentBoard__DOT__st_cur = ((IData)(vlTOPp->reset)
                                              ? (IData)(vlTOPp->DevelopmentBoard__DOT__st_next)
                                              : 2U);
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
    VL_DEBUG_IF( if(__req && ((vlTOPp->DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 ^ vlTOPp->__Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25))) VL_DBG_MSGF("        CHANGE: /mnt/hgfs/Shared_lab4/Sim_developmentboard/../RTL/pll.v:7: DevelopmentBoard.vga_display_inst.pll_inst.clk_25\n"); );
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
    DevelopmentBoard__DOT__st_cur = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__st_next = VL_RAND_RESET_I(2);
    DevelopmentBoard__DOT__button_prev = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_x = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_y = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pix_data = VL_RAND_RESET_I(16);
    DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__pix_data_req = VL_RAND_RESET_I(1);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_h = VL_RAND_RESET_I(10);
    DevelopmentBoard__DOT__vga_display_inst__DOT__vga_ctrl_inst__DOT__cnt_v = VL_RAND_RESET_I(10);
    __Vtableidx1 = 0;
    __Vtable1_DevelopmentBoard__DOT__st_next[0] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[1] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[2] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[3] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[4] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[5] = 1U;
    __Vtable1_DevelopmentBoard__DOT__st_next[6] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[7] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[8] = 1U;
    __Vtable1_DevelopmentBoard__DOT__st_next[9] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[10] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[11] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[12] = 1U;
    __Vtable1_DevelopmentBoard__DOT__st_next[13] = 2U;
    __Vtable1_DevelopmentBoard__DOT__st_next[14] = 0U;
    __Vtable1_DevelopmentBoard__DOT__st_next[15] = 2U;
    __VinpClk__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
    __Vchglast__TOP__DevelopmentBoard__DOT__vga_display_inst__DOT__pll_inst__DOT__clk_25 = VL_RAND_RESET_I(1);
}
