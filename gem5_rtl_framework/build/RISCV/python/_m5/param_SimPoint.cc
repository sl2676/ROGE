/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SimPoint.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/simple/probes/simpoint.hh"

#include "base/types.hh"
#include <string>
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SimPoint");
    py::class_<SimPointParams, ProbeListenerObjectParams, std::unique_ptr<SimPointParams, py::nodelete>>(m, "SimPointParams")
        .def(py::init<>())
        .def("create", &SimPointParams::create)
        .def_readwrite("interval", &SimPointParams::interval)
        .def_readwrite("profile_file", &SimPointParams::profile_file)
        ;

    py::class_<gem5::SimPoint, gem5::ProbeListenerObject, std::unique_ptr<gem5::SimPoint, py::nodelete>>(m, "gem5_COLONS_SimPoint")
        ;

}

static EmbeddedPyBind embed_obj("SimPoint", module_init, "ProbeListenerObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySimPointParamsClass
{
  public:
    gem5::SimPoint *create() const;
};

template <class CxxClass, class Enable=void>
class DummySimPointShunt;

template <class CxxClass>
class DummySimPointShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SimPointParams &>::value>>
{
  public:
    using Params = SimPointParams;
    static gem5::SimPoint *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySimPointShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SimPointParams &>::value>>
{
  public:
    using Params = DummySimPointParamsClass;
    static gem5::SimPoint *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SimPoint *
DummySimPointShunt<gem5::SimPoint>::Params::create() const
{
    return DummySimPointShunt<gem5::SimPoint>::
        create(*this);
}

} // namespace gem5
