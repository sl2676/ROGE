/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__TlmToGem5Bridge32__
#define __PARAMS__TlmToGem5Bridge32__

namespace sc_gem5 {
template <unsigned int BITWIDTH>
class TlmToGem5Bridge;
} // namespace sc_gem5

#include "params/TlmToGem5BridgeBase.hh"

namespace gem5
{
struct TlmToGem5Bridge32Params
    : public TlmToGem5BridgeBaseParams
{
    sc_gem5::TlmToGem5Bridge<32> * create() const;
    unsigned int port_tlm_connection_count;
};

} // namespace gem5

#endif // __PARAMS__TlmToGem5Bridge32__
