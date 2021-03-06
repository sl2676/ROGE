/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SEWorkload.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "sim/se_workload.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SEWorkload");
    py::class_<SEWorkloadParams, WorkloadParams, std::unique_ptr<SEWorkloadParams, py::nodelete>>(m, "SEWorkloadParams")
        .def(py::init<>())
        .def("create", &SEWorkloadParams::create)
        ;

    py::class_<gem5::SEWorkload, gem5::Workload, std::unique_ptr<gem5::SEWorkload, py::nodelete>>(m, "gem5_COLONS_SEWorkload")
        ;

}

static EmbeddedPyBind embed_obj("SEWorkload", module_init, "Workload");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySEWorkloadParamsClass
{
  public:
    gem5::SEWorkload *create() const;
};

template <class CxxClass, class Enable=void>
class DummySEWorkloadShunt;

template <class CxxClass>
class DummySEWorkloadShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SEWorkloadParams &>::value>>
{
  public:
    using Params = SEWorkloadParams;
    static gem5::SEWorkload *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySEWorkloadShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SEWorkloadParams &>::value>>
{
  public:
    using Params = DummySEWorkloadParamsClass;
    static gem5::SEWorkload *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SEWorkload *
DummySEWorkloadShunt<gem5::SEWorkload>::Params::create() const
{
    return DummySEWorkloadShunt<gem5::SEWorkload>::
        create(*this);
}

} // namespace gem5
