/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/DirectedGenerator.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/directedtest/DirectedGenerator.hh"

#include "base/types.hh"
#include "sim/system.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_DirectedGenerator");
    py::class_<DirectedGeneratorParams, SimObjectParams, std::unique_ptr<DirectedGeneratorParams, py::nodelete>>(m, "DirectedGeneratorParams")
        .def_readwrite("num_cpus", &DirectedGeneratorParams::num_cpus)
        .def_readwrite("system", &DirectedGeneratorParams::system)
        ;

    py::class_<gem5::DirectedGenerator, gem5::SimObject, std::unique_ptr<gem5::DirectedGenerator, py::nodelete>>(m, "gem5_COLONS_DirectedGenerator")
        ;

}

static EmbeddedPyBind embed_obj("DirectedGenerator", module_init, "SimObject");

} // namespace gem5
