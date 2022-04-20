/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Cache.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/cache.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Cache");
    py::class_<CacheParams, BaseCacheParams, std::unique_ptr<CacheParams, py::nodelete>>(m, "CacheParams")
        .def(py::init<>())
        .def("create", &CacheParams::create)
        ;

    py::class_<gem5::Cache, gem5::BaseCache, std::unique_ptr<gem5::Cache, py::nodelete>>(m, "gem5_COLONS_Cache")
        ;

}

static EmbeddedPyBind embed_obj("Cache", module_init, "BaseCache");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyCacheParamsClass
{
  public:
    gem5::Cache *create() const;
};

template <class CxxClass, class Enable=void>
class DummyCacheShunt;

template <class CxxClass>
class DummyCacheShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const CacheParams &>::value>>
{
  public:
    using Params = CacheParams;
    static gem5::Cache *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyCacheShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const CacheParams &>::value>>
{
  public:
    using Params = DummyCacheParamsClass;
    static gem5::Cache *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::Cache *
DummyCacheShunt<gem5::Cache>::Params::create() const
{
    return DummyCacheShunt<gem5::Cache>::
        create(*this);
}

} // namespace gem5
