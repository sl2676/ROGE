/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__LTAGE__
#define __PARAMS__LTAGE__

namespace gem5 {
namespace branch_prediction {
class LTAGE;
} // namespace branch_prediction
} // namespace gem5
#include <cstddef>
#include "params/LoopPredictor.hh"

#include "params/TAGE.hh"

namespace gem5
{
struct LTAGEParams
    : public TAGEParams
{
    gem5::branch_prediction::LTAGE * create() const;
    gem5::branch_prediction::LoopPredictor * loop_predictor;
};

} // namespace gem5

#endif // __PARAMS__LTAGE__
