/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__BranchPredictor__
#define __PARAMS__BranchPredictor__

namespace gem5 {
namespace branch_prediction {
class BPredUnit;
} // namespace branch_prediction
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/IndirectPredictor.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

namespace gem5
{
struct BranchPredictorParams
    : public SimObjectParams
{
    unsigned BTBEntries;
    unsigned BTBTagSize;
    unsigned RASSize;
    gem5::branch_prediction::IndirectPredictor * indirectBranchPred;
    unsigned instShiftAmt;
    unsigned numThreads;
};

} // namespace gem5

#endif // __PARAMS__BranchPredictor__