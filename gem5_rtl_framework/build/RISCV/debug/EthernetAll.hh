/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1248
 */

#ifndef __DEBUG_EthernetAll_HH__
#define __DEBUG_EthernetAll_HH__

#include "base/compiler.hh" // For namespace deprecation

namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Debug, debug);
namespace debug
{
class CompoundFlag;
class SimpleFlag;
extern CompoundFlag& EthernetAll;
extern SimpleFlag& Ethernet;
extern SimpleFlag& EthernetPIO;
extern SimpleFlag& EthernetDMA;
extern SimpleFlag& EthernetData;
extern SimpleFlag& EthernetDesc;
extern SimpleFlag& EthernetIntr;
extern SimpleFlag& EthernetSM;
extern SimpleFlag& EthernetCksum;
extern SimpleFlag& EthernetEEPROM;
} // namespace debug
} // namespace gem5

#endif // __DEBUG_EthernetAll_HH__
