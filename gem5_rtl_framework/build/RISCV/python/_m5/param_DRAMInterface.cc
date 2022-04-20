/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/DRAMInterface.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/mem_interface.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "enums/PageManage.hh"
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
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_DRAMInterface");
    py::class_<DRAMInterfaceParams, MemInterfaceParams, std::unique_ptr<DRAMInterfaceParams, py::nodelete>>(m, "DRAMInterfaceParams")
        .def(py::init<>())
        .def("create", &DRAMInterfaceParams::create)
        .def_readwrite("IDD0", &DRAMInterfaceParams::IDD0)
        .def_readwrite("IDD02", &DRAMInterfaceParams::IDD02)
        .def_readwrite("IDD2N", &DRAMInterfaceParams::IDD2N)
        .def_readwrite("IDD2N2", &DRAMInterfaceParams::IDD2N2)
        .def_readwrite("IDD2P0", &DRAMInterfaceParams::IDD2P0)
        .def_readwrite("IDD2P02", &DRAMInterfaceParams::IDD2P02)
        .def_readwrite("IDD2P1", &DRAMInterfaceParams::IDD2P1)
        .def_readwrite("IDD2P12", &DRAMInterfaceParams::IDD2P12)
        .def_readwrite("IDD3N", &DRAMInterfaceParams::IDD3N)
        .def_readwrite("IDD3N2", &DRAMInterfaceParams::IDD3N2)
        .def_readwrite("IDD3P0", &DRAMInterfaceParams::IDD3P0)
        .def_readwrite("IDD3P02", &DRAMInterfaceParams::IDD3P02)
        .def_readwrite("IDD3P1", &DRAMInterfaceParams::IDD3P1)
        .def_readwrite("IDD3P12", &DRAMInterfaceParams::IDD3P12)
        .def_readwrite("IDD4R", &DRAMInterfaceParams::IDD4R)
        .def_readwrite("IDD4R2", &DRAMInterfaceParams::IDD4R2)
        .def_readwrite("IDD4W", &DRAMInterfaceParams::IDD4W)
        .def_readwrite("IDD4W2", &DRAMInterfaceParams::IDD4W2)
        .def_readwrite("IDD5", &DRAMInterfaceParams::IDD5)
        .def_readwrite("IDD52", &DRAMInterfaceParams::IDD52)
        .def_readwrite("IDD6", &DRAMInterfaceParams::IDD6)
        .def_readwrite("IDD62", &DRAMInterfaceParams::IDD62)
        .def_readwrite("VDD", &DRAMInterfaceParams::VDD)
        .def_readwrite("VDD2", &DRAMInterfaceParams::VDD2)
        .def_readwrite("activation_limit", &DRAMInterfaceParams::activation_limit)
        .def_readwrite("bank_groups_per_rank", &DRAMInterfaceParams::bank_groups_per_rank)
        .def_readwrite("beats_per_clock", &DRAMInterfaceParams::beats_per_clock)
        .def_readwrite("data_clock_sync", &DRAMInterfaceParams::data_clock_sync)
        .def_readwrite("dll", &DRAMInterfaceParams::dll)
        .def_readwrite("enable_dram_powerdown", &DRAMInterfaceParams::enable_dram_powerdown)
        .def_readwrite("max_accesses_per_row", &DRAMInterfaceParams::max_accesses_per_row)
        .def_readwrite("page_policy", &DRAMInterfaceParams::page_policy)
        .def_readwrite("tAAD", &DRAMInterfaceParams::tAAD)
        .def_readwrite("tBURST_MAX", &DRAMInterfaceParams::tBURST_MAX)
        .def_readwrite("tBURST_MIN", &DRAMInterfaceParams::tBURST_MIN)
        .def_readwrite("tCCD_L", &DRAMInterfaceParams::tCCD_L)
        .def_readwrite("tCCD_L_WR", &DRAMInterfaceParams::tCCD_L_WR)
        .def_readwrite("tCL", &DRAMInterfaceParams::tCL)
        .def_readwrite("tPPD", &DRAMInterfaceParams::tPPD)
        .def_readwrite("tRAS", &DRAMInterfaceParams::tRAS)
        .def_readwrite("tRCD", &DRAMInterfaceParams::tRCD)
        .def_readwrite("tREFI", &DRAMInterfaceParams::tREFI)
        .def_readwrite("tRFC", &DRAMInterfaceParams::tRFC)
        .def_readwrite("tRP", &DRAMInterfaceParams::tRP)
        .def_readwrite("tRRD", &DRAMInterfaceParams::tRRD)
        .def_readwrite("tRRD_L", &DRAMInterfaceParams::tRRD_L)
        .def_readwrite("tRTP", &DRAMInterfaceParams::tRTP)
        .def_readwrite("tWR", &DRAMInterfaceParams::tWR)
        .def_readwrite("tWTR_L", &DRAMInterfaceParams::tWTR_L)
        .def_readwrite("tXAW", &DRAMInterfaceParams::tXAW)
        .def_readwrite("tXP", &DRAMInterfaceParams::tXP)
        .def_readwrite("tXPDLL", &DRAMInterfaceParams::tXPDLL)
        .def_readwrite("tXS", &DRAMInterfaceParams::tXS)
        .def_readwrite("tXSDLL", &DRAMInterfaceParams::tXSDLL)
        .def_readwrite("two_cycle_activate", &DRAMInterfaceParams::two_cycle_activate)
        ;

    py::class_<gem5::memory::DRAMInterface, gem5::memory::MemInterface, std::unique_ptr<gem5::memory::DRAMInterface, py::nodelete>>(m, "gem5_COLONS_memory_COLONS_DRAMInterface")
        ;

}

static EmbeddedPyBind embed_obj("DRAMInterface", module_init, "MemInterface");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyDRAMInterfaceParamsClass
{
  public:
    gem5::memory::DRAMInterface *create() const;
};

template <class CxxClass, class Enable=void>
class DummyDRAMInterfaceShunt;

template <class CxxClass>
class DummyDRAMInterfaceShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const DRAMInterfaceParams &>::value>>
{
  public:
    using Params = DRAMInterfaceParams;
    static gem5::memory::DRAMInterface *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyDRAMInterfaceShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const DRAMInterfaceParams &>::value>>
{
  public:
    using Params = DummyDRAMInterfaceParamsClass;
    static gem5::memory::DRAMInterface *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::memory::DRAMInterface *
DummyDRAMInterfaceShunt<gem5::memory::DRAMInterface>::Params::create() const
{
    return DummyDRAMInterfaceShunt<gem5::memory::DRAMInterface>::
        create(*this);
}

} // namespace gem5