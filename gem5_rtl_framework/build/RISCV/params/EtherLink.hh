/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__EtherLink__
#define __PARAMS__EtherLink__

namespace gem5 {
class EtherLink;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/EtherDump.hh"
#include <cstddef>

#include "params/SimObject.hh"

namespace gem5
{
struct EtherLinkParams
    : public SimObjectParams
{
    gem5::EtherLink * create() const;
    Tick delay;
    Tick delay_var;
    gem5::EtherDump * dump;
    float speed;
    unsigned int port_int0_connection_count;
    unsigned int port_int1_connection_count;
};

} // namespace gem5

#endif // __PARAMS__EtherLink__
