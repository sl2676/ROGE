/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:454
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/L1Cache_TBE.hh"
#include "mem/ruby/system/RubySystem.hh"

namespace gem5
{

namespace ruby
{

/** \brief Print the state of this object */
void
L1Cache_TBE::print(std::ostream& out) const
{
    out << "[L1Cache_TBE: ";
    out << "TBEState = " << m_TBEState << " ";
    out << "DataBlk = " << m_DataBlk << " ";
    out << "]";
}
} // namespace ruby
} // namespace gem5
