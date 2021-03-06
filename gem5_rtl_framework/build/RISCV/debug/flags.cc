/**
 * DO NOT EDIT THIS FILE!
 * File automatically generated by
 *   /home/sean/gem5-rtl/build/RISCV/SConscript:1205
 */

#include "base/compiler.hh" // For namespace deprecation
#include "base/debug.hh"

namespace gem5
{

GEM5_DEPRECATED_NAMESPACE(Debug, debug);
namespace debug
{

SimpleFlag& Activity = *(
    new SimpleFlag("Activity", "None", false)
);
SimpleFlag& AddrRanges = *(
    new SimpleFlag("AddrRanges", "None", false)
);
SimpleFlag& Annotate = *(
    new SimpleFlag("Annotate", "State machine annotation debugging", false)
);
SimpleFlag& AnnotateQ = *(
    new SimpleFlag("AnnotateQ", "State machine annotation queue debugging", false)
);
SimpleFlag& AnnotateVerbose = *(
    new SimpleFlag("AnnotateVerbose", "Dump all state machine annotation details", false)
);
SimpleFlag& BaseXBar = *(
    new SimpleFlag("BaseXBar", "None", false)
);
SimpleFlag& Branch = *(
    new SimpleFlag("Branch", "None", false)
);
SimpleFlag& Bridge = *(
    new SimpleFlag("Bridge", "None", false)
);
SimpleFlag& CCRegs = *(
    new SimpleFlag("CCRegs", "None", false)
);
SimpleFlag& CFI = *(
    new SimpleFlag("CFI", "None", false)
);
SimpleFlag& Cache = *(
    new SimpleFlag("Cache", "None", false)
);
SimpleFlag& CacheComp = *(
    new SimpleFlag("CacheComp", "None", false)
);
SimpleFlag& CachePort = *(
    new SimpleFlag("CachePort", "None", false)
);
SimpleFlag& CacheRepl = *(
    new SimpleFlag("CacheRepl", "None", false)
);
SimpleFlag& CacheTags = *(
    new SimpleFlag("CacheTags", "None", false)
);
SimpleFlag& CacheVerbose = *(
    new SimpleFlag("CacheVerbose", "None", false)
);
SimpleFlag& Checker = *(
    new SimpleFlag("Checker", "None", false)
);
SimpleFlag& Checkpoint = *(
    new SimpleFlag("Checkpoint", "None", false)
);
SimpleFlag& Clint = *(
    new SimpleFlag("Clint", "None", false)
);
SimpleFlag& ClockDomain = *(
    new SimpleFlag("ClockDomain", "None", false)
);
SimpleFlag& CoherentXBar = *(
    new SimpleFlag("CoherentXBar", "None", false)
);
SimpleFlag& CommMonitor = *(
    new SimpleFlag("CommMonitor", "None", false)
);
SimpleFlag& Commit = *(
    new SimpleFlag("Commit", "None", false)
);
SimpleFlag& CommitRate = *(
    new SimpleFlag("CommitRate", "None", false)
);
SimpleFlag& Config = *(
    new SimpleFlag("Config", "None", false)
);
SimpleFlag& Context = *(
    new SimpleFlag("Context", "None", false)
);
SimpleFlag& CxxConfig = *(
    new SimpleFlag("CxxConfig", "None", false)
);
SimpleFlag& DMA = *(
    new SimpleFlag("DMA", "None", false)
);
SimpleFlag& DMACopyEngine = *(
    new SimpleFlag("DMACopyEngine", "None", false)
);
SimpleFlag& DRAM = *(
    new SimpleFlag("DRAM", "None", false)
);
SimpleFlag& DRAMPower = *(
    new SimpleFlag("DRAMPower", "None", false)
);
SimpleFlag& DRAMSim2 = *(
    new SimpleFlag("DRAMSim2", "None", false)
);
SimpleFlag& DRAMState = *(
    new SimpleFlag("DRAMState", "None", false)
);
SimpleFlag& DRAMsim3 = *(
    new SimpleFlag("DRAMsim3", "None", false)
);
SimpleFlag& DVFS = *(
    new SimpleFlag("DVFS", "None", false)
);
SimpleFlag& DebugPrintf = *(
    new SimpleFlag("DebugPrintf", "None", false)
);
SimpleFlag& Decode = *(
    new SimpleFlag("Decode", "None", false)
);
SimpleFlag& DirectedTest = *(
    new SimpleFlag("DirectedTest", "None", false)
);
SimpleFlag& DiskImageRead = *(
    new SimpleFlag("DiskImageRead", "None", false)
);
SimpleFlag& DiskImageWrite = *(
    new SimpleFlag("DiskImageWrite", "None", false)
);
SimpleFlag& DistEthernet = *(
    new SimpleFlag("DistEthernet", "None", false)
);
SimpleFlag& DistEthernetCmd = *(
    new SimpleFlag("DistEthernetCmd", "None", false)
);
SimpleFlag& DistEthernetPkt = *(
    new SimpleFlag("DistEthernetPkt", "None", false)
);
SimpleFlag& Drain = *(
    new SimpleFlag("Drain", "None", false)
);
SimpleFlag& DynInst = *(
    new SimpleFlag("DynInst", "None", false)
);
SimpleFlag& ElasticTrace = *(
    new SimpleFlag("ElasticTrace", "None", false)
);
SimpleFlag& Ethernet = *(
    new SimpleFlag("Ethernet", "None", false)
);
SimpleFlag& EthernetCksum = *(
    new SimpleFlag("EthernetCksum", "None", false)
);
SimpleFlag& EthernetDMA = *(
    new SimpleFlag("EthernetDMA", "None", false)
);
SimpleFlag& EthernetData = *(
    new SimpleFlag("EthernetData", "None", false)
);
SimpleFlag& EthernetDesc = *(
    new SimpleFlag("EthernetDesc", "None", false)
);
SimpleFlag& EthernetEEPROM = *(
    new SimpleFlag("EthernetEEPROM", "None", false)
);
SimpleFlag& EthernetIntr = *(
    new SimpleFlag("EthernetIntr", "None", false)
);
SimpleFlag& EthernetPIO = *(
    new SimpleFlag("EthernetPIO", "None", false)
);
SimpleFlag& EthernetSM = *(
    new SimpleFlag("EthernetSM", "None", false)
);
SimpleFlag& Event = *(
    new SimpleFlag("Event", "None", false)
);
SimpleFlag& ExecAsid = *(
    new SimpleFlag("ExecAsid", "Format: Include ASID in trace", false)
);
SimpleFlag& ExecCPSeq = *(
    new SimpleFlag("ExecCPSeq", "Format: Instruction sequence number", false)
);
SimpleFlag& ExecEffAddr = *(
    new SimpleFlag("ExecEffAddr", "Format: Include effective address", false)
);
SimpleFlag& ExecEnable = *(
    new SimpleFlag("ExecEnable", "Filter: Enable exec tracing (no tracing without this)", false)
);
SimpleFlag& ExecFaulting = *(
    new SimpleFlag("ExecFaulting", "Trace faulting instructions", false)
);
SimpleFlag& ExecFetchSeq = *(
    new SimpleFlag("ExecFetchSeq", "Format: Fetch sequence number", false)
);
SimpleFlag& ExecFlags = *(
    new SimpleFlag("ExecFlags", "Format: Include instruction flags in trace", false)
);
SimpleFlag& ExecKernel = *(
    new SimpleFlag("ExecKernel", "Filter: Trace kernel mode instructions", false)
);
SimpleFlag& ExecMacro = *(
    new SimpleFlag("ExecMacro", "Filter: Include macroops", false)
);
SimpleFlag& ExecMicro = *(
    new SimpleFlag("ExecMicro", "Filter: Include microops", false)
);
SimpleFlag& ExecOpClass = *(
    new SimpleFlag("ExecOpClass", "Format: Include operand class", false)
);
SimpleFlag& ExecRegDelta = *(
    new SimpleFlag("ExecRegDelta", "None", false)
);
SimpleFlag& ExecResult = *(
    new SimpleFlag("ExecResult", "Format: Include results from execution", false)
);
SimpleFlag& ExecSymbol = *(
    new SimpleFlag("ExecSymbol", "Format: Try to include symbol names", false)
);
SimpleFlag& ExecThread = *(
    new SimpleFlag("ExecThread", "Format: Include thread ID in trace", false)
);
SimpleFlag& ExecUser = *(
    new SimpleFlag("ExecUser", "Filter: Trace user mode instructions", false)
);
SimpleFlag& ExternalPort = *(
    new SimpleFlag("ExternalPort", "None", false)
);
SimpleFlag& Fault = *(
    new SimpleFlag("Fault", "None", false)
);
SimpleFlag& Fetch = *(
    new SimpleFlag("Fetch", "None", false)
);
SimpleFlag& FloatRegs = *(
    new SimpleFlag("FloatRegs", "None", false)
);
SimpleFlag& Flow = *(
    new SimpleFlag("Flow", "None", false)
);
SimpleFlag& FmtFlag = *(
    new SimpleFlag("FmtFlag", "Show the --debug-flag that enabled each debug message", true)
);
SimpleFlag& FmtStackTrace = *(
    new SimpleFlag("FmtStackTrace", "Print a stack trace after every debug message", true)
);
SimpleFlag& FmtTicksOff = *(
    new SimpleFlag("FmtTicksOff", "Don't show tick count on debug messages", true)
);
SimpleFlag& FreeList = *(
    new SimpleFlag("FreeList", "None", false)
);
SimpleFlag& GDBAcc = *(
    new SimpleFlag("GDBAcc", "Remote debugger accesses", false)
);
SimpleFlag& GDBExtra = *(
    new SimpleFlag("GDBExtra", "Dump extra information on reads and writes", false)
);
SimpleFlag& GDBMisc = *(
    new SimpleFlag("GDBMisc", "Breakpoints, traps, watchpoints, etc.", false)
);
SimpleFlag& GDBRead = *(
    new SimpleFlag("GDBRead", "Reads to the remote address space", false)
);
SimpleFlag& GDBRecv = *(
    new SimpleFlag("GDBRecv", "Messages received from the remote application", false)
);
SimpleFlag& GDBSend = *(
    new SimpleFlag("GDBSend", "Messages sent to the remote application", false)
);
SimpleFlag& GDBWrite = *(
    new SimpleFlag("GDBWrite", "Writes to the remote address space", false)
);
SimpleFlag& GarnetSyntheticTraffic = *(
    new SimpleFlag("GarnetSyntheticTraffic", "None", false)
);
SimpleFlag& HMCController = *(
    new SimpleFlag("HMCController", "None", false)
);
SimpleFlag& HWPrefetch = *(
    new SimpleFlag("HWPrefetch", "None", false)
);
SimpleFlag& HWPrefetchQueue = *(
    new SimpleFlag("HWPrefetchQueue", "None", false)
);
SimpleFlag& HelloExample = *(
    new SimpleFlag("HelloExample", "For Learning gem5 Part 2. Simple example debug flag", false)
);
SimpleFlag& HtmCpu = *(
    new SimpleFlag("HtmCpu", "Hardware Transactional Memory (CPU side)", false)
);
SimpleFlag& HtmMem = *(
    new SimpleFlag("HtmMem", "Hardware Transactional Memory (Mem side)", false)
);
SimpleFlag& IEW = *(
    new SimpleFlag("IEW", "None", false)
);
SimpleFlag& IPI = *(
    new SimpleFlag("IPI", "None", false)
);
SimpleFlag& IPR = *(
    new SimpleFlag("IPR", "None", false)
);
SimpleFlag& IQ = *(
    new SimpleFlag("IQ", "None", false)
);
SimpleFlag& IdeCtrl = *(
    new SimpleFlag("IdeCtrl", "None", false)
);
SimpleFlag& IdeDisk = *(
    new SimpleFlag("IdeDisk", "None", false)
);
SimpleFlag& Indirect = *(
    new SimpleFlag("Indirect", "None", false)
);
SimpleFlag& IntRegs = *(
    new SimpleFlag("IntRegs", "None", false)
);
SimpleFlag& Intel8254Timer = *(
    new SimpleFlag("Intel8254Timer", "None", false)
);
SimpleFlag& Interrupt = *(
    new SimpleFlag("Interrupt", "None", false)
);
SimpleFlag& IsaFake = *(
    new SimpleFlag("IsaFake", "None", false)
);
SimpleFlag& LLSC = *(
    new SimpleFlag("LLSC", "None", false)
);
SimpleFlag& LSQ = *(
    new SimpleFlag("LSQ", "None", false)
);
SimpleFlag& LSQUnit = *(
    new SimpleFlag("LSQUnit", "None", false)
);
SimpleFlag& LTage = *(
    new SimpleFlag("LTage", "None", false)
);
SimpleFlag& Loader = *(
    new SimpleFlag("Loader", "None", false)
);
SimpleFlag& MC146818 = *(
    new SimpleFlag("MC146818", "None", false)
);
SimpleFlag& MMU = *(
    new SimpleFlag("MMU", "None", false)
);
SimpleFlag& MSHR = *(
    new SimpleFlag("MSHR", "None", false)
);
SimpleFlag& MemChecker = *(
    new SimpleFlag("MemChecker", "None", false)
);
SimpleFlag& MemCheckerMonitor = *(
    new SimpleFlag("MemCheckerMonitor", "None", false)
);
SimpleFlag& MemCtrl = *(
    new SimpleFlag("MemCtrl", "None", false)
);
SimpleFlag& MemDepUnit = *(
    new SimpleFlag("MemDepUnit", "None", false)
);
SimpleFlag& MemTest = *(
    new SimpleFlag("MemTest", "None", false)
);
SimpleFlag& MemoryAccess = *(
    new SimpleFlag("MemoryAccess", "None", false)
);
SimpleFlag& MinorCPU = *(
    new SimpleFlag("MinorCPU", "Minor CPU-level events", false)
);
SimpleFlag& MinorExecute = *(
    new SimpleFlag("MinorExecute", "Minor Execute stage", false)
);
SimpleFlag& MinorInterrupt = *(
    new SimpleFlag("MinorInterrupt", "Minor interrupt handling", false)
);
SimpleFlag& MinorMem = *(
    new SimpleFlag("MinorMem", "Minor memory accesses", false)
);
SimpleFlag& MinorScoreboard = *(
    new SimpleFlag("MinorScoreboard", "Minor Execute register scoreboard", false)
);
SimpleFlag& MinorTiming = *(
    new SimpleFlag("MinorTiming", "Extra timing for instructions", false)
);
SimpleFlag& MinorTrace = *(
    new SimpleFlag("MinorTrace", "MinorTrace cycle-by-cycle state trace", false)
);
SimpleFlag& MiscRegs = *(
    new SimpleFlag("MiscRegs", "None", false)
);
SimpleFlag& Mwait = *(
    new SimpleFlag("Mwait", "None", false)
);
SimpleFlag& NVM = *(
    new SimpleFlag("NVM", "None", false)
);
SimpleFlag& NoncoherentXBar = *(
    new SimpleFlag("NoncoherentXBar", "None", false)
);
SimpleFlag& O3CPU = *(
    new SimpleFlag("O3CPU", "None", false)
);
SimpleFlag& O3PipeView = *(
    new SimpleFlag("O3PipeView", "None", false)
);
SimpleFlag& PCEvent = *(
    new SimpleFlag("PCEvent", "None", false)
);
SimpleFlag& PMP = *(
    new SimpleFlag("PMP", "None", false)
);
SimpleFlag& PS2 = *(
    new SimpleFlag("PS2", "None", false)
);
SimpleFlag& PacketQueue = *(
    new SimpleFlag("PacketQueue", "None", false)
);
SimpleFlag& PageTableWalker = *(
    new SimpleFlag("PageTableWalker", "Page table walker state machine debugging", false)
);
SimpleFlag& PciDevice = *(
    new SimpleFlag("PciDevice", "None", false)
);
SimpleFlag& PciHost = *(
    new SimpleFlag("PciHost", "None", false)
);
SimpleFlag& Plic = *(
    new SimpleFlag("Plic", "None", false)
);
SimpleFlag& PowerDomain = *(
    new SimpleFlag("PowerDomain", "None", false)
);
SimpleFlag& Printf = *(
    new SimpleFlag("Printf", "None", false)
);
SimpleFlag& ProbeVerbose = *(
    new SimpleFlag("ProbeVerbose", "None", false)
);
SimpleFlag& ProtocolTrace = *(
    new SimpleFlag("ProtocolTrace", "None", false)
);
SimpleFlag& PseudoInst = *(
    new SimpleFlag("PseudoInst", "None", false)
);
SimpleFlag& QOS = *(
    new SimpleFlag("QOS", "None", false)
);
SimpleFlag& Quiesce = *(
    new SimpleFlag("Quiesce", "None", false)
);
SimpleFlag& ROB = *(
    new SimpleFlag("ROB", "None", false)
);
SimpleFlag& Rename = *(
    new SimpleFlag("Rename", "None", false)
);
SimpleFlag& RiscvMisc = *(
    new SimpleFlag("RiscvMisc", "None", false)
);
SimpleFlag& RubyCache = *(
    new SimpleFlag("RubyCache", "None", false)
);
SimpleFlag& RubyCacheTrace = *(
    new SimpleFlag("RubyCacheTrace", "None", false)
);
SimpleFlag& RubyDma = *(
    new SimpleFlag("RubyDma", "None", false)
);
SimpleFlag& RubyGenerated = *(
    new SimpleFlag("RubyGenerated", "None", false)
);
SimpleFlag& RubyNetwork = *(
    new SimpleFlag("RubyNetwork", "None", false)
);
SimpleFlag& RubyPort = *(
    new SimpleFlag("RubyPort", "None", false)
);
SimpleFlag& RubyPrefetcher = *(
    new SimpleFlag("RubyPrefetcher", "None", false)
);
SimpleFlag& RubyQueue = *(
    new SimpleFlag("RubyQueue", "None", false)
);
SimpleFlag& RubyResourceStalls = *(
    new SimpleFlag("RubyResourceStalls", "None", false)
);
SimpleFlag& RubySequencer = *(
    new SimpleFlag("RubySequencer", "None", false)
);
SimpleFlag& RubySlicc = *(
    new SimpleFlag("RubySlicc", "None", false)
);
SimpleFlag& RubyStats = *(
    new SimpleFlag("RubyStats", "None", false)
);
SimpleFlag& RubySystem = *(
    new SimpleFlag("RubySystem", "None", false)
);
SimpleFlag& RubyTest = *(
    new SimpleFlag("RubyTest", "None", false)
);
SimpleFlag& RubyTester = *(
    new SimpleFlag("RubyTester", "None", false)
);
SimpleFlag& SQL = *(
    new SimpleFlag("SQL", "SQL queries sent to the server", false)
);
SimpleFlag& Scoreboard = *(
    new SimpleFlag("Scoreboard", "None", false)
);
SimpleFlag& SerialLink = *(
    new SimpleFlag("SerialLink", "None", false)
);
SimpleFlag& SimpleCPU = *(
    new SimpleFlag("SimpleCPU", "None", false)
);
SimpleFlag& SimpleCache = *(
    new SimpleFlag("SimpleCache", "For Learning gem5 Part 2.", false)
);
SimpleFlag& SimpleDisk = *(
    new SimpleFlag("SimpleDisk", "None", false)
);
SimpleFlag& SimpleDiskData = *(
    new SimpleFlag("SimpleDiskData", "None", false)
);
SimpleFlag& SimpleMemobj = *(
    new SimpleFlag("SimpleMemobj", "For Learning gem5 Part 2.", false)
);
SimpleFlag& SimpleTrace = *(
    new SimpleFlag("SimpleTrace", "None", false)
);
SimpleFlag& SnoopFilter = *(
    new SimpleFlag("SnoopFilter", "None", false)
);
SimpleFlag& Stack = *(
    new SimpleFlag("Stack", "None", false)
);
SimpleFlag& StackDist = *(
    new SimpleFlag("StackDist", "None", false)
);
SimpleFlag& StatEvents = *(
    new SimpleFlag("StatEvents", "Statistics event tracking", false)
);
SimpleFlag& Stats = *(
    new SimpleFlag("Stats", "Statistics management", false)
);
SimpleFlag& StoreSet = *(
    new SimpleFlag("StoreSet", "None", false)
);
SimpleFlag& SyscallBase = *(
    new SimpleFlag("SyscallBase", "None", false)
);
SimpleFlag& SyscallVerbose = *(
    new SimpleFlag("SyscallVerbose", "None", false)
);
SimpleFlag& TLB = *(
    new SimpleFlag("TLB", "None", false)
);
SimpleFlag& TLBVerbose = *(
    new SimpleFlag("TLBVerbose", "None", false)
);
SimpleFlag& Tage = *(
    new SimpleFlag("Tage", "None", false)
);
SimpleFlag& TageSCL = *(
    new SimpleFlag("TageSCL", "None", false)
);
SimpleFlag& Terminal = *(
    new SimpleFlag("Terminal", "None", false)
);
SimpleFlag& TerminalVerbose = *(
    new SimpleFlag("TerminalVerbose", "None", false)
);
SimpleFlag& ThermalDomain = *(
    new SimpleFlag("ThermalDomain", "None", false)
);
SimpleFlag& Thread = *(
    new SimpleFlag("Thread", "None", false)
);
SimpleFlag& TimeSync = *(
    new SimpleFlag("TimeSync", "None", false)
);
SimpleFlag& Timer = *(
    new SimpleFlag("Timer", "None", false)
);
SimpleFlag& TokenPort = *(
    new SimpleFlag("TokenPort", "None", false)
);
SimpleFlag& TraceCPUData = *(
    new SimpleFlag("TraceCPUData", "None", false)
);
SimpleFlag& TraceCPUInst = *(
    new SimpleFlag("TraceCPUInst", "None", false)
);
SimpleFlag& TrafficGen = *(
    new SimpleFlag("TrafficGen", "None", false)
);
SimpleFlag& Uart = *(
    new SimpleFlag("Uart", "None", false)
);
SimpleFlag& VIO = *(
    new SimpleFlag("VIO", "VirtIO base functionality", false)
);
SimpleFlag& VIO9P = *(
    new SimpleFlag("VIO9P", "General 9p over VirtIO debugging", false)
);
SimpleFlag& VIO9PData = *(
    new SimpleFlag("VIO9PData", "Dump data in VirtIO 9p connections", false)
);
SimpleFlag& VIOBlock = *(
    new SimpleFlag("VIOBlock", "VirtIO block device", false)
);
SimpleFlag& VIOConsole = *(
    new SimpleFlag("VIOConsole", "VirtIO console device", false)
);
SimpleFlag& VIOIface = *(
    new SimpleFlag("VIOIface", "VirtIO transport", false)
);
SimpleFlag& VNC = *(
    new SimpleFlag("VNC", "None", false)
);
SimpleFlag& VecPredRegs = *(
    new SimpleFlag("VecPredRegs", "None", false)
);
SimpleFlag& VecRegs = *(
    new SimpleFlag("VecRegs", "None", false)
);
SimpleFlag& VirtIOMMIO = *(
    new SimpleFlag("VirtIOMMIO", "None", false)
);
SimpleFlag& Vma = *(
    new SimpleFlag("Vma", "None", false)
);
SimpleFlag& VoltageDomain = *(
    new SimpleFlag("VoltageDomain", "None", false)
);
SimpleFlag& VtoPhys = *(
    new SimpleFlag("VtoPhys", "None", false)
);
SimpleFlag& WorkItems = *(
    new SimpleFlag("WorkItems", "None", false)
);
SimpleFlag& Writeback = *(
    new SimpleFlag("Writeback", "None", false)
);
SimpleFlag& rtlFIFO = *(
    new SimpleFlag("rtlFIFO", "None", false)
);
SimpleFlag& rtlFIFODebug = *(
    new SimpleFlag("rtlFIFODebug", "None", false)
);
SimpleFlag& rtlObject = *(
    new SimpleFlag("rtlObject", "None", false)
);
SimpleFlag& rtlObjectDebug = *(
    new SimpleFlag("rtlObjectDebug", "None", false)
);
CompoundFlag& All = *(
    new CompoundFlag("All", "Controls all debug flags. It should not be used within C++ code.", {
        &Activity,
        &AddrRanges,
        &Annotate,
        &AnnotateQ,
        &AnnotateVerbose,
        &BaseXBar,
        &Branch,
        &Bridge,
        &CCRegs,
        &CFI,
        &Cache,
        &CacheComp,
        &CachePort,
        &CacheRepl,
        &CacheTags,
        &CacheVerbose,
        &Checker,
        &Checkpoint,
        &Clint,
        &ClockDomain,
        &CoherentXBar,
        &CommMonitor,
        &Commit,
        &CommitRate,
        &Config,
        &Context,
        &CxxConfig,
        &DMA,
        &DMACopyEngine,
        &DRAM,
        &DRAMPower,
        &DRAMSim2,
        &DRAMState,
        &DRAMsim3,
        &DVFS,
        &DebugPrintf,
        &Decode,
        &DirectedTest,
        &DiskImageRead,
        &DiskImageWrite,
        &DistEthernet,
        &DistEthernetCmd,
        &DistEthernetPkt,
        &Drain,
        &DynInst,
        &ElasticTrace,
        &Ethernet,
        &EthernetCksum,
        &EthernetDMA,
        &EthernetData,
        &EthernetDesc,
        &EthernetEEPROM,
        &EthernetIntr,
        &EthernetPIO,
        &EthernetSM,
        &Event,
        &ExecAsid,
        &ExecCPSeq,
        &ExecEffAddr,
        &ExecEnable,
        &ExecFaulting,
        &ExecFetchSeq,
        &ExecFlags,
        &ExecKernel,
        &ExecMacro,
        &ExecMicro,
        &ExecOpClass,
        &ExecRegDelta,
        &ExecResult,
        &ExecSymbol,
        &ExecThread,
        &ExecUser,
        &ExternalPort,
        &Fault,
        &Fetch,
        &FloatRegs,
        &Flow,
        &FreeList,
        &GDBAcc,
        &GDBExtra,
        &GDBMisc,
        &GDBRead,
        &GDBRecv,
        &GDBSend,
        &GDBWrite,
        &GarnetSyntheticTraffic,
        &HMCController,
        &HWPrefetch,
        &HWPrefetchQueue,
        &HelloExample,
        &HtmCpu,
        &HtmMem,
        &IEW,
        &IPI,
        &IPR,
        &IQ,
        &IdeCtrl,
        &IdeDisk,
        &Indirect,
        &IntRegs,
        &Intel8254Timer,
        &Interrupt,
        &IsaFake,
        &LLSC,
        &LSQ,
        &LSQUnit,
        &LTage,
        &Loader,
        &MC146818,
        &MMU,
        &MSHR,
        &MemChecker,
        &MemCheckerMonitor,
        &MemCtrl,
        &MemDepUnit,
        &MemTest,
        &MemoryAccess,
        &MinorCPU,
        &MinorExecute,
        &MinorInterrupt,
        &MinorMem,
        &MinorScoreboard,
        &MinorTiming,
        &MinorTrace,
        &MiscRegs,
        &Mwait,
        &NVM,
        &NoncoherentXBar,
        &O3CPU,
        &O3PipeView,
        &PCEvent,
        &PMP,
        &PS2,
        &PacketQueue,
        &PageTableWalker,
        &PciDevice,
        &PciHost,
        &Plic,
        &PowerDomain,
        &Printf,
        &ProbeVerbose,
        &ProtocolTrace,
        &PseudoInst,
        &QOS,
        &Quiesce,
        &ROB,
        &Rename,
        &RiscvMisc,
        &RubyCache,
        &RubyCacheTrace,
        &RubyDma,
        &RubyGenerated,
        &RubyNetwork,
        &RubyPort,
        &RubyPrefetcher,
        &RubyQueue,
        &RubyResourceStalls,
        &RubySequencer,
        &RubySlicc,
        &RubyStats,
        &RubySystem,
        &RubyTest,
        &RubyTester,
        &SQL,
        &Scoreboard,
        &SerialLink,
        &SimpleCPU,
        &SimpleCache,
        &SimpleDisk,
        &SimpleDiskData,
        &SimpleMemobj,
        &SimpleTrace,
        &SnoopFilter,
        &Stack,
        &StackDist,
        &StatEvents,
        &Stats,
        &StoreSet,
        &SyscallBase,
        &SyscallVerbose,
        &TLB,
        &TLBVerbose,
        &Tage,
        &TageSCL,
        &Terminal,
        &TerminalVerbose,
        &ThermalDomain,
        &Thread,
        &TimeSync,
        &Timer,
        &TokenPort,
        &TraceCPUData,
        &TraceCPUInst,
        &TrafficGen,
        &Uart,
        &VIO,
        &VIO9P,
        &VIO9PData,
        &VIOBlock,
        &VIOConsole,
        &VIOIface,
        &VNC,
        &VecPredRegs,
        &VecRegs,
        &VirtIOMMIO,
        &Vma,
        &VoltageDomain,
        &VtoPhys,
        &WorkItems,
        &Writeback,
        &rtlFIFO,
        &rtlFIFODebug,
        &rtlObject,
        &rtlObjectDebug,
    })
);
CompoundFlag& AnnotateAll = *(
    new CompoundFlag("AnnotateAll", "All Annotation flags", {
        &Annotate,
        &AnnotateQ,
        &AnnotateVerbose,
    })
);
CompoundFlag& CacheAll = *(
    new CompoundFlag("CacheAll", "None", {
        &Cache,
        &CacheComp,
        &CachePort,
        &CacheRepl,
        &CacheVerbose,
        &HWPrefetch,
        &MSHR,
    })
);
CompoundFlag& DiskImageAll = *(
    new CompoundFlag("DiskImageAll", "None", {
        &DiskImageRead,
        &DiskImageWrite,
    })
);
CompoundFlag& EthernetAll = *(
    new CompoundFlag("EthernetAll", "None", {
        &Ethernet,
        &EthernetPIO,
        &EthernetDMA,
        &EthernetData,
        &EthernetDesc,
        &EthernetIntr,
        &EthernetSM,
        &EthernetCksum,
        &EthernetEEPROM,
    })
);
CompoundFlag& EthernetNoData = *(
    new CompoundFlag("EthernetNoData", "None", {
        &Ethernet,
        &EthernetPIO,
        &EthernetDesc,
        &EthernetIntr,
        &EthernetSM,
        &EthernetCksum,
    })
);
CompoundFlag& Exec = *(
    new CompoundFlag("Exec", "None", {
        &ExecEnable,
        &ExecOpClass,
        &ExecThread,
        &ExecEffAddr,
        &ExecResult,
        &ExecSymbol,
        &ExecMicro,
        &ExecMacro,
        &ExecFaulting,
        &ExecUser,
        &ExecKernel,
    })
);
CompoundFlag& ExecAll = *(
    new CompoundFlag("ExecAll", "None", {
        &ExecEnable,
        &ExecCPSeq,
        &ExecEffAddr,
        &ExecFaulting,
        &ExecFetchSeq,
        &ExecOpClass,
        &ExecRegDelta,
        &ExecResult,
        &ExecSymbol,
        &ExecThread,
        &ExecMicro,
        &ExecMacro,
        &ExecUser,
        &ExecKernel,
        &ExecAsid,
        &ExecFlags,
    })
);
CompoundFlag& ExecNoTicks = *(
    new CompoundFlag("ExecNoTicks", "None", {
        &Exec,
        &FmtTicksOff,
    })
);
CompoundFlag& GDBAll = *(
    new CompoundFlag("GDBAll", "All Remote debugging flags", {
        &GDBMisc,
        &GDBAcc,
        &GDBRead,
        &GDBWrite,
        &GDBSend,
        &GDBRecv,
        &GDBExtra,
    })
);
CompoundFlag& IdeAll = *(
    new CompoundFlag("IdeAll", "None", {
        &IdeCtrl,
        &IdeDisk,
    })
);
CompoundFlag& Minor = *(
    new CompoundFlag("Minor", "None", {
        &MinorCPU,
        &MinorExecute,
        &MinorInterrupt,
        &MinorMem,
        &MinorScoreboard,
    })
);
CompoundFlag& O3CPUAll = *(
    new CompoundFlag("O3CPUAll", "None", {
        &Fetch,
        &Decode,
        &Rename,
        &IEW,
        &Commit,
        &IQ,
        &ROB,
        &FreeList,
        &LSQ,
        &LSQUnit,
        &StoreSet,
        &MemDepUnit,
        &DynInst,
        &O3CPU,
        &Activity,
        &Scoreboard,
        &Writeback,
    })
);
CompoundFlag& Registers = *(
    new CompoundFlag("Registers", "None", {
        &IntRegs,
        &FloatRegs,
        &VecRegs,
        &VecPredRegs,
        &CCRegs,
        &MiscRegs,
    })
);
CompoundFlag& Ruby = *(
    new CompoundFlag("Ruby", "None", {
        &RubyQueue,
        &RubyNetwork,
        &RubyTester,
        &RubyGenerated,
        &RubySlicc,
        &RubySystem,
        &RubyCache,
        &RubyDma,
        &RubyPort,
        &RubySequencer,
        &RubyCacheTrace,
        &RubyPrefetcher,
    })
);
CompoundFlag& SyscallAll = *(
    new CompoundFlag("SyscallAll", "None", {
        &SyscallBase,
        &SyscallVerbose,
    })
);
CompoundFlag& XBar = *(
    new CompoundFlag("XBar", "None", {
        &BaseXBar,
        &CoherentXBar,
        &NoncoherentXBar,
        &SnoopFilter,
    })
);

} // namespace debug
} // namespace gem5
