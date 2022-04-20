// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__top__DOT__fifo__DOT__tail_ptr = vlSelf->top__DOT__fifo__DOT__tail_ptr;
    vlSelf->__Vdly__top__DOT__fifo__DOT__head_ptr = vlSelf->top__DOT__fifo__DOT__head_ptr;
    if (vlSelf->rst) {
        vlSelf->__Vdly__top__DOT__fifo__DOT__tail_ptr = 0U;
        vlSelf->__Vdly__top__DOT__fifo__DOT__head_ptr = 0U;
        vlSelf->top__DOT__fifo__DOT__fifo_cnt = 0U;
    } else {
        vlSelf->__Vdly__top__DOT__fifo__DOT__tail_ptr 
            = (7U & (((IData)(vlSelf->top__DOT__fifo__DOT__write_enable) 
                      & (~ (IData)(vlSelf->full))) ? 
                     ((IData)(1U) + (IData)(vlSelf->top__DOT__fifo__DOT__tail_ptr))
                      : (IData)(vlSelf->top__DOT__fifo__DOT__tail_ptr)));
        vlSelf->__Vdly__top__DOT__fifo__DOT__head_ptr 
            = (7U & (((IData)(vlSelf->top__DOT__fifo__DOT__read_enable) 
                      & (~ (IData)(vlSelf->empty)))
                      ? ((IData)(1U) + (IData)(vlSelf->top__DOT__fifo__DOT__head_ptr))
                      : (IData)(vlSelf->top__DOT__fifo__DOT__head_ptr)));
        vlSelf->top__DOT__fifo__DOT__fifo_cnt = (0xfU 
                                                 & (((IData)(vlSelf->top__DOT__fifo__DOT__read_enable) 
                                                     & (~ (IData)(vlSelf->top__DOT__fifo__DOT__write_enable)))
                                                     ? 
                                                    ((IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt) 
                                                     - (IData)(1U))
                                                     : 
                                                    (((~ (IData)(vlSelf->top__DOT__fifo__DOT__read_enable)) 
                                                      & (IData)(vlSelf->top__DOT__fifo__DOT__write_enable))
                                                      ? 
                                                     ((IData)(1U) 
                                                      + (IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt))
                                                      : (IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt))));
    }
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Init
    CData/*2:0*/ __Vdlyvdim0__top__DOT__fifo__DOT__fifo_mem__v0;
    QData/*63:0*/ __Vdlyvval__top__DOT__fifo__DOT__fifo_mem__v0;
    // Body
    vlSelf->data_output = (((~ (IData)(vlSelf->empty)) 
                            & (IData)(vlSelf->top__DOT__fifo__DOT__read_enable))
                            ? vlSelf->top__DOT__fifo__DOT__fifo_mem
                           [vlSelf->top__DOT__fifo__DOT__head_ptr]
                            : vlSelf->data_output);
    __Vdlyvval__top__DOT__fifo__DOT__fifo_mem__v0 = 
        (((~ (IData)(vlSelf->full)) & (IData)(vlSelf->top__DOT__fifo__DOT__write_enable))
          ? vlSelf->data_input : vlSelf->top__DOT__fifo__DOT__fifo_mem
         [vlSelf->top__DOT__fifo__DOT__tail_ptr]);
    __Vdlyvdim0__top__DOT__fifo__DOT__fifo_mem__v0 
        = vlSelf->top__DOT__fifo__DOT__tail_ptr;
    vlSelf->top__DOT__fifo__DOT__fifo_mem[__Vdlyvdim0__top__DOT__fifo__DOT__fifo_mem__v0] 
        = __Vdlyvval__top__DOT__fifo__DOT__fifo_mem__v0;
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__fifo__DOT__head_ptr = vlSelf->__Vdly__top__DOT__fifo__DOT__head_ptr;
    vlSelf->empty = (0U == (IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt));
    vlSelf->top__DOT__fifo__DOT__tail_ptr = vlSelf->__Vdly__top__DOT__fifo__DOT__tail_ptr;
    vlSelf->full = (8U == (IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt));
}

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Body
    vlSelf->top__DOT__fifo__DOT__read_enable = ((IData)(vlSelf->read_enable) 
                                                & (~ (IData)(vlSelf->empty)));
    vlSelf->top__DOT__fifo__DOT__write_enable = ((IData)(vlSelf->write_enable) 
                                                 & (~ (IData)(vlSelf->full)));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
    }
    Vtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->read_enable & 0xfeU))) {
        Verilated::overWidthError("read_enable");}
    if (VL_UNLIKELY((vlSelf->write_enable & 0xfeU))) {
        Verilated::overWidthError("write_enable");}
}
#endif  // VL_DEBUG
