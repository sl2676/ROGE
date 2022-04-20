/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TAGE_SC_L_TAGE_64KB.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/tage_sc_l_64KB.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TAGE_SC_L_TAGE_64KB");
    py::class_<TAGE_SC_L_TAGE_64KBParams, TAGE_SC_L_TAGEParams, std::unique_ptr<TAGE_SC_L_TAGE_64KBParams, py::nodelete>>(m, "TAGE_SC_L_TAGE_64KBParams")
        .def(py::init<>())
        .def("create", &TAGE_SC_L_TAGE_64KBParams::create)
        ;

    py::class_<gem5::branch_prediction::TAGE_SC_L_TAGE_64KB, gem5::branch_prediction::TAGE_SC_L_TAGE, std::unique_ptr<gem5::branch_prediction::TAGE_SC_L_TAGE_64KB, py::nodelete>>(m, "gem5_COLONS_branch_prediction_COLONS_TAGE_SC_L_TAGE_64KB")
        ;

}

static EmbeddedPyBind embed_obj("TAGE_SC_L_TAGE_64KB", module_init, "TAGE_SC_L_TAGE");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTAGE_SC_L_TAGE_64KBParamsClass
{
  public:
    gem5::branch_prediction::TAGE_SC_L_TAGE_64KB *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTAGE_SC_L_TAGE_64KBShunt;

template <class CxxClass>
class DummyTAGE_SC_L_TAGE_64KBShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TAGE_SC_L_TAGE_64KBParams &>::value>>
{
  public:
    using Params = TAGE_SC_L_TAGE_64KBParams;
    static gem5::branch_prediction::TAGE_SC_L_TAGE_64KB *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTAGE_SC_L_TAGE_64KBShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TAGE_SC_L_TAGE_64KBParams &>::value>>
{
  public:
    using Params = DummyTAGE_SC_L_TAGE_64KBParamsClass;
    static gem5::branch_prediction::TAGE_SC_L_TAGE_64KB *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::branch_prediction::TAGE_SC_L_TAGE_64KB *
DummyTAGE_SC_L_TAGE_64KBShunt<gem5::branch_prediction::TAGE_SC_L_TAGE_64KB>::Params::create() const
{
    return DummyTAGE_SC_L_TAGE_64KBShunt<gem5::branch_prediction::TAGE_SC_L_TAGE_64KB>::
        create(*this);
}

} // namespace gem5