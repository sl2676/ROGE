/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__StridePrefetcherHashedSetAssociative__
#define __PARAMS__StridePrefetcherHashedSetAssociative__

namespace gem5 {
namespace prefetch {
class StridePrefetcherHashedSetAssociative;
} // namespace prefetch
} // namespace gem5

#include "params/SetAssociative.hh"

namespace gem5
{
struct StridePrefetcherHashedSetAssociativeParams
    : public SetAssociativeParams
{
    gem5::prefetch::StridePrefetcherHashedSetAssociative * create() const;
};

} // namespace gem5

#endif // __PARAMS__StridePrefetcherHashedSetAssociative__
