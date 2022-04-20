/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:836
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/HtmCallbackMode.hh"

namespace gem5
{

namespace ruby
{

// Code for output operator
::std::ostream&
operator<<(::std::ostream& out, const HtmCallbackMode& obj)
{
    out << HtmCallbackMode_to_string(obj);
    out << ::std::flush;
    return out;
}

// Code to convert state to a string
std::string
HtmCallbackMode_to_string(const HtmCallbackMode& obj)
{
    switch(obj) {
      case HtmCallbackMode_HTM_CMD:
        return "HTM_CMD";
      case HtmCallbackMode_LD_FAIL:
        return "LD_FAIL";
      case HtmCallbackMode_ST_FAIL:
        return "ST_FAIL";
      default:
        panic("Invalid range for type HtmCallbackMode");
    }
    // Appease the compiler since this function has a return value
    return "";
}

// Code to convert from a string to the enumeration
HtmCallbackMode
string_to_HtmCallbackMode(const std::string& str)
{
    if (str == "HTM_CMD") {
        return HtmCallbackMode_HTM_CMD;
    } else if (str == "LD_FAIL") {
        return HtmCallbackMode_LD_FAIL;
    } else if (str == "ST_FAIL") {
        return HtmCallbackMode_ST_FAIL;
    } else {
        panic("Invalid string conversion for %s, type HtmCallbackMode", str);
    }
}

// Code to increment an enumeration type
HtmCallbackMode&
operator++(HtmCallbackMode& e)
{
    assert(e < HtmCallbackMode_NUM);
    return e = HtmCallbackMode(e+1);
}
} // namespace ruby
} // namespace gem5
