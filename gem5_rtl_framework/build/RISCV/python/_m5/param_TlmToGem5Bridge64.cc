/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/TlmToGem5Bridge64.hh"
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
    py::module_ m = m_internal.def_submodule("param_TlmToGem5Bridge64");
    py::class_<TlmToGem5Bridge64Params, TlmToGem5BridgeBaseParams, std::unique_ptr<TlmToGem5Bridge64Params, py::nodelete>>(m, "TlmToGem5Bridge64Params")
        .def(py::init<>())
        .def("create", &TlmToGem5Bridge64Params::create)
        .def_readwrite("port_tlm_connection_count", &TlmToGem5Bridge64Params::port_tlm_connection_count)
        ;

    py::class_<sc_gem5::TlmToGem5Bridge<64>, sc_gem5::TlmToGem5BridgeBase, std::unique_ptr<sc_gem5::TlmToGem5Bridge<64>, py::nodelete>>(m, "sc_gem5_COLONS_TlmToGem5Bridge<64>")
        ;

}

static EmbeddedPyBind embed_obj("TlmToGem5Bridge64", module_init, "TlmToGem5BridgeBase");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyTlmToGem5Bridge64ParamsClass
{
  public:
    sc_gem5::TlmToGem5Bridge<64> *create() const;
};

template <class CxxClass, class Enable=void>
class DummyTlmToGem5Bridge64Shunt;

template <class CxxClass>
class DummyTlmToGem5Bridge64Shunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const TlmToGem5Bridge64Params &>::value>>
{
  public:
    using Params = TlmToGem5Bridge64Params;
    static sc_gem5::TlmToGem5Bridge<64> *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyTlmToGem5Bridge64Shunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const TlmToGem5Bridge64Params &>::value>>
{
  public:
    using Params = DummyTlmToGem5Bridge64ParamsClass;
    static sc_gem5::TlmToGem5Bridge<64> *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED sc_gem5::TlmToGem5Bridge<64> *
DummyTlmToGem5Bridge64Shunt<sc_gem5::TlmToGem5Bridge<64>>::Params::create() const
{
    return DummyTlmToGem5Bridge64Shunt<sc_gem5::TlmToGem5Bridge<64>>::
        create(*this);
}

} // namespace gem5
