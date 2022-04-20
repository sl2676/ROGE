/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TimingExprReadIntReg.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TimingExprReadIntReg");
    py::class_<TimingExprReadIntRegParams, TimingExprParams, std::unique_ptr<TimingExprReadIntRegParams, py::nodelete>>(m, "TimingExprReadIntRegParams")
        .def(py::init<>())
        .def("create", &TimingExprReadIntRegParams::create)
        .def_readwrite("reg", &TimingExprReadIntRegParams::reg)
        ;

    py::class_<gem5::TimingExprReadIntReg, gem5::TimingExpr, std::unique_ptr<gem5::TimingExprReadIntReg, py::nodelete>>(m, "gem5_COLONS_TimingExprReadIntReg")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprReadIntReg", module_init, "TimingExpr");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTimingExprReadIntRegParamsClass
{
  public:
    gem5::TimingExprReadIntReg *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTimingExprReadIntRegShunt;

template <class CxxClass>
class DummyTimingExprReadIntRegShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TimingExprReadIntRegParams &>::value>>
{
  public:
    using Params = TimingExprReadIntRegParams;
    static gem5::TimingExprReadIntReg *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTimingExprReadIntRegShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TimingExprReadIntRegParams &>::value>>
{
  public:
    using Params = DummyTimingExprReadIntRegParamsClass;
    static gem5::TimingExprReadIntReg *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::TimingExprReadIntReg *
DummyTimingExprReadIntRegShunt<gem5::TimingExprReadIntReg>::Params::create() const
{
    return DummyTimingExprReadIntRegShunt<gem5::TimingExprReadIntReg>::
        create(*this);
}

} // namespace gem5
