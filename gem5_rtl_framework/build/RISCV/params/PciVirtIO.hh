/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__PciVirtIO__
#define __PARAMS__PciVirtIO__

namespace gem5 {
class PciVirtIO;
} // namespace gem5
#include <cstddef>
#include "params/VirtIODeviceBase.hh"

#include "params/PciDevice.hh"

namespace gem5
{
struct PciVirtIOParams
    : public PciDeviceParams
{
    gem5::PciVirtIO * create() const;
    gem5::VirtIODeviceBase * vio;
};

} // namespace gem5

#endif // __PARAMS__PciVirtIO__
