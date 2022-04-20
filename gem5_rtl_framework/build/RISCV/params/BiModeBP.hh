/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__BiModeBP__
#define __PARAMS__BiModeBP__

namespace gem5 {
namespace branch_prediction {
class BiModeBP;
} // namespace branch_prediction
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/BranchPredictor.hh"

namespace gem5
{
struct BiModeBPParams
    : public BranchPredictorParams
{
    gem5::branch_prediction::BiModeBP * create() const;
    unsigned choiceCtrBits;
    unsigned choicePredictorSize;
    unsigned globalCtrBits;
    unsigned globalPredictorSize;
};

} // namespace gem5

#endif // __PARAMS__BiModeBP__