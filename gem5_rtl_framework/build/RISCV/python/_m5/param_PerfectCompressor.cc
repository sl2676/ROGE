/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/PerfectCompressor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/compressors/perfect.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_PerfectCompressor");
    py::class_<PerfectCompressorParams, BaseCacheCompressorParams, std::unique_ptr<PerfectCompressorParams, py::nodelete>>(m, "PerfectCompressorParams")
        .def(py::init<>())
        .def("create", &PerfectCompressorParams::create)
        .def_readwrite("max_compression_ratio", &PerfectCompressorParams::max_compression_ratio)
        ;

    py::class_<gem5::compression::Perfect, gem5::compression::Base, std::unique_ptr<gem5::compression::Perfect, py::nodelete>>(m, "gem5_COLONS_compression_COLONS_Perfect")
        ;

}

static EmbeddedPyBind embed_obj("PerfectCompressor", module_init, "BaseCacheCompressor");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyPerfectCompressorParamsClass
{
  public:
    gem5::compression::Perfect *create() const;
};

template <class CxxClass, class Enable=void>
class DummyPerfectCompressorShunt;

template <class CxxClass>
class DummyPerfectCompressorShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const PerfectCompressorParams &>::value>>
{
  public:
    using Params = PerfectCompressorParams;
    static gem5::compression::Perfect *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyPerfectCompressorShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const PerfectCompressorParams &>::value>>
{
  public:
    using Params = DummyPerfectCompressorParamsClass;
    static gem5::compression::Perfect *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::compression::Perfect *
DummyPerfectCompressorShunt<gem5::compression::Perfect>::Params::create() const
{
    return DummyPerfectCompressorShunt<gem5::compression::Perfect>::
        create(*this);
}

} // namespace gem5