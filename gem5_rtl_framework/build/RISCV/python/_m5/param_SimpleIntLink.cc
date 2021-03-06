/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SimpleIntLink.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/simple/SimpleLink.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SimpleIntLink");
    py::class_<SimpleIntLinkParams, BasicIntLinkParams, std::unique_ptr<SimpleIntLinkParams, py::nodelete>>(m, "SimpleIntLinkParams")
        .def(py::init<>())
        .def("create", &SimpleIntLinkParams::create)
        ;

    py::class_<gem5::ruby::SimpleIntLink, gem5::ruby::BasicIntLink, std::unique_ptr<gem5::ruby::SimpleIntLink, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_SimpleIntLink")
        ;

}

static EmbeddedPyBind embed_obj("SimpleIntLink", module_init, "BasicIntLink");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySimpleIntLinkParamsClass
{
  public:
    gem5::ruby::SimpleIntLink *create() const;
};

template <class CxxClass, class Enable=void>
class DummySimpleIntLinkShunt;

template <class CxxClass>
class DummySimpleIntLinkShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SimpleIntLinkParams &>::value>>
{
  public:
    using Params = SimpleIntLinkParams;
    static gem5::ruby::SimpleIntLink *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySimpleIntLinkShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SimpleIntLinkParams &>::value>>
{
  public:
    using Params = DummySimpleIntLinkParamsClass;
    static gem5::ruby::SimpleIntLink *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::SimpleIntLink *
DummySimpleIntLinkShunt<gem5::ruby::SimpleIntLink>::Params::create() const
{
    return DummySimpleIntLinkShunt<gem5::ruby::SimpleIntLink>::
        create(*this);
}

} // namespace gem5
