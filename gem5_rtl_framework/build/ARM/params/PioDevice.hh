/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__PioDevice__
#define __PARAMS__PioDevice__

namespace gem5 {
class PioDevice;
} // namespace gem5
#include <cstddef>
#include "params/System.hh"

#include "params/ClockedObject.hh"

namespace gem5
{
struct PioDeviceParams
    : public ClockedObjectParams
{
    gem5::System * system;
    unsigned int port_pio_connection_count;
};

} // namespace gem5

#endif // __PARAMS__PioDevice__
