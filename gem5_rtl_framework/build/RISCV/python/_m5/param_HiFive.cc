/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/HiFive.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/riscv/hifive.hh"

#include "dev/riscv/clint.hh"
#include "base/types.hh"
#include "dev/riscv/plic.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_HiFive");
    py::class_<HiFiveParams, PlatformParams, std::unique_ptr<HiFiveParams, py::nodelete>>(m, "HiFiveParams")
        .def(py::init<>())
        .def("create", &HiFiveParams::create)
        .def_readwrite("clint", &HiFiveParams::clint)
        .def_readwrite("cpu_count", &HiFiveParams::cpu_count)
        .def_readwrite("plic", &HiFiveParams::plic)
        .def_readwrite("uart_int_id", &HiFiveParams::uart_int_id)
        ;

    py::class_<gem5::HiFive, gem5::Platform, std::unique_ptr<gem5::HiFive, py::nodelete>>(m, "gem5_COLONS_HiFive")
        ;

}

static EmbeddedPyBind embed_obj("HiFive", module_init, "Platform");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyHiFiveParamsClass
{
  public:
    gem5::HiFive *create() const;
};

template <class CxxClass, class Enable=void>
class DummyHiFiveShunt;

template <class CxxClass>
class DummyHiFiveShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const HiFiveParams &>::value>>
{
  public:
    using Params = HiFiveParams;
    static gem5::HiFive *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyHiFiveShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const HiFiveParams &>::value>>
{
  public:
    using Params = DummyHiFiveParamsClass;
    static gem5::HiFive *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::HiFive *
DummyHiFiveShunt<gem5::HiFive>::Params::create() const
{
    return DummyHiFiveShunt<gem5::HiFive>::
        create(*this);
}

} // namespace gem5