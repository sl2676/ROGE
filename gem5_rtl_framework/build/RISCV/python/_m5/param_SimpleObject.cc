/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SimpleObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/simple_object.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SimpleObject");
    py::class_<SimpleObjectParams, SimObjectParams, std::unique_ptr<SimpleObjectParams, py::nodelete>>(m, "SimpleObjectParams")
        .def(py::init<>())
        .def("create", &SimpleObjectParams::create)
        ;

    py::class_<gem5::SimpleObject, gem5::SimObject, std::unique_ptr<gem5::SimpleObject, py::nodelete>>(m, "gem5_COLONS_SimpleObject")
        ;

}

static EmbeddedPyBind embed_obj("SimpleObject", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySimpleObjectParamsClass
{
  public:
    gem5::SimpleObject *create() const;
};

template <class CxxClass, class Enable=void>
class DummySimpleObjectShunt;

template <class CxxClass>
class DummySimpleObjectShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SimpleObjectParams &>::value>>
{
  public:
    using Params = SimpleObjectParams;
    static gem5::SimpleObject *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySimpleObjectShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SimpleObjectParams &>::value>>
{
  public:
    using Params = DummySimpleObjectParamsClass;
    static gem5::SimpleObject *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SimpleObject *
DummySimpleObjectShunt<gem5::SimpleObject>::Params::create() const
{
    return DummySimpleObjectShunt<gem5::SimpleObject>::
        create(*this);
}

} // namespace gem5
