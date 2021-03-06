/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/CoherentXBar.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/coherent_xbar.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "mem/snoop_filter.hh"
#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_CoherentXBar");
    py::class_<CoherentXBarParams, BaseXBarParams, std::unique_ptr<CoherentXBarParams, py::nodelete>>(m, "CoherentXBarParams")
        .def(py::init<>())
        .def("create", &CoherentXBarParams::create)
        .def_readwrite("max_outstanding_snoops", &CoherentXBarParams::max_outstanding_snoops)
        .def_readwrite("max_routing_table_size", &CoherentXBarParams::max_routing_table_size)
        .def_readwrite("point_of_coherency", &CoherentXBarParams::point_of_coherency)
        .def_readwrite("point_of_unification", &CoherentXBarParams::point_of_unification)
        .def_readwrite("snoop_filter", &CoherentXBarParams::snoop_filter)
        .def_readwrite("snoop_response_latency", &CoherentXBarParams::snoop_response_latency)
        .def_readwrite("system", &CoherentXBarParams::system)
        ;

    py::class_<gem5::CoherentXBar, gem5::BaseXBar, std::unique_ptr<gem5::CoherentXBar, py::nodelete>>(m, "gem5_COLONS_CoherentXBar")
        ;

}

static EmbeddedPyBind embed_obj("CoherentXBar", module_init, "BaseXBar");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyCoherentXBarParamsClass
{
  public:
    gem5::CoherentXBar *create() const;
};

template <class CxxClass, class Enable=void>
class DummyCoherentXBarShunt;

template <class CxxClass>
class DummyCoherentXBarShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const CoherentXBarParams &>::value>>
{
  public:
    using Params = CoherentXBarParams;
    static gem5::CoherentXBar *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyCoherentXBarShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const CoherentXBarParams &>::value>>
{
  public:
    using Params = DummyCoherentXBarParamsClass;
    static gem5::CoherentXBar *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::CoherentXBar *
DummyCoherentXBarShunt<gem5::CoherentXBar>::Params::create() const
{
    return DummyCoherentXBarShunt<gem5::CoherentXBar>::
        create(*this);
}

} // namespace gem5
