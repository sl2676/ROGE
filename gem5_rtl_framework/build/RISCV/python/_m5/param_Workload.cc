/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Workload.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/workload.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Workload");
    py::class_<WorkloadParams, SimObjectParams, std::unique_ptr<WorkloadParams, py::nodelete>>(m, "WorkloadParams")
        .def_readwrite("wait_for_remote_gdb", &WorkloadParams::wait_for_remote_gdb)
        ;

    py::class_<gem5::Workload, gem5::SimObject, std::unique_ptr<gem5::Workload, py::nodelete>>(m, "gem5_COLONS_Workload")
        ;

}

static EmbeddedPyBind embed_obj("Workload", module_init, "SimObject");

} // namespace gem5
