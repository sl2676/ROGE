/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/ARM/SConscript:987
 */

#ifndef __PARAMS__SEWorkload__
#define __PARAMS__SEWorkload__

namespace gem5 {
class SEWorkload;
} // namespace gem5

#include "params/Workload.hh"

namespace gem5
{
struct SEWorkloadParams
    : public WorkloadParams
{
    gem5::SEWorkload * create() const;
};

} // namespace gem5

#endif // __PARAMS__SEWorkload__