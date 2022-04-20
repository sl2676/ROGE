/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/PciIoBar.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/pci/device.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_PciIoBar");
    py::class_<PciIoBarParams, PciBarParams, std::unique_ptr<PciIoBarParams, py::nodelete>>(m, "PciIoBarParams")
        .def(py::init<>())
        .def("create", &PciIoBarParams::create)
        .def_readwrite("size", &PciIoBarParams::size)
        ;

    py::class_<gem5::PciIoBar, gem5::PciBar, std::unique_ptr<gem5::PciIoBar, py::nodelete>>(m, "gem5_COLONS_PciIoBar")
        ;

}

static EmbeddedPyBind embed_obj("PciIoBar", module_init, "PciBar");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyPciIoBarParamsClass
{
  public:
    gem5::PciIoBar *create() const;
};

template <class CxxClass, class Enable=void>
class DummyPciIoBarShunt;

template <class CxxClass>
class DummyPciIoBarShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const PciIoBarParams &>::value>>
{
  public:
    using Params = PciIoBarParams;
    static gem5::PciIoBar *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyPciIoBarShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const PciIoBarParams &>::value>>
{
  public:
    using Params = DummyPciIoBarParamsClass;
    static gem5::PciIoBar *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::PciIoBar *
DummyPciIoBarShunt<gem5::PciIoBar>::Params::create() const
{
    return DummyPciIoBarShunt<gem5::PciIoBar>::
        create(*this);
}

} // namespace gem5
