/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__ArmInterrupts__
#define __PARAMS__ArmInterrupts__

namespace gem5 {
namespace ArmISA {
class Interrupts;
} // namespace ArmISA
} // namespace gem5

#include "params/BaseInterrupts.hh"

namespace gem5
{
struct ArmInterruptsParams
    : public BaseInterruptsParams
{
    gem5::ArmISA::Interrupts * create() const;
};

} // namespace gem5

#endif // __PARAMS__ArmInterrupts__
