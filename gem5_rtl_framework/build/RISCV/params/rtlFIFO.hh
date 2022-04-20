/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__rtlFIFO__
#define __PARAMS__rtlFIFO__

namespace gem5 {
class rtlFIFO;
} // namespace gem5

#include "params/rtlObject.hh"

namespace gem5
{
struct rtlFIFOParams
    : public rtlObjectParams
{
    gem5::rtlFIFO * create() const;
    unsigned int port_cpu_side_connection_count;
    unsigned int port_mem_side_connection_count;
};

} // namespace gem5

#endif // __PARAMS__rtlFIFO__
