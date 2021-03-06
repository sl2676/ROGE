/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1034
 */

#include "pybind11/pybind11.h"
#include "pybind11/stl.h"

#include <type_traits>

#include "base/compiler.hh"
#include "params/BaseReplacementPolicy.hh"
#include "python/pybind11/core.hh"
#include "sim/init.hh"
#include "sim/sim_object.hh"

#include "mem/cache/replacement_policies/base.hh"

namespace py = pybind11;

namespace gem5
{

static void
module_init(py::module_ &m_internal)
{
    py::module_ m = m_internal.def_submodule("param_BaseReplacementPolicy");
    py::class_<BaseReplacementPolicyParams, SimObjectParams, std::unique_ptr<BaseReplacementPolicyParams, py::nodelete>>(m, "BaseReplacementPolicyParams")
        ;

    py::class_<gem5::replacement_policy::Base, gem5::SimObject, std::unique_ptr<gem5::replacement_policy::Base, py::nodelete>>(m, "gem5_COLONS_replacement_policy_COLONS_Base")
        ;

}

static EmbeddedPyBind embed_obj("BaseReplacementPolicy", module_init, "SimObject");

} // namespace gem5
