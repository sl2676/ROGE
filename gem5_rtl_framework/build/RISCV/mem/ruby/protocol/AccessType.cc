/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:836
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/AccessType.hh"

namespace gem5
{

namespace ruby
{

// Code for output operator
::std::ostream&
operator<<(::std::ostream& out, const AccessType& obj)
{
    out << AccessType_to_string(obj);
    out << ::std::flush;
    return out;
}

// Code to convert state to a string
std::string
AccessType_to_string(const AccessType& obj)
{
    switch(obj) {
      case AccessType_Read:
        return "Read";
      case AccessType_Write:
        return "Write";
      default:
        panic("Invalid range for type AccessType");
    }
    // Appease the compiler since this function has a return value
    return "";
}

// Code to convert from a string to the enumeration
AccessType
string_to_AccessType(const std::string& str)
{
    if (str == "Read") {
        return AccessType_Read;
    } else if (str == "Write") {
        return AccessType_Write;
    } else {
        panic("Invalid string conversion for %s, type AccessType", str);
    }
}

// Code to increment an enumeration type
AccessType&
operator++(AccessType& e)
{
    assert(e < AccessType_NUM);
    return e = AccessType(e+1);
}
} // namespace ruby
} // namespace gem5
