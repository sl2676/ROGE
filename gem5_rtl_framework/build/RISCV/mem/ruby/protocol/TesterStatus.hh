/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:576
 */

#ifndef __TesterStatus_HH__
#define __TesterStatus_HH__

#include <iostream>
#include <string>

namespace gem5
{

namespace ruby
{


// Class definition
/** \enum TesterStatus
 *  \brief ...
 */
enum TesterStatus {
    TesterStatus_FIRST,
    TesterStatus_Idle = TesterStatus_FIRST, /**< Idle */
    TesterStatus_Action_Pending, /**< Action Pending */
    TesterStatus_Ready, /**< Ready */
    TesterStatus_Check_Pending, /**< Check Pending */
    TesterStatus_NUM
};

// Code to convert from a string to the enumeration
TesterStatus string_to_TesterStatus(const ::std::string& str);

// Code to convert state to a string
::std::string TesterStatus_to_string(const TesterStatus& obj);

// Code to increment an enumeration type
TesterStatus &operator++(TesterStatus &e);

::std::ostream&
operator<<(::std::ostream& out, const TesterStatus& obj);

} // namespace ruby
} // namespace gem5
#endif // __TesterStatus_HH__
