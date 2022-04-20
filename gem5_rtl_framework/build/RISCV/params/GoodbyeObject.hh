/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__GoodbyeObject__
#define __PARAMS__GoodbyeObject__

namespace gem5 {
class GoodbyeObject;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/SimObject.hh"

namespace gem5
{
struct GoodbyeObjectParams
    : public SimObjectParams
{
    gem5::GoodbyeObject * create() const;
    uint64_t buffer_size;
    float write_bandwidth;
};

} // namespace gem5

#endif // __PARAMS__GoodbyeObject__
