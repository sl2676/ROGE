/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/O3CPU.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/o3/dyn_inst.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "cpu/pred/bpred_unit.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "cpu/o3/fu_pool.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "enums/CommitPolicy.hh"
#include "enums/SMTFetchPolicy.hh"
#include "enums/SMTQueuePolicy.hh"
#include "base/types.hh"
#include "enums/SMTQueuePolicy.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "enums/SMTQueuePolicy.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_O3CPU");
    py::class_<O3CPUParams, BaseCPUParams, std::unique_ptr<O3CPUParams, py::nodelete>>(m, "O3CPUParams")
        .def(py::init<>())
        .def("create", &O3CPUParams::create)
        .def_readwrite("LFSTSize", &O3CPUParams::LFSTSize)
        .def_readwrite("LQEntries", &O3CPUParams::LQEntries)
        .def_readwrite("LSQCheckLoads", &O3CPUParams::LSQCheckLoads)
        .def_readwrite("LSQDepCheckShift", &O3CPUParams::LSQDepCheckShift)
        .def_readwrite("SQEntries", &O3CPUParams::SQEntries)
        .def_readwrite("SSITSize", &O3CPUParams::SSITSize)
        .def_readwrite("activity", &O3CPUParams::activity)
        .def_readwrite("backComSize", &O3CPUParams::backComSize)
        .def_readwrite("branchPred", &O3CPUParams::branchPred)
        .def_readwrite("cacheLoadPorts", &O3CPUParams::cacheLoadPorts)
        .def_readwrite("cacheStorePorts", &O3CPUParams::cacheStorePorts)
        .def_readwrite("commitToDecodeDelay", &O3CPUParams::commitToDecodeDelay)
        .def_readwrite("commitToFetchDelay", &O3CPUParams::commitToFetchDelay)
        .def_readwrite("commitToIEWDelay", &O3CPUParams::commitToIEWDelay)
        .def_readwrite("commitToRenameDelay", &O3CPUParams::commitToRenameDelay)
        .def_readwrite("commitWidth", &O3CPUParams::commitWidth)
        .def_readwrite("decodeToFetchDelay", &O3CPUParams::decodeToFetchDelay)
        .def_readwrite("decodeToRenameDelay", &O3CPUParams::decodeToRenameDelay)
        .def_readwrite("decodeWidth", &O3CPUParams::decodeWidth)
        .def_readwrite("dispatchWidth", &O3CPUParams::dispatchWidth)
        .def_readwrite("fetchBufferSize", &O3CPUParams::fetchBufferSize)
        .def_readwrite("fetchQueueSize", &O3CPUParams::fetchQueueSize)
        .def_readwrite("fetchToDecodeDelay", &O3CPUParams::fetchToDecodeDelay)
        .def_readwrite("fetchTrapLatency", &O3CPUParams::fetchTrapLatency)
        .def_readwrite("fetchWidth", &O3CPUParams::fetchWidth)
        .def_readwrite("forwardComSize", &O3CPUParams::forwardComSize)
        .def_readwrite("fuPool", &O3CPUParams::fuPool)
        .def_readwrite("iewToCommitDelay", &O3CPUParams::iewToCommitDelay)
        .def_readwrite("iewToDecodeDelay", &O3CPUParams::iewToDecodeDelay)
        .def_readwrite("iewToFetchDelay", &O3CPUParams::iewToFetchDelay)
        .def_readwrite("iewToRenameDelay", &O3CPUParams::iewToRenameDelay)
        .def_readwrite("issueToExecuteDelay", &O3CPUParams::issueToExecuteDelay)
        .def_readwrite("issueWidth", &O3CPUParams::issueWidth)
        .def_readwrite("needsTSO", &O3CPUParams::needsTSO)
        .def_readwrite("numIQEntries", &O3CPUParams::numIQEntries)
        .def_readwrite("numPhysCCRegs", &O3CPUParams::numPhysCCRegs)
        .def_readwrite("numPhysFloatRegs", &O3CPUParams::numPhysFloatRegs)
        .def_readwrite("numPhysIntRegs", &O3CPUParams::numPhysIntRegs)
        .def_readwrite("numPhysVecPredRegs", &O3CPUParams::numPhysVecPredRegs)
        .def_readwrite("numPhysVecRegs", &O3CPUParams::numPhysVecRegs)
        .def_readwrite("numROBEntries", &O3CPUParams::numROBEntries)
        .def_readwrite("numRobs", &O3CPUParams::numRobs)
        .def_readwrite("renameToDecodeDelay", &O3CPUParams::renameToDecodeDelay)
        .def_readwrite("renameToFetchDelay", &O3CPUParams::renameToFetchDelay)
        .def_readwrite("renameToIEWDelay", &O3CPUParams::renameToIEWDelay)
        .def_readwrite("renameToROBDelay", &O3CPUParams::renameToROBDelay)
        .def_readwrite("renameWidth", &O3CPUParams::renameWidth)
        .def_readwrite("smtCommitPolicy", &O3CPUParams::smtCommitPolicy)
        .def_readwrite("smtFetchPolicy", &O3CPUParams::smtFetchPolicy)
        .def_readwrite("smtIQPolicy", &O3CPUParams::smtIQPolicy)
        .def_readwrite("smtIQThreshold", &O3CPUParams::smtIQThreshold)
        .def_readwrite("smtLSQPolicy", &O3CPUParams::smtLSQPolicy)
        .def_readwrite("smtLSQThreshold", &O3CPUParams::smtLSQThreshold)
        .def_readwrite("smtNumFetchingThreads", &O3CPUParams::smtNumFetchingThreads)
        .def_readwrite("smtROBPolicy", &O3CPUParams::smtROBPolicy)
        .def_readwrite("smtROBThreshold", &O3CPUParams::smtROBThreshold)
        .def_readwrite("squashWidth", &O3CPUParams::squashWidth)
        .def_readwrite("store_set_clear_period", &O3CPUParams::store_set_clear_period)
        .def_readwrite("trapLatency", &O3CPUParams::trapLatency)
        .def_readwrite("wbWidth", &O3CPUParams::wbWidth)
        ;

    py::class_<gem5::o3::CPU, gem5::BaseCPU, std::unique_ptr<gem5::o3::CPU, py::nodelete>>(m, "gem5_COLONS_o3_COLONS_CPU")
        ;

}

static EmbeddedPyBind embed_obj("O3CPU", module_init, "BaseCPU");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyO3CPUParamsClass
{
  public:
    gem5::o3::CPU *create() const;
};

template <class CxxClass, class Enable=void>
class DummyO3CPUShunt;

template <class CxxClass>
class DummyO3CPUShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const O3CPUParams &>::value>>
{
  public:
    using Params = O3CPUParams;
    static gem5::o3::CPU *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyO3CPUShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const O3CPUParams &>::value>>
{
  public:
    using Params = DummyO3CPUParamsClass;
    static gem5::o3::CPU *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::o3::CPU *
DummyO3CPUShunt<gem5::o3::CPU>::Params::create() const
{
    return DummyO3CPUShunt<gem5::o3::CPU>::
        create(*this);
}

} // namespace gem5
