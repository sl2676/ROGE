/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:454
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/Cache_RetryTriggerMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

namespace gem5
{

namespace ruby
{

/** \brief Print the state of this object */
void
Cache_RetryTriggerMsg::print(std::ostream& out) const
{
    out << "[Cache_RetryTriggerMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "event = " << m_event << " ";
    out << "retryDest = " << m_retryDest << " ";
    out << "]";
}
bool
Cache_RetryTriggerMsg::functionalRead(Packet* param_pkt)
{
return (false);

}
bool
Cache_RetryTriggerMsg::functionalRead(Packet* param_pkt, WriteMask& param_mask)
{
return (false);

}
bool
Cache_RetryTriggerMsg::functionalWrite(Packet* param_pkt)
{
return (false);

}
} // namespace ruby
} // namespace gem5
