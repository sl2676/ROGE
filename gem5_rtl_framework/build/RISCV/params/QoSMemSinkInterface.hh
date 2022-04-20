/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__QoSMemSinkInterface__
#define __PARAMS__QoSMemSinkInterface__

namespace gem5 {
namespace memory {
namespace qos {
class MemSinkInterface;
} // namespace qos
} // namespace memory
} // namespace gem5

#include "params/AbstractMemory.hh"

namespace gem5
{
struct QoSMemSinkInterfaceParams
    : public AbstractMemoryParams
{
    gem5::memory::qos::MemSinkInterface * create() const;
};

} // namespace gem5

#endif // __PARAMS__QoSMemSinkInterface__
