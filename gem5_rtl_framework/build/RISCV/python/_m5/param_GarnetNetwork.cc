/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/GarnetNetwork.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet/GarnetNetwork.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "mem/ruby/network/fault_model/FaultModel.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_GarnetNetwork");
    py::class_<GarnetNetworkParams, RubyNetworkParams, std::unique_ptr<GarnetNetworkParams, py::nodelete>>(m, "GarnetNetworkParams")
        .def(py::init<>())
        .def("create", &GarnetNetworkParams::create)
        .def_readwrite("buffers_per_ctrl_vc", &GarnetNetworkParams::buffers_per_ctrl_vc)
        .def_readwrite("buffers_per_data_vc", &GarnetNetworkParams::buffers_per_data_vc)
        .def_readwrite("enable_fault_model", &GarnetNetworkParams::enable_fault_model)
        .def_readwrite("fault_model", &GarnetNetworkParams::fault_model)
        .def_readwrite("garnet_deadlock_threshold", &GarnetNetworkParams::garnet_deadlock_threshold)
        .def_readwrite("ni_flit_size", &GarnetNetworkParams::ni_flit_size)
        .def_readwrite("num_rows", &GarnetNetworkParams::num_rows)
        .def_readwrite("routing_algorithm", &GarnetNetworkParams::routing_algorithm)
        .def_readwrite("vcs_per_vnet", &GarnetNetworkParams::vcs_per_vnet)
        ;

    py::class_<gem5::ruby::garnet::GarnetNetwork, gem5::ruby::Network, std::unique_ptr<gem5::ruby::garnet::GarnetNetwork, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_garnet_COLONS_GarnetNetwork")
        ;

}

static EmbeddedPyBind embed_obj("GarnetNetwork", module_init, "RubyNetwork");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyGarnetNetworkParamsClass
{
  public:
    gem5::ruby::garnet::GarnetNetwork *create() const;
};

template <class CxxClass, class Enable=void>
class DummyGarnetNetworkShunt;

template <class CxxClass>
class DummyGarnetNetworkShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const GarnetNetworkParams &>::value>>
{
  public:
    using Params = GarnetNetworkParams;
    static gem5::ruby::garnet::GarnetNetwork *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyGarnetNetworkShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const GarnetNetworkParams &>::value>>
{
  public:
    using Params = DummyGarnetNetworkParamsClass;
    static gem5::ruby::garnet::GarnetNetwork *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::garnet::GarnetNetwork *
DummyGarnetNetworkShunt<gem5::ruby::garnet::GarnetNetwork>::Params::create() const
{
    return DummyGarnetNetworkShunt<gem5::ruby::garnet::GarnetNetwork>::
        create(*this);
}

} // namespace gem5
