/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:987
 */

#ifndef __PARAMS__PciDevice__
#define __PARAMS__PciDevice__

namespace gem5 {
class PciDevice;
} // namespace gem5
#include <cstddef>
#include "params/PciBar.hh"
#include <cstddef>
#include "params/PciBar.hh"
#include <cstddef>
#include "params/PciBar.hh"
#include <cstddef>
#include "params/PciBar.hh"
#include <cstddef>
#include "params/PciBar.hh"
#include <cstddef>
#include "params/PciBar.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "params/PciHost.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"
#include <cstddef>
#include "base/types.hh"

#include "params/DmaDevice.hh"

namespace gem5
{
struct PciDeviceParams
    : public DmaDeviceParams
{
    gem5::PciBar * BAR0;
    gem5::PciBar * BAR1;
    gem5::PciBar * BAR2;
    gem5::PciBar * BAR3;
    gem5::PciBar * BAR4;
    gem5::PciBar * BAR5;
    uint8_t BIST;
    uint8_t CacheLineSize;
    uint8_t CapabilityPtr;
    uint32_t CardbusCIS;
    uint8_t ClassCode;
    uint16_t Command;
    uint16_t DeviceID;
    uint32_t ExpansionROM;
    uint8_t HeaderType;
    uint8_t InterruptLine;
    uint8_t InterruptPin;
    uint8_t LatencyTimer;
    uint8_t MSICAPBaseOffset;
    uint8_t MSICAPCapId;
    uint32_t MSICAPMaskBits;
    uint32_t MSICAPMsgAddr;
    uint16_t MSICAPMsgCtrl;
    uint16_t MSICAPMsgData;
    uint32_t MSICAPMsgUpperAddr;
    uint8_t MSICAPNextCapability;
    uint32_t MSICAPPendingBits;
    uint8_t MSIXCAPBaseOffset;
    uint8_t MSIXCAPCapId;
    uint8_t MSIXCAPNextCapability;
    uint16_t MSIXMsgCtrl;
    uint32_t MSIXPbaOffset;
    uint32_t MSIXTableOffset;
    uint8_t MaximumLatency;
    uint8_t MinimumGrant;
    uint8_t PMCAPBaseOffset;
    uint8_t PMCAPCapId;
    uint16_t PMCAPCapabilities;
    uint16_t PMCAPCtrlStatus;
    uint8_t PMCAPNextCapability;
    uint8_t PXCAPBaseOffset;
    uint8_t PXCAPCapId;
    uint16_t PXCAPCapabilities;
    uint32_t PXCAPDevCap2;
    uint32_t PXCAPDevCapabilities;
    uint16_t PXCAPDevCtrl;
    uint32_t PXCAPDevCtrl2;
    uint16_t PXCAPDevStatus;
    uint32_t PXCAPLinkCap;
    uint16_t PXCAPLinkCtrl;
    uint16_t PXCAPLinkStatus;
    uint8_t PXCAPNextCapability;
    uint8_t ProgIF;
    uint8_t Revision;
    uint16_t Status;
    uint8_t SubClassCode;
    uint16_t SubsystemID;
    uint16_t SubsystemVendorID;
    uint16_t VendorID;
    Tick config_latency;
    gem5::PciHost * host;
    int pci_bus;
    int pci_dev;
    int pci_func;
    Tick pio_latency;
};

} // namespace gem5

#endif // __PARAMS__PciDevice__
