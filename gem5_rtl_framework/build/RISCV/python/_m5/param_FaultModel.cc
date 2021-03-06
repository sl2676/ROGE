/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/FaultModel.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/ruby/network/fault_model/FaultModel.hh"

#include <vector>
#include <vector>
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_FaultModel");
    py::class_<FaultModelParams, SimObjectParams, std::unique_ptr<FaultModelParams, py::nodelete>>(m, "FaultModelParams")
        .def(py::init<>())
        .def("create", &FaultModelParams::create)
        .def_readwrite("baseline_fault_vector_database", &FaultModelParams::baseline_fault_vector_database)
        .def_readwrite("temperature_weights_database", &FaultModelParams::temperature_weights_database)
        ;

    py::class_<gem5::ruby::FaultModel, gem5::SimObject, std::unique_ptr<gem5::ruby::FaultModel, py::nodelete>>(m, "gem5_COLONS_ruby_COLONS_FaultModel")
        ;

}

static EmbeddedPyBind embed_obj("FaultModel", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyFaultModelParamsClass
{
  public:
    gem5::ruby::FaultModel *create() const;
};

template <class CxxClass, class Enable=void>
class DummyFaultModelShunt;

template <class CxxClass>
class DummyFaultModelShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const FaultModelParams &>::value>>
{
  public:
    using Params = FaultModelParams;
    static gem5::ruby::FaultModel *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyFaultModelShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const FaultModelParams &>::value>>
{
  public:
    using Params = DummyFaultModelParamsClass;
    static gem5::ruby::FaultModel *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::ruby::FaultModel *
DummyFaultModelShunt<gem5::ruby::FaultModel>::Params::create() const
{
    return DummyFaultModelShunt<gem5::ruby::FaultModel>::
        create(*this);
}

} // namespace gem5
