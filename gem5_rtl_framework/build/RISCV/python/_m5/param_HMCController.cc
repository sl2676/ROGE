/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/HMCController.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/hmc_controller.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_HMCController");
    py::class_<HMCControllerParams, NoncoherentXBarParams, std::unique_ptr<HMCControllerParams, py::nodelete>>(m, "HMCControllerParams")
        .def(py::init<>())
        .def("create", &HMCControllerParams::create)
        ;

    py::class_<gem5::HMCController, gem5::NoncoherentXBar, std::unique_ptr<gem5::HMCController, py::nodelete>>(m, "gem5_COLONS_HMCController")
        ;

}

static EmbeddedPyBind embed_obj("HMCController", module_init, "NoncoherentXBar");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyHMCControllerParamsClass
{
  public:
    gem5::HMCController *create() const;
};

template <class CxxClass, class Enable=void>
class DummyHMCControllerShunt;

template <class CxxClass>
class DummyHMCControllerShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const HMCControllerParams &>::value>>
{
  public:
    using Params = HMCControllerParams;
    static gem5::HMCController *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyHMCControllerShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const HMCControllerParams &>::value>>
{
  public:
    using Params = DummyHMCControllerParamsClass;
    static gem5::HMCController *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::HMCController *
DummyHMCControllerShunt<gem5::HMCController>::Params::create() const
{
    return DummyHMCControllerShunt<gem5::HMCController>::
        create(*this);
}

} // namespace gem5
