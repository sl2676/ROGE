/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__PowerState__
#define __PARAMS__PowerState__

namespace gem5 {
class PowerState;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "enums/PwrState.hh"
#include <vector>
#include "params/PowerState.hh"
#include <vector>
#include "enums/PwrState.hh"

#include "params/SimObject.hh"

#include "enums/PwrState.hh"

#include "enums/PwrState.hh"

namespace gem5
{
struct PowerStateParams
    : public SimObjectParams
{
    gem5::PowerState * create() const;
    unsigned clk_gate_bins;
    Tick clk_gate_max;
    Tick clk_gate_min;
    enums::PwrState default_state;
    std::vector< gem5::PowerState * > leaders;
    std::vector< enums::PwrState > possible_states;
};

} // namespace gem5

#endif // __PARAMS__PowerState__