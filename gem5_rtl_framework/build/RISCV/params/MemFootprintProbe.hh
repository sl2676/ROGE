/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__MemFootprintProbe__
#define __PARAMS__MemFootprintProbe__

namespace gem5 {
class MemFootprintProbe;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/BaseMemProbe.hh"

namespace gem5
{
struct MemFootprintProbeParams
    : public BaseMemProbeParams
{
    gem5::MemFootprintProbe * create() const;
    unsigned page_size;
    gem5::System * system;
};

} // namespace gem5

#endif // __PARAMS__MemFootprintProbe__
