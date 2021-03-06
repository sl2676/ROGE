/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/GoodbyeObject.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/goodbye_object.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_GoodbyeObject");
    py::class_<GoodbyeObjectParams, SimObjectParams, std::unique_ptr<GoodbyeObjectParams, py::nodelete>>(m, "GoodbyeObjectParams")
        .def(py::init<>())
        .def("create", &GoodbyeObjectParams::create)
        .def_readwrite("buffer_size", &GoodbyeObjectParams::buffer_size)
        .def_readwrite("write_bandwidth", &GoodbyeObjectParams::write_bandwidth)
        ;

    py::class_<gem5::GoodbyeObject, gem5::SimObject, std::unique_ptr<gem5::GoodbyeObject, py::nodelete>>(m, "gem5_COLONS_GoodbyeObject")
        ;

}

static EmbeddedPyBind embed_obj("GoodbyeObject", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyGoodbyeObjectParamsClass
{
  public:
    gem5::GoodbyeObject *create() const;
};

template <class CxxClass, class Enable=void>
class DummyGoodbyeObjectShunt;

template <class CxxClass>
class DummyGoodbyeObjectShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const GoodbyeObjectParams &>::value>>
{
  public:
    using Params = GoodbyeObjectParams;
    static gem5::GoodbyeObject *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyGoodbyeObjectShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const GoodbyeObjectParams &>::value>>
{
  public:
    using Params = DummyGoodbyeObjectParamsClass;
    static gem5::GoodbyeObject *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::GoodbyeObject *
DummyGoodbyeObjectShunt<gem5::GoodbyeObject>::Params::create() const
{
    return DummyGoodbyeObjectShunt<gem5::GoodbyeObject>::
        create(*this);
}

} // namespace gem5
