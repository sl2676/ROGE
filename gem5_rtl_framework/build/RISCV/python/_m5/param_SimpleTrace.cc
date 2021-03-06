/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SimpleTrace.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/o3/probe/simple_trace.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SimpleTrace");
    py::class_<SimpleTraceParams, ProbeListenerObjectParams, std::unique_ptr<SimpleTraceParams, py::nodelete>>(m, "SimpleTraceParams")
        .def(py::init<>())
        .def("create", &SimpleTraceParams::create)
        ;

    py::class_<gem5::o3::SimpleTrace, gem5::ProbeListenerObject, std::unique_ptr<gem5::o3::SimpleTrace, py::nodelete>>(m, "gem5_COLONS_o3_COLONS_SimpleTrace")
        ;

}

static EmbeddedPyBind embed_obj("SimpleTrace", module_init, "ProbeListenerObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySimpleTraceParamsClass
{
  public:
    gem5::o3::SimpleTrace *create() const;
};

template <class CxxClass, class Enable=void>
class DummySimpleTraceShunt;

template <class CxxClass>
class DummySimpleTraceShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SimpleTraceParams &>::value>>
{
  public:
    using Params = SimpleTraceParams;
    static gem5::o3::SimpleTrace *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySimpleTraceShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SimpleTraceParams &>::value>>
{
  public:
    using Params = DummySimpleTraceParamsClass;
    static gem5::o3::SimpleTrace *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::o3::SimpleTrace *
DummySimpleTraceShunt<gem5::o3::SimpleTrace>::Params::create() const
{
    return DummySimpleTraceShunt<gem5::o3::SimpleTrace>::
        create(*this);
}

} // namespace gem5
