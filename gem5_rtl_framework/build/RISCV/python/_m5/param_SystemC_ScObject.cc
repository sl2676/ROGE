/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SystemC_ScObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "systemc/ext/core/sc_object.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SystemC_ScObject");
    py::class_<SystemC_ScObjectParams, SimObjectParams, std::unique_ptr<SystemC_ScObjectParams, py::nodelete>>(m, "SystemC_ScObjectParams")
        ;

    py::class_<sc_core::sc_object, std::unique_ptr<sc_core::sc_object, py::nodelete>>(m, "sc_core_COLONS_sc_object")
        ;

}

static EmbeddedPyBind embed_obj("SystemC_ScObject", module_init, "SimObject");

} // namespace gem5