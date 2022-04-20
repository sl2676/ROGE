/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__FPCD__
#define __PARAMS__FPCD__

namespace gem5 {
namespace compression {
class FPCD;
} // namespace compression
} // namespace gem5

#include "params/BaseDictionaryCompressor.hh"

namespace gem5
{
struct FPCDParams
    : public BaseDictionaryCompressorParams
{
    gem5::compression::FPCD * create() const;
};

} // namespace gem5

#endif // __PARAMS__FPCD__