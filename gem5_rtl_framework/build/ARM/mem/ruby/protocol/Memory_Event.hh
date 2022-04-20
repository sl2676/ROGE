/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:576
 */

#ifndef __Memory_Event_HH__
#define __Memory_Event_HH__

#include <iostream>
#include <string>

namespace gem5
{

namespace ruby
{


// Class definition
/** \enum Memory_Event
 *  \brief Memory events
 */
enum Memory_Event {
    Memory_Event_FIRST,
    Memory_Event_CheckAllocTBE = Memory_Event_FIRST, /**<  */
    Memory_Event_CheckAllocTBE_WithCredit, /**<  */
    Memory_Event_WriteNoSnpPtl, /**<  */
    Memory_Event_WriteNoSnp, /**<  */
    Memory_Event_ReadNoSnp, /**<  */
    Memory_Event_ReadNoSnpSep, /**<  */
    Memory_Event_WriteData, /**<  */
    Memory_Event_MemoryData, /**<  */
    Memory_Event_MemoryAck, /**<  */
    Memory_Event_Trigger_Send, /**<  */
    Memory_Event_Trigger_SendDone, /**<  */
    Memory_Event_Trigger_ReceiveDone, /**<  */
    Memory_Event_Trigger_SendRetry, /**<  */
    Memory_Event_Trigger_SendPCrdGrant, /**<  */
    Memory_Event_NUM
};

// Code to convert from a string to the enumeration
Memory_Event string_to_Memory_Event(const ::std::string& str);

// Code to convert state to a string
::std::string Memory_Event_to_string(const Memory_Event& obj);

// Code to increment an enumeration type
Memory_Event &operator++(Memory_Event &e);

::std::ostream&
operator<<(::std::ostream& out, const Memory_Event& obj);

} // namespace ruby
} // namespace gem5
#endif // __Memory_Event_HH__