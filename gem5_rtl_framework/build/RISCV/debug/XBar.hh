/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1248
 */

#ifndef __DEBUG_XBar_HH__
#define __DEBUG_XBar_HH__

#include "base/compiler.hh" // For namespace deprecation

namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Debug, debug);
namespace debug
{
class CompoundFlag;
class SimpleFlag;
extern CompoundFlag& XBar;
extern SimpleFlag& BaseXBar;
extern SimpleFlag& CoherentXBar;
extern SimpleFlag& NoncoherentXBar;
extern SimpleFlag& SnoopFilter;
} // namespace debug
} // namespace gem5

#endif // __DEBUG_XBar_HH__
