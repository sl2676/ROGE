/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SHiPMemRP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/ship_rp.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SHiPMemRP");
    py::class_<SHiPMemRPParams, SHiPRPParams, std::unique_ptr<SHiPMemRPParams, py::nodelete>>(m, "SHiPMemRPParams")
        .def(py::init<>())
        .def("create", &SHiPMemRPParams::create)
        ;

    py::class_<gem5::replacement_policy::SHiPMem, gem5::replacement_policy::SHiP, std::unique_ptr<gem5::replacement_policy::SHiPMem, py::nodelete>>(m, "gem5_COLONS_replacement_policy_COLONS_SHiPMem")
        ;

}

static EmbeddedPyBind embed_obj("SHiPMemRP", module_init, "SHiPRP");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySHiPMemRPParamsClass
{
  public:
    gem5::replacement_policy::SHiPMem *create() const;
};

template <class CxxClass, class Enable=void>
class DummySHiPMemRPShunt;

template <class CxxClass>
class DummySHiPMemRPShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SHiPMemRPParams &>::value>>
{
  public:
    using Params = SHiPMemRPParams;
    static gem5::replacement_policy::SHiPMem *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySHiPMemRPShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SHiPMemRPParams &>::value>>
{
  public:
    using Params = DummySHiPMemRPParamsClass;
    static gem5::replacement_policy::SHiPMem *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::replacement_policy::SHiPMem *
DummySHiPMemRPShunt<gem5::replacement_policy::SHiPMem>::Params::create() const
{
    return DummySHiPMemRPShunt<gem5::replacement_policy::SHiPMem>::
        create(*this);
}

} // namespace gem5
