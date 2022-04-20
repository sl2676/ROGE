/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MPP_LoopPredictor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/multiperspective_perceptron_tage.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MPP_LoopPredictor");
    py::class_<MPP_LoopPredictorParams, LoopPredictorParams, std::unique_ptr<MPP_LoopPredictorParams, py::nodelete>>(m, "MPP_LoopPredictorParams")
        .def(py::init<>())
        .def("create", &MPP_LoopPredictorParams::create)
        ;

    py::class_<gem5::branch_prediction::MPP_LoopPredictor, gem5::branch_prediction::LoopPredictor, std::unique_ptr<gem5::branch_prediction::MPP_LoopPredictor, py::nodelete>>(m, "gem5_COLONS_branch_prediction_COLONS_MPP_LoopPredictor")
        ;

}

static EmbeddedPyBind embed_obj("MPP_LoopPredictor", module_init, "LoopPredictor");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMPP_LoopPredictorParamsClass
{
  public:
    gem5::branch_prediction::MPP_LoopPredictor *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMPP_LoopPredictorShunt;

template <class CxxClass>
class DummyMPP_LoopPredictorShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MPP_LoopPredictorParams &>::value>>
{
  public:
    using Params = MPP_LoopPredictorParams;
    static gem5::branch_prediction::MPP_LoopPredictor *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMPP_LoopPredictorShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MPP_LoopPredictorParams &>::value>>
{
  public:
    using Params = DummyMPP_LoopPredictorParamsClass;
    static gem5::branch_prediction::MPP_LoopPredictor *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::branch_prediction::MPP_LoopPredictor *
DummyMPP_LoopPredictorShunt<gem5::branch_prediction::MPP_LoopPredictor>::Params::create() const
{
    return DummyMPP_LoopPredictorShunt<gem5::branch_prediction::MPP_LoopPredictor>::
        create(*this);
}

} // namespace gem5
