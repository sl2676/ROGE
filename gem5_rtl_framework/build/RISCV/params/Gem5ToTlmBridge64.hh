/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__Gem5ToTlmBridge64__
#define __PARAMS__Gem5ToTlmBridge64__

namespace sc_gem5 {
template <unsigned int BITWIDTH>
class Gem5ToTlmBridge;
} // namespace sc_gem5

#include "params/Gem5ToTlmBridgeBase.hh"

namespace gem5
{
struct Gem5ToTlmBridge64Params
    : public Gem5ToTlmBridgeBaseParams
{
    sc_gem5::Gem5ToTlmBridge<64> * create() const;
    unsigned int port_tlm_connection_count;
};

} // namespace gem5

#endif // __PARAMS__Gem5ToTlmBridge64__