/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TlmToGem5Bridge128.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "systemc/tlm_bridge/tlm_to_gem5.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_TlmToGem5Bridge128");
    py::class_<TlmToGem5Bridge128Params, TlmToGem5BridgeBaseParams, std::unique_ptr<TlmToGem5Bridge128Params, py::nodelete>>(m, "TlmToGem5Bridge128Params")
        .def(py::init<>())
        .def("create", &TlmToGem5Bridge128Params::create)
        .def_readwrite("port_tlm_connection_count", &TlmToGem5Bridge128Params::port_tlm_connection_count)
        ;

    py::class_<sc_gem5::TlmToGem5Bridge<128>, sc_gem5::TlmToGem5BridgeBase, std::unique_ptr<sc_gem5::TlmToGem5Bridge<128>, py::nodelete>>(m, "sc_gem5_COLONS_TlmToGem5Bridge<128>")
        ;

}

static EmbeddedPyBind embed_obj("TlmToGem5Bridge128", module_init, "TlmToGem5BridgeBase");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTlmToGem5Bridge128ParamsClass
{
  public:
    sc_gem5::TlmToGem5Bridge<128> *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTlmToGem5Bridge128Shunt;

template <class CxxClass>
class DummyTlmToGem5Bridge128Shunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TlmToGem5Bridge128Params &>::value>>
{
  public:
    using Params = TlmToGem5Bridge128Params;
    static sc_gem5::TlmToGem5Bridge<128> *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTlmToGem5Bridge128Shunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TlmToGem5Bridge128Params &>::value>>
{
  public:
    using Params = DummyTlmToGem5Bridge128ParamsClass;
    static sc_gem5::TlmToGem5Bridge<128> *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED sc_gem5::TlmToGem5Bridge<128> *
DummyTlmToGem5Bridge128Shunt<sc_gem5::TlmToGem5Bridge<128>>::Params::create() const
{
    return DummyTlmToGem5Bridge128Shunt<sc_gem5::TlmToGem5Bridge<128>>::
        create(*this);
}

} // namespace gem5