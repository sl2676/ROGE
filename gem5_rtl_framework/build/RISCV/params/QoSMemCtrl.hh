/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__QoSMemCtrl__
#define __PARAMS__QoSMemCtrl__

namespace gem5 {
namespace memory {
namespace qos {
class MemCtrl;
} // namespace qos
} // namespace memory
} // namespace gem5
#include <cstddef>
#include "params/QoSPolicy.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "enums/QoSQPolicy.hh"
#include <vector>
#include <string>
#include <cstddef>
#include <cstddef>
#include "params/QoSTurnaroundPolicy.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/ClockedObject.hh"

#include "enums/QoSQPolicy.hh"

namespace gem5
{
struct QoSMemCtrlParams
    : public ClockedObjectParams
{
    gem5::memory::qos::Policy * qos_policy;
    unsigned qos_priorities;
    bool qos_priority_escalation;
    enums::QoSQPolicy qos_q_policy;
    std::vector< std::string > qos_requestors;
    bool qos_syncro_scheduler;
    gem5::memory::qos::TurnaroundPolicy * qos_turnaround_policy;
    gem5::System * system;
};

} // namespace gem5

#endif // __PARAMS__QoSMemCtrl__
