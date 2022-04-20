/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:404
 */

#ifndef __RequestMsg_HH__
#define __RequestMsg_HH__

#include <iostream>

#include "mem/ruby/slicc_interface/RubySlicc_Util.hh"

#include "mem/ruby/protocol/CoherenceRequestType.hh"
#include "mem/ruby/protocol/MachineID.hh"
#include "mem/ruby/protocol/NetDest.hh"
#include "mem/ruby/protocol/DataBlock.hh"
#include "mem/ruby/protocol/MessageSizeType.hh"
#include "mem/ruby/protocol/Message.hh"
namespace gem5
{

namespace ruby
{

class RequestMsg :  public Message
{
  public:
    RequestMsg
(Tick curTime) : Message(curTime) {
        // m_addr has no default
        m_Type = CoherenceRequestType_NUM;
         // default value of CoherenceRequestType
        // m_Requestor has no default
        // m_Destination has no default
        // m_DataBlk has no default
        m_MessageSize = MessageSizeType_NUM;
         // default value of MessageSizeType
    }
    RequestMsg(const RequestMsg&) = default;
    RequestMsg
    &operator=(const RequestMsg&) = default;
    RequestMsg(const Tick curTime, const Addr& local_addr, const CoherenceRequestType& local_Type, const MachineID& local_Requestor, const NetDest& local_Destination, const DataBlock& local_DataBlk, const MessageSizeType& local_MessageSize)
        : Message(curTime)
    {
        m_addr = local_addr;
        m_Type = local_Type;
        m_Requestor = local_Requestor;
        m_Destination = local_Destination;
        m_DataBlk = local_DataBlk;
        m_MessageSize = local_MessageSize;
    }
    MsgPtr
    clone() const
    {
         return std::shared_ptr<Message>(new RequestMsg(*this));
    }
    // Const accessors methods for each field
    /** \brief Const accessor method for addr field.
     *  \return addr field
     */
    const Addr&
    getaddr() const
    {
        return m_addr;
    }
    /** \brief Const accessor method for Type field.
     *  \return Type field
     */
    const CoherenceRequestType&
    getType() const
    {
        return m_Type;
    }
    /** \brief Const accessor method for Requestor field.
     *  \return Requestor field
     */
    const MachineID&
    getRequestor() const
    {
        return m_Requestor;
    }
    /** \brief Const accessor method for Destination field.
     *  \return Destination field
     */
    const NetDest&
    getDestination() const
    {
        return m_Destination;
    }
    /** \brief Const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    const DataBlock&
    getDataBlk() const
    {
        return m_DataBlk;
    }
    /** \brief Const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    const MessageSizeType&
    getMessageSize() const
    {
        return m_MessageSize;
    }
    // Non const Accessors methods for each field
    /** \brief Non-const accessor method for addr field.
     *  \return addr field
     */
    Addr&
    getaddr()
    {
        return m_addr;
    }
    /** \brief Non-const accessor method for Type field.
     *  \return Type field
     */
    CoherenceRequestType&
    getType()
    {
        return m_Type;
    }
    /** \brief Non-const accessor method for Requestor field.
     *  \return Requestor field
     */
    MachineID&
    getRequestor()
    {
        return m_Requestor;
    }
    /** \brief Non-const accessor method for Destination field.
     *  \return Destination field
     */
    NetDest&
    getDestination()
    {
        return m_Destination;
    }
    /** \brief Non-const accessor method for DataBlk field.
     *  \return DataBlk field
     */
    DataBlock&
    getDataBlk()
    {
        return m_DataBlk;
    }
    /** \brief Non-const accessor method for MessageSize field.
     *  \return MessageSize field
     */
    MessageSizeType&
    getMessageSize()
    {
        return m_MessageSize;
    }
    // Mutator methods for each field
    /** \brief Mutator method for addr field */
    void
    setaddr(const Addr& local_addr)
    {
        m_addr = local_addr;
    }
    /** \brief Mutator method for Type field */
    void
    setType(const CoherenceRequestType& local_Type)
    {
        m_Type = local_Type;
    }
    /** \brief Mutator method for Requestor field */
    void
    setRequestor(const MachineID& local_Requestor)
    {
        m_Requestor = local_Requestor;
    }
    /** \brief Mutator method for Destination field */
    void
    setDestination(const NetDest& local_Destination)
    {
        m_Destination = local_Destination;
    }
    /** \brief Mutator method for DataBlk field */
    void
    setDataBlk(const DataBlock& local_DataBlk)
    {
        m_DataBlk = local_DataBlk;
    }
    /** \brief Mutator method for MessageSize field */
    void
    setMessageSize(const MessageSizeType& local_MessageSize)
    {
        m_MessageSize = local_MessageSize;
    }
    void print(std::ostream& out) const;
  //private:
    /** Physical address for this request */
    Addr m_addr;
    /** Type of request (GetS, GetX, PutX, etc) */
    CoherenceRequestType m_Type;
    /** Node who initiated the request */
    MachineID m_Requestor;
    /** Multicast destination mask */
    NetDest m_Destination;
    /** data for the cache line */
    DataBlock m_DataBlk;
    /** size category of the message */
    MessageSizeType m_MessageSize;
    bool functionalRead(Packet* param_pkt);
    bool functionalWrite(Packet* param_pkt);
};
inline ::std::ostream&
operator<<(::std::ostream& out, const RequestMsg& obj)
{
    obj.print(out);
    out << ::std::flush;
    return out;
}

} // namespace ruby
} // namespace gem5

#endif // __RequestMsg_HH__
