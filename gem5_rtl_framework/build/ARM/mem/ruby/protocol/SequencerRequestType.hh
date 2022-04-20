/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/src/mem/slicc/symbols/Type.py:576
 */

#ifndef __SequencerRequestType_HH__
#define __SequencerRequestType_HH__

#include <iostream>
#include <string>

namespace gem5
{

namespace ruby
{


// Class definition
/** \enum SequencerRequestType
 *  \brief ...
 */
enum SequencerRequestType {
    SequencerRequestType_FIRST,
    SequencerRequestType_Default = SequencerRequestType_FIRST, /**< Replace this with access_types passed to the DMA Ruby object */
    SequencerRequestType_LD, /**< Load */
    SequencerRequestType_ST, /**< Store */
    SequencerRequestType_ATOMIC, /**< Atomic Load/Store */
    SequencerRequestType_REPLACEMENT, /**< Replacement */
    SequencerRequestType_FLUSH, /**< Flush request type */
    SequencerRequestType_NULL, /**< Invalid request type */
    SequencerRequestType_NUM
};

// Code to convert from a string to the enumeration
SequencerRequestType string_to_SequencerRequestType(const ::std::string& str);

// Code to convert state to a string
::std::string SequencerRequestType_to_string(const SequencerRequestType& obj);

// Code to increment an enumeration type
SequencerRequestType &operator++(SequencerRequestType &e);

::std::ostream&
operator<<(::std::ostream& out, const SequencerRequestType& obj);

} // namespace ruby
} // namespace gem5
#endif // __SequencerRequestType_HH__
