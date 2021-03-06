/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/GarnetExtLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/garnet/GarnetLink.hh"

#include <vector>
#include "mem/ruby/network/garnet/CreditLink.hh"
#include <vector>
#include "mem/ruby/network/garnet/NetworkBridge.hh"
#include <vector>
#include "mem/ruby/network/garnet/NetworkBridge.hh"
#include <vector>
#include "mem/ruby/network/garnet/NetworkBridge.hh"
#include <vector>
#include "mem/ruby/network/garnet/NetworkBridge.hh"
#include <vector>
#include "mem/ruby/network/garnet/NetworkLink.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_GarnetExtLink");
    py::class_<GarnetExtLinkParams, BasicExtLinkParams, std::unique_ptr<GarnetExtLinkParams, py::nodelete>>(m, "GarnetExtLinkParams")
        .def(py::init<>())
        .def("create", &GarnetExtLinkParams::create)
        .def_readwrite("credit_links", &GarnetExtLinkParams::credit_links)
        .def_readwrite("ext_cdc", &GarnetExtLinkParams::ext_cdc)
        .def_readwrite("ext_cred_bridge", &GarnetExtLinkParams::ext_cred_bridge)
        .def_readwrite("ext_net_bridge", &GarnetExtLinkParams::ext_net_bridge)
        .def_readwrite("ext_serdes", &GarnetExtLinkParams::ext_serdes)
        .def_readwrite("int_cdc", &GarnetExtLinkParams::int_cdc)
        .def_readwrite("int_cred_bridge", &GarnetExtLinkParams::int_cred_bridge)
        .def_readwrite("int_net_bridge", &GarnetExtLinkParams::int_net_bridge)
        .def_readwrite("int_serdes", &GarnetExtLinkParams::int_serdes)
        .def_readwrite("network_links", &GarnetExtLinkParams::network_links)
        .def_readwrite("width", &GarnetExtLinkParams::width)
        ;

    py::class_<gem5::ruby::garnet::GarnetExtLink, gem5::ruby::BasicExtLink, std::unique_ptr<gem5::ruby::garnet::GarnetExtLink, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_garnet_COLONS_GarnetExtLink")
        ;

}

static EmbeddedPyBind embed_obj("GarnetExtLink", module_init, "BasicExtLink");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyGarnetExtLinkParamsClass
{
  public:
    gem5::ruby::garnet::GarnetExtLink *create() const;
};

template <class CxxClass, class Enable=void>
class DummyGarnetExtLinkShunt;

template <class CxxClass>
class DummyGarnetExtLinkShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const GarnetExtLinkParams &>::value>>
{
  public:
    using Params = GarnetExtLinkParams;
    static gem5::ruby::garnet::GarnetExtLink *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyGarnetExtLinkShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const GarnetExtLinkParams &>::value>>
{
  public:
    using Params = DummyGarnetExtLinkParamsClass;
    static gem5::ruby::garnet::GarnetExtLink *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::garnet::GarnetExtLink *
DummyGarnetExtLinkShunt<gem5::ruby::garnet::GarnetExtLink>::Params::create() const
{
    return DummyGarnetExtLinkShunt<gem5::ruby::garnet::GarnetExtLink>::
        create(*this);
}

} // namespace gem5
