/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__I2CDevice__
#define __PARAMS__I2CDevice__

namespace gem5 {
class I2CDevice;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

namespace gem5
{
struct I2CDeviceParams
    : public SimObjectParams
{
    uint8_t i2c_addr;
};

} // namespace gem5

#endif // __PARAMS__I2CDevice__