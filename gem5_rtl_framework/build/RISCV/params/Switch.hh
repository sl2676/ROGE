/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__Switch__
#define __PARAMS__Switch__

namespace gem5 {
namespace ruby {
class Switch;
} // namespace ruby
} // namespace gem5
#include <vector>
#include "params/MessageBuffer.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BasicRouter.hh"

namespace gem5
{
struct SwitchParams
    : public BasicRouterParams
{
    gem5::ruby::Switch * create() const;
    std::vector< gem5::ruby::MessageBuffer * > port_buffers;
    int virt_nets;
};

} // namespace gem5

#endif // __PARAMS__Switch__