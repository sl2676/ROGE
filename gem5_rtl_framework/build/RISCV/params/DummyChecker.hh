/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__DummyChecker__
#define __PARAMS__DummyChecker__

namespace gem5 {
class DummyChecker;
} // namespace gem5

#include "params/CheckerCPU.hh"

namespace gem5
{
struct DummyCheckerParams
    : public CheckerCPUParams
{
    gem5::DummyChecker * create() const;
};

} // namespace gem5

#endif // __PARAMS__DummyChecker__
