/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Terminal.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/serial/terminal.hh"

#include "base/types.hh"
#include "enums/TerminalDump.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Terminal");
    py::class_<TerminalParams, SerialDeviceParams, std::unique_ptr<TerminalParams, py::nodelete>>(m, "TerminalParams")
        .def(py::init<>())
        .def("create", &TerminalParams::create)
        .def_readwrite("number", &TerminalParams::number)
        .def_readwrite("outfile", &TerminalParams::outfile)
        .def_readwrite("port", &TerminalParams::port)
        ;

    py::class_<gem5::Terminal, gem5::SerialDevice, std::unique_ptr<gem5::Terminal, py::nodelete>>(m, "gem5_COLONS_Terminal")
        ;

}

static EmbeddedPyBind embed_obj("Terminal", module_init, "SerialDevice");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTerminalParamsClass
{
  public:
    gem5::Terminal *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTerminalShunt;

template <class CxxClass>
class DummyTerminalShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TerminalParams &>::value>>
{
  public:
    using Params = TerminalParams;
    static gem5::Terminal *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTerminalShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TerminalParams &>::value>>
{
  public:
    using Params = DummyTerminalParamsClass;
    static gem5::Terminal *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::Terminal *
DummyTerminalShunt<gem5::Terminal>::Params::create() const
{
    return DummyTerminalShunt<gem5::Terminal>::
        create(*this);
}

} // namespace gem5
