/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1022
 */

#ifndef __ENUM__None__SMTQueuePolicy__
#define __ENUM__None__SMTQueuePolicy__

namespace gem5
{
enum class SMTQueuePolicy
{
    Dynamic = 0,
    Partitioned = 1,
    Threshold = 2,
    Num_SMTQueuePolicy = 3
};
extern const char *SMTQueuePolicyStrings[static_cast<int>(SMTQueuePolicy::Num_SMTQueuePolicy)];

} // namespace gem5

#endif // __ENUM__None__SMTQueuePolicy__
