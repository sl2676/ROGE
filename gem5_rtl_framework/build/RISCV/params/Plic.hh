/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__Plic__
#define __PARAMS__Plic__

namespace gem5 {
class Plic;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicPioDevice.hh"

namespace gem5
{
struct PlicParams
    : public BasicPioDeviceParams
{
    gem5::Plic * create() const;
    int n_src;
    Addr pio_size;
};

} // namespace gem5

#endif // __PARAMS__Plic__
