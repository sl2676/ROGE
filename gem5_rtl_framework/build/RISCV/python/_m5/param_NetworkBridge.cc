/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/NetworkBridge.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet/NetworkBridge.hh"

#include "base/types.hh"
#include "mem/ruby/network/garnet/NetworkLink.hh"
#include "base/types.hh"
#include "enums/CDCType.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_NetworkBridge");
    py::class_<NetworkBridgeParams, CreditLinkParams, std::unique_ptr<NetworkBridgeParams, py::nodelete>>(m, "NetworkBridgeParams")
        .def(py::init<>())
        .def("create", &NetworkBridgeParams::create)
        .def_readwrite("cdc_latency", &NetworkBridgeParams::cdc_latency)
        .def_readwrite("link", &NetworkBridgeParams::link)
        .def_readwrite("serdes_latency", &NetworkBridgeParams::serdes_latency)
        .def_readwrite("vtype", &NetworkBridgeParams::vtype)
        ;

    py::class_<gem5::ruby::garnet::NetworkBridge, gem5::ruby::garnet::CreditLink, std::unique_ptr<gem5::ruby::garnet::NetworkBridge, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_garnet_COLONS_NetworkBridge")
        ;

}

static EmbeddedPyBind embed_obj("NetworkBridge", module_init, "CreditLink");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyNetworkBridgeParamsClass
{
  public:
    gem5::ruby::garnet::NetworkBridge *create() const;
};

template <class CxxClass, class Enable=void>
class DummyNetworkBridgeShunt;

template <class CxxClass>
class DummyNetworkBridgeShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const NetworkBridgeParams &>::value>>
{
  public:
    using Params = NetworkBridgeParams;
    static gem5::ruby::garnet::NetworkBridge *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyNetworkBridgeShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const NetworkBridgeParams &>::value>>
{
  public:
    using Params = DummyNetworkBridgeParamsClass;
    static gem5::ruby::garnet::NetworkBridge *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::garnet::NetworkBridge *
DummyNetworkBridgeShunt<gem5::ruby::garnet::NetworkBridge>::Params::create() const
{
    return DummyNetworkBridgeShunt<gem5::ruby::garnet::NetworkBridge>::
        create(*this);
}

} // namespace gem5
