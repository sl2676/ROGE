/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:454
 */

#include <iostream>
#include <memory>

#include "mem/ruby/protocol/CHIResponseMsg.hh"
#include "mem/ruby/system/RubySystem.hh"

namespace gem5
{

namespace ruby
{

/** \brief Print the state of this object */
void
CHIResponseMsg::print(std::ostream& out) const
{
    out << "[CHIResponseMsg: ";
    out << "addr = " << printAddress(m_addr) << " ";
    out << "type = " << m_type << " ";
    out << "responder = " << m_responder << " ";
    out << "Destination = " << m_Destination << " ";
    out << "stale = " << m_stale << " ";
    out << "MessageSize = " << m_MessageSize << " ";
    out << "]";
}
bool
CHIResponseMsg::functionalRead(Packet* param_pkt)
{
return (false);

}
bool
CHIResponseMsg::functionalRead(Packet* param_pkt, WriteMask& param_mask)
{
return (false);

}
bool
CHIResponseMsg::functionalWrite(Packet* param_pkt)
{
return (false);

}
} // namespace ruby
} // namespace gem5
