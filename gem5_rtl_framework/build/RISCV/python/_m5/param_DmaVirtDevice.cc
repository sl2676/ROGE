/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/DmaVirtDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/dma_virt_device.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_DmaVirtDevice");
    py::class_<DmaVirtDeviceParams, DmaDeviceParams, std::unique_ptr<DmaVirtDeviceParams, py::nodelete>>(m, "DmaVirtDeviceParams")
        ;

    py::class_<gem5::DmaVirtDevice, gem5::DmaDevice, std::unique_ptr<gem5::DmaVirtDevice, py::nodelete>>(m, "gem5_COLONS_DmaVirtDevice")
        ;

}

static EmbeddedPyBind embed_obj("DmaVirtDevice", module_init, "DmaDevice");

} // namespace gem5