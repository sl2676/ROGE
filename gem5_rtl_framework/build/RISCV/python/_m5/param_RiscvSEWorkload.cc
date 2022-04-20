/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/RiscvSEWorkload.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "arch/riscv/se_workload.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_RiscvSEWorkload");
    py::class_<RiscvSEWorkloadParams, SEWorkloadParams, std::unique_ptr<RiscvSEWorkloadParams, py::nodelete>>(m, "RiscvSEWorkloadParams")
        ;

    py::class_<gem5::RiscvISA::SEWorkload, gem5::SEWorkload, std::unique_ptr<gem5::RiscvISA::SEWorkload, py::nodelete>>(m, "gem5_COLONS_RiscvISA_COLONS_SEWorkload")
        ;

}

static EmbeddedPyBind embed_obj("RiscvSEWorkload", module_init, "SEWorkload");

} // namespace gem5
