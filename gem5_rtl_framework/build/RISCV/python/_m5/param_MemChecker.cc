/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MemChecker.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/mem_checker.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MemChecker");
    py::class_<MemCheckerParams, SimObjectParams, std::unique_ptr<MemCheckerParams, py::nodelete>>(m, "MemCheckerParams")
        .def(py::init<>())
        .def("create", &MemCheckerParams::create)
        ;

    py::class_<gem5::MemChecker, gem5::SimObject, std::unique_ptr<gem5::MemChecker, py::nodelete>>(m, "gem5_COLONS_MemChecker")
        ;

}

static EmbeddedPyBind embed_obj("MemChecker", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMemCheckerParamsClass
{
  public:
    gem5::MemChecker *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMemCheckerShunt;

template <class CxxClass>
class DummyMemCheckerShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MemCheckerParams &>::value>>
{
  public:
    using Params = MemCheckerParams;
    static gem5::MemChecker *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMemCheckerShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MemCheckerParams &>::value>>
{
  public:
    using Params = DummyMemCheckerParamsClass;
    static gem5::MemChecker *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::MemChecker *
DummyMemCheckerShunt<gem5::MemChecker>::Params::create() const
{
    return DummyMemCheckerShunt<gem5::MemChecker>::
        create(*this);
}

} // namespace gem5