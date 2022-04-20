// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"rst", false,-1);
    tracep->declQuad(c+19,"data_input", false,-1, 63,0);
    tracep->declBit(c+21,"read_enable", false,-1);
    tracep->declBit(c+22,"write_enable", false,-1);
    tracep->declQuad(c+23,"data_output", false,-1, 63,0);
    tracep->declBit(c+25,"empty", false,-1);
    tracep->declBit(c+26,"full", false,-1);
    tracep->pushNamePrefix("top ");
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"rst", false,-1);
    tracep->declQuad(c+19,"data_input", false,-1, 63,0);
    tracep->declBit(c+21,"read_enable", false,-1);
    tracep->declBit(c+22,"write_enable", false,-1);
    tracep->declQuad(c+23,"data_output", false,-1, 63,0);
    tracep->declBit(c+25,"empty", false,-1);
    tracep->declBit(c+26,"full", false,-1);
    tracep->pushNamePrefix("fifo ");
    tracep->declBus(c+32,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+33,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBit(c+17,"clk", false,-1);
    tracep->declBit(c+18,"rst", false,-1);
    tracep->declQuad(c+19,"data_input", false,-1, 63,0);
    tracep->declBit(c+21,"read_enable_input", false,-1);
    tracep->declBit(c+22,"write_enable_input", false,-1);
    tracep->declQuad(c+23,"data_output", false,-1, 63,0);
    tracep->declBit(c+25,"empty", false,-1);
    tracep->declBit(c+26,"full", false,-1);
    tracep->declBus(c+34,"FIFO_SIZE", false,-1, 31,0);
    for (int i = 0; i < 8; ++i) {
        tracep->declQuad(c+1+i*2,"fifo_mem", true,(i+0), 63,0);
    }
    tracep->declBus(c+27,"head_ptr", false,-1, 2,0);
    tracep->declBus(c+28,"tail_ptr", false,-1, 2,0);
    tracep->declBus(c+29,"fifo_cnt", false,-1, 3,0);
    tracep->declBit(c+30,"read_enable", false,-1);
    tracep->declBit(c+31,"write_enable", false,-1);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd* tracep);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vtop___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vtop___024root__trace_full_top_0(void* voidSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtop___024root__trace_full_sub_0((&vlSymsp->TOP), tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_full_sub_0(Vtop___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = tracep->oldp(vlSymsp->__Vm_baseCode);
    // Body
    tracep->fullQData(oldp+1,(vlSelf->top__DOT__fifo__DOT__fifo_mem[0]),64);
    tracep->fullQData(oldp+3,(vlSelf->top__DOT__fifo__DOT__fifo_mem[1]),64);
    tracep->fullQData(oldp+5,(vlSelf->top__DOT__fifo__DOT__fifo_mem[2]),64);
    tracep->fullQData(oldp+7,(vlSelf->top__DOT__fifo__DOT__fifo_mem[3]),64);
    tracep->fullQData(oldp+9,(vlSelf->top__DOT__fifo__DOT__fifo_mem[4]),64);
    tracep->fullQData(oldp+11,(vlSelf->top__DOT__fifo__DOT__fifo_mem[5]),64);
    tracep->fullQData(oldp+13,(vlSelf->top__DOT__fifo__DOT__fifo_mem[6]),64);
    tracep->fullQData(oldp+15,(vlSelf->top__DOT__fifo__DOT__fifo_mem[7]),64);
    tracep->fullBit(oldp+17,(vlSelf->clk));
    tracep->fullBit(oldp+18,(vlSelf->rst));
    tracep->fullQData(oldp+19,(vlSelf->data_input),64);
    tracep->fullBit(oldp+21,(vlSelf->read_enable));
    tracep->fullBit(oldp+22,(vlSelf->write_enable));
    tracep->fullQData(oldp+23,(vlSelf->data_output),64);
    tracep->fullBit(oldp+25,(vlSelf->empty));
    tracep->fullBit(oldp+26,(vlSelf->full));
    tracep->fullCData(oldp+27,(vlSelf->top__DOT__fifo__DOT__head_ptr),3);
    tracep->fullCData(oldp+28,(vlSelf->top__DOT__fifo__DOT__tail_ptr),3);
    tracep->fullCData(oldp+29,(vlSelf->top__DOT__fifo__DOT__fifo_cnt),4);
    tracep->fullBit(oldp+30,(vlSelf->top__DOT__fifo__DOT__read_enable));
    tracep->fullBit(oldp+31,(vlSelf->top__DOT__fifo__DOT__write_enable));
    tracep->fullIData(oldp+32,(0x40U),32);
    tracep->fullIData(oldp+33,(3U),32);
    tracep->fullIData(oldp+34,(8U),32);
}
