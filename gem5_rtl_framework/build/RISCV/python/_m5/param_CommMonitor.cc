/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/CommMonitor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/comm_monitor.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "sim/system.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_CommMonitor");
    py::class_<CommMonitorParams, SimObjectParams, std::unique_ptr<CommMonitorParams, py::nodelete>>(m, "CommMonitorParams")
        .def(py::init<>())
        .def("create", &CommMonitorParams::create)
        .def_readwrite("bandwidth_bins", &CommMonitorParams::bandwidth_bins)
        .def_readwrite("burst_length_bins", &CommMonitorParams::burst_length_bins)
        .def_readwrite("disable_addr_dists", &CommMonitorParams::disable_addr_dists)
        .def_readwrite("disable_bandwidth_hists", &CommMonitorParams::disable_bandwidth_hists)
        .def_readwrite("disable_burst_length_hists", &CommMonitorParams::disable_burst_length_hists)
        .def_readwrite("disable_itt_dists", &CommMonitorParams::disable_itt_dists)
        .def_readwrite("disable_latency_hists", &CommMonitorParams::disable_latency_hists)
        .def_readwrite("disable_outstanding_hists", &CommMonitorParams::disable_outstanding_hists)
        .def_readwrite("disable_transaction_hists", &CommMonitorParams::disable_transaction_hists)
        .def_readwrite("itt_bins", &CommMonitorParams::itt_bins)
        .def_readwrite("itt_max_bin", &CommMonitorParams::itt_max_bin)
        .def_readwrite("latency_bins", &CommMonitorParams::latency_bins)
        .def_readwrite("outstanding_bins", &CommMonitorParams::outstanding_bins)
        .def_readwrite("read_addr_mask", &CommMonitorParams::read_addr_mask)
        .def_readwrite("sample_period", &CommMonitorParams::sample_period)
        .def_readwrite("system", &CommMonitorParams::system)
        .def_readwrite("transaction_bins", &CommMonitorParams::transaction_bins)
        .def_readwrite("write_addr_mask", &CommMonitorParams::write_addr_mask)
        .def_readwrite("port_mem_side_port_connection_count", &CommMonitorParams::port_mem_side_port_connection_count)
        .def_readwrite("port_cpu_side_port_connection_count", &CommMonitorParams::port_cpu_side_port_connection_count)
        ;

    py::class_<gem5::CommMonitor, gem5::SimObject, std::unique_ptr<gem5::CommMonitor, py::nodelete>>(m, "gem5_COLONS_CommMonitor")
        ;

}

static EmbeddedPyBind embed_obj("CommMonitor", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyCommMonitorParamsClass
{
  public:
    gem5::CommMonitor *create() const;
};

template <class CxxClass, class Enable=void>
class DummyCommMonitorShunt;

template <class CxxClass>
class DummyCommMonitorShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const CommMonitorParams &>::value>>
{
  public:
    using Params = CommMonitorParams;
    static gem5::CommMonitor *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyCommMonitorShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const CommMonitorParams &>::value>>
{
  public:
    using Params = DummyCommMonitorParamsClass;
    static gem5::CommMonitor *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::CommMonitor *
DummyCommMonitorShunt<gem5::CommMonitor>::Params::create() const
{
    return DummyCommMonitorShunt<gem5::CommMonitor>::
        create(*this);
}

} // namespace gem5
