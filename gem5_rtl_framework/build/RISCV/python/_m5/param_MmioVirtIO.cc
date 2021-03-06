/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MmioVirtIO.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/riscv/vio_mmio.hh"

#include "dev/virtio/base.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MmioVirtIO");
    py::class_<MmioVirtIOParams, PlicIntDeviceParams, std::unique_ptr<MmioVirtIOParams, py::nodelete>>(m, "MmioVirtIOParams")
        .def(py::init<>())
        .def("create", &MmioVirtIOParams::create)
        .def_readwrite("vio", &MmioVirtIOParams::vio)
        ;

    py::class_<gem5::MmioVirtIO, gem5::PlicIntDevice, std::unique_ptr<gem5::MmioVirtIO, py::nodelete>>(m, "gem5_COLONS_MmioVirtIO")
        ;

}

static EmbeddedPyBind embed_obj("MmioVirtIO", module_init, "PlicIntDevice");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMmioVirtIOParamsClass
{
  public:
    gem5::MmioVirtIO *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMmioVirtIOShunt;

template <class CxxClass>
class DummyMmioVirtIOShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MmioVirtIOParams &>::value>>
{
  public:
    using Params = MmioVirtIOParams;
    static gem5::MmioVirtIO *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMmioVirtIOShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MmioVirtIOParams &>::value>>
{
  public:
    using Params = DummyMmioVirtIOParamsClass;
    static gem5::MmioVirtIO *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::MmioVirtIO *
DummyMmioVirtIOShunt<gem5::MmioVirtIO>::Params::create() const
{
    return DummyMmioVirtIOShunt<gem5::MmioVirtIO>::
        create(*this);
}

} // namespace gem5
