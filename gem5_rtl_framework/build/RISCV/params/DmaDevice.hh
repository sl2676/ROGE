/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__DmaDevice__
#define __PARAMS__DmaDevice__

namespace gem5 {
class DmaDevice;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/PioDevice.hh"

namespace gem5
{
struct DmaDeviceParams
    : public PioDeviceParams
{
    unsigned sid;
    unsigned ssid;
    unsigned int port_dma_connection_count;
};

} // namespace gem5

#endif // __PARAMS__DmaDevice__