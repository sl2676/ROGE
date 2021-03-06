/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TimingExprSrcReg.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/timing_expr.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TimingExprSrcReg");
    py::class_<TimingExprSrcRegParams, TimingExprParams, std::unique_ptr<TimingExprSrcRegParams, py::nodelete>>(m, "TimingExprSrcRegParams")
        .def(py::init<>())
        .def("create", &TimingExprSrcRegParams::create)
        .def_readwrite("index", &TimingExprSrcRegParams::index)
        ;

    py::class_<gem5::TimingExprSrcReg, gem5::TimingExpr, std::unique_ptr<gem5::TimingExprSrcReg, py::nodelete>>(m, "gem5_COLONS_TimingExprSrcReg")
        ;

}

static EmbeddedPyBind embed_obj("TimingExprSrcReg", module_init, "TimingExpr");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTimingExprSrcRegParamsClass
{
  public:
    gem5::TimingExprSrcReg *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTimingExprSrcRegShunt;

template <class CxxClass>
class DummyTimingExprSrcRegShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TimingExprSrcRegParams &>::value>>
{
  public:
    using Params = TimingExprSrcRegParams;
    static gem5::TimingExprSrcReg *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTimingExprSrcRegShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TimingExprSrcRegParams &>::value>>
{
  public:
    using Params = DummyTimingExprSrcRegParamsClass;
    static gem5::TimingExprSrcReg *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::TimingExprSrcReg *
DummyTimingExprSrcRegShunt<gem5::TimingExprSrcReg>::Params::create() const
{
    return DummyTimingExprSrcRegShunt<gem5::TimingExprSrcReg>::
        create(*this);
}

} // namespace gem5
