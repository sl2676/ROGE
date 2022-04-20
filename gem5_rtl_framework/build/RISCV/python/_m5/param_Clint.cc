/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Clint.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/riscv/clint.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Clint");
    py::class_<ClintParams, BasicPioDeviceParams, std::unique_ptr<ClintParams, py::nodelete>>(m, "ClintParams")
        .def(py::init<>())
        .def("create", &ClintParams::create)
        .def_readwrite("pio_size", &ClintParams::pio_size)
        .def_readwrite("port_int_pin_connection_count", &ClintParams::port_int_pin_connection_count)
        ;

    py::class_<gem5::Clint, gem5::BasicPioDevice, std::unique_ptr<gem5::Clint, py::nodelete>>(m, "gem5_COLONS_Clint")
        ;

}

static EmbeddedPyBind embed_obj("Clint", module_init, "BasicPioDevice");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyClintParamsClass
{
  public:
    gem5::Clint *create() const;
};

template <class CxxClass, class Enable=void>
class DummyClintShunt;

template <class CxxClass>
class DummyClintShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const ClintParams &>::value>>
{
  public:
    using Params = ClintParams;
    static gem5::Clint *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyClintShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const ClintParams &>::value>>
{
  public:
    using Params = DummyClintParamsClass;
    static gem5::Clint *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::Clint *
DummyClintShunt<gem5::Clint>::Params::create() const
{
    return DummyClintShunt<gem5::Clint>::
        create(*this);
}

} // namespace gem5