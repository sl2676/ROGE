/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/rtlFIFO.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "rtl/rtlFIFO.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_rtlFIFO");
    py::class_<rtlFIFOParams, rtlObjectParams, std::unique_ptr<rtlFIFOParams, py::nodelete>>(m, "rtlFIFOParams")
        .def(py::init<>())
        .def("create", &rtlFIFOParams::create)
        .def_readwrite("port_cpu_side_connection_count", &rtlFIFOParams::port_cpu_side_connection_count)
        .def_readwrite("port_mem_side_connection_count", &rtlFIFOParams::port_mem_side_connection_count)
        ;

    py::class_<gem5::rtlFIFO, gem5::rtlObject, std::unique_ptr<gem5::rtlFIFO, py::nodelete>>(m, "gem5_COLONS_rtlFIFO")
        ;

}

static EmbeddedPyBind embed_obj("rtlFIFO", module_init, "rtlObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyrtlFIFOParamsClass
{
  public:
    gem5::rtlFIFO *create() const;
};

template <class CxxClass, class Enable=void>
class DummyrtlFIFOShunt;

template <class CxxClass>
class DummyrtlFIFOShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const rtlFIFOParams &>::value>>
{
  public:
    using Params = rtlFIFOParams;
    static gem5::rtlFIFO *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyrtlFIFOShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const rtlFIFOParams &>::value>>
{
  public:
    using Params = DummyrtlFIFOParamsClass;
    static gem5::rtlFIFO *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::rtlFIFO *
DummyrtlFIFOShunt<gem5::rtlFIFO>::Params::create() const
{
    return DummyrtlFIFOShunt<gem5::rtlFIFO>::
        create(*this);
}

} // namespace gem5
