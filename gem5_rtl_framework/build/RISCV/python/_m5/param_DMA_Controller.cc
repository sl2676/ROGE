/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/DMA_Controller.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/protocol/DMA_Controller.hh"

#include "mem/ruby/system/DMASequencer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "mem/ruby/network/MessageBuffer.hh"
#include "base/types.hh"
#include "mem/ruby/network/MessageBuffer.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_DMA_Controller");
    py::class_<DMA_ControllerParams, RubyControllerParams, std::unique_ptr<DMA_ControllerParams, py::nodelete>>(m, "DMA_ControllerParams")
        .def(py::init<>())
        .def("create", &DMA_ControllerParams::create)
        .def_readwrite("dma_sequencer", &DMA_ControllerParams::dma_sequencer)
        .def_readwrite("mandatoryQueue", &DMA_ControllerParams::mandatoryQueue)
        .def_readwrite("requestToDir", &DMA_ControllerParams::requestToDir)
        .def_readwrite("request_latency", &DMA_ControllerParams::request_latency)
        .def_readwrite("responseFromDir", &DMA_ControllerParams::responseFromDir)
        ;

    py::class_<gem5::ruby::DMA_Controller, gem5::ruby::AbstractController, std::unique_ptr<gem5::ruby::DMA_Controller, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_DMA_Controller")
        ;

}

static EmbeddedPyBind embed_obj("DMA_Controller", module_init, "RubyController");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyDMA_ControllerParamsClass
{
  public:
    gem5::ruby::DMA_Controller *create() const;
};

template <class CxxClass, class Enable=void>
class DummyDMA_ControllerShunt;

template <class CxxClass>
class DummyDMA_ControllerShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const DMA_ControllerParams &>::value>>
{
  public:
    using Params = DMA_ControllerParams;
    static gem5::ruby::DMA_Controller *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyDMA_ControllerShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const DMA_ControllerParams &>::value>>
{
  public:
    using Params = DummyDMA_ControllerParamsClass;
    static gem5::ruby::DMA_Controller *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::DMA_Controller *
DummyDMA_ControllerShunt<gem5::ruby::DMA_Controller>::Params::create() const
{
    return DummyDMA_ControllerShunt<gem5::ruby::DMA_Controller>::
        create(*this);
}

} // namespace gem5
