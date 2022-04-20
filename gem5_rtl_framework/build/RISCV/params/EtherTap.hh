/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__EtherTap__
#define __PARAMS__EtherTap__

namespace gem5 {
class EtherTap;
} // namespace gem5
#include <cstddef>
#include <string>
#include <cstddef>
#include <string>

#include "params/EtherTapBase.hh"

namespace gem5
{
struct EtherTapParams
    : public EtherTapBaseParams
{
    gem5::EtherTap * create() const;
    std::string tap_device_name;
    std::string tun_clone_device;
};

} // namespace gem5

#endif // __PARAMS__EtherTap__
