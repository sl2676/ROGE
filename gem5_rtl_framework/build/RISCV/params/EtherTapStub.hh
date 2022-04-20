/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__EtherTapStub__
#define __PARAMS__EtherTapStub__

namespace gem5 {
class EtherTapStub;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"

#include "params/EtherTapBase.hh"

namespace gem5
{
struct EtherTapStubParams
    : public EtherTapBaseParams
{
    gem5::EtherTapStub * create() const;
    uint16_t port;
};

} // namespace gem5

#endif // __PARAMS__EtherTapStub__
