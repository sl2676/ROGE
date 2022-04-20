/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/VoltageDomain.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/voltage_domain.hh"

#include <vector>
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_VoltageDomain");
    py::class_<VoltageDomainParams, SimObjectParams, std::unique_ptr<VoltageDomainParams, py::nodelete>>(m, "VoltageDomainParams")
        .def(py::init<>())
        .def("create", &VoltageDomainParams::create)
        .def_readwrite("voltage", &VoltageDomainParams::voltage)
        ;

    py::class_<gem5::VoltageDomain, gem5::SimObject, std::unique_ptr<gem5::VoltageDomain, py::nodelete>>(m, "gem5_COLONS_VoltageDomain")
        ;

}

static EmbeddedPyBind embed_obj("VoltageDomain", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyVoltageDomainParamsClass
{
  public:
    gem5::VoltageDomain *create() const;
};

template <class CxxClass, class Enable=void>
class DummyVoltageDomainShunt;

template <class CxxClass>
class DummyVoltageDomainShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const VoltageDomainParams &>::value>>
{
  public:
    using Params = VoltageDomainParams;
    static gem5::VoltageDomain *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyVoltageDomainShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const VoltageDomainParams &>::value>>
{
  public:
    using Params = DummyVoltageDomainParamsClass;
    static gem5::VoltageDomain *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::VoltageDomain *
DummyVoltageDomainShunt<gem5::VoltageDomain>::Params::create() const
{
    return DummyVoltageDomainShunt<gem5::VoltageDomain>::
        create(*this);
}

} // namespace gem5
