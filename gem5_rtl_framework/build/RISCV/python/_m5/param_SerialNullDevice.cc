/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SerialNullDevice.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/serial.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SerialNullDevice");
    py::class_<SerialNullDeviceParams, SerialDeviceParams, std::unique_ptr<SerialNullDeviceParams, py::nodelete>>(m, "SerialNullDeviceParams")
        .def(py::init<>())
        .def("create", &SerialNullDeviceParams::create)
        ;

    py::class_<gem5::SerialNullDevice, gem5::SerialDevice, std::unique_ptr<gem5::SerialNullDevice, py::nodelete>>(m, "gem5_COLONS_SerialNullDevice")
        ;

}

static EmbeddedPyBind embed_obj("SerialNullDevice", module_init, "SerialDevice");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySerialNullDeviceParamsClass
{
  public:
    gem5::SerialNullDevice *create() const;
};

template <class CxxClass, class Enable=void>
class DummySerialNullDeviceShunt;

template <class CxxClass>
class DummySerialNullDeviceShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SerialNullDeviceParams &>::value>>
{
  public:
    using Params = SerialNullDeviceParams;
    static gem5::SerialNullDevice *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySerialNullDeviceShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SerialNullDeviceParams &>::value>>
{
  public:
    using Params = DummySerialNullDeviceParamsClass;
    static gem5::SerialNullDevice *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SerialNullDevice *
DummySerialNullDeviceShunt<gem5::SerialNullDevice>::Params::create() const
{
    return DummySerialNullDeviceShunt<gem5::SerialNullDevice>::
        create(*this);
}

} // namespace gem5
