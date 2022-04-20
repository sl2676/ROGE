/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TimingExprLet.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include <vector>
#include "cpu/timing_expr.hh"
#include "cpu/timing_expr.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TimingExprLet");
    py::class_<TimingExprLetParams, TimingExprParams, std::unique_ptr<TimingExprLetParams, py::nodelete>>(m, "TimingExprLetParams")
        .def(py::init<>())
        .def("create", &TimingExprLetParams::create)
        .def_readwrite("defns", &TimingExprLetParams::defns)
        .def_readwrite("expr", &TimingExprLetParams::expr)
        ;

    py::class_<gem5::TimingExprLet, gem5::TimingExpr, std::unique_ptr<gem5::TimingExprLet, py::nodelete>>(m, "gem5_COLONS_TimingExprLet")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprLet", module_init, "TimingExpr");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTimingExprLetParamsClass
{
  public:
    gem5::TimingExprLet *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTimingExprLetShunt;

template <class CxxClass>
class DummyTimingExprLetShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TimingExprLetParams &>::value>>
{
  public:
    using Params = TimingExprLetParams;
    static gem5::TimingExprLet *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTimingExprLetShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TimingExprLetParams &>::value>>
{
  public:
    using Params = DummyTimingExprLetParamsClass;
    static gem5::TimingExprLet *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::TimingExprLet *
DummyTimingExprLetShunt<gem5::TimingExprLet>::Params::create() const
{
    return DummyTimingExprLetShunt<gem5::TimingExprLet>::
        create(*this);
}

} // namespace gem5