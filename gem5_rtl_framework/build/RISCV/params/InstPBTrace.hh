/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__InstPBTrace__
#define __PARAMS__InstPBTrace__

namespace gem5 {
namespace Trace {
class InstPBTrace;
} // namespace Trace
} // namespace gem5
#include <cstddef>
#include <string>

#include "params/InstTracer.hh"

namespace gem5
{
struct InstPBTraceParams
    : public InstTracerParams
{
    gem5::Trace::InstPBTrace * create() const;
    std::string file_name;
};

} // namespace gem5

#endif // __PARAMS__InstPBTrace__
