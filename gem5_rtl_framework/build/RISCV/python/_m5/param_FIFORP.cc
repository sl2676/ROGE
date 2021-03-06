/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/FIFORP.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/fifo_rp.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_FIFORP");
    py::class_<FIFORPParams, BaseReplacementPolicyParams, std::unique_ptr<FIFORPParams, py::nodelete>>(m, "FIFORPParams")
        .def(py::init<>())
        .def("create", &FIFORPParams::create)
        ;

    py::class_<gem5::replacement_policy::FIFO, gem5::replacement_policy::Base, std::unique_ptr<gem5::replacement_policy::FIFO, py::nodelete>>(m, "gem5_COLONS_replacement_policy_COLONS_FIFO")
        ;

}

static EmbeddedPyBind embed_obj("FIFORP", module_init, "BaseReplacementPolicy");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyFIFORPParamsClass
{
  public:
    gem5::replacement_policy::FIFO *create() const;
};

template <class CxxClass, class Enable=void>
class DummyFIFORPShunt;

template <class CxxClass>
class DummyFIFORPShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const FIFORPParams &>::value>>
{
  public:
    using Params = FIFORPParams;
    static gem5::replacement_policy::FIFO *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyFIFORPShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const FIFORPParams &>::value>>
{
  public:
    using Params = DummyFIFORPParamsClass;
    static gem5::replacement_policy::FIFO *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::replacement_policy::FIFO *
DummyFIFORPShunt<gem5::replacement_policy::FIFO>::Params::create() const
{
    return DummyFIFORPShunt<gem5::replacement_policy::FIFO>::
        create(*this);
}

} // namespace gem5
