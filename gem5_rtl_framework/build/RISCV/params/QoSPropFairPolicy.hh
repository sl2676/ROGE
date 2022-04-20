/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__QoSPropFairPolicy__
#define __PARAMS__QoSPropFairPolicy__

namespace gem5 {
namespace memory {
namespace qos {
class PropFairPolicy;
} // namespace qos
} // namespace memory
} // namespace gem5
#include <cstddef>

#include "params/QoSPolicy.hh"

namespace gem5
{
struct QoSPropFairPolicyParams
    : public QoSPolicyParams
{
    gem5::memory::qos::PropFairPolicy * create() const;
    double weight;
};

} // namespace gem5

#endif // __PARAMS__QoSPropFairPolicy__
