/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1012
 */

#include "base/compiler.hh"
#include "enums/ScopedEnum.hh"

namespace gem5
{

const char *ScopedEnumStrings[static_cast<int>(ScopedEnum::Num_ScopedEnum)] =
{
};
} // namespace gem5
#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <sim/init.hh>

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("enum_ScopedEnum");

py::enum_<ScopedEnum>(m, "enum_ScopedEnum")
        .value("Num_ScopedEnum", ScopedEnum::Num_ScopedEnum)
        ;
    }

static EmbeddedPyBind embed_enum("enum_ScopedEnum", module_init);

} // namespace gem5
