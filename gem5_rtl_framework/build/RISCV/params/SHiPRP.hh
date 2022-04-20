/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__SHiPRP__
#define __PARAMS__SHiPRP__

namespace gem5 {
namespace replacement_policy {
class SHiP;
} // namespace replacement_policy
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BRRIPRP.hh"

namespace gem5
{
struct SHiPRPParams
    : public BRRIPRPParams
{
    int insertion_threshold;
    unsigned shct_size;
};

} // namespace gem5

#endif // __PARAMS__SHiPRP__
