/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SimpleUart.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/simple.hh"

#include "enums/ByteOrder.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SimpleUart");
    py::class_<SimpleUartParams, UartParams, std::unique_ptr<SimpleUartParams, py::nodelete>>(m, "SimpleUartParams")
        .def(py::init<>())
        .def("create", &SimpleUartParams::create)
        .def_readwrite("byte_order", &SimpleUartParams::byte_order)
        .def_readwrite("end_on_eot", &SimpleUartParams::end_on_eot)
        .def_readwrite("pio_size", &SimpleUartParams::pio_size)
        ;

    py::class_<gem5::SimpleUart, gem5::Uart, std::unique_ptr<gem5::SimpleUart, py::nodelete>>(m, "gem5_COLONS_SimpleUart")
        ;

}

static EmbeddedPyBind embed_obj("SimpleUart", module_init, "Uart");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySimpleUartParamsClass
{
  public:
    gem5::SimpleUart *create() const;
};

template <class CxxClass, class Enable=void>
class DummySimpleUartShunt;

template <class CxxClass>
class DummySimpleUartShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SimpleUartParams &>::value>>
{
  public:
    using Params = SimpleUartParams;
    static gem5::SimpleUart *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySimpleUartShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SimpleUartParams &>::value>>
{
  public:
    using Params = DummySimpleUartParamsClass;
    static gem5::SimpleUart *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SimpleUart *
DummySimpleUartShunt<gem5::SimpleUart>::Params::create() const
{
    return DummySimpleUartShunt<gem5::SimpleUart>::
        create(*this);
}

} // namespace gem5
