// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), tracep);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        tracep->chgQData(oldp+0,(vlSelf->top__DOT__fifo__DOT__fifo_mem[0]),64);
        tracep->chgQData(oldp+2,(vlSelf->top__DOT__fifo__DOT__fifo_mem[1]),64);
        tracep->chgQData(oldp+4,(vlSelf->top__DOT__fifo__DOT__fifo_mem[2]),64);
        tracep->chgQData(oldp+6,(vlSelf->top__DOT__fifo__DOT__fifo_mem[3]),64);
        tracep->chgQData(oldp+8,(vlSelf->top__DOT__fifo__DOT__fifo_mem[4]),64);
        tracep->chgQData(oldp+10,(vlSelf->top__DOT__fifo__DOT__fifo_mem[5]),64);
        tracep->chgQData(oldp+12,(vlSelf->top__DOT__fifo__DOT__fifo_mem[6]),64);
        tracep->chgQData(oldp+14,(vlSelf->top__DOT__fifo__DOT__fifo_mem[7]),64);
    }
    tracep->chgBit(oldp+16,(vlSelf->clk));
    tracep->chgBit(oldp+17,(vlSelf->rst));
    tracep->chgQData(oldp+18,(vlSelf->data_input),64);
    tracep->chgBit(oldp+20,(vlSelf->read_enable));
    tracep->chgBit(oldp+21,(vlSelf->write_enable));
    tracep->chgQData(oldp+22,(vlSelf->data_output),64);
    tracep->chgBit(oldp+24,(vlSelf->empty));
    tracep->chgBit(oldp+25,(vlSelf->full));
    tracep->chgCData(oldp+26,(vlSelf->top__DOT__fifo__DOT__head_ptr),3);
    tracep->chgCData(oldp+27,(vlSelf->top__DOT__fifo__DOT__tail_ptr),3);
    tracep->chgCData(oldp+28,(vlSelf->top__DOT__fifo__DOT__fifo_cnt),4);
    tracep->chgBit(oldp+29,(vlSelf->top__DOT__fifo__DOT__read_enable));
    tracep->chgBit(oldp+30,(vlSelf->top__DOT__fifo__DOT__write_enable));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
