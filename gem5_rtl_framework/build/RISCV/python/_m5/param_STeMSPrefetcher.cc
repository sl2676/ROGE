/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/STeMSPrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/spatio_temporal_memory_streaming.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "mem/cache/tags/indexing_policies/base.hh"
#include "mem/cache/replacement_policies/base.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "mem/cache/tags/indexing_policies/base.hh"
#include "mem/cache/replacement_policies/base.hh"
#include "base/types.hh"
#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_STeMSPrefetcher");
    py::class_<STeMSPrefetcherParams, QueuedPrefetcherParams, std::unique_ptr<STeMSPrefetcherParams, py::nodelete>>(m, "STeMSPrefetcherParams")
        .def(py::init<>())
        .def("create", &STeMSPrefetcherParams::create)
        .def_readwrite("active_generation_table_assoc", &STeMSPrefetcherParams::active_generation_table_assoc)
        .def_readwrite("active_generation_table_entries", &STeMSPrefetcherParams::active_generation_table_entries)
        .def_readwrite("active_generation_table_indexing_policy", &STeMSPrefetcherParams::active_generation_table_indexing_policy)
        .def_readwrite("active_generation_table_replacement_policy", &STeMSPrefetcherParams::active_generation_table_replacement_policy)
        .def_readwrite("pattern_sequence_table_assoc", &STeMSPrefetcherParams::pattern_sequence_table_assoc)
        .def_readwrite("pattern_sequence_table_entries", &STeMSPrefetcherParams::pattern_sequence_table_entries)
        .def_readwrite("pattern_sequence_table_indexing_policy", &STeMSPrefetcherParams::pattern_sequence_table_indexing_policy)
        .def_readwrite("pattern_sequence_table_replacement_policy", &STeMSPrefetcherParams::pattern_sequence_table_replacement_policy)
        .def_readwrite("reconstruction_entries", &STeMSPrefetcherParams::reconstruction_entries)
        .def_readwrite("region_miss_order_buffer_entries", &STeMSPrefetcherParams::region_miss_order_buffer_entries)
        .def_readwrite("spatial_region_size", &STeMSPrefetcherParams::spatial_region_size)
        ;

    py::class_<gem5::prefetch::STeMS, gem5::prefetch::Queued, std::unique_ptr<gem5::prefetch::STeMS, py::nodelete>>(m, "gem5_COLONS_prefetch_COLONS_STeMS")
        ;

}

static EmbeddedPyBind embed_obj("STeMSPrefetcher", module_init, "QueuedPrefetcher");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySTeMSPrefetcherParamsClass
{
  public:
    gem5::prefetch::STeMS *create() const;
};

template <class CxxClass, class Enable=void>
class DummySTeMSPrefetcherShunt;

template <class CxxClass>
class DummySTeMSPrefetcherShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const STeMSPrefetcherParams &>::value>>
{
  public:
    using Params = STeMSPrefetcherParams;
    static gem5::prefetch::STeMS *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySTeMSPrefetcherShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const STeMSPrefetcherParams &>::value>>
{
  public:
    using Params = DummySTeMSPrefetcherParamsClass;
    static gem5::prefetch::STeMS *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::prefetch::STeMS *
DummySTeMSPrefetcherShunt<gem5::prefetch::STeMS>::Params::create() const
{
    return DummySTeMSPrefetcherShunt<gem5::prefetch::STeMS>::
        create(*this);
}

} // namespace gem5