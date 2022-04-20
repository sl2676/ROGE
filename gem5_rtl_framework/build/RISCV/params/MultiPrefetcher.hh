/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__MultiPrefetcher__
#define __PARAMS__MultiPrefetcher__

namespace gem5 {
namespace prefetch {
class Multi;
} // namespace prefetch
} // namespace gem5
#include <vector>
#include "params/BasePrefetcher.hh"

#include "params/BasePrefetcher.hh"

namespace gem5
{
struct MultiPrefetcherParams
    : public BasePrefetcherParams
{
    gem5::prefetch::Multi * create() const;
    std::vector< gem5::prefetch::Base * > prefetchers;
};

} // namespace gem5

#endif // __PARAMS__MultiPrefetcher__