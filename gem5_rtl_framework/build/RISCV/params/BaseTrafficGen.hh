/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__BaseTrafficGen__
#define __PARAMS__BaseTrafficGen__

namespace gem5 {
class BaseTrafficGen;
} // namespace gem5
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <vector>
#include "base/types.hh"
#include <cstddef>
#include "enums/StreamGenType.hh"
#include <cstddef>
#include "params/System.hh"

#include "params/ClockedObject.hh"

#include "enums/StreamGenType.hh"

namespace gem5
{
struct BaseTrafficGenParams
    : public ClockedObjectParams
{
    int cpu_id;
    bool elastic_req;
    int max_outstanding_reqs;
    unsigned numThreads;
    Tick progress_check;
    std::vector< unsigned > sids;
    unsigned socket_id;
    std::vector< unsigned > ssids;
    StreamGenType stream_gen;
    gem5::System * system;
    unsigned int port_port_connection_count;
};

} // namespace gem5

#endif // __PARAMS__BaseTrafficGen__