/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TimingExprBin.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
#include "enums/TimingExprOp.hh"
#include "cpu/timing_expr.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TimingExprBin");
    py::class_<TimingExprBinParams, TimingExprParams, std::unique_ptr<TimingExprBinParams, py::nodelete>>(m, "TimingExprBinParams")
        .def(py::init<>())
        .def("create", &TimingExprBinParams::create)
        .def_readwrite("left", &TimingExprBinParams::left)
        .def_readwrite("op", &TimingExprBinParams::op)
        .def_readwrite("right", &TimingExprBinParams::right)
        ;

    py::class_<gem5::TimingExprBin, gem5::TimingExpr, std::unique_ptr<gem5::TimingExprBin, py::nodelete>>(m, "gem5_COLONS_TimingExprBin")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprBin", module_init, "TimingExpr");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTimingExprBinParamsClass
{
  public:
    gem5::TimingExprBin *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTimingExprBinShunt;

template <class CxxClass>
class DummyTimingExprBinShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TimingExprBinParams &>::value>>
{
  public:
    using Params = TimingExprBinParams;
    static gem5::TimingExprBin *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTimingExprBinShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TimingExprBinParams &>::value>>
{
  public:
    using Params = DummyTimingExprBinParamsClass;
    static gem5::TimingExprBin *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::TimingExprBin *
DummyTimingExprBinShunt<gem5::TimingExprBin>::Params::create() const
{
    return DummyTimingExprBinShunt<gem5::TimingExprBin>::
        create(*this);
}

} // namespace gem5
