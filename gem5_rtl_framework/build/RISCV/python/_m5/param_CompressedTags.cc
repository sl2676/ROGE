/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/CompressedTags.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/tags/compressed_tags.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_CompressedTags");
    py::class_<CompressedTagsParams, SectorTagsParams, std::unique_ptr<CompressedTagsParams, py::nodelete>>(m, "CompressedTagsParams")
        .def(py::init<>())
        .def("create", &CompressedTagsParams::create)
        .def_readwrite("max_compression_ratio", &CompressedTagsParams::max_compression_ratio)
        ;

    py::class_<gem5::CompressedTags, gem5::SectorTags, std::unique_ptr<gem5::CompressedTags, py::nodelete>>(m, "gem5_COLONS_CompressedTags")
        ;

}

static EmbeddedPyBind embed_obj("CompressedTags", module_init, "SectorTags");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyCompressedTagsParamsClass
{
  public:
    gem5::CompressedTags *create() const;
};

template <class CxxClass, class Enable=void>
class DummyCompressedTagsShunt;

template <class CxxClass>
class DummyCompressedTagsShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const CompressedTagsParams &>::value>>
{
  public:
    using Params = CompressedTagsParams;
    static gem5::CompressedTags *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyCompressedTagsShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const CompressedTagsParams &>::value>>
{
  public:
    using Params = DummyCompressedTagsParamsClass;
    static gem5::CompressedTags *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::CompressedTags *
DummyCompressedTagsShunt<gem5::CompressedTags>::Params::create() const
{
    return DummyCompressedTagsShunt<gem5::CompressedTags>::
        create(*this);
}

} // namespace gem5