/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/QoSPropFairPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/qos/policy_pf.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_QoSPropFairPolicy");
    py::class_<QoSPropFairPolicyParams, QoSPolicyParams, std::unique_ptr<QoSPropFairPolicyParams, py::nodelete>>(m, "QoSPropFairPolicyParams")
        .def(py::init<>())
        .def("create", &QoSPropFairPolicyParams::create)
        .def_readwrite("weight", &QoSPropFairPolicyParams::weight)
        ;

    py::class_<gem5::memory::qos::PropFairPolicy, gem5::memory::qos::Policy, std::unique_ptr<gem5::memory::qos::PropFairPolicy, py::nodelete>>(m, "gem5_COLONS_memory_COLONS_qos_COLONS_PropFairPolicy")
        .def("initRequestorName", &gem5::memory::qos::PropFairPolicy::initRequestorName)
        .def("initRequestorObj", &gem5::memory::qos::PropFairPolicy::initRequestorObj)
        ;

}

static EmbeddedPyBind embed_obj("QoSPropFairPolicy", module_init, "QoSPolicy");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyQoSPropFairPolicyParamsClass
{
  public:
    gem5::memory::qos::PropFairPolicy *create() const;
};

template <class CxxClass, class Enable=void>
class DummyQoSPropFairPolicyShunt;

template <class CxxClass>
class DummyQoSPropFairPolicyShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const QoSPropFairPolicyParams &>::value>>
{
  public:
    using Params = QoSPropFairPolicyParams;
    static gem5::memory::qos::PropFairPolicy *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyQoSPropFairPolicyShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const QoSPropFairPolicyParams &>::value>>
{
  public:
    using Params = DummyQoSPropFairPolicyParamsClass;
    static gem5::memory::qos::PropFairPolicy *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::memory::qos::PropFairPolicy *
DummyQoSPropFairPolicyShunt<gem5::memory::qos::PropFairPolicy>::Params::create() const
{
    return DummyQoSPropFairPolicyShunt<gem5::memory::qos::PropFairPolicy>::
        create(*this);
}

} // namespace gem5
