/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__RubyHTMSequencer__
#define __PARAMS__RubyHTMSequencer__

namespace gem5 {
namespace ruby {
class HTMSequencer;
} // namespace ruby
} // namespace gem5

#include "params/RubySequencer.hh"

namespace gem5
{
struct RubyHTMSequencerParams
    : public RubySequencerParams
{
    gem5::ruby::HTMSequencer * create() const;
};

} // namespace gem5

#endif // __PARAMS__RubyHTMSequencer__
