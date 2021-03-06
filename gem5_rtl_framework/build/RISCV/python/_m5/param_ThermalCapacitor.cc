/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/ThermalCapacitor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/thermal_model.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_ThermalCapacitor");
    py::class_<ThermalCapacitorParams, SimObjectParams, std::unique_ptr<ThermalCapacitorParams, py::nodelete>>(m, "ThermalCapacitorParams")
        .def(py::init<>())
        .def("create", &ThermalCapacitorParams::create)
        .def_readwrite("capacitance", &ThermalCapacitorParams::capacitance)
        ;

    py::class_<gem5::ThermalCapacitor, gem5::SimObject, std::unique_ptr<gem5::ThermalCapacitor, py::nodelete>>(m, "gem5_COLONS_ThermalCapacitor")
        .def("setNodes", &gem5::ThermalCapacitor::setNodes)
        ;

}

static EmbeddedPyBind embed_obj("ThermalCapacitor", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyThermalCapacitorParamsClass
{
  public:
    gem5::ThermalCapacitor *create() const;
};

template <class CxxClass, class Enable=void>
class DummyThermalCapacitorShunt;

template <class CxxClass>
class DummyThermalCapacitorShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const ThermalCapacitorParams &>::value>>
{
  public:
    using Params = ThermalCapacitorParams;
    static gem5::ThermalCapacitor *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyThermalCapacitorShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const ThermalCapacitorParams &>::value>>
{
  public:
    using Params = DummyThermalCapacitorParamsClass;
    static gem5::ThermalCapacitor *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ThermalCapacitor *
DummyThermalCapacitorShunt<gem5::ThermalCapacitor>::Params::create() const
{
    return DummyThermalCapacitorShunt<gem5::ThermalCapacitor>::
        create(*this);
}

} // namespace gem5
