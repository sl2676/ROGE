/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__RepeatedQwordsCompressor__
#define __PARAMS__RepeatedQwordsCompressor__

namespace gem5 {
namespace compression {
class RepeatedQwords;
} // namespace compression
} // namespace gem5

#include "params/BaseDictionaryCompressor.hh"

namespace gem5
{
struct RepeatedQwordsCompressorParams
    : public BaseDictionaryCompressorParams
{
    gem5::compression::RepeatedQwords * create() const;
};

} // namespace gem5

#endif // __PARAMS__RepeatedQwordsCompressor__
