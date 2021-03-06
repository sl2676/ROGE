/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/AccessMapPatternMatching.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/access_map_pattern_matching.hh"

#include "base/types.hh"
#include "base/types.hh"
#include "mem/cache/tags/indexing_policies/base.hh"
#include "mem/cache/replacement_policies/base.hh"
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
    py::module_ m = m_internal.def_submodule("param_AccessMapPatternMatching");
    py::class_<AccessMapPatternMatchingParams, ClockedObjectParams, std::unique_ptr<AccessMapPatternMatchingParams, py::nodelete>>(m, "AccessMapPatternMatchingParams")
        .def(py::init<>())
        .def("create", &AccessMapPatternMatchingParams::create)
        .def_readwrite("access_map_table_assoc", &AccessMapPatternMatchingParams::access_map_table_assoc)
        .def_readwrite("access_map_table_entries", &AccessMapPatternMatchingParams::access_map_table_entries)
        .def_readwrite("access_map_table_indexing_policy", &AccessMapPatternMatchingParams::access_map_table_indexing_policy)
        .def_readwrite("access_map_table_replacement_policy", &AccessMapPatternMatchingParams::access_map_table_replacement_policy)
        .def_readwrite("block_size", &AccessMapPatternMatchingParams::block_size)
        .def_readwrite("epoch_cycles", &AccessMapPatternMatchingParams::epoch_cycles)
        .def_readwrite("high_accuracy_threshold", &AccessMapPatternMatchingParams::high_accuracy_threshold)
        .def_readwrite("high_cache_hit_threshold", &AccessMapPatternMatchingParams::high_cache_hit_threshold)
        .def_readwrite("high_coverage_threshold", &AccessMapPatternMatchingParams::high_coverage_threshold)
        .def_readwrite("hot_zone_size", &AccessMapPatternMatchingParams::hot_zone_size)
        .def_readwrite("limit_stride", &AccessMapPatternMatchingParams::limit_stride)
        .def_readwrite("low_accuracy_threshold", &AccessMapPatternMatchingParams::low_accuracy_threshold)
        .def_readwrite("low_cache_hit_threshold", &AccessMapPatternMatchingParams::low_cache_hit_threshold)
        .def_readwrite("low_coverage_threshold", &AccessMapPatternMatchingParams::low_coverage_threshold)
        .def_readwrite("offchip_memory_latency", &AccessMapPatternMatchingParams::offchip_memory_latency)
        .def_readwrite("start_degree", &AccessMapPatternMatchingParams::start_degree)
        ;

    py::class_<gem5::prefetch::AccessMapPatternMatching, gem5::ClockedObject, std::unique_ptr<gem5::prefetch::AccessMapPatternMatching, py::nodelete>>(m, "gem5_COLONS_prefetch_COLONS_AccessMapPatternMatching")
        ;

}

static EmbeddedPyBind embed_obj("AccessMapPatternMatching", module_init, "ClockedObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyAccessMapPatternMatchingParamsClass
{
  public:
    gem5::prefetch::AccessMapPatternMatching *create() const;
};

template <class CxxClass, class Enable=void>
class DummyAccessMapPatternMatchingShunt;

template <class CxxClass>
class DummyAccessMapPatternMatchingShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const AccessMapPatternMatchingParams &>::value>>
{
  public:
    using Params = AccessMapPatternMatchingParams;
    static gem5::prefetch::AccessMapPatternMatching *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyAccessMapPatternMatchingShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const AccessMapPatternMatchingParams &>::value>>
{
  public:
    using Params = DummyAccessMapPatternMatchingParamsClass;
    static gem5::prefetch::AccessMapPatternMatching *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::prefetch::AccessMapPatternMatching *
DummyAccessMapPatternMatchingShunt<gem5::prefetch::AccessMapPatternMatching>::Params::create() const
{
    return DummyAccessMapPatternMatchingShunt<gem5::prefetch::AccessMapPatternMatching>::
        create(*this);
}

} // namespace gem5
