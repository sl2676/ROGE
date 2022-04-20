/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TaggedPrefetcher.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/prefetch/tagged.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TaggedPrefetcher");
    py::class_<TaggedPrefetcherParams, QueuedPrefetcherParams, std::unique_ptr<TaggedPrefetcherParams, py::nodelete>>(m, "TaggedPrefetcherParams")
        .def(py::init<>())
        .def("create", &TaggedPrefetcherParams::create)
        .def_readwrite("degree", &TaggedPrefetcherParams::degree)
        ;

    py::class_<gem5::prefetch::Tagged, gem5::prefetch::Queued, std::unique_ptr<gem5::prefetch::Tagged, py::nodelete>>(m, "gem5_COLONS_prefetch_COLONS_Tagged")
        ;

}

static EmbeddedPyBind embed_obj("TaggedPrefetcher", module_init, "QueuedPrefetcher");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTaggedPrefetcherParamsClass
{
  public:
    gem5::prefetch::Tagged *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTaggedPrefetcherShunt;

template <class CxxClass>
class DummyTaggedPrefetcherShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TaggedPrefetcherParams &>::value>>
{
  public:
    using Params = TaggedPrefetcherParams;
    static gem5::prefetch::Tagged *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTaggedPrefetcherShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TaggedPrefetcherParams &>::value>>
{
  public:
    using Params = DummyTaggedPrefetcherParamsClass;
    static gem5::prefetch::Tagged *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::prefetch::Tagged *
DummyTaggedPrefetcherShunt<gem5::prefetch::Tagged>::Params::create() const
{
    return DummyTaggedPrefetcherShunt<gem5::prefetch::Tagged>::
        create(*this);
}

} // namespace gem5