/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/EtherDump.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/net/etherdump.hh"

#include <string>
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_EtherDump");
    py::class_<EtherDumpParams, SimObjectParams, std::unique_ptr<EtherDumpParams, py::nodelete>>(m, "EtherDumpParams")
        .def(py::init<>())
        .def("create", &EtherDumpParams::create)
        .def_readwrite("file", &EtherDumpParams::file)
        .def_readwrite("maxlen", &EtherDumpParams::maxlen)
        ;

    py::class_<gem5::EtherDump, gem5::SimObject, std::unique_ptr<gem5::EtherDump, py::nodelete>>(m, "gem5_COLONS_EtherDump")
        ;

}

static EmbeddedPyBind embed_obj("EtherDump", module_init, "SimObject");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyEtherDumpParamsClass
{
  public:
    gem5::EtherDump *create() const;
};

template <class CxxClass, class Enable=void>
class DummyEtherDumpShunt;

template <class CxxClass>
class DummyEtherDumpShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const EtherDumpParams &>::value>>
{
  public:
    using Params = EtherDumpParams;
    static gem5::EtherDump *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyEtherDumpShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const EtherDumpParams &>::value>>
{
  public:
    using Params = DummyEtherDumpParamsClass;
    static gem5::EtherDump *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::EtherDump *
DummyEtherDumpShunt<gem5::EtherDump>::Params::create() const
{
    return DummyEtherDumpShunt<gem5::EtherDump>::
        create(*this);
}

} // namespace gem5
