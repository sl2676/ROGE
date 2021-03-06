/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Directory_Controller.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/protocol/Directory_Controller.hh"

#include "mem/ruby/structures/DirectoryMemory.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Directory_Controller");
    py::class_<Directory_ControllerParams, RubyControllerParams, std::unique_ptr<Directory_ControllerParams, py::nodelete>>(m, "Directory_ControllerParams")
        .def(py::init<>())
        .def("create", &Directory_ControllerParams::create)
        .def_readwrite("directory", &Directory_ControllerParams::directory)
        .def_readwrite("directory_latency", &Directory_ControllerParams::directory_latency)
        .def_readwrite("dmaRequestToDir", &Directory_ControllerParams::dmaRequestToDir)
        .def_readwrite("dmaResponseFromDir", &Directory_ControllerParams::dmaResponseFromDir)
        .def_readwrite("forwardFromDir", &Directory_ControllerParams::forwardFromDir)
        .def_readwrite("requestToDir", &Directory_ControllerParams::requestToDir)
        .def_readwrite("requestToMemory", &Directory_ControllerParams::requestToMemory)
        .def_readwrite("responseFromDir", &Directory_ControllerParams::responseFromDir)
        .def_readwrite("responseFromMemory", &Directory_ControllerParams::responseFromMemory)
        .def_readwrite("to_memory_controller_latency", &Directory_ControllerParams::to_memory_controller_latency)
        ;

    py::class_<gem5::ruby::Directory_Controller, gem5::ruby::AbstractController, std::unique_ptr<gem5::ruby::Directory_Controller, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_Directory_Controller")
        ;

}

static EmbeddedPyBind embed_obj("Directory_Controller", module_init, "RubyController");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyDirectory_ControllerParamsClass
{
  public:
    gem5::ruby::Directory_Controller *create() const;
};

template <class CxxClass, class Enable=void>
class DummyDirectory_ControllerShunt;

template <class CxxClass>
class DummyDirectory_ControllerShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const Directory_ControllerParams &>::value>>
{
  public:
    using Params = Directory_ControllerParams;
    static gem5::ruby::Directory_Controller *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyDirectory_ControllerShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const Directory_ControllerParams &>::value>>
{
  public:
    using Params = DummyDirectory_ControllerParamsClass;
    static gem5::ruby::Directory_Controller *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::Directory_Controller *
DummyDirectory_ControllerShunt<gem5::ruby::Directory_Controller>::Params::create() const
{
    return DummyDirectory_ControllerShunt<gem5::ruby::Directory_Controller>::
        create(*this);
}

} // namespace gem5
