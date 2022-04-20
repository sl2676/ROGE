/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__DerivedClockDomain__
#define __PARAMS__DerivedClockDomain__

namespace gem5 {
class DerivedClockDomain;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/ClockDomain.hh"

#include "params/ClockDomain.hh"

namespace gem5
{
struct DerivedClockDomainParams
    : public ClockDomainParams
{
    gem5::DerivedClockDomain * create() const;
    unsigned clk_divider;
    gem5::ClockDomain * clk_domain;
};

} // namespace gem5

#endif // __PARAMS__DerivedClockDomain__
