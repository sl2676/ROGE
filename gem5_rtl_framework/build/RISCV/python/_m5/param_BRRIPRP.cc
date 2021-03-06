/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/BRRIPRP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/brrip_rp.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_BRRIPRP");
    py::class_<BRRIPRPParams, BaseReplacementPolicyParams, std::unique_ptr<BRRIPRPParams, py::nodelete>>(m, "BRRIPRPParams")
        .def(py::init<>())
        .def("create", &BRRIPRPParams::create)
        .def_readwrite("btp", &BRRIPRPParams::btp)
        .def_readwrite("hit_priority", &BRRIPRPParams::hit_priority)
        .def_readwrite("num_bits", &BRRIPRPParams::num_bits)
        ;

    py::class_<gem5::replacement_policy::BRRIP, gem5::replacement_policy::Base, std::unique_ptr<gem5::replacement_policy::BRRIP, py::nodelete>>(m, "gem5_COLONS_replacement_policy_COLONS_BRRIP")
        ;

}

static EmbeddedPyBind embed_obj("BRRIPRP", module_init, "BaseReplacementPolicy");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyBRRIPRPParamsClass
{
  public:
    gem5::replacement_policy::BRRIP *create() const;
};

template <class CxxClass, class Enable=void>
class DummyBRRIPRPShunt;

template <class CxxClass>
class DummyBRRIPRPShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const BRRIPRPParams &>::value>>
{
  public:
    using Params = BRRIPRPParams;
    static gem5::replacement_policy::BRRIP *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyBRRIPRPShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const BRRIPRPParams &>::value>>
{
  public:
    using Params = DummyBRRIPRPParamsClass;
    static gem5::replacement_policy::BRRIP *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::replacement_policy::BRRIP *
DummyBRRIPRPShunt<gem5::replacement_policy::BRRIP>::Params::create() const
{
    return DummyBRRIPRPShunt<gem5::replacement_policy::BRRIP>::
        create(*this);
}

} // namespace gem5
