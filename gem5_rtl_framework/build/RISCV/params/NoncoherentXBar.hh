/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__NoncoherentXBar__
#define __PARAMS__NoncoherentXBar__

namespace gem5 {
class NoncoherentXBar;
} // namespace gem5

#include "params/BaseXBar.hh"

namespace gem5
{
struct NoncoherentXBarParams
    : public BaseXBarParams
{
    gem5::NoncoherentXBar * create() const;
};

} // namespace gem5

#endif // __PARAMS__NoncoherentXBar__
