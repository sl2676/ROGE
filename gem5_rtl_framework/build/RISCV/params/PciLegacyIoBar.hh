/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__PciLegacyIoBar__
#define __PARAMS__PciLegacyIoBar__

namespace gem5 {
class PciLegacyIoBar;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"

#include "params/PciIoBar.hh"

namespace gem5
{
struct PciLegacyIoBarParams
    : public PciIoBarParams
{
    gem5::PciLegacyIoBar * create() const;
    uint32_t addr;
};

} // namespace gem5

#endif // __PARAMS__PciLegacyIoBar__
