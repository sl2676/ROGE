/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/Gem5ToTlmBridge32.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "systemc/tlm_bridge/gem5_to_tlm.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_Gem5ToTlmBridge32");
    py::class_<Gem5ToTlmBridge32Params, Gem5ToTlmBridgeBaseParams, std::unique_ptr<Gem5ToTlmBridge32Params, py::nodelete>>(m, "Gem5ToTlmBridge32Params")
        .def(py::init<>())
        .def("create", &Gem5ToTlmBridge32Params::create)
        .def_readwrite("port_tlm_connection_count", &Gem5ToTlmBridge32Params::port_tlm_connection_count)
        ;

    py::class_<sc_gem5::Gem5ToTlmBridge<32>, sc_gem5::Gem5ToTlmBridgeBase, std::unique_ptr<sc_gem5::Gem5ToTlmBridge<32>, py::nodelete>>(m, "sc_gem5_COLONS_Gem5ToTlmBridge<32>")
        ;

}

static EmbeddedPyBind embed_obj("Gem5ToTlmBridge32", module_init, "Gem5ToTlmBridgeBase");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyGem5ToTlmBridge32ParamsClass
{
  public:
    sc_gem5::Gem5ToTlmBridge<32> *create() const;
};

template <class CxxClass, class Enable=void>
class DummyGem5ToTlmBridge32Shunt;

template <class CxxClass>
class DummyGem5ToTlmBridge32Shunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const Gem5ToTlmBridge32Params &>::value>>
{
  public:
    using Params = Gem5ToTlmBridge32Params;
    static sc_gem5::Gem5ToTlmBridge<32> *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyGem5ToTlmBridge32Shunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const Gem5ToTlmBridge32Params &>::value>>
{
  public:
    using Params = DummyGem5ToTlmBridge32ParamsClass;
    static sc_gem5::Gem5ToTlmBridge<32> *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED sc_gem5::Gem5ToTlmBridge<32> *
DummyGem5ToTlmBridge32Shunt<sc_gem5::Gem5ToTlmBridge<32>>::Params::create() const
{
    return DummyGem5ToTlmBridge32Shunt<sc_gem5::Gem5ToTlmBridge<32>>::
        create(*this);
}

} // namespace gem5