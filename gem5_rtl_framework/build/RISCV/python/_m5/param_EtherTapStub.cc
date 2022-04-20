/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/EtherTapStub.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/ethertap.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_EtherTapStub");
    py::class_<EtherTapStubParams, EtherTapBaseParams, std::unique_ptr<EtherTapStubParams, py::nodelete>>(m, "EtherTapStubParams")
        .def(py::init<>())
        .def("create", &EtherTapStubParams::create)
        .def_readwrite("port", &EtherTapStubParams::port)
        ;

    py::class_<gem5::EtherTapStub, gem5::EtherTapBase, std::unique_ptr<gem5::EtherTapStub, py::nodelete>>(m, "gem5_COLONS_EtherTapStub")
        ;

}

static EmbeddedPyBind embed_obj("EtherTapStub", module_init, "EtherTapBase");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyEtherTapStubParamsClass
{
  public:
    gem5::EtherTapStub *create() const;
};

template <class CxxClass, class Enable=void>
class DummyEtherTapStubShunt;

template <class CxxClass>
class DummyEtherTapStubShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const EtherTapStubParams &>::value>>
{
  public:
    using Params = EtherTapStubParams;
    static gem5::EtherTapStub *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyEtherTapStubShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const EtherTapStubParams &>::value>>
{
  public:
    using Params = DummyEtherTapStubParamsClass;
    static gem5::EtherTapStub *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::EtherTapStub *
DummyEtherTapStubShunt<gem5::EtherTapStub>::Params::create() const
{
    return DummyEtherTapStubShunt<gem5::EtherTapStub>::
        create(*this);
}

} // namespace gem5