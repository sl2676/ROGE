/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SBOOEPrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/sbooe.hh"

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
    py::module_ m = m_internal.def_submodule("param_SBOOEPrefetcher");
    py::class_<SBOOEPrefetcherParams, QueuedPrefetcherParams, std::unique_ptr<SBOOEPrefetcherParams, py::nodelete>>(m, "SBOOEPrefetcherParams")
        .def(py::init<>())
        .def("create", &SBOOEPrefetcherParams::create)
        .def_readwrite("latency_buffer_size", &SBOOEPrefetcherParams::latency_buffer_size)
        .def_readwrite("sandbox_entries", &SBOOEPrefetcherParams::sandbox_entries)
        .def_readwrite("score_threshold_pct", &SBOOEPrefetcherParams::score_threshold_pct)
        .def_readwrite("sequential_prefetchers", &SBOOEPrefetcherParams::sequential_prefetchers)
        ;

    py::class_<gem5::prefetch::SBOOE, gem5::prefetch::Queued, std::unique_ptr<gem5::prefetch::SBOOE, py::nodelete>>(m, "gem5_COLONS_prefetch_COLONS_SBOOE")
        ;

}

static EmbeddedPyBind embed_obj("SBOOEPrefetcher", module_init, "QueuedPrefetcher");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySBOOEPrefetcherParamsClass
{
  public:
    gem5::prefetch::SBOOE *create() const;
};

template <class CxxClass, class Enable=void>
class DummySBOOEPrefetcherShunt;

template <class CxxClass>
class DummySBOOEPrefetcherShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SBOOEPrefetcherParams &>::value>>
{
  public:
    using Params = SBOOEPrefetcherParams;
    static gem5::prefetch::SBOOE *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySBOOEPrefetcherShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SBOOEPrefetcherParams &>::value>>
{
  public:
    using Params = DummySBOOEPrefetcherParamsClass;
    static gem5::prefetch::SBOOE *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::prefetch::SBOOE *
DummySBOOEPrefetcherShunt<gem5::prefetch::SBOOE>::Params::create() const
{
    return DummySBOOEPrefetcherShunt<gem5::prefetch::SBOOE>::
        create(*this);
}

} // namespace gem5
