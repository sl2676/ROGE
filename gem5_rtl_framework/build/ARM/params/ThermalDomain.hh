/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__ThermalDomain__
#define __PARAMS__ThermalDomain__

namespace gem5 {
class ThermalDomain;
} // namespace gem5
#include <cstddef>
#include "base/temperature.hh"

#include "params/SimObject.hh"

namespace gem5
{
struct ThermalDomainParams
    : public SimObjectParams
{
    gem5::ThermalDomain * create() const;
    Temperature initial_temperature;
};

} // namespace gem5

#endif // __PARAMS__ThermalDomain__