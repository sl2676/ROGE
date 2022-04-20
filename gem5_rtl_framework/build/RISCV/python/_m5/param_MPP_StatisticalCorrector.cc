/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MPP_StatisticalCorrector.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/multiperspective_perceptron_tage.hh"

#include <vector>
#include "base/types.hh"
#include "base/types.hh"
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
    py::module_ m = m_internal.def_submodule("param_MPP_StatisticalCorrector");
    py::class_<MPP_StatisticalCorrectorParams, StatisticalCorrectorParams, std::unique_ptr<MPP_StatisticalCorrectorParams, py::nodelete>>(m, "MPP_StatisticalCorrectorParams")
        .def_readwrite("gm", &MPP_StatisticalCorrectorParams::gm)
        .def_readwrite("gnb", &MPP_StatisticalCorrectorParams::gnb)
        .def_readwrite("logGnb", &MPP_StatisticalCorrectorParams::logGnb)
        .def_readwrite("logPnb", &MPP_StatisticalCorrectorParams::logPnb)
        .def_readwrite("pm", &MPP_StatisticalCorrectorParams::pm)
        .def_readwrite("pnb", &MPP_StatisticalCorrectorParams::pnb)
        ;

    py::class_<gem5::branch_prediction::MPP_StatisticalCorrector, gem5::branch_prediction::StatisticalCorrector, std::unique_ptr<gem5::branch_prediction::MPP_StatisticalCorrector, py::nodelete>>(m, "gem5_COLONS_branch_prediction_COLONS_MPP_StatisticalCorrector")
        ;

}

static EmbeddedPyBind embed_obj("MPP_StatisticalCorrector", module_init, "StatisticalCorrector");

} // namespace gem5