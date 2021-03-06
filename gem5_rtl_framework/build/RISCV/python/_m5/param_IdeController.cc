/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/IdeController.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/ide_ctrl.hh"

#include "base/types.hh"
#include <vector>
#include "dev/storage/ide_disk.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_IdeController");
    py::class_<IdeControllerParams, PciDeviceParams, std::unique_ptr<IdeControllerParams, py::nodelete>>(m, "IdeControllerParams")
        .def(py::init<>())
        .def("create", &IdeControllerParams::create)
        .def_readwrite("ctrl_offset", &IdeControllerParams::ctrl_offset)
        .def_readwrite("disks", &IdeControllerParams::disks)
        .def_readwrite("io_shift", &IdeControllerParams::io_shift)
        ;

    py::class_<gem5::IdeController, gem5::PciDevice, std::unique_ptr<gem5::IdeController, py::nodelete>>(m, "gem5_COLONS_IdeController")
        ;

}

static EmbeddedPyBind embed_obj("IdeController", module_init, "PciDevice");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyIdeControllerParamsClass
{
  public:
    gem5::IdeController *create() const;
};

template <class CxxClass, class Enable=void>
class DummyIdeControllerShunt;

template <class CxxClass>
class DummyIdeControllerShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const IdeControllerParams &>::value>>
{
  public:
    using Params = IdeControllerParams;
    static gem5::IdeController *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyIdeControllerShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const IdeControllerParams &>::value>>
{
  public:
    using Params = DummyIdeControllerParamsClass;
    static gem5::IdeController *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::IdeController *
DummyIdeControllerShunt<gem5::IdeController>::Params::create() const
{
    return DummyIdeControllerShunt<gem5::IdeController>::
        create(*this);
}

} // namespace gem5
