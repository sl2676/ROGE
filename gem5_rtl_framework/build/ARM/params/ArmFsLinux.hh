/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__ArmFsLinux__
#define __PARAMS__ArmFsLinux__

namespace gem5 {
namespace ArmISA {
class FsLinux;
} // namespace ArmISA
} // namespace gem5

#include "params/ArmFsWorkload.hh"

namespace gem5
{
struct ArmFsLinuxParams
    : public ArmFsWorkloadParams
{
    gem5::ArmISA::FsLinux * create() const;
};

} // namespace gem5

#endif // __PARAMS__ArmFsLinux__
