/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__SimObject__
#define __PARAMS__SimObject__

#include <string>
namespace gem5 {
class SimObject;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"

namespace gem5
{
struct SimObjectParams
{
        SimObjectParams() {}
        virtual ~SimObjectParams() {}

        std::string name;
                
    uint32_t eventq_index;
};

} // namespace gem5

#endif // __PARAMS__SimObject__
