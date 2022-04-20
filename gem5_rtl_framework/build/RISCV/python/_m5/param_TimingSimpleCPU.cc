/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TimingSimpleCPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/simple/timing.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TimingSimpleCPU");
    py::class_<TimingSimpleCPUParams, BaseSimpleCPUParams, std::unique_ptr<TimingSimpleCPUParams, py::nodelete>>(m, "TimingSimpleCPUParams")
        .def(py::init<>())
        .def("create", &TimingSimpleCPUParams::create)
        ;

    py::class_<gem5::TimingSimpleCPU, gem5::BaseSimpleCPU, std::unique_ptr<gem5::TimingSimpleCPU, py::nodelete>>(m, "gem5_COLONS_TimingSimpleCPU")
        ;

}

static EmbeddedPyBind embed_obj("TimingSimpleCPU", module_init, "BaseSimpleCPU");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTimingSimpleCPUParamsClass
{
  public:
    gem5::TimingSimpleCPU *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTimingSimpleCPUShunt;

template <class CxxClass>
class DummyTimingSimpleCPUShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TimingSimpleCPUParams &>::value>>
{
  public:
    using Params = TimingSimpleCPUParams;
    static gem5::TimingSimpleCPU *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTimingSimpleCPUShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TimingSimpleCPUParams &>::value>>
{
  public:
    using Params = DummyTimingSimpleCPUParamsClass;
    static gem5::TimingSimpleCPU *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::TimingSimpleCPU *
DummyTimingSimpleCPUShunt<gem5::TimingSimpleCPU>::Params::create() const
{
    return DummyTimingSimpleCPUShunt<gem5::TimingSimpleCPU>::
        create(*this);
}

} // namespace gem5
