/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__ArmEmuFreebsd__
#define __PARAMS__ArmEmuFreebsd__

namespace gem5 {
namespace ArmISA {
class EmuFreebsd;
} // namespace ArmISA
} // namespace gem5

#include "params/ArmSEWorkload.hh"

namespace gem5
{
struct ArmEmuFreebsdParams
    : public ArmSEWorkloadParams
{
    gem5::ArmISA::EmuFreebsd * create() const;
};

} // namespace gem5

#endif // __PARAMS__ArmEmuFreebsd__