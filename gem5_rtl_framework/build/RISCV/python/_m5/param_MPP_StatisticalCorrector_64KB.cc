/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MPP_StatisticalCorrector_64KB.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/multiperspective_perceptron_tage_64KB.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MPP_StatisticalCorrector_64KB");
    py::class_<MPP_StatisticalCorrector_64KBParams, MPP_StatisticalCorrectorParams, std::unique_ptr<MPP_StatisticalCorrector_64KBParams, py::nodelete>>(m, "MPP_StatisticalCorrector_64KBParams")
        .def(py::init<>())
        .def("create", &MPP_StatisticalCorrector_64KBParams::create)
        .def_readwrite("logSnb", &MPP_StatisticalCorrector_64KBParams::logSnb)
        .def_readwrite("logTnb", &MPP_StatisticalCorrector_64KBParams::logTnb)
        .def_readwrite("numEntriesSecondLocalHistories", &MPP_StatisticalCorrector_64KBParams::numEntriesSecondLocalHistories)
        .def_readwrite("numEntriesThirdLocalHistories", &MPP_StatisticalCorrector_64KBParams::numEntriesThirdLocalHistories)
        .def_readwrite("sm", &MPP_StatisticalCorrector_64KBParams::sm)
        .def_readwrite("snb", &MPP_StatisticalCorrector_64KBParams::snb)
        .def_readwrite("tm", &MPP_StatisticalCorrector_64KBParams::tm)
        .def_readwrite("tnb", &MPP_StatisticalCorrector_64KBParams::tnb)
        ;

    py::class_<gem5::branch_prediction::MPP_StatisticalCorrector_64KB, gem5::branch_prediction::MPP_StatisticalCorrector, std::unique_ptr<gem5::branch_prediction::MPP_StatisticalCorrector_64KB, py::nodelete>>(m, "gem5_COLONS_branch_prediction_COLONS_MPP_StatisticalCorrector_64KB")
        ;

}

static EmbeddedPyBind embed_obj("MPP_StatisticalCorrector_64KB", module_init, "MPP_StatisticalCorrector");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMPP_StatisticalCorrector_64KBParamsClass
{
  public:
    gem5::branch_prediction::MPP_StatisticalCorrector_64KB *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMPP_StatisticalCorrector_64KBShunt;

template <class CxxClass>
class DummyMPP_StatisticalCorrector_64KBShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MPP_StatisticalCorrector_64KBParams &>::value>>
{
  public:
    using Params = MPP_StatisticalCorrector_64KBParams;
    static gem5::branch_prediction::MPP_StatisticalCorrector_64KB *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMPP_StatisticalCorrector_64KBShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MPP_StatisticalCorrector_64KBParams &>::value>>
{
  public:
    using Params = DummyMPP_StatisticalCorrector_64KBParamsClass;
    static gem5::branch_prediction::MPP_StatisticalCorrector_64KB *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::branch_prediction::MPP_StatisticalCorrector_64KB *
DummyMPP_StatisticalCorrector_64KBShunt<gem5::branch_prediction::MPP_StatisticalCorrector_64KB>::Params::create() const
{
    return DummyMPP_StatisticalCorrector_64KBShunt<gem5::branch_prediction::MPP_StatisticalCorrector_64KB>::
        create(*this);
}

} // namespace gem5
