/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__BaseSimpleCPU__
#define __PARAMS__BaseSimpleCPU__

namespace gem5 {
class BaseSimpleCPU;
} // namespace gem5
#include <cstddef>
#include "params/BranchPredictor.hh"

#include "params/BaseCPU.hh"

namespace gem5
{
struct BaseSimpleCPUParams
    : public BaseCPUParams
{
    gem5::branch_prediction::BPredUnit * branchPred;
};

} // namespace gem5

#endif // __PARAMS__BaseSimpleCPU__
