/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/RawDiskImage.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "dev/storage/disk_image.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_RawDiskImage");
    py::class_<RawDiskImageParams, DiskImageParams, std::unique_ptr<RawDiskImageParams, py::nodelete>>(m, "RawDiskImageParams")
        .def(py::init<>())
        .def("create", &RawDiskImageParams::create)
        ;

    py::class_<gem5::RawDiskImage, gem5::DiskImage, std::unique_ptr<gem5::RawDiskImage, py::nodelete>>(m, "gem5_COLONS_RawDiskImage")
        ;

}

static EmbeddedPyBind embed_obj("RawDiskImage", module_init, "DiskImage");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyRawDiskImageParamsClass
{
  public:
    gem5::RawDiskImage *create() const;
};

template <class CxxClass, class Enable=void>
class DummyRawDiskImageShunt;

template <class CxxClass>
class DummyRawDiskImageShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const RawDiskImageParams &>::value>>
{
  public:
    using Params = RawDiskImageParams;
    static gem5::RawDiskImage *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyRawDiskImageShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const RawDiskImageParams &>::value>>
{
  public:
    using Params = DummyRawDiskImageParamsClass;
    static gem5::RawDiskImage *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::RawDiskImage *
DummyRawDiskImageShunt<gem5::RawDiskImage>::Params::create() const
{
    return DummyRawDiskImageShunt<gem5::RawDiskImage>::
        create(*this);
}

} // namespace gem5
