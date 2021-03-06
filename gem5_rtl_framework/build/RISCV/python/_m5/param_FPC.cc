/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/FPC.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/compressors/fpc.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_FPC");
    py::class_<FPCParams, BaseDictionaryCompressorParams, std::unique_ptr<FPCParams, py::nodelete>>(m, "FPCParams")
        .def(py::init<>())
        .def("create", &FPCParams::create)
        .def_readwrite("zero_run_bits", &FPCParams::zero_run_bits)
        ;

    py::class_<gem5::compression::FPC, gem5::compression::BaseDictionaryCompressor, std::unique_ptr<gem5::compression::FPC, py::nodelete>>(m, "gem5_COLONS_compression_COLONS_FPC")
        ;

}

static EmbeddedPyBind embed_obj("FPC", module_init, "BaseDictionaryCompressor");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyFPCParamsClass
{
  public:
    gem5::compression::FPC *create() const;
};

template <class CxxClass, class Enable=void>
class DummyFPCShunt;

template <class CxxClass>
class DummyFPCShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const FPCParams &>::value>>
{
  public:
    using Params = FPCParams;
    static gem5::compression::FPC *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyFPCShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const FPCParams &>::value>>
{
  public:
    using Params = DummyFPCParamsClass;
    static gem5::compression::FPC *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::compression::FPC *
DummyFPCShunt<gem5::compression::FPC>::Params::create() const
{
    return DummyFPCShunt<gem5::compression::FPC>::
        create(*this);
}

} // namespace gem5
