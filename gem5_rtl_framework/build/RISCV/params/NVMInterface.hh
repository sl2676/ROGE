/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__NVMInterface__
#define __PARAMS__NVMInterface__

namespace gem5 {
namespace memory {
class NVMInterface;
} // namespace memory
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>

#include "params/MemInterface.hh"

namespace gem5
{
struct NVMInterfaceParams
    : public MemInterfaceParams
{
    gem5::memory::NVMInterface * create() const;
    unsigned max_pending_reads;
    unsigned max_pending_writes;
    Tick tREAD;
    Tick tSEND;
    Tick tWRITE;
    bool two_cycle_rdwr;
};

} // namespace gem5

#endif // __PARAMS__NVMInterface__
