/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__BasicIntLink__
#define __PARAMS__BasicIntLink__

namespace gem5 {
namespace ruby {
class BasicIntLink;
} // namespace ruby
} // namespace gem5
#include <cstddef>
#include <string>
#include <cstddef>
#include "params/BasicRouter.hh"
#include <cstddef>
#include "params/BasicRouter.hh"
#include <cstddef>
#include <string>

#include "params/BasicLink.hh"

namespace gem5
{
struct BasicIntLinkParams
    : public BasicLinkParams
{
    gem5::ruby::BasicIntLink * create() const;
    std::string dst_inport;
    gem5::ruby::BasicRouter * dst_node;
    gem5::ruby::BasicRouter * src_node;
    std::string src_outport;
};

} // namespace gem5

#endif // __PARAMS__BasicIntLink__
