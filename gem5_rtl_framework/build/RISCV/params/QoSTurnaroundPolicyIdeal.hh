/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__QoSTurnaroundPolicyIdeal__
#define __PARAMS__QoSTurnaroundPolicyIdeal__

namespace gem5 {
namespace memory {
namespace qos {
class TurnaroundPolicyIdeal;
} // namespace qos
} // namespace memory
} // namespace gem5

#include "params/QoSTurnaroundPolicy.hh"

namespace gem5
{
struct QoSTurnaroundPolicyIdealParams
    : public QoSTurnaroundPolicyParams
{
    gem5::memory::qos::TurnaroundPolicyIdeal * create() const;
};

} // namespace gem5

#endif // __PARAMS__QoSTurnaroundPolicyIdeal__