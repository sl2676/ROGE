/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/DCPTPrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/delta_correlating_prediction_tables.hh"

#include "mem/cache/prefetch/delta_correlating_prediction_tables.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_DCPTPrefetcher");
    py::class_<DCPTPrefetcherParams, QueuedPrefetcherParams, std::unique_ptr<DCPTPrefetcherParams, py::nodelete>>(m, "DCPTPrefetcherParams")
        .def(py::init<>())
        .def("create", &DCPTPrefetcherParams::create)
        .def_readwrite("dcpt", &DCPTPrefetcherParams::dcpt)
        ;

    py::class_<gem5::prefetch::DCPT, gem5::prefetch::Queued, std::unique_ptr<gem5::prefetch::DCPT, py::nodelete>>(m, "gem5_COLONS_prefetch_COLONS_DCPT")
        ;

}

static EmbeddedPyBind embed_obj("DCPTPrefetcher", module_init, "QueuedPrefetcher");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyDCPTPrefetcherParamsClass
{
  public:
    gem5::prefetch::DCPT *create() const;
};

template <class CxxClass, class Enable=void>
class DummyDCPTPrefetcherShunt;

template <class CxxClass>
class DummyDCPTPrefetcherShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const DCPTPrefetcherParams &>::value>>
{
  public:
    using Params = DCPTPrefetcherParams;
    static gem5::prefetch::DCPT *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyDCPTPrefetcherShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const DCPTPrefetcherParams &>::value>>
{
  public:
    using Params = DummyDCPTPrefetcherParamsClass;
    static gem5::prefetch::DCPT *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::prefetch::DCPT *
DummyDCPTPrefetcherShunt<gem5::prefetch::DCPT>::Params::create() const
{
    return DummyDCPTPrefetcherShunt<gem5::prefetch::DCPT>::
        create(*this);
}

} // namespace gem5
