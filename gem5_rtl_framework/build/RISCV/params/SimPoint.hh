/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__SimPoint__
#define __PARAMS__SimPoint__

namespace gem5 {
class SimPoint;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>

#include "params/ProbeListenerObject.hh"

namespace gem5
{
struct SimPointParams
    : public ProbeListenerObjectParams
{
    gem5::SimPoint * create() const;
    uint64_t interval;
    std::string profile_file;
};

} // namespace gem5

#endif // __PARAMS__SimPoint__
