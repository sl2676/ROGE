/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/L1Cache_Controller.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/protocol/L1Cache_Controller.hh"

#include "mem/ruby/structures/CacheMemory.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/system/Sequencer.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_L1Cache_Controller");
    py::class_<L1Cache_ControllerParams, RubyControllerParams, std::unique_ptr<L1Cache_ControllerParams, py::nodelete>>(m, "L1Cache_ControllerParams")
        .def(py::init<>())
        .def("create", &L1Cache_ControllerParams::create)
        .def_readwrite("cacheMemory", &L1Cache_ControllerParams::cacheMemory)
        .def_readwrite("cache_response_latency", &L1Cache_ControllerParams::cache_response_latency)
        .def_readwrite("forwardToCache", &L1Cache_ControllerParams::forwardToCache)
        .def_readwrite("issue_latency", &L1Cache_ControllerParams::issue_latency)
        .def_readwrite("mandatoryQueue", &L1Cache_ControllerParams::mandatoryQueue)
        .def_readwrite("requestFromCache", &L1Cache_ControllerParams::requestFromCache)
        .def_readwrite("responseFromCache", &L1Cache_ControllerParams::responseFromCache)
        .def_readwrite("responseToCache", &L1Cache_ControllerParams::responseToCache)
        .def_readwrite("send_evictions", &L1Cache_ControllerParams::send_evictions)
        .def_readwrite("sequencer", &L1Cache_ControllerParams::sequencer)
        ;

    py::class_<gem5::ruby::L1Cache_Controller, gem5::ruby::AbstractController, std::unique_ptr<gem5::ruby::L1Cache_Controller, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_L1Cache_Controller")
        ;

}

static EmbeddedPyBind embed_obj("L1Cache_Controller", module_init, "RubyController");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyL1Cache_ControllerParamsClass
{
  public:
    gem5::ruby::L1Cache_Controller *create() const;
};

template <class CxxClass, class Enable=void>
class DummyL1Cache_ControllerShunt;

template <class CxxClass>
class DummyL1Cache_ControllerShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const L1Cache_ControllerParams &>::value>>
{
  public:
    using Params = L1Cache_ControllerParams;
    static gem5::ruby::L1Cache_Controller *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyL1Cache_ControllerShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const L1Cache_ControllerParams &>::value>>
{
  public:
    using Params = DummyL1Cache_ControllerParamsClass;
    static gem5::ruby::L1Cache_Controller *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::L1Cache_Controller *
DummyL1Cache_ControllerShunt<gem5::ruby::L1Cache_Controller>::Params::create() const
{
    return DummyL1Cache_ControllerShunt<gem5::ruby::L1Cache_Controller>::
        create(*this);
}

} // namespace gem5
