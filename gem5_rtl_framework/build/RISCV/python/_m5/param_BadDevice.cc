/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/BadDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/baddev.hh"

#include <string>
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_BadDevice");
    py::class_<BadDeviceParams, BasicPioDeviceParams, std::unique_ptr<BadDeviceParams, py::nodelete>>(m, "BadDeviceParams")
        .def(py::init<>())
        .def("create", &BadDeviceParams::create)
        .def_readwrite("devicename", &BadDeviceParams::devicename)
        ;

    py::class_<gem5::BadDevice, gem5::BasicPioDevice, std::unique_ptr<gem5::BadDevice, py::nodelete>>(m, "gem5_COLONS_BadDevice")
        ;

}

static EmbeddedPyBind embed_obj("BadDevice", module_init, "BasicPioDevice");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyBadDeviceParamsClass
{
  public:
    gem5::BadDevice *create() const;
};

template <class CxxClass, class Enable=void>
class DummyBadDeviceShunt;

template <class CxxClass>
class DummyBadDeviceShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const BadDeviceParams &>::value>>
{
  public:
    using Params = BadDeviceParams;
    static gem5::BadDevice *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyBadDeviceShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const BadDeviceParams &>::value>>
{
  public:
    using Params = DummyBadDeviceParamsClass;
    static gem5::BadDevice *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::BadDevice *
DummyBadDeviceShunt<gem5::BadDevice>::Params::create() const
{
    return DummyBadDeviceShunt<gem5::BadDevice>::
        create(*this);
}

} // namespace gem5