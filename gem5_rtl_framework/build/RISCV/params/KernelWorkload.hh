/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__KernelWorkload__
#define __PARAMS__KernelWorkload__

namespace gem5 {
class KernelWorkload;
} // namespace gem5
#include <cstddef>
#include <cstddef>
#include <string>
#include <vector>
#include <string>
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <string>

#include "params/Workload.hh"

namespace gem5
{
struct KernelWorkloadParams
    : public WorkloadParams
{
    gem5::KernelWorkload * create() const;
    bool addr_check;
    std::string command_line;
    std::vector< std::string > extras;
    std::vector< Addr > extras_addrs;
    uint64_t load_addr_mask;
    uint64_t load_addr_offset;
    std::string object_file;
};

} // namespace gem5

#endif // __PARAMS__KernelWorkload__
