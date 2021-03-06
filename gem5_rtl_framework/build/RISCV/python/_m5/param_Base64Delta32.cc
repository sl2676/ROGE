/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Base64Delta32.hh"
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
    py::module_ m = m_internal.def_submodule("param_Base64Delta32");
    py::class_<Base64Delta32Params, BaseDictionaryCompressorParams, std::unique_ptr<Base64Delta32Params, py::nodelete>>(m, "Base64Delta32Params")
        .def(py::init<>())
        .def("create", &Base64Delta32Params::create)
        ;

    py::class_<gem5::compression::Base64Delta32, gem5::compression::BaseDictionaryCompressor, std::unique_ptr<gem5::compression::Base64Delta32, py::nodelete>>(m, "gem5_COLONS_compression_COLONS_Base64Delta32")
        ;

}

static EmbeddedPyBind embed_obj("Base64Delta32", module_init, "BaseDictionaryCompressor");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyBase64Delta32ParamsClass
{
  public:
    gem5::compression::Base64Delta32 *create() const;
};

template <class CxxClass, class Enable=void>
class DummyBase64Delta32Shunt;

template <class CxxClass>
class DummyBase64Delta32Shunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const Base64Delta32Params &>::value>>
{
  public:
    using Params = Base64Delta32Params;
    static gem5::compression::Base64Delta32 *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyBase64Delta32Shunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const Base64Delta32Params &>::value>>
{
  public:
    using Params = DummyBase64Delta32ParamsClass;
    static gem5::compression::Base64Delta32 *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::compression::Base64Delta32 *
DummyBase64Delta32Shunt<gem5::compression::Base64Delta32>::Params::create() const
{
    return DummyBase64Delta32Shunt<gem5::compression::Base64Delta32>::
        create(*this);
}

} // namespace gem5
