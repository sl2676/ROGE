/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__SystemC_Kernel__
#define __PARAMS__SystemC_Kernel__

namespace sc_gem5 {
class Kernel;
} // namespace sc_gem5

#include "params/SimObject.hh"

namespace gem5
{
struct SystemC_KernelParams
    : public SimObjectParams
{
    sc_gem5::Kernel * create() const;
};

} // namespace gem5

#endif // __PARAMS__SystemC_Kernel__