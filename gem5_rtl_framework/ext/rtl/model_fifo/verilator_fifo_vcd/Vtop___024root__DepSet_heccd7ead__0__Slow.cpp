// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Body
    vlSelf->full = (8U == (IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt));
    vlSelf->empty = (0U == (IData)(vlSelf->top__DOT__fifo__DOT__fifo_cnt));
    vlSelf->top__DOT__fifo__DOT__write_enable = ((IData)(vlSelf->write_enable) 
                                                 & (~ (IData)(vlSelf->full)));
    vlSelf->top__DOT__fifo__DOT__read_enable = ((IData)(vlSelf->read_enable) 
                                                & (~ (IData)(vlSelf->empty)));
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->data_input = VL_RAND_RESET_Q(64);
    vlSelf->read_enable = VL_RAND_RESET_I(1);
    vlSelf->write_enable = VL_RAND_RESET_I(1);
    vlSelf->data_output = VL_RAND_RESET_Q(64);
    vlSelf->empty = VL_RAND_RESET_I(1);
    vlSelf->full = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<8; ++__Vi0) {
        vlSelf->top__DOT__fifo__DOT__fifo_mem[__Vi0] = VL_RAND_RESET_Q(64);
    }
    vlSelf->top__DOT__fifo__DOT__head_ptr = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__fifo__DOT__tail_ptr = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__fifo__DOT__fifo_cnt = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__fifo__DOT__read_enable = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__fifo__DOT__write_enable = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__top__DOT__fifo__DOT__head_ptr = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__top__DOT__fifo__DOT__tail_ptr = VL_RAND_RESET_I(3);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
