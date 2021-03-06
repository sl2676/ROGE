/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/NoncoherentCache.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/noncoherent_cache.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_NoncoherentCache");
    py::class_<NoncoherentCacheParams, BaseCacheParams, std::unique_ptr<NoncoherentCacheParams, py::nodelete>>(m, "NoncoherentCacheParams")
        .def(py::init<>())
        .def("create", &NoncoherentCacheParams::create)
        ;

    py::class_<gem5::NoncoherentCache, gem5::BaseCache, std::unique_ptr<gem5::NoncoherentCache, py::nodelete>>(m, "gem5_COLONS_NoncoherentCache")
        ;

}

static EmbeddedPyBind embed_obj("NoncoherentCache", module_init, "BaseCache");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyNoncoherentCacheParamsClass
{
  public:
    gem5::NoncoherentCache *create() const;
};

template <class CxxClass, class Enable=void>
class DummyNoncoherentCacheShunt;

template <class CxxClass>
class DummyNoncoherentCacheShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const NoncoherentCacheParams &>::value>>
{
  public:
    using Params = NoncoherentCacheParams;
    static gem5::NoncoherentCache *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyNoncoherentCacheShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const NoncoherentCacheParams &>::value>>
{
  public:
    using Params = DummyNoncoherentCacheParamsClass;
    static gem5::NoncoherentCache *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::NoncoherentCache *
DummyNoncoherentCacheShunt<gem5::NoncoherentCache>::Params::create() const
{
    return DummyNoncoherentCacheShunt<gem5::NoncoherentCache>::
        create(*this);
}

} // namespace gem5
