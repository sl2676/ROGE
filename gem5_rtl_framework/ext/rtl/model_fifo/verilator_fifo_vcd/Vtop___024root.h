// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;
VL_MODULE(Vtop___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(read_enable,0,0);
    VL_IN8(write_enable,0,0);
    VL_OUT8(empty,0,0);
    VL_OUT8(full,0,0);
    CData/*2:0*/ top__DOT__fifo__DOT__head_ptr;
    CData/*2:0*/ top__DOT__fifo__DOT__tail_ptr;
    CData/*3:0*/ top__DOT__fifo__DOT__fifo_cnt;
    CData/*0:0*/ top__DOT__fifo__DOT__read_enable;
    CData/*0:0*/ top__DOT__fifo__DOT__write_enable;
    CData/*2:0*/ __Vdly__top__DOT__fifo__DOT__head_ptr;
    CData/*2:0*/ __Vdly__top__DOT__fifo__DOT__tail_ptr;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_IN64(data_input,63,0);
    VL_OUT64(data_output,63,0);
    VlUnpacked<QData/*63:0*/, 8> top__DOT__fifo__DOT__fifo_mem;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
