/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__ArmFsWorkload__
#define __PARAMS__ArmFsWorkload__

namespace gem5 {
namespace ArmISA {
class FsWorkload;
} // namespace ArmISA
} // namespace gem5
#include <vector>
#include <string>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>
#include <cstddef>
#include <cstddef>
#include <cstddef>
#include "enums/ArmMachineType.hh"
#include <cstddef>
#include <cstddef>

#include "params/KernelWorkload.hh"

#include "enums/ArmMachineType.hh"

namespace gem5
{
struct ArmFsWorkloadParams
    : public KernelWorkloadParams
{
    gem5::ArmISA::FsWorkload * create() const;
    std::vector< std::string > boot_loader;
    Addr cpu_release_addr;
    Addr dtb_addr;
    std::string dtb_filename;
    bool early_kernel_symbols;
    bool enable_context_switch_stats_dump;
    enums::ArmMachineType machine_type;
    bool panic_on_oops;
    bool panic_on_panic;
};

} // namespace gem5

#endif // __PARAMS__ArmFsWorkload__
