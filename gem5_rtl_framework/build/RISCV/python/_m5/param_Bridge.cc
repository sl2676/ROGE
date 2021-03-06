/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Bridge.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/bridge.hh"

#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/addr_range.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Bridge");
    py::class_<BridgeParams, ClockedObjectParams, std::unique_ptr<BridgeParams, py::nodelete>>(m, "BridgeParams")
        .def(py::init<>())
        .def("create", &BridgeParams::create)
        .def_readwrite("delay", &BridgeParams::delay)
        .def_readwrite("ranges", &BridgeParams::ranges)
        .def_readwrite("req_size", &BridgeParams::req_size)
        .def_readwrite("resp_size", &BridgeParams::resp_size)
        .def_readwrite("port_mem_side_port_connection_count", &BridgeParams::port_mem_side_port_connection_count)
        .def_readwrite("port_cpu_side_port_connection_count", &BridgeParams::port_cpu_side_port_connection_count)
        ;

    py::class_<gem5::Bridge, gem5::ClockedObject, std::unique_ptr<gem5::Bridge, py::nodelete>>(m, "gem5_COLONS_Bridge")
        ;

}

static EmbeddedPyBind embed_obj("Bridge", module_init, "ClockedObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyBridgeParamsClass
{
  public:
    gem5::Bridge *create() const;
};

template <class CxxClass, class Enable=void>
class DummyBridgeShunt;

template <class CxxClass>
class DummyBridgeShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const BridgeParams &>::value>>
{
  public:
    using Params = BridgeParams;
    static gem5::Bridge *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyBridgeShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const BridgeParams &>::value>>
{
  public:
    using Params = DummyBridgeParamsClass;
    static gem5::Bridge *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::Bridge *
DummyBridgeShunt<gem5::Bridge>::Params::create() const
{
    return DummyBridgeShunt<gem5::Bridge>::
        create(*this);
}

} // namespace gem5
