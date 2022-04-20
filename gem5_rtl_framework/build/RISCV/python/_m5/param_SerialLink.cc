/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SerialLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/serial_link.hh"

#include "base/types.hh"
#include "base/types.hh"
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
    py::module_ m = m_internal.def_submodule("param_SerialLink");
    py::class_<SerialLinkParams, ClockedObjectParams, std::unique_ptr<SerialLinkParams, py::nodelete>>(m, "SerialLinkParams")
        .def(py::init<>())
        .def("create", &SerialLinkParams::create)
        .def_readwrite("delay", &SerialLinkParams::delay)
        .def_readwrite("link_speed", &SerialLinkParams::link_speed)
        .def_readwrite("num_lanes", &SerialLinkParams::num_lanes)
        .def_readwrite("ranges", &SerialLinkParams::ranges)
        .def_readwrite("req_size", &SerialLinkParams::req_size)
        .def_readwrite("resp_size", &SerialLinkParams::resp_size)
        .def_readwrite("port_mem_side_port_connection_count", &SerialLinkParams::port_mem_side_port_connection_count)
        .def_readwrite("port_cpu_side_port_connection_count", &SerialLinkParams::port_cpu_side_port_connection_count)
        ;

    py::class_<gem5::SerialLink, gem5::ClockedObject, std::unique_ptr<gem5::SerialLink, py::nodelete>>(m, "gem5_COLONS_SerialLink")
        ;

}

static EmbeddedPyBind embed_obj("SerialLink", module_init, "ClockedObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySerialLinkParamsClass
{
  public:
    gem5::SerialLink *create() const;
};

template <class CxxClass, class Enable=void>
class DummySerialLinkShunt;

template <class CxxClass>
class DummySerialLinkShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SerialLinkParams &>::value>>
{
  public:
    using Params = SerialLinkParams;
    static gem5::SerialLink *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySerialLinkShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SerialLinkParams &>::value>>
{
  public:
    using Params = DummySerialLinkParamsClass;
    static gem5::SerialLink *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SerialLink *
DummySerialLinkShunt<gem5::SerialLink>::Params::create() const
{
    return DummySerialLinkShunt<gem5::SerialLink>::
        create(*this);
}

} // namespace gem5
