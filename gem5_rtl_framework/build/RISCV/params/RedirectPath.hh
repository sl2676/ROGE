/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__RedirectPath__
#define __PARAMS__RedirectPath__

namespace gem5 {
class RedirectPath;
} // namespace gem5
#include <cstddef>
#include <string>
#include <vector>
#include <string>

#include "params/SimObject.hh"

namespace gem5
{
struct RedirectPathParams
    : public SimObjectParams
{
    gem5::RedirectPath * create() const;
    std::string app_path;
    std::vector< std::string > host_paths;
};

} // namespace gem5

#endif // __PARAMS__RedirectPath__
