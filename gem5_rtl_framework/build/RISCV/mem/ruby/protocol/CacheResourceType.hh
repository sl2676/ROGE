/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5_rtl_framework/src/mem/slicc/symbols/Type.py:576
 */

#ifndef __CacheResourceType_HH__
#define __CacheResourceType_HH__

#include <iostream>
#include <string>

namespace gem5
{

namespace ruby
{


// Class definition
/** \enum CacheResourceType
 *  \brief ...
 */
enum CacheResourceType {
    CacheResourceType_FIRST,
    CacheResourceType_DataArray = CacheResourceType_FIRST, /**< Access to the cache's data array */
    CacheResourceType_TagArray, /**< Access to the cache's tag array */
    CacheResourceType_NUM
};

// Code to convert from a string to the enumeration
CacheResourceType string_to_CacheResourceType(const ::std::string& str);

// Code to convert state to a string
::std::string CacheResourceType_to_string(const CacheResourceType& obj);

// Code to increment an enumeration type
CacheResourceType &operator++(CacheResourceType &e);

::std::ostream&
operator<<(::std::ostream& out, const CacheResourceType& obj);

} // namespace ruby
} // namespace gem5
#endif // __CacheResourceType_HH__
