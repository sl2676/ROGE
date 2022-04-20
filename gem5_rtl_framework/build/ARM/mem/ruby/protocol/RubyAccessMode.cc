/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:836
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/RubyAccessMode.hh"

namespace gem5
{

namespace ruby
{

// Code for output operator
::std::ostream&
operator<<(::std::ostream& out, const RubyAccessMode& obj)
{
    out << RubyAccessMode_to_string(obj);
    out << ::std::flush;
    return out;
}

// Code to convert state to a string
std::string
RubyAccessMode_to_string(const RubyAccessMode& obj)
{
    switch(obj) {
      case RubyAccessMode_Supervisor:
        return "Supervisor";
      case RubyAccessMode_User:
        return "User";
      case RubyAccessMode_Device:
        return "Device";
      default:
        panic("Invalid range for type RubyAccessMode");
    }
    // Appease the compiler since this function has a return value
    return "";
}

// Code to convert from a string to the enumeration
RubyAccessMode
string_to_RubyAccessMode(const std::string& str)
{
    if (str == "Supervisor") {
        return RubyAccessMode_Supervisor;
    } else if (str == "User") {
        return RubyAccessMode_User;
    } else if (str == "Device") {
        return RubyAccessMode_Device;
    } else {
        panic("Invalid string conversion for %s, type RubyAccessMode", str);
    }
}

// Code to increment an enumeration type
RubyAccessMode&
operator++(RubyAccessMode& e)
{
    assert(e < RubyAccessMode_NUM);
    return e = RubyAccessMode(e+1);
}
} // namespace ruby
} // namespace gem5