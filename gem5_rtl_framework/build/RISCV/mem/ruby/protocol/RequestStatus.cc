/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:836
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/RequestStatus.hh"

namespace gem5
{

namespace ruby
{

// Code for output operator
::std::ostream&
operator<<(::std::ostream& out, const RequestStatus& obj)
{
    out << RequestStatus_to_string(obj);
    out << ::std::flush;
    return out;
}

// Code to convert state to a string
std::string
RequestStatus_to_string(const RequestStatus& obj)
{
    switch(obj) {
      case RequestStatus_Ready:
        return "Ready";
      case RequestStatus_Issued:
        return "Issued";
      case RequestStatus_BufferFull:
        return "BufferFull";
      case RequestStatus_Aliased:
        return "Aliased";
      case RequestStatus_NULL:
        return "NULL";
      default:
        panic("Invalid range for type RequestStatus");
    }
    // Appease the compiler since this function has a return value
    return "";
}

// Code to convert from a string to the enumeration
RequestStatus
string_to_RequestStatus(const std::string& str)
{
    if (str == "Ready") {
        return RequestStatus_Ready;
    } else if (str == "Issued") {
        return RequestStatus_Issued;
    } else if (str == "BufferFull") {
        return RequestStatus_BufferFull;
    } else if (str == "Aliased") {
        return RequestStatus_Aliased;
    } else if (str == "NULL") {
        return RequestStatus_NULL;
    } else {
        panic("Invalid string conversion for %s, type RequestStatus", str);
    }
}

// Code to increment an enumeration type
RequestStatus&
operator++(RequestStatus& e)
{
    assert(e < RequestStatus_NUM);
    return e = RequestStatus(e+1);
}
} // namespace ruby
} // namespace gem5