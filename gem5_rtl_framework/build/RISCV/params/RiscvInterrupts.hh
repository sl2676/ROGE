/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__RiscvInterrupts__
#define __PARAMS__RiscvInterrupts__

namespace gem5 {
namespace RiscvISA {
class Interrupts;
} // namespace RiscvISA
} // namespace gem5

#include "params/BaseInterrupts.hh"

namespace gem5
{
struct RiscvInterruptsParams
    : public BaseInterruptsParams
{
    gem5::RiscvISA::Interrupts * create() const;
};

} // namespace gem5

#endif // __PARAMS__RiscvInterrupts__
