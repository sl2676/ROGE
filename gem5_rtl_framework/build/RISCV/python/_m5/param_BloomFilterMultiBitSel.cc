/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/BloomFilterMultiBitSel.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "base/filters/multi_bit_sel_bloom_filter.hh"

#include "base/types.hh"
#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_BloomFilterMultiBitSel");
    py::class_<BloomFilterMultiBitSelParams, BloomFilterBaseParams, std::unique_ptr<BloomFilterMultiBitSelParams, py::nodelete>>(m, "BloomFilterMultiBitSelParams")
        .def(py::init<>())
        .def("create", &BloomFilterMultiBitSelParams::create)
        .def_readwrite("is_parallel", &BloomFilterMultiBitSelParams::is_parallel)
        .def_readwrite("num_hashes", &BloomFilterMultiBitSelParams::num_hashes)
        .def_readwrite("skip_bits", &BloomFilterMultiBitSelParams::skip_bits)
        ;

    py::class_<gem5::bloom_filter::MultiBitSel, gem5::bloom_filter::Base, std::unique_ptr<gem5::bloom_filter::MultiBitSel, py::nodelete>>(m, "gem5_COLONS_bloom_filter_COLONS_MultiBitSel")
        ;

}

static EmbeddedPyBind embed_obj("BloomFilterMultiBitSel", module_init, "BloomFilterBase");

} // namespace gem5

namespace gem5
{

namespace
{

class DummyBloomFilterMultiBitSelParamsClass
{
  public:
    gem5::bloom_filter::MultiBitSel *create() const;
};

template <class CxxClass, class Enable=void>
class DummyBloomFilterMultiBitSelShunt;

template <class CxxClass>
class DummyBloomFilterMultiBitSelShunt<CxxClass, std::enable_if_t<
    std::is_constructible<CxxClass,
        const BloomFilterMultiBitSelParams &>::value>>
{
  public:
    using Params = BloomFilterMultiBitSelParams;
    static gem5::bloom_filter::MultiBitSel *
    create(const Params &p)
    {
        return new CxxClass(p);
    }
};

template <class CxxClass>
class DummyBloomFilterMultiBitSelShunt<CxxClass, std::enable_if_t<
    !std::is_constructible<CxxClass,
        const BloomFilterMultiBitSelParams &>::value>>
{
  public:
    using Params = DummyBloomFilterMultiBitSelParamsClass;
    static gem5::bloom_filter::MultiBitSel *
    create(const Params &p)
    {
        return nullptr;
    }
};

} // anonymous namespace

GEM5_VAR_USED gem5::bloom_filter::MultiBitSel *
DummyBloomFilterMultiBitSelShunt<gem5::bloom_filter::MultiBitSel>::Params::create() const
{
    return DummyBloomFilterMultiBitSelShunt<gem5::bloom_filter::MultiBitSel>::
        create(*this);
}

} // namespace gem5