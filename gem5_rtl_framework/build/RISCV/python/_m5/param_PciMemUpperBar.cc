/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/PciMemUpperBar.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/pci/device.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_PciMemUpperBar");
    py::class_<PciMemUpperBarParams, PciBarParams, std::unique_ptr<PciMemUpperBarParams, py::nodelete>>(m, "PciMemUpperBarParams")
        .def(py::init<>())
        .def("create", &PciMemUpperBarParams::create)
        ;

    py::class_<gem5::PciMemUpperBar, gem5::PciBar, std::unique_ptr<gem5::PciMemUpperBar, py::nodelete>>(m, "gem5_COLONS_PciMemUpperBar")
        ;

}

static EmbeddedPyBind embed_obj("PciMemUpperBar", module_init, "PciBar");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyPciMemUpperBarParamsClass
{
  public:
    gem5::PciMemUpperBar *create() const;
};

template <class CxxClass, class Enable=void>
class DummyPciMemUpperBarShunt;

template <class CxxClass>
class DummyPciMemUpperBarShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const PciMemUpperBarParams &>::value>>
{
  public:
    using Params = PciMemUpperBarParams;
    static gem5::PciMemUpperBar *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyPciMemUpperBarShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const PciMemUpperBarParams &>::value>>
{
  public:
    using Params = DummyPciMemUpperBarParamsClass;
    static gem5::PciMemUpperBar *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::PciMemUpperBar *
DummyPciMemUpperBarShunt<gem5::PciMemUpperBar>::Params::create() const
{
    return DummyPciMemUpperBarShunt<gem5::PciMemUpperBar>::
        create(*this);
}

} // namespace gem5