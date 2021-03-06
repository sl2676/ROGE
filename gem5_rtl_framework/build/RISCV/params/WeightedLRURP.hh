/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__WeightedLRURP__
#define __PARAMS__WeightedLRURP__

namespace gem5 {
namespace replacement_policy {
class WeightedLRU;
} // namespace replacement_policy
} // namespace gem5

#include "params/LRURP.hh"

namespace gem5
{
struct WeightedLRURPParams
    : public LRURPParams
{
    gem5::replacement_policy::WeightedLRU * create() const;
};

} // namespace gem5

#endif // __PARAMS__WeightedLRURP__
