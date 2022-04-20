/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/PyTrafficGen.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "cpu/testers/traffic_gen/pygen.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_PyTrafficGen");
    py::class_<PyTrafficGenParams, BaseTrafficGenParams, std::unique_ptr<PyTrafficGenParams, py::nodelete>>(m, "PyTrafficGenParams")
        .def(py::init<>())
        .def("create", &PyTrafficGenParams::create)
        ;

    py::class_<gem5::PyTrafficGen, gem5::BaseTrafficGen, std::unique_ptr<gem5::PyTrafficGen, py::nodelete>>(m, "gem5_COLONS_PyTrafficGen")
        .def("createIdle", &gem5::PyTrafficGen::createIdle)
        .def("createExit", &gem5::PyTrafficGen::createExit)
        .def("createLinear", &gem5::PyTrafficGen::createLinear)
        .def("createRandom", &gem5::PyTrafficGen::createRandom)
        .def("createDram", &gem5::PyTrafficGen::createDram)
        .def("createDramRot", &gem5::PyTrafficGen::createDramRot)
        .def("createHybrid", &gem5::PyTrafficGen::createHybrid)
        .def("createNvm", &gem5::PyTrafficGen::createNvm)
        .def("createStrided", &gem5::PyTrafficGen::createStrided)
        .def("start", &gem5::PyTrafficGen::start, py::arg("meta_generator"))
        .def("createTrace", &gem5::PyTrafficGen::createTrace, py::arg("duration"), py::arg("trace_file"), py::arg("addr_offset") = 0)
        ;

}

static EmbeddedPyBind embed_obj("PyTrafficGen", module_init, "BaseTrafficGen");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyPyTrafficGenParamsClass
{
  public:
    gem5::PyTrafficGen *create() const;
};

template <class CxxClass, class Enable=void>
class DummyPyTrafficGenShunt;

template <class CxxClass>
class DummyPyTrafficGenShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const PyTrafficGenParams &>::value>>
{
  public:
    using Params = PyTrafficGenParams;
    static gem5::PyTrafficGen *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyPyTrafficGenShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const PyTrafficGenParams &>::value>>
{
  public:
    using Params = DummyPyTrafficGenParamsClass;
    static gem5::PyTrafficGen *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::PyTrafficGen *
DummyPyTrafficGenShunt<gem5::PyTrafficGen>::Params::create() const
{
    return DummyPyTrafficGenShunt<gem5::PyTrafficGen>::
        create(*this);
}

} // namespace gem5