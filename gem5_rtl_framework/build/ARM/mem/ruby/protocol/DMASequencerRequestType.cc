/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:836
 */

#include <cassert>
#include <iostream>
#include <string>

#include "base/logging.hh"
#include "mem/ruby/protocol/DMASequencerRequestType.hh"

namespace gem5
{

namespace ruby
{

// Code for output operator
::std::ostream&
operator<<(::std::ostream& out, const DMASequencerRequestType& obj)
{
    out << DMASequencerRequestType_to_string(obj);
    out << ::std::flush;
    return out;
}

// Code to convert state to a string
std::string
DMASequencerRequestType_to_string(const DMASequencerRequestType& obj)
{
    switch(obj) {
      case DMASequencerRequestType_Default:
        return "Default";
      default:
        panic("Invalid range for type DMASequencerRequestType");
    }
    // Appease the compiler since this function has a return value
    return "";
}

// Code to convert from a string to the enumeration
DMASequencerRequestType
string_to_DMASequencerRequestType(const std::string& str)
{
    if (str == "Default") {
        return DMASequencerRequestType_Default;
    } else {
        panic("Invalid string conversion for %s, type DMASequencerRequestType", str);
    }
}

// Code to increment an enumeration type
DMASequencerRequestType&
operator++(DMASequencerRequestType& e)
{
    assert(e < DMASequencerRequestType_NUM);
    return e = DMASequencerRequestType(e+1);
}
} // namespace ruby
} // namespace gem5
