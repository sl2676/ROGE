/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__GarnetNetwork__
#define __PARAMS__GarnetNetwork__

namespace gem5 {
namespace ruby {
namespace garnet {
class GarnetNetwork;
} // namespace garnet
} // namespace ruby
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "params/FaultModel.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/RubyNetwork.hh"

namespace gem5
{
struct GarnetNetworkParams
    : public RubyNetworkParams
{
    gem5::ruby::garnet::GarnetNetwork * create() const;
    uint32_t buffers_per_ctrl_vc;
    uint32_t buffers_per_data_vc;
    bool enable_fault_model;
    gem5::ruby::FaultModel * fault_model;
    uint32_t garnet_deadlock_threshold;
    uint32_t ni_flit_size;
    int num_rows;
    int routing_algorithm;
    uint32_t vcs_per_vnet;
};

} // namespace gem5

#endif // __PARAMS__GarnetNetwork__
