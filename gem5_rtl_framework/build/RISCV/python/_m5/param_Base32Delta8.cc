/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Base32Delta8.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/compressors/base_delta.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Base32Delta8");
    py::class_<Base32Delta8Params, BaseDictionaryCompressorParams, std::unique_ptr<Base32Delta8Params, py::nodelete>>(m, "Base32Delta8Params")
        .def(py::init<>())
        .def("create", &Base32Delta8Params::create)
        ;

    py::class_<gem5::compression::Base32Delta8, gem5::compression::BaseDictionaryCompressor, std::unique_ptr<gem5::compression::Base32Delta8, py::nodelete>>(m, "gem5_COLONS_compression_COLONS_Base32Delta8")
        ;

}

static EmbeddedPyBind embed_obj("Base32Delta8", module_init, "BaseDictionaryCompressor");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyBase32Delta8ParamsClass
{
  public:
    gem5::compression::Base32Delta8 *create() const;
};

template <class CxxClass, class Enable=void>
class DummyBase32Delta8Shunt;

template <class CxxClass>
class DummyBase32Delta8Shunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const Base32Delta8Params &>::value>>
{
  public:
    using Params = Base32Delta8Params;
    static gem5::compression::Base32Delta8 *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyBase32Delta8Shunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const Base32Delta8Params &>::value>>
{
  public:
    using Params = DummyBase32Delta8ParamsClass;
    static gem5::compression::Base32Delta8 *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::compression::Base32Delta8 *
DummyBase32Delta8Shunt<gem5::compression::Base32Delta8>::Params::create() const
{
    return DummyBase32Delta8Shunt<gem5::compression::Base32Delta8>::
        create(*this);
}

} // namespace gem5