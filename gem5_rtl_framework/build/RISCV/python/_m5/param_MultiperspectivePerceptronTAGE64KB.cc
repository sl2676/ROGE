/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/MultiperspectivePerceptronTAGE64KB.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/pred/multiperspective_perceptron_tage_64KB.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_MultiperspectivePerceptronTAGE64KB");
    py::class_<MultiperspectivePerceptronTAGE64KBParams, MultiperspectivePerceptronTAGEParams, std::unique_ptr<MultiperspectivePerceptronTAGE64KBParams, py::nodelete>>(m, "MultiperspectivePerceptronTAGE64KBParams")
        .def(py::init<>())
        .def("create", &MultiperspectivePerceptronTAGE64KBParams::create)
        ;

    py::class_<gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB, gem5::branch_prediction::MultiperspectivePerceptronTAGE, std::unique_ptr<gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB, py::nodelete>>(m, "gem5_COLONS_branch_prediction_COLONS_MultiperspectivePerceptronTAGE64KB")
        ;

}

static EmbeddedPyBind embed_obj("MultiperspectivePerceptronTAGE64KB", module_init, "MultiperspectivePerceptronTAGE");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyMultiperspectivePerceptronTAGE64KBParamsClass
{
  public:
    gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB *create() const;
};

template <class CxxClass, class Enable=void>
class DummyMultiperspectivePerceptronTAGE64KBShunt;

template <class CxxClass>
class DummyMultiperspectivePerceptronTAGE64KBShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const MultiperspectivePerceptronTAGE64KBParams &>::value>>
{
  public:
    using Params = MultiperspectivePerceptronTAGE64KBParams;
    static gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyMultiperspectivePerceptronTAGE64KBShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const MultiperspectivePerceptronTAGE64KBParams &>::value>>
{
  public:
    using Params = DummyMultiperspectivePerceptronTAGE64KBParamsClass;
    static gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB *
DummyMultiperspectivePerceptronTAGE64KBShunt<gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB>::Params::create() const
{
    return DummyMultiperspectivePerceptronTAGE64KBShunt<gem5::branch_prediction::MultiperspectivePerceptronTAGE64KB>::
        create(*this);
}

} // namespace gem5
