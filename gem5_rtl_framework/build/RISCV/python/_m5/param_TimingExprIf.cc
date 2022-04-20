/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TimingExprIf.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "cpu/timing_expr.hh"
#include "cpu/timing_expr.hh"
#include "cpu/timing_expr.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TimingExprIf");
    py::class_<TimingExprIfParams, TimingExprParams, std::unique_ptr<TimingExprIfParams, py::nodelete>>(m, "TimingExprIfParams")
        .def(py::init<>())
        .def("create", &TimingExprIfParams::create)
        .def_readwrite("cond", &TimingExprIfParams::cond)
        .def_readwrite("falseExpr", &TimingExprIfParams::falseExpr)
        .def_readwrite("trueExpr", &TimingExprIfParams::trueExpr)
        ;

    py::class_<gem5::TimingExprIf, gem5::TimingExpr, std::unique_ptr<gem5::TimingExprIf, py::nodelete>>(m, "gem5_COLONS_TimingExprIf")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprIf", module_init, "TimingExpr");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTimingExprIfParamsClass
{
  public:
    gem5::TimingExprIf *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTimingExprIfShunt;

template <class CxxClass>
class DummyTimingExprIfShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TimingExprIfParams &>::value>>
{
  public:
    using Params = TimingExprIfParams;
    static gem5::TimingExprIf *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTimingExprIfShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TimingExprIfParams &>::value>>
{
  public:
    using Params = DummyTimingExprIfParamsClass;
    static gem5::TimingExprIf *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::TimingExprIf *
DummyTimingExprIfShunt<gem5::TimingExprIf>::Params::create() const
{
    return DummyTimingExprIfShunt<gem5::TimingExprIf>::
        create(*this);
}

} // namespace gem5
