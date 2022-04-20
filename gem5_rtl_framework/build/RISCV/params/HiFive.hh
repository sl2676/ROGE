/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__HiFive__
#define __PARAMS__HiFive__

namespace gem5 {
class HiFive;
} // namespace gem5
#include <cstddef>
#include "params/Clint.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/Plic.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/Platform.hh"

namespace gem5
{
struct HiFiveParams
    : public PlatformParams
{
    gem5::HiFive * create() const;
    gem5::Clint * clint;
    int cpu_count;
    gem5::Plic * plic;
    int uart_int_id;
};

} // namespace gem5

#endif // __PARAMS__HiFive__
