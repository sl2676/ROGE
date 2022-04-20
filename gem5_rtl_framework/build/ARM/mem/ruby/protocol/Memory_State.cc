/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:836
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/Memory_State.hh"

namespace gem5
{

namespace ruby
{

// Code to convert the current state to an access permission
AccessPermission Memory_State_to_permission(const Memory_State& obj)
{
    switch(obj) {
      case Memory_State_READY:
        return AccessPermission_Backing_Store;
      case Memory_State_WAITING_NET_DATA:
        return AccessPermission_Backing_Store_Busy;
      case Memory_State_SENDING_NET_DATA:
        return AccessPermission_Backing_Store_Busy;
      case Memory_State_READING_MEM:
        return AccessPermission_Backing_Store_Busy;
      case Memory_State_null:
        return AccessPermission_Backing_Store;
      default:
        panic("Unknown state access permission converstion for Memory_State");
    }
    // Appease the compiler since this function has a return value
    return AccessPermission_Invalid;
}

} // namespace ruby
} // namespace gem5

namespace gem5
{

namespace ruby
{

// Code for output operator
::std::ostream&
operator<<(::std::ostream& out, const Memory_State& obj)
{
    out << Memory_State_to_string(obj);
    out << ::std::flush;
    return out;
}

// Code to convert state to a string
std::string
Memory_State_to_string(const Memory_State& obj)
{
    switch(obj) {
      case Memory_State_READY:
        return "READY";
      case Memory_State_WAITING_NET_DATA:
        return "WAITING_NET_DATA";
      case Memory_State_SENDING_NET_DATA:
        return "SENDING_NET_DATA";
      case Memory_State_READING_MEM:
        return "READING_MEM";
      case Memory_State_null:
        return "null";
      default:
        panic("Invalid range for type Memory_State");
    }
    // Appease the compiler since this function has a return value
    return "";
}

// Code to convert from a string to the enumeration
Memory_State
string_to_Memory_State(const std::string& str)
{
    if (str == "READY") {
        return Memory_State_READY;
    } else if (str == "WAITING_NET_DATA") {
        return Memory_State_WAITING_NET_DATA;
    } else if (str == "SENDING_NET_DATA") {
        return Memory_State_SENDING_NET_DATA;
    } else if (str == "READING_MEM") {
        return Memory_State_READING_MEM;
    } else if (str == "null") {
        return Memory_State_null;
    } else {
        panic("Invalid string conversion for %s, type Memory_State", str);
    }
}

// Code to increment an enumeration type
Memory_State&
operator++(Memory_State& e)
{
    assert(e < Memory_State_NUM);
    return e = Memory_State(e+1);
}
} // namespace ruby
} // namespace gem5
