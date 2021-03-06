/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/BaseDictionaryCompressor.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/compressors/dictionary_compressor.hh"

#include "base/types.hh"
namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_BaseDictionaryCompressor");
    py::class_<BaseDictionaryCompressorParams, BaseCacheCompressorParams, std::unique_ptr<BaseDictionaryCompressorParams, py::nodelete>>(m, "BaseDictionaryCompressorParams")
        .def_readwrite("dictionary_size", &BaseDictionaryCompressorParams::dictionary_size)
        ;

    py::class_<gem5::compression::BaseDictionaryCompressor, gem5::compression::Base, std::unique_ptr<gem5::compression::BaseDictionaryCompressor, py::nodelete>>(m, "gem5_COLONS_compression_COLONS_BaseDictionaryCompressor")
        ;

}

static EmbeddedPyBind embed_obj("BaseDictionaryCompressor", module_init, "BaseCacheCompressor");

} // namespace gem5
