/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__CompressedTags__
#define __PARAMS__CompressedTags__

namespace gem5 {
class CompressedTags;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"

#include "params/SectorTags.hh"

namespace gem5
{
struct CompressedTagsParams
    : public SectorTagsParams
{
    gem5::CompressedTags * create() const;
    int max_compression_ratio;
};

} // namespace gem5

#endif // __PARAMS__CompressedTags__
