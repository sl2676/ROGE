/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/WeightedLRURP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/weighted_lru_rp.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_WeightedLRURP");
    py::class_<WeightedLRURPParams, LRURPParams, std::unique_ptr<WeightedLRURPParams, py::nodelete>>(m, "WeightedLRURPParams")
        .def(py::init<>())
        .def("create", &WeightedLRURPParams::create)
        ;

    py::class_<gem5::replacement_policy::WeightedLRU, gem5::replacement_policy::LRU, std::unique_ptr<gem5::replacement_policy::WeightedLRU, py::nodelete>>(m, "gem5_COLONS_replacement_policy_COLONS_WeightedLRU")
        ;

}

static EmbeddedPyBind embed_obj("WeightedLRURP", module_init, "LRURP");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyWeightedLRURPParamsClass
{
  public:
    gem5::replacement_policy::WeightedLRU *create() const;
};

template <class CxxClass, class Enable=void>
class DummyWeightedLRURPShunt;

template <class CxxClass>
class DummyWeightedLRURPShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const WeightedLRURPParams &>::value>>
{
  public:
    using Params = WeightedLRURPParams;
    static gem5::replacement_policy::WeightedLRU *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyWeightedLRURPShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const WeightedLRURPParams &>::value>>
{
  public:
    using Params = DummyWeightedLRURPParamsClass;
    static gem5::replacement_policy::WeightedLRU *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::replacement_policy::WeightedLRU *
DummyWeightedLRURPShunt<gem5::replacement_policy::WeightedLRU>::Params::create() const
{
    return DummyWeightedLRURPShunt<gem5::replacement_policy::WeightedLRU>::
        create(*this);
}

} // namespace gem5
