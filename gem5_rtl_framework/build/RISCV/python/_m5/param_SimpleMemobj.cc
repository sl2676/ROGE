/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/SimpleMemobj.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "learning_gem5/part2/simple_memobj.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_SimpleMemobj");
    py::class_<SimpleMemobjParams, SimObjectParams, std::unique_ptr<SimpleMemobjParams, py::nodelete>>(m, "SimpleMemobjParams")
        .def(py::init<>())
        .def("create", &SimpleMemobjParams::create)
        .def_readwrite("port_inst_port_connection_count", &SimpleMemobjParams::port_inst_port_connection_count)
        .def_readwrite("port_data_port_connection_count", &SimpleMemobjParams::port_data_port_connection_count)
        .def_readwrite("port_mem_side_connection_count", &SimpleMemobjParams::port_mem_side_connection_count)
        ;

    py::class_<gem5::SimpleMemobj, gem5::SimObject, std::unique_ptr<gem5::SimpleMemobj, py::nodelete>>(m, "gem5_COLONS_SimpleMemobj")
        ;

}

static EmbeddedPyBind embed_obj("SimpleMemobj", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummySimpleMemobjParamsClass
{
  public:
    gem5::SimpleMemobj *create() const;
};

template <class CxxClass, class Enable=void>
class DummySimpleMemobjShunt;

template <class CxxClass>
class DummySimpleMemobjShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const SimpleMemobjParams &>::value>>
{
  public:
    using Params = SimpleMemobjParams;
    static gem5::SimpleMemobj *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummySimpleMemobjShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const SimpleMemobjParams &>::value>>
{
  public:
    using Params = DummySimpleMemobjParamsClass;
    static gem5::SimpleMemobj *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::SimpleMemobj *
DummySimpleMemobjShunt<gem5::SimpleMemobj>::Params::create() const
{
    return DummySimpleMemobjShunt<gem5::SimpleMemobj>::
        create(*this);
}

} // namespace gem5
