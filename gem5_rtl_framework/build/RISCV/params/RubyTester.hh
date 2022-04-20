/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__RubyTester__
#define __PARAMS__RubyTester__

namespace gem5 {
class RubyTester;
} // namespace gem5
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/System.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/ClockedObject.hh"

namespace gem5
{
struct RubyTesterParams
    : public ClockedObjectParams
{
    gem5::RubyTester * create() const;
    bool check_flush;
    int checks_to_complete;
    int deadlock_threshold;
    int num_cpus;
    gem5::System * system;
    int wakeup_frequency;
    unsigned int port_cpuInstDataPort_connection_count;
    unsigned int port_cpuInstPort_connection_count;
    unsigned int port_cpuDataPort_connection_count;
};

} // namespace gem5

#endif // __PARAMS__RubyTester__
