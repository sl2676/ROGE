// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   arm/isa/main.isa


#include <cmath>

#include "arch/arm/faults.hh"
#include "arch/arm/interrupts.hh"
#include "arch/arm/isa.hh"
#include "arch/arm/htm.hh"
#include "arch/arm/pauth_helpers.hh"
#include "arch/arm/reg_abi.hh"
#include "arch/arm/semihosting.hh"
#include "arch/arm/utility.hh"
#include "arch/generic/memhelpers.hh"
#include "base/condcodes.hh"
#include "base/crc.hh"
#include "base/fenv.hh"
#include "cpu/base.hh"
#include "debug/Arm.hh"
#include "mem/packet.hh"
#include "mem/packet_access.hh"
#include "sim/pseudo_inst.hh"
#include "sim/sim_exit.hh"

using namespace gem5;
using namespace ArmISA;

