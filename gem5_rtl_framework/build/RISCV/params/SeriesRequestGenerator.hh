/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__SeriesRequestGenerator__
#define __PARAMS__SeriesRequestGenerator__

namespace gem5 {
class SeriesRequestGenerator;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DirectedGenerator.hh"

namespace gem5
{
struct SeriesRequestGeneratorParams
    : public DirectedGeneratorParams
{
    gem5::SeriesRequestGenerator * create() const;
    int addr_increment_size;
    uint32_t num_series;
    int percent_writes;
};

} // namespace gem5

#endif // __PARAMS__SeriesRequestGenerator__