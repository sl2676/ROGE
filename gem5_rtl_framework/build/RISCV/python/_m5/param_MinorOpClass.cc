/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MinorOpClass.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/minor/func_unit.hh"

#include "enums/OpClass.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MinorOpClass");
    py::class_<MinorOpClassParams, SimObjectParams, std::unique_ptr<MinorOpClassParams, py::nodelete>>(m, "MinorOpClassParams")
        .def(py::init<>())
        .def("create", &MinorOpClassParams::create)
        .def_readwrite("opClass", &MinorOpClassParams::opClass)
        ;

    py::class_<gem5::MinorOpClass, gem5::SimObject, std::unique_ptr<gem5::MinorOpClass, py::nodelete>>(m, "gem5_COLONS_MinorOpClass")
        ;

}

static EmbeddedPyBind embed_obj("MinorOpClass", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMinorOpClassParamsClass
{
  public:
    gem5::MinorOpClass *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMinorOpClassShunt;

template <class CxxClass>
class DummyMinorOpClassShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MinorOpClassParams &>::value>>
{
  public:
    using Params = MinorOpClassParams;
    static gem5::MinorOpClass *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMinorOpClassShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MinorOpClassParams &>::value>>
{
  public:
    using Params = DummyMinorOpClassParamsClass;
    static gem5::MinorOpClass *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::MinorOpClass *
DummyMinorOpClassShunt<gem5::MinorOpClass>::Params::create() const
{
    return DummyMinorOpClassShunt<gem5::MinorOpClass>::
        create(*this);
}

} // namespace gem5
