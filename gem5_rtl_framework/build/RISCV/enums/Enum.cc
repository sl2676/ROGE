/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1012
 */

#include "base/compiler.hh"
#include "enums/Enum.hh"

namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Enums, enums);
namespace enums
{
    const char *EnumStrings[Num_Enum] =
    {
    };
} // namespace enums
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
    py::module_ m = m_internal.def_submodule("enum_Enum");

py::enum_<enums::Enum>(m, "enum_Enum")
        .value("Num_Enum", enums::Num_Enum)
        .export_values()
        ;
    }

static EmbeddedPyBind embed_enum("enum_Enum", module_init);

} // namespace gem5
