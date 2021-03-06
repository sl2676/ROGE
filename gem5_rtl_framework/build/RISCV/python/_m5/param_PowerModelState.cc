/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/PowerModelState.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/power/power_model.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_PowerModelState");
    py::class_<PowerModelStateParams, SimObjectParams, std::unique_ptr<PowerModelStateParams, py::nodelete>>(m, "PowerModelStateParams")
        ;

    py::class_<gem5::PowerModelState, gem5::SimObject, std::unique_ptr<gem5::PowerModelState, py::nodelete>>(m, "gem5_COLONS_PowerModelState")
        .def("getDynamicPower", &gem5::PowerModelState::getDynamicPower)
        .def("getStaticPower", &gem5::PowerModelState::getStaticPower)
        ;

}

static EmbeddedPyBind embed_obj("PowerModelState", module_init, "SimObject");

} // namespace gem5
