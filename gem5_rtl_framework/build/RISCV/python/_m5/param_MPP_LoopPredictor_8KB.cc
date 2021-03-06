/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MPP_LoopPredictor_8KB.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/multiperspective_perceptron_tage_8KB.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MPP_LoopPredictor_8KB");
    py::class_<MPP_LoopPredictor_8KBParams, MPP_LoopPredictorParams, std::unique_ptr<MPP_LoopPredictor_8KBParams, py::nodelete>>(m, "MPP_LoopPredictor_8KBParams")
        .def(py::init<>())
        .def("create", &MPP_LoopPredictor_8KBParams::create)
        ;

    py::class_<gem5::branch_prediction::MPP_LoopPredictor_8KB, gem5::branch_prediction::MPP_LoopPredictor, std::unique_ptr<gem5::branch_prediction::MPP_LoopPredictor_8KB, py::nodelete>>(m, "gem5_COLONS_branch_prediction_COLONS_MPP_LoopPredictor_8KB")
        ;

}

static EmbeddedPyBind embed_obj("MPP_LoopPredictor_8KB", module_init, "MPP_LoopPredictor");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMPP_LoopPredictor_8KBParamsClass
{
  public:
    gem5::branch_prediction::MPP_LoopPredictor_8KB *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMPP_LoopPredictor_8KBShunt;

template <class CxxClass>
class DummyMPP_LoopPredictor_8KBShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MPP_LoopPredictor_8KBParams &>::value>>
{
  public:
    using Params = MPP_LoopPredictor_8KBParams;
    static gem5::branch_prediction::MPP_LoopPredictor_8KB *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMPP_LoopPredictor_8KBShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MPP_LoopPredictor_8KBParams &>::value>>
{
  public:
    using Params = DummyMPP_LoopPredictor_8KBParamsClass;
    static gem5::branch_prediction::MPP_LoopPredictor_8KB *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::branch_prediction::MPP_LoopPredictor_8KB *
DummyMPP_LoopPredictor_8KBShunt<gem5::branch_prediction::MPP_LoopPredictor_8KB>::Params::create() const
{
    return DummyMPP_LoopPredictor_8KBShunt<gem5::branch_prediction::MPP_LoopPredictor_8KB>::
        create(*this);
}

} // namespace gem5
