/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__VncInput__
#define __PARAMS__VncInput__

namespace gem5 {
class VncInput;
} // namespace gem5
#include <cstddef>
#include <cstddef>
#include "enums/ImageFormat.hh"

#include "params/SimObject.hh"

#include "enums/ImageFormat.hh"

namespace gem5
{
struct VncInputParams
    : public SimObjectParams
{
    gem5::VncInput * create() const;
    bool frame_capture;
    enums::ImageFormat img_format;
};

} // namespace gem5

#endif // __PARAMS__VncInput__
