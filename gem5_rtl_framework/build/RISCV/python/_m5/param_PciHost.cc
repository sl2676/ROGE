/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/PciHost.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/pci/host.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_PciHost");
    py::class_<PciHostParams, PioDeviceParams, std::unique_ptr<PciHostParams, py::nodelete>>(m, "PciHostParams")
        ;

    py::class_<gem5::PciHost, gem5::PioDevice, std::unique_ptr<gem5::PciHost, py::nodelete>>(m, "gem5_COLONS_PciHost")
        ;

}

static EmbeddedPyBind embed_obj("PciHost", module_init, "PioDevice");

} // namespace gem5
