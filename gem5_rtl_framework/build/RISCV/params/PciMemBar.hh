/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__PciMemBar__
#define __PARAMS__PciMemBar__

namespace gem5 {
class PciMemBar;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"

#include "params/PciBar.hh"

namespace gem5
{
struct PciMemBarParams
    : public PciBarParams
{
    gem5::PciMemBar * create() const;
    uint64_t size;
};

} // namespace gem5

#endif // __PARAMS__PciMemBar__
