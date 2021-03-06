/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/VirtIO9PBase.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/virtio/fs9p.hh"

#include "base/types.hh"
#include <string>
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_VirtIO9PBase");
    py::class_<VirtIO9PBaseParams, VirtIODeviceBaseParams, std::unique_ptr<VirtIO9PBaseParams, py::nodelete>>(m, "VirtIO9PBaseParams")
        .def_readwrite("queueSize", &VirtIO9PBaseParams::queueSize)
        .def_readwrite("tag", &VirtIO9PBaseParams::tag)
        ;

    py::class_<gem5::VirtIO9PBase, gem5::VirtIODeviceBase, std::unique_ptr<gem5::VirtIO9PBase, py::nodelete>>(m, "gem5_COLONS_VirtIO9PBase")
        ;

}

static EmbeddedPyBind embed_obj("VirtIO9PBase", module_init, "VirtIODeviceBase");

} // namespace gem5
