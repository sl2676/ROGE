/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__SimpleTrace__
#define __PARAMS__SimpleTrace__

namespace gem5 {
namespace o3 {
class SimpleTrace;
} // namespace o3
} // namespace gem5

#include "params/ProbeListenerObject.hh"

namespace gem5
{
struct SimpleTraceParams
    : public ProbeListenerObjectParams
{
    gem5::o3::SimpleTrace * create() const;
};

} // namespace gem5

#endif // __PARAMS__SimpleTrace__
