/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__BloomFilterBase__
#define __PARAMS__BloomFilterBase__

namespace gem5 {
namespace bloom_filter {
class Base;
} // namespace bloom_filter
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/SimObject.hh"

namespace gem5
{
struct BloomFilterBaseParams
    : public SimObjectParams
{
    int num_bits;
    unsigned offset_bits;
    int size;
    int threshold;
};

} // namespace gem5

#endif // __PARAMS__BloomFilterBase__
