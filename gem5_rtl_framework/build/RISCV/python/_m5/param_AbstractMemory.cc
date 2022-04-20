/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/AbstractMemory.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/abstract_mem.hh"

#include <string>
#include "base/types.hh"
#include "base/addr_range.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_AbstractMemory");
    py::class_<AbstractMemoryParams, ClockedObjectParams, std::unique_ptr<AbstractMemoryParams, py::nodelete>>(m, "AbstractMemoryParams")
        .def_readwrite("conf_table_reported", &AbstractMemoryParams::conf_table_reported)
        .def_readwrite("image_file", &AbstractMemoryParams::image_file)
        .def_readwrite("in_addr_map", &AbstractMemoryParams::in_addr_map)
        .def_readwrite("kvm_map", &AbstractMemoryParams::kvm_map)
        .def_readwrite("null", &AbstractMemoryParams::null)
        .def_readwrite("range", &AbstractMemoryParams::range)
        ;

    py::class_<gem5::memory::AbstractMemory, gem5::ClockedObject, std::unique_ptr<gem5::memory::AbstractMemory, py::nodelete>>(m, "gem5_COLONS_memory_COLONS_AbstractMemory")
        ;

}

static EmbeddedPyBind embed_obj("AbstractMemory", module_init, "ClockedObject");

} // namespace gem5