// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa

#if !defined(__SPLIT) || (__SPLIT == 1)

// CIAddi4spnOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                return std::make_shared<IllegalInstFault>("zero instruction",\n                                                           machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))

    Fault
    C_addi4spn::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t sp = 0;
uint64_t Rp2 = 0;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
            if (machInst == 0)
                return std::make_shared<IllegalInstFault>("zero instruction",
                                                           machInst);
            Rp2 = sp + imm;
        ;
        
        
        {
            uint64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_addi4spn::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                if (status.fs == FPUStatus::OFF)\n                    return std::make_shared<IllegalInstFault>("FPU is off",\n                                                               machInst);\n\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_fld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint64_t Fp2_bits = 0;
uint64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                STATUS status = xc->readMiscReg(MISCREG_STATUS);
                if (status.fs == FPUStatus::OFF)
                    return std::make_shared<IllegalInstFault>("FPU is off",
                                                               machInst);

                Fp2_bits = Mem;
            ;

        
        {
            uint64_t final_val = Fp2_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    C_fld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    C_fld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Fp2_bits = 0;
uint64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                STATUS status = xc->readMiscReg(MISCREG_STATUS);
                if (status.fs == FPUStatus::OFF)
                    return std::make_shared<IllegalInstFault>("FPU is off",
                                                               machInst);

                Fp2_bits = Mem;
            ;
        
        {
            uint64_t final_val = Fp2_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_lw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
int64_t Rp2 = 0;
int32_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                Rp2 = Mem;
            ;

        
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    C_lw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
int32_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    C_lw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rp2 = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                Rp2 = Mem;
            ;
        
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_ld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
int64_t Rp2 = 0;
int64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                Rp2 = Mem;
            ;

        
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    C_ld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
int64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                EA = Rp1 + offset;
            ;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    C_ld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rp2 = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                Rp2 = Mem;
            ;
        
        
        {
            int64_t final_val = Rp2;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                if (status.fs == FPUStatus::OFF)\n                    return std::make_shared<IllegalInstFault>("FPU is off",\n                                                               machInst);\n\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_fsd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint64_t Fp2_bits = 0;
uint64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
Fp2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        
                STATUS status = xc->readMiscReg(MISCREG_STATUS);
                if (status.fs == FPUStatus::OFF)
                    return std::make_shared<IllegalInstFault>("FPU is off",
                                                               machInst);

                Mem = Fp2_bits;
            ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    C_fsd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint64_t Fp2_bits = 0;
uint64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
Fp2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        
                STATUS status = xc->readMiscReg(MISCREG_STATUS);
                if (status.fs == FPUStatus::OFF)
                    return std::make_shared<IllegalInstFault>("FPU is off",
                                                               machInst);

                Mem = Fp2_bits;
            ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    C_fsd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})

    Fault
    C_sw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint32_t Rp2 = 0;
uint32_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        
                Mem = Rp2;
            ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    C_sw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint32_t Rp2 = 0;
uint32_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        
                Mem = Rp2;
            ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    C_sw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    Fault
    C_sd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
uint64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        
                    Mem = Rp2;
            ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    C_sd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
uint64_t Mem = {};
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                EA = Rp1 + offset;
            ;

        
                    Mem = Rp2;
            ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    C_sd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    } else { // imm == 0\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})

    Fault
    C_addi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
;
        
                if ((RC1 == 0) != (imm == 0)) {
                    if (RC1 == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x0", machInst);
                    } else { // imm == 0
                        return std::make_shared<IllegalInstFault>(
                                "immediate = 0", machInst);
                    }
                }
                Rc1 = Rc1 + imm;
            ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_addi::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})

    Fault
    C_addiw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
;
        
                if (RC1 == 0) {
                    return std::make_shared<IllegalInstFault>(
                            "source reg x0", machInst);
                }
                Rc1 = (int32_t)Rc1 + imm;
            ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_addiw::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = imm;\n            '],{})

    Fault
    C_li::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
;
        ;
        
                if (RC1 == 0) {
                    return std::make_shared<IllegalInstFault>(
                            "source reg x0", machInst);
                }
                Rc1 = imm;
            ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_li::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})

    Fault
    C_addi16sp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t sp = 0;
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                    if (imm == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "immediate = 0", machInst);
                    }
                    sp = sp + imm;
                ;
        
        
        {
            int64_t final_val = sp;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_addi16sp::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})

    Fault
    C_lui::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
;
        ;
        
                    if (RC1 == 0 || RC1 == 2) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x0", machInst);
                    }
                    if (imm == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "immediate = 0", machInst);
                    }
                    Rc1 = imm;
                ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_lui::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        // To be compliant with GCC, the immediate is formated to a 20-bit
        // signed integer.
        ss << ((((uint64_t)imm) >> 12) & 0xFFFFF);
        return ss.str();
    }

// CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})

    Fault
    C_srli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                    if (imm == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "immediate = 0", machInst);
                    }
                    Rp1 = Rp1 >> imm;
                ;
        
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_srli::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})

    Fault
    C_srai::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rp1 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                    if (imm == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "immediate = 0", machInst);
                    }
                    Rp1 = Rp1 >> imm;
                ;
        
        
        {
            int64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_srai::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})

    Fault
    C_andi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
;
        
                    Rp1 = Rp1 & imm;
                ;
        
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_andi::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CompressedROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})

    Fault
    C_sub::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                            Rp1 = Rp1 - Rp2;
                        ;
        
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_sub::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// CompressedROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})

    Fault
    C_xor::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                            Rp1 = Rp1 ^ Rp2;
                        ;
        
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_xor::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// CompressedROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})

    Fault
    C_or::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                            Rp1 = Rp1 | Rp2;
                        ;
        
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_or::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// CompressedROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})

    Fault
    C_and::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
uint64_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                            Rp1 = Rp1 & Rp2;
                        ;
        
        
        {
            uint64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_and::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// Unknown::unknown(([], {}))

// CompressedROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})

    Fault
    C_subw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rp1 = 0;
int32_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                            Rp1 = (int32_t)Rp1 - Rp2;
                        ;
        
        
        {
            int64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_subw::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// CompressedROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})

    Fault
    C_addw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rp1 = 0;
int32_t Rp2 = 0;
;
        Rp1 = xc->readIntRegOperand(this, 0);
Rp2 = xc->readIntRegOperand(this, 1);
;
        
                            Rp1 = (int32_t)Rp1 + Rp2;
                        ;
        
        
        {
            int64_t final_val = Rp1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_addw::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// CJOp::c_j((['\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl'], {}))

    Fault
    C_j::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
PC = __parserAutoPCState.pc();
;
        
            NPC = PC + imm;
        ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    C_j::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    C_j::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    C_beqz::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rp1 = xc->readIntRegOperand(this, 0);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                if (Rp1 == 0)
                    NPC = PC + imm;
                else
                    NPC = NPC;
            ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    C_beqz::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    C_beqz::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    C_bnez::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rp1 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rp1 = xc->readIntRegOperand(this, 0);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                if (Rp1 != 0)
                    NPC = PC + imm;
                else
                    NPC = NPC;
            ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    C_bnez::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    C_bnez::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                return std::make_shared<IllegalInstFault>(\n                        "immediate = 0", machInst);\n            }\n            if (RC1 == 0) {\n                return std::make_shared<IllegalInstFault>(\n                        "source reg x0", machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))

    Fault
    C_slli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rc1 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
;
        
            if (imm == 0) {
                return std::make_shared<IllegalInstFault>(
                        "immediate = 0", machInst);
            }
            if (RC1 == 0) {
                return std::make_shared<IllegalInstFault>(
                        "source reg x0", machInst);
            }
            Rc1 = Rc1 << imm;
        ;
        
        
        {
            uint64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_slli::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_fldsp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Fc1_bits = 0;
uint64_t sp = 0;
uint64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                Fc1_bits = Mem;
            ;

        
        {
            uint64_t final_val = Fc1_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    C_fldsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    C_fldsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Fc1_bits = 0;
uint64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                Fc1_bits = Mem;
            ;
        
        {
            uint64_t final_val = Fc1_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_lwsp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
int64_t Rc1 = 0;
int32_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                if (RC1 == 0) {
                    return std::make_shared<IllegalInstFault>(
                            "source reg x0", machInst);
                }
                Rc1 = Mem;
            ;

        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    C_lwsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
int32_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    C_lwsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                if (RC1 == 0) {
                    return std::make_shared<IllegalInstFault>(
                            "source reg x0", machInst);
                }
                Rc1 = Mem;
            ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_ldsp::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
int64_t Rc1 = 0;
int64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                if (RC1 == 0) {
                    return std::make_shared<IllegalInstFault>(
                            "source reg x0", machInst);
                }
                Rc1 = Mem;
            ;

        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    C_ldsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
int64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
;
        
                EA = sp + offset;
            ;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    C_ldsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                if (RC1 == 0) {
                    return std::make_shared<IllegalInstFault>(
                            "source reg x0", machInst);
                }
                Rc1 = Mem;
            ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Jump::c_jr((['\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    C_jr::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rc1 = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rc1 = xc->readIntRegOperand(this, 0);
;
        
                    if (RC1 == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x0", machInst);
                    }
                    NPC = Rc1;
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    C_jr::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        pc.set((tc->readIntReg(srcRegIdx(0).index()) + imm)&~0x1);
        return pc;
    }

    std::string
    C_jr::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::stringstream ss;
        ss << mnemonic << ' ';
        if (QUADRANT == 0x3)
            ss << registerName(destRegIdx(0)) << ", "
               << imm << "(" << registerName(srcRegIdx(0)) << ")";
        else
            ss << registerName(srcRegIdx(0));
        return ss.str();
    }

// CROp::c_mv((['\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))

    Fault
    C_mv::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rc1 = 0;
uint64_t Rc2 = 0;
;
        Rc2 = xc->readIntRegOperand(this, 0);
;
        
                    if (RC1 == 0) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x0", machInst);
                    }
                    Rc1 = Rc2;
                ;
        
        
        {
            uint64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    return std::make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))

    Fault
    C_ebreak::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        ;
        ;
        
                    if (RC2 != 0) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x1", machInst);
                    }
                    return std::make_shared<BreakpointFault>(xc->pcState());
                ;
        ;
        return NoFault;
    }

// Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            return std::make_shared<IllegalInstFault>(\n                                    "source reg x0", machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    C_jalr::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t ra = 0;
uint64_t Rc1 = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rc1 = xc->readIntRegOperand(this, 0);
NPC = __parserAutoPCState.npc();
;
        
                        if (RC1 == 0) {
                            return std::make_shared<IllegalInstFault>(
                                    "source reg x0", machInst);
                        }
                        ra = NPC;
                        NPC = Rc1;
                    ;
        
        
        {
            uint64_t final_val = ra;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }__parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    C_jalr::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        pc.set((tc->readIntReg(srcRegIdx(0).index()) + imm)&~0x1);
        return pc;
    }

    std::string
    C_jalr::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::stringstream ss;
        ss << mnemonic << ' ';
        if (QUADRANT == 0x3)
            ss << registerName(destRegIdx(0)) << ", "
               << imm << "(" << registerName(srcRegIdx(0)) << ")";
        else
            ss << registerName(srcRegIdx(0));
        return ss.str();
    }

// CompressedROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))

    Fault
    C_add::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rc1 = 0;
int64_t Rc2 = 0;
;
        Rc1 = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                        Rc1 = Rc1 + Rc2;
                    ;
        
        
        {
            int64_t final_val = Rc1;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    C_add::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        ss << registerName(indices[0]) << ", ";
        ss << registerName(indices[1]);
        return ss.str();
    }

// Unknown::unknown(([], {}))

// CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_fsdsp::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint64_t Fc2_bits = 0;
uint64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
Fc2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = sp + offset;
            ;

        
                Mem = Fc2_bits;
            ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    C_fsdsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint64_t Fc2_bits = 0;
uint64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
Fc2_bits = xc->readFloatRegOperandBits(this, 1);
;
        
                EA = sp + offset;
            ;

        
                Mem = Fc2_bits;
            ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    C_fsdsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_swsp::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint32_t Rc2 = 0;
uint32_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        
                Mem = Rc2;
            ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    C_swsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint32_t Rc2 = 0;
uint32_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        
                Mem = Rc2;
            ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    C_swsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})

    Fault
    C_sdsp::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint64_t Rc2 = 0;
uint64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        
                Mem = Rc2;
            ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    C_sdsp::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t sp = 0;
uint64_t Rc2 = 0;
uint64_t Mem = {};
;
        sp = xc->readIntRegOperand(this, 0);
Rc2 = xc->readIntRegOperand(this, 1);
;
        
                EA = sp + offset;
            ;

        
                Mem = Rc2;
            ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    C_sdsp::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})

    Fault
    Lb::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int8_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lb::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int8_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lb::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int8_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})

    Fault
    Lh::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int16_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lh::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int16_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lh::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int16_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})

    Fault
    Lw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})

    Fault
    Ld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Ld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Ld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})

    Fault
    Lbu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint8_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lbu::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint8_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lbu::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint8_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})

    Fault
    Lhu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint16_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lhu::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint16_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lhu::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint16_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})

    Fault
    Lwu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lwu::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lwu::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// Load::flw(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                    "FPU is off", machInst);\n                    freg_t fd;\n                    fd = freg(f32(Mem_uw));\n                    Fd_bits = fd.v;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Fault
    Flw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                    "FPU is off", machInst);
                    freg_t fd;
                    fd = freg(f32(Mem));
                    Fd_bits = fd.v;
                ;

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Flw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Flw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Fd_bits = 0;
uint32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                    "FPU is off", machInst);
                    freg_t fd;
                    fd = freg(f32(Mem));
                    Fd_bits = fd.v;
                ;
        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Load::fld(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                    "FPU is off", machInst);\n                    freg_t fd;\n                    fd = freg(f64(Mem));\n                    Fd_bits = fd.v;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Fault
    Fld::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                    "FPU is off", machInst);
                    freg_t fd;
                    fd = freg(f64(Mem));
                    Fd_bits = fd.v;
                ;

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Fld::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1 + offset;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Fld::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Fd_bits = 0;
uint64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                    "FPU is off", machInst);
                    freg_t fd;
                    fd = freg(f64(Mem));
                    Fd_bits = fd.v;
                ;
        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FenceOp::fence(['\n                ', 'uint64_t', 'IsReadBarrier', 'IsWriteBarrier', 'No_OpClass'],{})

    Fault
    Fence::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        ;
        ;
        
                ;
        ;
        return NoFault;
    }

    std::string
    Fence::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::stringstream ss;
        ss << mnemonic;
        if (!FUNCT3) {
            ss << ' ';
            if (PRED & 0x8)
                ss << 'i';
            if (PRED & 0x4)
                ss << 'o';
            if (PRED & 0x2)
                ss << 'r';
            if (PRED & 0x1)
                ss << 'w';
            ss << ", ";
            if (SUCC & 0x8)
                ss << 'i';
            if (SUCC & 0x4)
                ss << 'o';
            if (SUCC & 0x2)
                ss << 'r';
            if (SUCC & 0x1)
                ss << 'w';
        }
        return ss.str();
    }

// FenceOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    Fault
    Fence_i::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        ;
        ;
        
                ;
        ;
        return NoFault;
    }

    std::string
    Fence_i::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::stringstream ss;
        ss << mnemonic;
        if (!FUNCT3) {
            ss << ' ';
            if (PRED & 0x8)
                ss << 'i';
            if (PRED & 0x4)
                ss << 'o';
            if (PRED & 0x2)
                ss << 'r';
            if (PRED & 0x1)
                ss << 'w';
            ss << ", ";
            if (SUCC & 0x8)
                ss << 'i';
            if (SUCC & 0x4)
                ss << 'o';
            if (SUCC & 0x2)
                ss << 'r';
            if (SUCC & 0x1)
                ss << 'w';
        }
        return ss.str();
    }

// Unknown::unknown(([], {}))

// IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})

    Fault
    Addi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 + imm;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Addi::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::slli(['\n                    Rd = Rs1 << imm;\n                '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    Fault
    Slli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 << imm;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Slli::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})

    Fault
    Slti::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = (Rs1 < imm) ? 1 : 0;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Slti::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})

    Fault
    Sltiu::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = (Rs1 < imm) ? 1 : 0;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Sltiu::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})

    Fault
    Xori::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 ^ imm;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Xori::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::srli(['\n                        Rd = Rs1 >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    Fault
    Srli::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                        Rd = Rs1 >> imm;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Srli::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::srai(['\n                        Rd_sd = Rs1_sd >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    Fault
    Srai::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                        Rd = Rs1 >> imm;
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Srai::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})

    Fault
    Ori::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 | imm;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Ori::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})

    Fault
    Andi::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 & imm;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Andi::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// UOp::auipc((['\n            Rd = PC + (sext<20>(imm) << 12);\n        '], {}))

    Fault
    Auipc::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t PC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
PC = __parserAutoPCState.pc();
;
        
            Rd = PC + (sext<20>(imm) << 12);
        ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Auipc::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})

    Fault
    Addiw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 + imm;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Addiw::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::slliw(['\n                    Rd_sd = Rs1_sw << imm;\n                '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    Fault
    Slliw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                    Rd = Rs1 << imm;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Slliw::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> imm);\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    Fault
    Srliw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                        Rd = (int32_t)(Rs1 >> imm);
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Srliw::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    Fault
    Sraiw::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        
                        Rd = Rs1 >> imm;
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Sraiw::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0),srcRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})

    Fault
    Sb::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint8_t Rs2 = 0;
uint8_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    Sb::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint8_t Rs2 = 0;
uint8_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    Sb::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})

    Fault
    Sh::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint16_t Rs2 = 0;
uint16_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    Sh::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint16_t Rs2 = 0;
uint16_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    Sh::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})

    Fault
    Sw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    Sw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    Sw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})

    Fault
    Sd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    Sd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1 + offset;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    Sd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Store::fsw(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                "FPU is off", machInst);\n\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fault
    Fsw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                "FPU is off", machInst);

                    Mem = (uint32_t)Fs2_bits;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    Fsw::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                "FPU is off", machInst);

                    Mem = (uint32_t)Fs2_bits;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    Fsw::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Store::fsd(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                "FPU is off", machInst);\n\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fault
    Fsd::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                "FPU is off", machInst);

                    Mem = Fs2_bits;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;
        ;

        return NoFault;
    }

    Fault
    Fsd::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Fs2_bits = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;
        EA = Rs1 + offset;;

        
                    STATUS status = xc->readMiscReg(MISCREG_STATUS);
                    if (status.fs == FPUStatus::OFF)
                        return std::make_shared<IllegalInstFault>(
                                "FPU is off", machInst);

                    Mem = Fs2_bits;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault
    Fsd::completeAcc(PacketPtr pkt, ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        return NoFault;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))

    Fault
    Lr_w::Lr_wMicro::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lr_w::Lr_wMicro::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lr_w::Lr_wMicro::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))

    Fault Sc_w::Sc_wMicro::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        uint64_t result;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        &result);
            if (fault != NoFault)
                return fault;
        }
        // RISC-V has the opposite convention gem5 has for success flags,
        // so we invert the result here.
        result = !result;

        
                    Rd = result;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Sc_w::Sc_wMicro::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
uint32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    Mem = Rs2;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault Sc_w::Sc_wMicro::completeAcc(Packet *pkt,
          ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
;

        // RISC-V has the opposite convention gem5 has for success flags,
        // so we invert the result here.
        uint64_t result = !pkt->req->getExtraData();

        
                    Rd = result;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoadd_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                          new AtomicGenericOp<int32_t>(Rs2_sw,\n                                  [](int32_t* b, int32_t a){ *b += a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoadd_w::Amoadd_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int32_t> *amo_op =
                          new AtomicGenericOp<int32_t>(Rs2,
                                  [](int32_t* b, int32_t a){ *b += a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoadd_w::Amoadd_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int32_t> *amo_op =
                          new AtomicGenericOp<int32_t>(Rs2,
                                  [](int32_t* b, int32_t a){ *b += a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoadd_w::Amoadd_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoswap_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoswap_w::Amoswap_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoswap_w::Amoswap_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoswap_w::Amoswap_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoxor_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b ^= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoxor_w::Amoxor_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b ^= a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoxor_w::Amoxor_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b ^= a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoxor_w::Amoxor_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoor_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b |= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoor_w::Amoor_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b |= a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoor_w::Amoor_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b |= a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoor_w::Amoor_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoand_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b &= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoand_w::Amoand_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b &= a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoand_w::Amoand_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                          new AtomicGenericOp<uint32_t>(Rs2,
                                  [](uint32_t* b, uint32_t a){ *b &= a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoand_w::Amoand_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amomin_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                      new AtomicGenericOp<int32_t>(Rs2_sw,\n                        [](int32_t* b, int32_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amomin_w::Amomin_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int32_t> *amo_op =
                      new AtomicGenericOp<int32_t>(Rs2,
                        [](int32_t* b, int32_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amomin_w::Amomin_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int32_t> *amo_op =
                      new AtomicGenericOp<int32_t>(Rs2,
                        [](int32_t* b, int32_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amomin_w::Amomin_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amomax_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                      new AtomicGenericOp<int32_t>(Rs2_sw,\n                        [](int32_t* b, int32_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amomax_w::Amomax_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int32_t> *amo_op =
                      new AtomicGenericOp<int32_t>(Rs2,
                        [](int32_t* b, int32_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amomax_w::Amomax_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int32_t> *amo_op =
                      new AtomicGenericOp<int32_t>(Rs2,
                        [](int32_t* b, int32_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amomax_w::Amomax_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amominu_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                      new AtomicGenericOp<uint32_t>(Rs2_uw,\n                        [](uint32_t* b, uint32_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amominu_w::Amominu_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                      new AtomicGenericOp<uint32_t>(Rs2,
                        [](uint32_t* b, uint32_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amominu_w::Amominu_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                      new AtomicGenericOp<uint32_t>(Rs2,
                        [](uint32_t* b, uint32_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amominu_w::Amominu_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amomaxu_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                      new AtomicGenericOp<uint32_t>(Rs2_uw,\n                        [](uint32_t* b, uint32_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amomaxu_w::Amomaxu_wRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                      new AtomicGenericOp<uint32_t>(Rs2,
                        [](uint32_t* b, uint32_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amomaxu_w::Amomaxu_wRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint32_t Rs2 = 0;
int32_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint32_t> *amo_op =
                      new AtomicGenericOp<uint32_t>(Rs2,
                        [](uint32_t* b, uint32_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amomaxu_w::Amomaxu_wRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))

    Fault
    Lr_d::Lr_dMicro::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        {
            Fault fault =
                readMemAtomicLE(xc, traceData, EA, Mem, memAccessFlags);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Lr_d::Lr_dMicro::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
;
        EA = Rs1;;

        return initiateMemRead(xc, traceData, EA, Mem, memAccessFlags);
    }

    Fault
    Lr_d::Lr_dMicro::completeAcc(PacketPtr pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))

    Fault Sc_d::Sc_dMicro::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;
        uint64_t result;

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;

        
                    Mem = Rs2;
                ;

        {
            Fault fault =
                writeMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags,
                        &result);
            if (fault != NoFault)
                return fault;
        }
        // RISC-V has the opposite convention gem5 has for success flags,
        // so we invert the result here.
        result = !result;

        
                    Rd = result;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Sc_d::Sc_dMicro::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    Mem = Rs2;
                ;

        {
            Fault fault = writeMemTimingLE(xc, traceData, Mem, EA,
                memAccessFlags, nullptr);
            if (fault != NoFault)
                return fault;
        }

        ;

        return NoFault;
    }

    Fault Sc_d::Sc_dMicro::completeAcc(Packet *pkt,
          ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
;

        // RISC-V has the opposite convention gem5 has for success flags,
        // so we invert the result here.
        uint64_t result = !pkt->req->getExtraData();

        
                    Rd = result;
                ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoadd_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                          new AtomicGenericOp<int64_t>(Rs2_sd,\n                                  [](int64_t* b, int64_t a){ *b += a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoadd_d::Amoadd_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int64_t> *amo_op =
                          new AtomicGenericOp<int64_t>(Rs2,
                                  [](int64_t* b, int64_t a){ *b += a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoadd_d::Amoadd_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int64_t> *amo_op =
                          new AtomicGenericOp<int64_t>(Rs2,
                                  [](int64_t* b, int64_t a){ *b += a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoadd_d::Amoadd_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoswap_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                  [](uint64_t* b, uint64_t a){ *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoswap_d::Amoswap_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                  [](uint64_t* b, uint64_t a){ *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoswap_d::Amoswap_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                  [](uint64_t* b, uint64_t a){ *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoswap_d::Amoswap_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoxor_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b ^= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoxor_d::Amoxor_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                 [](uint64_t* b, uint64_t a){ *b ^= a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoxor_d::Amoxor_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                 [](uint64_t* b, uint64_t a){ *b ^= a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoxor_d::Amoxor_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoor_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b |= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoor_d::Amoor_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                 [](uint64_t* b, uint64_t a){ *b |= a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoor_d::Amoor_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                 [](uint64_t* b, uint64_t a){ *b |= a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoor_d::Amoor_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amoand_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b &= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amoand_d::Amoand_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                 [](uint64_t* b, uint64_t a){ *b &= a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amoand_d::Amoand_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                          new AtomicGenericOp<uint64_t>(Rs2,
                                 [](uint64_t* b, uint64_t a){ *b &= a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amoand_d::Amoand_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amomin_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                      new AtomicGenericOp<int64_t>(Rs2_sd,\n                        [](int64_t* b, int64_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amomin_d::Amomin_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int64_t> *amo_op =
                      new AtomicGenericOp<int64_t>(Rs2,
                        [](int64_t* b, int64_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amomin_d::Amomin_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int64_t> *amo_op =
                      new AtomicGenericOp<int64_t>(Rs2,
                        [](int64_t* b, int64_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amomin_d::Amomin_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amomax_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                      new AtomicGenericOp<int64_t>(Rs2_sd,\n                        [](int64_t* b, int64_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amomax_d::Amomax_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int64_t> *amo_op =
                      new AtomicGenericOp<int64_t>(Rs2,
                        [](int64_t* b, int64_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amomax_d::Amomax_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
int64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<int64_t> *amo_op =
                      new AtomicGenericOp<int64_t>(Rs2,
                        [](int64_t* b, int64_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amomax_d::Amomax_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amominu_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                      new AtomicGenericOp<uint64_t>(Rs2_ud,\n                        [](uint64_t* b, uint64_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amominu_d::Amominu_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                      new AtomicGenericOp<uint64_t>(Rs2,
                        [](uint64_t* b, uint64_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amominu_d::Amominu_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                      new AtomicGenericOp<uint64_t>(Rs2,
                        [](uint64_t* b, uint64_t a){ if (a < *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amominu_d::Amominu_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// AtomicMemOp::amomaxu_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                      new AtomicGenericOp<uint64_t>(Rs2_ud,\n                        [](uint64_t* b, uint64_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Fault Amomaxu_d::Amomaxu_dRMW::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        int64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                      new AtomicGenericOp<uint64_t>(Rs2,
                        [](uint64_t* b, uint64_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        {
            Fault fault =
                amoMemAtomicLE(xc, traceData, Mem, EA, memAccessFlags, amo_op);
            if (fault != NoFault)
                return fault;
        }

        
                    Rd = Mem;
                ;
         ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

    Fault
    Amomaxu_d::Amomaxu_dRMW::initiateAcc(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        Addr EA;

        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
int64_t Mem = {};
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        EA = Rs1;;
        
                    TypedAtomicOpFunctor<uint64_t> *amo_op =
                      new AtomicGenericOp<uint64_t>(Rs2,
                        [](uint64_t* b, uint64_t a){ if (a > *b) *b = a; });
                ;

        assert(amo_op);

        return initiateMemAMO(xc, traceData, EA, Mem, memAccessFlags, amo_op);
    }

    Fault Amomaxu_d::Amomaxu_dRMW::completeAcc(Packet *pkt,
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Mem = {};
;
        ;

        getMemLE(pkt, Mem, traceData);

        
                    Rd = Mem;
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})

    Fault
    Add::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 + Rs2;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})

    Fault
    Mul::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1*Rs2;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})

    Fault
    Sub::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 - Rs2;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})

    Fault
    Sll::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 << bits(Rs2, 5, 0);
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})

    Fault
    Mulh::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        bool negate = (Rs1 < 0) != (Rs2 < 0);

                        uint64_t Rs1_lo = (uint32_t)abs(Rs1);
                        uint64_t Rs1_hi = (uint64_t)abs(Rs1) >> 32;
                        uint64_t Rs2_lo = (uint32_t)abs(Rs2);
                        uint64_t Rs2_hi = (uint64_t)abs(Rs2) >> 32;

                        uint64_t hi = Rs1_hi*Rs2_hi;
                        uint64_t mid1 = Rs1_hi*Rs2_lo;
                        uint64_t mid2 = Rs1_lo*Rs2_hi;
                        uint64_t lo = Rs2_lo*Rs1_lo;
                        uint64_t carry = ((uint64_t)(uint32_t)mid1
                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;

                        uint64_t res = hi +
                                       (mid1 >> 32) +
                                       (mid2 >> 32) +
                                       carry;
                        Rd = negate ? ~res + (Rs1*Rs2 == 0 ? 1 : 0)
                                    : res;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})

    Fault
    Slt::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = (Rs1 < Rs2) ? 1 : 0;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})

    Fault
    Mulhsu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        bool negate = Rs1 < 0;
                        uint64_t Rs1_lo = (uint32_t)abs(Rs1);
                        uint64_t Rs1_hi = (uint64_t)abs(Rs1) >> 32;
                        uint64_t Rs2_lo = (uint32_t)Rs2;
                        uint64_t Rs2_hi = Rs2 >> 32;

                        uint64_t hi = Rs1_hi*Rs2_hi;
                        uint64_t mid1 = Rs1_hi*Rs2_lo;
                        uint64_t mid2 = Rs1_lo*Rs2_hi;
                        uint64_t lo = Rs1_lo*Rs2_lo;
                        uint64_t carry = ((uint64_t)(uint32_t)mid1
                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;

                        uint64_t res = hi +
                                       (mid1 >> 32) +
                                       (mid2 >> 32) +
                                       carry;
                        Rd = negate ? ~res + (Rs1*Rs2 == 0 ? 1 : 0) : res;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})

    Fault
    Sltu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = (Rs1 < Rs2) ? 1 : 0;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})

    Fault
    Mulhu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        uint64_t Rs1_lo = (uint32_t)Rs1;
                        uint64_t Rs1_hi = Rs1 >> 32;
                        uint64_t Rs2_lo = (uint32_t)Rs2;
                        uint64_t Rs2_hi = Rs2 >> 32;

                        uint64_t hi = Rs1_hi*Rs2_hi;
                        uint64_t mid1 = Rs1_hi*Rs2_lo;
                        uint64_t mid2 = Rs1_lo*Rs2_hi;
                        uint64_t lo = Rs1_lo*Rs2_lo;
                        uint64_t carry = ((uint64_t)(uint32_t)mid1
                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;

                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})

    Fault
    Xor::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 ^ Rs2;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (\n                                Rs1_sd == std::numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = std::numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Div::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        if (Rs2 == 0) {
                            Rd = -1;
                        } else if (
                                Rs1 == std::numeric_limits<int64_t>::min()
                                && Rs2 == -1) {
                            Rd = std::numeric_limits<int64_t>::min();
                        } else {
                            Rd = Rs1/Rs2;
                        }
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})

    Fault
    Srl::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 >> bits(Rs2, 5, 0);
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = std::numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Divu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        if (Rs2 == 0) {
                            Rd = std::numeric_limits<uint64_t>::max();
                        } else {
                            Rd = Rs1/Rs2;
                        }
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})

    Fault
    Sra::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 >> bits(Rs2, 5, 0);
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})

    Fault
    Or::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 | Rs2;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (\n                                Rs1_sd == std::numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Rem::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
int64_t Rs1 = 0;
int64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        if (Rs2 == 0) {
                            Rd = Rs1;
                        } else if (
                                Rs1 == std::numeric_limits<int64_t>::min()
                                && Rs2 == -1) {
                            Rd = 0;
                        } else {
                            Rd = Rs1%Rs2;
                        }
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})

    Fault
    And::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 & Rs2;
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Remu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        if (Rs2 == 0) {
                            Rd = Rs1;
                        } else {
                            Rd = Rs1%Rs2;
                        }
                    ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// UOp::lui((['\n            Rd = (uint64_t)(sext<20>(imm) << 12);\n        '], {}))

    Fault
    Lui::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
;
        ;
        
            Rd = (uint64_t)(sext<20>(imm) << 12);
        ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

    std::string
    Lui::generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})

    Fault
    Addw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 + Rs2;
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})

    Fault
    Mulw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = (int32_t)(Rs1*Rs2);
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})

    Fault
    Subw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 - Rs2;
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})

    Fault
    Sllw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                    Rd = Rs1 << bits(Rs2, 4, 0);
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == std::numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = std::numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Fault
    Divw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                    if (Rs2 == 0) {
                        Rd = -1;
                    } else if (Rs1 == std::numeric_limits<int32_t>::min()
                            && Rs2 == -1) {
                        Rd = std::numeric_limits<int32_t>::min();
                    } else {
                        Rd = Rs1/Rs2;
                    }
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})

    Fault
    Srlw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
uint32_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = (int32_t)(Rs1 >> bits(Rs2, 4, 0));
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = std::numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})

    Fault
    Divuw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
uint32_t Rs1 = 0;
uint32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        if (Rs2 == 0) {
                            Rd = std::numeric_limits<uint64_t>::max();
                        } else {
                            Rd = (int32_t)(Rs1/Rs2);
                        }
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})

    Fault
    Sraw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        Rd = Rs1 >> bits(Rs2, 4, 0);
                    ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == std::numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Fault
    Remw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
int32_t Rs1 = 0;
int32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                    if (Rs2 == 0) {
                        Rd = Rs1;
                    } else if (Rs1 == std::numeric_limits<int32_t>::min()
                            && Rs2 == -1) {
                        Rd = 0;
                    } else {
                        Rd = Rs1%Rs2;
                    }
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})

    Fault
    Remuw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rd = 0;
uint32_t Rs1 = 0;
uint32_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                    if (Rs2 == 0) {
                        Rd = (int32_t)Rs1;
                    } else {
                        Rd = (int32_t)(Rs1%Rs2);
                    }
                ;
        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),\n                                         f32(freg(Fs2_bits)),\n                                         f32(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fmadd_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),
                                         f32(freg(Fs2_bits)),
                                         f32(freg(Fs3_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),\n                                         f64(freg(Fs2_bits)),\n                                         f64(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fmadd_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),
                                         f64(freg(Fs2_bits)),
                                         f64(freg(Fs3_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),\n                                    f32(freg(Fs2_bits)),\n                                    f32(f32(freg(Fs3_bits)).v ^\n                                        mask(31, 31))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fmsub_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),
                                    f32(freg(Fs2_bits)),
                                    f32(f32(freg(Fs3_bits)).v ^
                                        mask(31, 31))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),\n                                    f64(freg(Fs2_bits)),\n                                    f64(f64(freg(Fs3_bits)).v ^\n                                        mask(63, 63))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fmsub_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),
                                    f64(freg(Fs2_bits)),
                                    f64(f64(freg(Fs3_bits)).v ^
                                        mask(63, 63))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^\n                                             mask(31, 31)),\n                                         f32(freg(Fs2_bits)),\n                                         f32(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fnmsub_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^
                                             mask(31, 31)),
                                         f32(freg(Fs2_bits)),
                                         f32(freg(Fs3_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fnmsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^\n                                             mask(63, 63)),\n                                         f64(freg(Fs2_bits)),\n                                         f64(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fnmsub_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^
                                             mask(63, 63)),
                                         f64(freg(Fs2_bits)),
                                         f64(freg(Fs3_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^\n                                             mask(31, 31)),\n                                    f32(freg(Fs2_bits)),\n                                    f32(f32(freg(Fs3_bits)).v ^\n                                        mask(31, 31))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fnmadd_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^
                                             mask(31, 31)),
                                    f32(freg(Fs2_bits)),
                                    f32(f32(freg(Fs3_bits)).v ^
                                        mask(31, 31))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fnmadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^\n                                             mask(63, 63)),\n                                    f64(freg(Fs2_bits)),\n                                    f64(f64(freg(Fs3_bits)).v ^\n                                        mask(63, 63))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fault Fnmadd_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
uint64_t Fs3_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
Fs3_bits = xc->readFloatRegOperandBits(this, 2);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^
                                             mask(63, 63)),
                                    f64(freg(Fs2_bits)),
                                    f64(f64(freg(Fs3_bits)).v ^
                                        mask(63, 63))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_add(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fault Fadd_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_add(f32(freg(Fs1_bits)),
                                      f32(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_add(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fault Fadd_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_add(f64(freg(Fs1_bits)),
                                      f64(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_sub(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fault Fsub_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_sub(f32(freg(Fs1_bits)),
                                      f32(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_sub(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fault Fsub_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_sub(f64(freg(Fs1_bits)),
                                      f64(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmul_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mul(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultOp'],{})

    Fault Fmul_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_mul(f32(freg(Fs1_bits)),
                                      f32(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmul_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mul(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultOp'],{})

    Fault Fmul_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_mul(f64(freg(Fs1_bits)),
                                      f64(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fdiv_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_div(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatDivOp'],{})

    Fault Fdiv_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_div(f32(freg(Fs1_bits)),
                                      f32(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fdiv_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_div(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatDivOp'],{})

    Fault Fdiv_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_div(f64(freg(Fs1_bits)),
                                      f64(freg(Fs2_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsgnj_s(['\n                        Fd_bits = boxF32(insertBits(unboxF32(Fs2_bits), 30, 0,\n                                                    unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    Fault Fsgnj_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Fd_bits = boxF32(insertBits(unboxF32(Fs2_bits), 30, 0,
                                                    unboxF32(Fs1_bits)));
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsgnjn_s(['\n                        Fd_bits = boxF32(insertBits(unboxF32(~Fs2_bits), 30, 0,\n                                                    unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    Fault Fsgnjn_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Fd_bits = boxF32(insertBits(unboxF32(~Fs2_bits), 30, 0,
                                                    unboxF32(Fs1_bits)));
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsgnjx_s(['\n                        Fd_bits = boxF32(insertBits(\n                                    unboxF32(Fs1_bits) ^ unboxF32(Fs2_bits),\n                                    30, 0, unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    Fault Fsgnjx_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Fd_bits = boxF32(insertBits(
                                    unboxF32(Fs1_bits) ^ unboxF32(Fs2_bits),
                                    30, 0, unboxF32(Fs1_bits)));
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fsgnj_d(['\n                        Fd_bits = insertBits(Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnj_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Fd_bits = insertBits(Fs2_bits, 62, 0, Fs1_bits);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsgnjn_d(['\n                        Fd_bits = insertBits(~Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnjn_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Fd_bits = insertBits(~Fs2_bits, 62, 0, Fs1_bits);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsgnjx_d(['\n                        Fd_bits = insertBits(\n                                Fs1_bits ^ Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    Fault Fsgnjx_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Fd_bits = insertBits(
                                Fs1_bits ^ Fs2_bits, 62, 0, Fs1_bits);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_s(['\n                        bool less = f32_lt_quiet(f32(freg(Fs1_bits)),\n                            f32(freg(Fs2_bits))) ||\n                            (f32_eq(f32(freg(Fs1_bits)),\n                            f32(freg(Fs2_bits))) &&\n                            bits(f32(freg(Fs1_bits)).v, 31));\n\n                        Fd_bits = less ||\n                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&\n                            isNaNF32UI(f32(freg(Fs2_bits)).v))\n                            Fd_bits = f32(defaultNaNF32UI).v;\n                        ', 'FloatCmpOp'],{})

    Fault Fmin_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        bool less = f32_lt_quiet(f32(freg(Fs1_bits)),
                            f32(freg(Fs2_bits))) ||
                            (f32_eq(f32(freg(Fs1_bits)),
                            f32(freg(Fs2_bits))) &&
                            bits(f32(freg(Fs1_bits)).v, 31));

                        Fd_bits = less ||
                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?
                            freg(Fs1_bits).v : freg(Fs2_bits).v;
                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&
                            isNaNF32UI(f32(freg(Fs2_bits)).v))
                            Fd_bits = f32(defaultNaNF32UI).v;
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmax_s(['\n                        bool greater = f32_lt_quiet(f32(freg(Fs2_bits)),\n                            f32(freg(Fs1_bits))) ||\n                            (f32_eq(f32(freg(Fs2_bits)),\n                            f32(freg(Fs1_bits))) &&\n                            bits(f32(freg(Fs2_bits)).v, 31));\n\n                        Fd_bits = greater ||\n                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&\n                            isNaNF32UI(f32(freg(Fs2_bits)).v))\n                            Fd_bits = f32(defaultNaNF32UI).v;\n                        ', 'FloatCmpOp'],{})

    Fault Fmax_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        bool greater = f32_lt_quiet(f32(freg(Fs2_bits)),
                            f32(freg(Fs1_bits))) ||
                            (f32_eq(f32(freg(Fs2_bits)),
                            f32(freg(Fs1_bits))) &&
                            bits(f32(freg(Fs2_bits)).v, 31));

                        Fd_bits = greater ||
                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?
                            freg(Fs1_bits).v : freg(Fs2_bits).v;
                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&
                            isNaNF32UI(f32(freg(Fs2_bits)).v))
                            Fd_bits = f32(defaultNaNF32UI).v;
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_d(['\n                        bool less = f64_lt_quiet(f64(freg(Fs1_bits)),\n                            f64(freg(Fs2_bits))) ||\n                            (f64_eq(f64(freg(Fs1_bits)),\n                            f64(freg(Fs2_bits))) &&\n                            bits(f64(freg(Fs1_bits)).v, 63));\n\n                        Fd_bits = less ||\n                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&\n                            isNaNF64UI(f64(freg(Fs2_bits)).v))\n                            Fd_bits = f64(defaultNaNF64UI).v;\n                    ', 'FloatCmpOp'],{})

    Fault Fmin_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        bool less = f64_lt_quiet(f64(freg(Fs1_bits)),
                            f64(freg(Fs2_bits))) ||
                            (f64_eq(f64(freg(Fs1_bits)),
                            f64(freg(Fs2_bits))) &&
                            bits(f64(freg(Fs1_bits)).v, 63));

                        Fd_bits = less ||
                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?
                            freg(Fs1_bits).v : freg(Fs2_bits).v;
                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&
                            isNaNF64UI(f64(freg(Fs2_bits)).v))
                            Fd_bits = f64(defaultNaNF64UI).v;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmax_d(['\n                        bool greater =\n                            f64_lt_quiet(f64(freg(Fs2_bits)),\n                            f64(freg(Fs1_bits))) ||\n                            (f64_eq(f64(freg(Fs2_bits)),\n                            f64(freg(Fs1_bits))) &&\n                            bits(f64(freg(Fs2_bits)).v, 63));\n\n                        Fd_bits = greater ||\n                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&\n                            isNaNF64UI(f64(Fs2_bits).v))\n                            Fd_bits = f64(defaultNaNF64UI).v;\n                    ', 'FloatCmpOp'],{})

    Fault Fmax_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        bool greater =
                            f64_lt_quiet(f64(freg(Fs2_bits)),
                            f64(freg(Fs1_bits))) ||
                            (f64_eq(f64(freg(Fs2_bits)),
                            f64(freg(Fs1_bits))) &&
                            bits(f64(freg(Fs2_bits)).v, 63));

                        Fd_bits = greater ||
                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?
                            freg(Fs1_bits).v : freg(Fs2_bits).v;
                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&
                            isNaNF64UI(f64(Fs2_bits).v))
                            Fd_bits = f64(defaultNaNF64UI).v;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        return std::make_shared<IllegalInstFault>(\n                                "CONV_SGN != 1", machInst);\n                    }\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_to_f32(f64(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fault Fcvt_s_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    if (CONV_SGN != 1) {
                        return std::make_shared<IllegalInstFault>(
                                "CONV_SGN != 1", machInst);
                    }
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f64_to_f32(f64(freg(Fs1_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "CONV_SGN != 0", machInst);\n                    }\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_to_f64(f32(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fault Fcvt_d_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    if (CONV_SGN != 0) {
                        return std::make_shared<IllegalInstFault>(
                                "CONV_SGN != 0", machInst);
                    }
                    RM_REQUIRED;
                    freg_t fd;
                    fd = freg(f32_to_f64(f32(freg(Fs1_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    freg_t fd;\n                    RM_REQUIRED;\n                    fd = freg(f32_sqrt(f32(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatSqrtOp'],{})

    Fault Fsqrt_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    if (RS2 != 0) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x1", machInst);
                    }
                    freg_t fd;
                    RM_REQUIRED;
                    fd = freg(f32_sqrt(f32(freg(Fs1_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    freg_t fd;\n                    RM_REQUIRED;\n                    fd = freg(f64_sqrt(f64(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatSqrtOp'],{})

    Fault Fsqrt_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    if (RS2 != 0) {
                        return std::make_shared<IllegalInstFault>(
                                "source reg x1", machInst);
                    }
                    freg_t fd;
                    RM_REQUIRED;
                    fd = freg(f64_sqrt(f64(freg(Fs1_bits))));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fle_s(['\n                        Rd = f32_le(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fault Fle_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f32_le(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::flt_s(['\n                        Rd = f32_lt(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fault Flt_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f32_lt(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::feq_s(['\n                        Rd = f32_eq(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fault Feq_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f32_eq(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fle_d(['\n                        Rd = f64_le(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fault Fle_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f64_le(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::flt_d(['\n                        Rd = f64_lt(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fault Flt_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f64_lt(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::feq_d(['\n                        Rd = f64_eq(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fault Feq_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
uint64_t Fs2_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
Fs2_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f64_eq(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_s(['\n                        RM_REQUIRED;\n                        Rd_sd = sext<32>(f32_to_i32(f32(freg(Fs1_bits)), rm,\n                                                    true));\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_w_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        int64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = sext<32>(f32_to_i32(f32(freg(Fs1_bits)), rm,
                                                    true));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_wu_s(['\n                        RM_REQUIRED;\n                        Rd = sext<32>(f32_to_ui32(f32(freg(Fs1_bits)), rm,\n                                                  true));\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_wu_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = sext<32>(f32_to_ui32(f32(freg(Fs1_bits)), rm,
                                                  true));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_l_s(['\n                        RM_REQUIRED;\n                        Rd_sd = f32_to_i64(f32(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_l_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        int64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = f32_to_i64(f32(freg(Fs1_bits)), rm, true);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_lu_s(['\n                        RM_REQUIRED;\n                        Rd = f32_to_ui64(f32(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_lu_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = f32_to_ui64(f32(freg(Fs1_bits)), rm, true);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_d(['\n                        RM_REQUIRED;\n                        Rd_sd = sext<32>(f64_to_i32(f64(freg(Fs1_bits)), rm,\n                                                    true));\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_w_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        int64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = sext<32>(f64_to_i32(f64(freg(Fs1_bits)), rm,
                                                    true));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_wu_d(['\n                        RM_REQUIRED;\n                        Rd = sext<32>(f64_to_ui32(f64(freg(Fs1_bits)), rm,\n                                                  true));\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_wu_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = sext<32>(f64_to_ui32(f64(freg(Fs1_bits)), rm,
                                                  true));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_l_d(['\n                        RM_REQUIRED;\n                        Rd_sd = f64_to_i64(f64(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_l_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        int64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = f64_to_i64(f64(freg(Fs1_bits)), rm, true);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            int64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_lu_d(['\n                        RM_REQUIRED;\n                        Rd = f64_to_ui64(f64(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_lu_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Rd = f64_to_ui64(f64(freg(Fs1_bits)), rm, true);
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_w(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(i32_to_f32((int32_t)Rs1_sw));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fault Fcvt_s_w::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        freg_t fd;
                        fd = freg(i32_to_f32((int32_t)Rs1));
                        Fd_bits = fd.v;
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_s_wu(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(ui32_to_f32((int32_t)Rs1_uw));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fault Fcvt_s_wu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        freg_t fd;
                        fd = freg(ui32_to_f32((int32_t)Rs1));
                        Fd_bits = fd.v;
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_s_l(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(i64_to_f32(Rs1_ud));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fault Fcvt_s_l::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        freg_t fd;
                        fd = freg(i64_to_f32(Rs1));
                        Fd_bits = fd.v;
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_s_lu(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(ui64_to_f32(Rs1));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fault Fcvt_s_lu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        freg_t fd;
                        fd = freg(ui64_to_f32(Rs1));
                        Fd_bits = fd.v;
                        ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_d_w(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_w::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        double Fd = 0;
int32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Fd = (double)Rs1;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            double final_val = Fd;
            xc->setFloatRegOperandBits(this, 0, floatToBits64(final_val));

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_d_wu(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_wu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        double Fd = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Fd = (double)Rs1;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            double final_val = Fd;
            xc->setFloatRegOperandBits(this, 0, floatToBits64(final_val));

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_d_l(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_l::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        double Fd = 0;
int64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Fd = (double)Rs1;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            double final_val = Fd;
            xc->setFloatRegOperandBits(this, 0, floatToBits64(final_val));

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fcvt_d_lu(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})

    Fault Fcvt_d_lu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        double Fd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        RM_REQUIRED;
                        Fd = (double)Rs1;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            double final_val = Fd;
            xc->setFloatRegOperandBits(this, 0, floatToBits64(final_val));

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})

    Fault Fmv_x_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Rd = xc->readIntRegOperand(this, 0);
Fs1_bits = xc->readFloatRegOperandBits(this, 1);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = (uint32_t)Fs1_bits;
                        if ((Rd&0x80000000) != 0) {
                            Rd |= (0xFFFFFFFFULL << 32);
                        }
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fclass_s(['\n                        Rd = f32_classify(f32(freg(Fs1_bits)));\n                    ', 'FloatMiscOp'],{})

    Fault Fclass_s::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f32_classify(f32(freg(Fs1_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_d(['\n                        Rd = freg(Fs1_bits).v;\n                    ', 'FloatCvtOp'],{})

    Fault Fmv_x_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = freg(Fs1_bits).v;
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fclass_d(['\n                        Rd = f64_classify(f64(freg(Fs1_bits)));\n                    ', 'FloatMiscOp'],{})

    Fault Fclass_d::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Rd = 0;
uint64_t Fs1_bits = 0;
;
        Fs1_bits = xc->readFloatRegOperandBits(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                        Rd = f64_classify(f64(freg(Fs1_bits)));
                    ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_s_x(['\n                    freg_t fd;\n                    fd = freg(f32(Rs1_uw));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fault Fmv_s_x::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint32_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    freg_t fd;
                    fd = freg(f32(Rs1));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// FPROp::fmv_d_x(['\n                    freg_t fd;\n                    fd = freg(f64(Rs1));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fault Fmv_d_x::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        STATUS status = xc->readMiscReg(MISCREG_STATUS);
        if (status.fs == FPUStatus::OFF)
            return std::make_shared<IllegalInstFault>("FPU is off", machInst);

        uint64_t Fd_bits = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal FFLAGS = xc->readMiscReg(MISCREG_FFLAGS);
        std::feclearexcept(FE_ALL_EXCEPT);
        
                    freg_t fd;
                    fd = freg(f64(Rs1));
                    Fd_bits = fd.v;
                ;

        FFLAGS |= softfloat_exceptionFlags;
        softfloat_exceptionFlags = 0;
        xc->setMiscReg(MISCREG_FFLAGS, FFLAGS);

        
        {
            uint64_t final_val = Fd_bits;
            xc->setFloatRegOperandBits(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };

        return NoFault;
    }

// Unknown::unknown(([], {}))

// BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Beq::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                    if (Rs1 == Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Beq::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Beq::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bne::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                    if (Rs1 != Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Bne::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bne::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Blt::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rs1 = 0;
int64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                    if (Rs1 < Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Blt::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Blt::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bge::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        int64_t Rs1 = 0;
int64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                    if (Rs1 >= Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Bge::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bge::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bltu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                    if (Rs1 < Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Bltu::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bltu::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Fault
    Bgeu::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
                    if (Rs1 >= Rs2) {
                        NPC = PC + imm;
                    } else {
                        NPC = NPC;
                    }
                ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Bgeu::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Bgeu::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {srcRegIdx(0),srcRegIdx(1)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// Unknown::unknown(([], {}))

// Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    Jalr::execute(
        ExecContext *xc, Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t Rs1 = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
Rs1 = xc->readIntRegOperand(this, 0);
NPC = __parserAutoPCState.npc();
;
        
                Rd = NPC;
                NPC = (imm + Rs1) & (~0x1);
            ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }__parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Jalr::branchTarget(ThreadContext *tc) const
    {
        PCState pc = tc->pcState();
        pc.set((tc->readIntReg(srcRegIdx(0).index()) + imm)&~0x1);
        return pc;
    }

    std::string
    Jalr::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::stringstream ss;
        ss << mnemonic << ' ';
        if (QUADRANT == 0x3)
            ss << registerName(destRegIdx(0)) << ", "
               << imm << "(" << registerName(srcRegIdx(0)) << ")";
        else
            ss << registerName(srcRegIdx(0));
        return ss.str();
    }

// Unknown::unknown(([], {}))

// JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))

    Fault
    Jal::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rd = 0;
uint64_t PC = 0;
uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
PC = __parserAutoPCState.pc();
NPC = __parserAutoPCState.npc();
;
        
            Rd = NPC;
            NPC = PC + imm;
        ;
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        }__parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

    RiscvISA::PCState
    Jal::branchTarget(const RiscvISA::PCState &branchPC) const
    {
        return branchPC.pc() + imm;
    }

    std::string
    Jal::generateDisassembly(
            Addr pc, const loader::SymbolTable *symtab) const
    {
        std::vector<RegId> indices = {destRegIdx(0)};
        std::stringstream ss;
        ss << mnemonic << ' ';
        for (const RegId& idx: indices)
            ss << registerName(idx) << ", ";
        ss << imm;
        return ss.str();
    }

// SystemOp::ecall(['\n                            return std::make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})

    Fault
    Ecall::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        ;
        ;
        
                            return std::make_shared<SyscallFault>(
                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));
                        ;
        ;
        return NoFault;
    }

// SystemOp::ebreak(['\n                            return std::make_shared<BreakpointFault>(\n                                xc->pcState());\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Ebreak::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        ;
        ;
        
                            return std::make_shared<BreakpointFault>(
                                xc->pcState());
                        ;
        ;
        return NoFault;
    }

// SystemOp::uret(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            status.uie = status.upie;\n                            status.upie = 1;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_UEPC);\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    Fault
    Uret::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
;
        
                            STATUS status = xc->readMiscReg(MISCREG_STATUS);
                            status.uie = status.upie;
                            status.upie = 1;
                            xc->setMiscReg(MISCREG_STATUS, status);
                            NPC = xc->readMiscReg(MISCREG_UEPC);
                        ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

// Unknown::unknown(([], {}))

// SystemOp::sret(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            auto pm = (PrivilegeMode)xc->readMiscReg(\n                                MISCREG_PRV);\n                            if (pm == PRV_U ||\n                                (pm == PRV_S && status.tsr == 1)) {\n                                return std::make_shared<IllegalInstFault>(\n                                            "sret in user mode or TSR enabled",\n                                            machInst);\n                                NPC = NPC;\n                            } else {\n                                xc->setMiscReg(MISCREG_PRV, status.spp);\n                                status.sie = status.spie;\n                                status.spie = 1;\n                                status.spp = PRV_U;\n                                xc->setMiscReg(MISCREG_STATUS, status);\n                                NPC = xc->readMiscReg(MISCREG_SEPC);\n                            }\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    Fault
    Sret::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
NPC = __parserAutoPCState.npc();
;
        
                            STATUS status = xc->readMiscReg(MISCREG_STATUS);
                            auto pm = (PrivilegeMode)xc->readMiscReg(
                                MISCREG_PRV);
                            if (pm == PRV_U ||
                                (pm == PRV_S && status.tsr == 1)) {
                                return std::make_shared<IllegalInstFault>(
                                            "sret in user mode or TSR enabled",
                                            machInst);
                                NPC = NPC;
                            } else {
                                xc->setMiscReg(MISCREG_PRV, status.spp);
                                status.sie = status.spie;
                                status.spie = 1;
                                status.spp = PRV_U;
                                xc->setMiscReg(MISCREG_STATUS, status);
                                NPC = xc->readMiscReg(MISCREG_SEPC);
                            }
                        ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

// SystemOp::wfi(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            auto pm = (PrivilegeMode)xc->readMiscReg(\n                                MISCREG_PRV);\n                            if (pm == PRV_U ||\n                                (pm == PRV_S && status.tw == 1)) {\n                                return std::make_shared<IllegalInstFault>(\n                                            "wfi in user mode or TW enabled",\n                                            machInst);\n                            }\n                            // don\'t do anything for now\n                        ', 'No_OpClass'],{})

    Fault
    Wfi::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        ;
        ;
        
                            STATUS status = xc->readMiscReg(MISCREG_STATUS);
                            auto pm = (PrivilegeMode)xc->readMiscReg(
                                MISCREG_PRV);
                            if (pm == PRV_U ||
                                (pm == PRV_S && status.tw == 1)) {
                                return std::make_shared<IllegalInstFault>(
                                            "wfi in user mode or TW enabled",
                                            machInst);
                            }
                            // don't do anything for now
                        ;
        ;
        return NoFault;
    }

// Unknown::unknown(([], {}))

// SystemOp::sfence_vma(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);\n                        if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {\n                            return std::make_shared<IllegalInstFault>(\n                                        "sfence in user mode or TVM enabled",\n                                        machInst);\n                        }\n                        xc->tcBase()->getMMUPtr()->demapPage(Rs1, Rs2);\n                    ', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    Fault
    Sfence_vma::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t Rs1 = 0;
uint64_t Rs2 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
Rs2 = xc->readIntRegOperand(this, 1);
;
        
                        STATUS status = xc->readMiscReg(MISCREG_STATUS);
                        auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
                        if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                            return std::make_shared<IllegalInstFault>(
                                        "sfence in user mode or TVM enabled",
                                        machInst);
                        }
                        xc->tcBase()->getMMUPtr()->demapPage(Rs1, Rs2);
                    ;
        ;
        return NoFault;
    }

// SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            return std::make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    Fault
    Mret::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t NPC = 0;
TheISA::PCState __parserAutoPCState;
;
        __parserAutoPCState = xc->pcState();
NPC = __parserAutoPCState.npc();
;
        
                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {
                            return std::make_shared<IllegalInstFault>(
                                        "mret at lower privilege", machInst);
                            NPC = NPC;
                        } else {
                            STATUS status = xc->readMiscReg(MISCREG_STATUS);
                            xc->setMiscReg(MISCREG_PRV, status.mpp);
                            status.mie = status.mpie;
                            status.mpie = 1;
                            status.mpp = PRV_U;
                            xc->setMiscReg(MISCREG_STATUS, status);
                            NPC = xc->readMiscReg(MISCREG_MEPC);
                        }
                    ;
        __parserAutoPCState.npc(NPC);
xc->pcState(__parserAutoPCState);
;
        return NoFault;
    }

// Unknown::unknown(([], {}))

// CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrw::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        if (!valid) {
            return std::make_shared<IllegalInstFault>(
                    csprintf("Illegal CSR index %#x\n", csr), machInst);
        }

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal data, olddata;

        switch (csr) {
          case CSR_SATP: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            STATUS status = xc->readMiscReg(MISCREG_STATUS);
            if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                return std::make_shared<IllegalInstFault>(
                        "SATP access in user mode or with TVM enabled\n",
                        machInst);
            }
            break;
          }
          case CSR_MSTATUS: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            if (pm != PrivilegeMode::PRV_M) {
                return std::make_shared<IllegalInstFault>(
                        "MSTATUS is only accessibly in machine mode\n",
                        machInst);
            }
            break;
          }
          default:
            break;
        }

        if (csr == CSR_FCSR) {
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
        } else {
            olddata = xc->readMiscReg(midx);
        }
        auto olddata_all = olddata;

        olddata &= maskVal;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", csrName, olddata);
        data = olddata;

        
                    Rd = data;
                    data = Rs1;
                ;

        data &= maskVal;
        if (data != olddata) {
            if (bits(csr, 11, 10) == 0x3) {
                return std::make_shared<IllegalInstFault>(
                        csprintf("CSR %s is read-only\n", csrName), machInst);
            }
            auto newdata_all = data;
            // We must keep those original bits not in mask.
            // olddata and data only contain the bits visable
            // in current privilige level.
            newdata_all = (olddata_all & ~maskVal) | data;
            DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n",
                    newdata_all, csrName);
            switch (csr) {
              case CSR_FCSR:
                xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                break;
              case CSR_MIP: case CSR_MIE:
              case CSR_SIP: case CSR_SIE:
              case CSR_UIP: case CSR_UIE:
              case CSR_MSTATUS: case CSR_SSTATUS: case CSR_USTATUS:
                if (newdata_all != olddata_all) {
                    xc->setMiscReg(midx, newdata_all);
                } else {
                    return std::make_shared<IllegalInstFault>(
                            "Only bits in mask are allowed to be set\n",
                            machInst);
                }
                break;
              default:
                xc->setMiscReg(midx, data);
                break;
            }
        }
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrs::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        if (!valid) {
            return std::make_shared<IllegalInstFault>(
                    csprintf("Illegal CSR index %#x\n", csr), machInst);
        }

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal data, olddata;

        switch (csr) {
          case CSR_SATP: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            STATUS status = xc->readMiscReg(MISCREG_STATUS);
            if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                return std::make_shared<IllegalInstFault>(
                        "SATP access in user mode or with TVM enabled\n",
                        machInst);
            }
            break;
          }
          case CSR_MSTATUS: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            if (pm != PrivilegeMode::PRV_M) {
                return std::make_shared<IllegalInstFault>(
                        "MSTATUS is only accessibly in machine mode\n",
                        machInst);
            }
            break;
          }
          default:
            break;
        }

        if (csr == CSR_FCSR) {
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
        } else {
            olddata = xc->readMiscReg(midx);
        }
        auto olddata_all = olddata;

        olddata &= maskVal;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", csrName, olddata);
        data = olddata;

        
                    Rd = data;
                    data |= Rs1;
                ;

        data &= maskVal;
        if (data != olddata) {
            if (bits(csr, 11, 10) == 0x3) {
                return std::make_shared<IllegalInstFault>(
                        csprintf("CSR %s is read-only\n", csrName), machInst);
            }
            auto newdata_all = data;
            // We must keep those original bits not in mask.
            // olddata and data only contain the bits visable
            // in current privilige level.
            newdata_all = (olddata_all & ~maskVal) | data;
            DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n",
                    newdata_all, csrName);
            switch (csr) {
              case CSR_FCSR:
                xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                break;
              case CSR_MIP: case CSR_MIE:
              case CSR_SIP: case CSR_SIE:
              case CSR_UIP: case CSR_UIE:
              case CSR_MSTATUS: case CSR_SSTATUS: case CSR_USTATUS:
                if (newdata_all != olddata_all) {
                    xc->setMiscReg(midx, newdata_all);
                } else {
                    return std::make_shared<IllegalInstFault>(
                            "Only bits in mask are allowed to be set\n",
                            machInst);
                }
                break;
              default:
                xc->setMiscReg(midx, data);
                break;
            }
        }
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrc::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        if (!valid) {
            return std::make_shared<IllegalInstFault>(
                    csprintf("Illegal CSR index %#x\n", csr), machInst);
        }

        uint64_t Rd = 0;
uint64_t Rs1 = 0;
;
        Rs1 = xc->readIntRegOperand(this, 0);
;

        RegVal data, olddata;

        switch (csr) {
          case CSR_SATP: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            STATUS status = xc->readMiscReg(MISCREG_STATUS);
            if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                return std::make_shared<IllegalInstFault>(
                        "SATP access in user mode or with TVM enabled\n",
                        machInst);
            }
            break;
          }
          case CSR_MSTATUS: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            if (pm != PrivilegeMode::PRV_M) {
                return std::make_shared<IllegalInstFault>(
                        "MSTATUS is only accessibly in machine mode\n",
                        machInst);
            }
            break;
          }
          default:
            break;
        }

        if (csr == CSR_FCSR) {
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
        } else {
            olddata = xc->readMiscReg(midx);
        }
        auto olddata_all = olddata;

        olddata &= maskVal;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", csrName, olddata);
        data = olddata;

        
                    Rd = data;
                    data &= ~Rs1;
                ;

        data &= maskVal;
        if (data != olddata) {
            if (bits(csr, 11, 10) == 0x3) {
                return std::make_shared<IllegalInstFault>(
                        csprintf("CSR %s is read-only\n", csrName), machInst);
            }
            auto newdata_all = data;
            // We must keep those original bits not in mask.
            // olddata and data only contain the bits visable
            // in current privilige level.
            newdata_all = (olddata_all & ~maskVal) | data;
            DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n",
                    newdata_all, csrName);
            switch (csr) {
              case CSR_FCSR:
                xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                break;
              case CSR_MIP: case CSR_MIE:
              case CSR_SIP: case CSR_SIE:
              case CSR_UIP: case CSR_UIE:
              case CSR_MSTATUS: case CSR_SSTATUS: case CSR_USTATUS:
                if (newdata_all != olddata_all) {
                    xc->setMiscReg(midx, newdata_all);
                } else {
                    return std::make_shared<IllegalInstFault>(
                            "Only bits in mask are allowed to be set\n",
                            machInst);
                }
                break;
              default:
                xc->setMiscReg(midx, data);
                break;
            }
        }
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrwi::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        if (!valid) {
            return std::make_shared<IllegalInstFault>(
                    csprintf("Illegal CSR index %#x\n", csr), machInst);
        }

        uint64_t Rd = 0;
;
        ;

        RegVal data, olddata;

        switch (csr) {
          case CSR_SATP: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            STATUS status = xc->readMiscReg(MISCREG_STATUS);
            if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                return std::make_shared<IllegalInstFault>(
                        "SATP access in user mode or with TVM enabled\n",
                        machInst);
            }
            break;
          }
          case CSR_MSTATUS: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            if (pm != PrivilegeMode::PRV_M) {
                return std::make_shared<IllegalInstFault>(
                        "MSTATUS is only accessibly in machine mode\n",
                        machInst);
            }
            break;
          }
          default:
            break;
        }

        if (csr == CSR_FCSR) {
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
        } else {
            olddata = xc->readMiscReg(midx);
        }
        auto olddata_all = olddata;

        olddata &= maskVal;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", csrName, olddata);
        data = olddata;

        
                    Rd = data;
                    data = uimm;
                ;

        data &= maskVal;
        if (data != olddata) {
            if (bits(csr, 11, 10) == 0x3) {
                return std::make_shared<IllegalInstFault>(
                        csprintf("CSR %s is read-only\n", csrName), machInst);
            }
            auto newdata_all = data;
            // We must keep those original bits not in mask.
            // olddata and data only contain the bits visable
            // in current privilige level.
            newdata_all = (olddata_all & ~maskVal) | data;
            DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n",
                    newdata_all, csrName);
            switch (csr) {
              case CSR_FCSR:
                xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                break;
              case CSR_MIP: case CSR_MIE:
              case CSR_SIP: case CSR_SIE:
              case CSR_UIP: case CSR_UIE:
              case CSR_MSTATUS: case CSR_SSTATUS: case CSR_USTATUS:
                if (newdata_all != olddata_all) {
                    xc->setMiscReg(midx, newdata_all);
                } else {
                    return std::make_shared<IllegalInstFault>(
                            "Only bits in mask are allowed to be set\n",
                            machInst);
                }
                break;
              default:
                xc->setMiscReg(midx, data);
                break;
            }
        }
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrsi::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        if (!valid) {
            return std::make_shared<IllegalInstFault>(
                    csprintf("Illegal CSR index %#x\n", csr), machInst);
        }

        uint64_t Rd = 0;
;
        ;

        RegVal data, olddata;

        switch (csr) {
          case CSR_SATP: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            STATUS status = xc->readMiscReg(MISCREG_STATUS);
            if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                return std::make_shared<IllegalInstFault>(
                        "SATP access in user mode or with TVM enabled\n",
                        machInst);
            }
            break;
          }
          case CSR_MSTATUS: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            if (pm != PrivilegeMode::PRV_M) {
                return std::make_shared<IllegalInstFault>(
                        "MSTATUS is only accessibly in machine mode\n",
                        machInst);
            }
            break;
          }
          default:
            break;
        }

        if (csr == CSR_FCSR) {
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
        } else {
            olddata = xc->readMiscReg(midx);
        }
        auto olddata_all = olddata;

        olddata &= maskVal;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", csrName, olddata);
        data = olddata;

        
                    Rd = data;
                    data |= uimm;
                ;

        data &= maskVal;
        if (data != olddata) {
            if (bits(csr, 11, 10) == 0x3) {
                return std::make_shared<IllegalInstFault>(
                        csprintf("CSR %s is read-only\n", csrName), machInst);
            }
            auto newdata_all = data;
            // We must keep those original bits not in mask.
            // olddata and data only contain the bits visable
            // in current privilige level.
            newdata_all = (olddata_all & ~maskVal) | data;
            DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n",
                    newdata_all, csrName);
            switch (csr) {
              case CSR_FCSR:
                xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                break;
              case CSR_MIP: case CSR_MIE:
              case CSR_SIP: case CSR_SIE:
              case CSR_UIP: case CSR_UIE:
              case CSR_MSTATUS: case CSR_SSTATUS: case CSR_USTATUS:
                if (newdata_all != olddata_all) {
                    xc->setMiscReg(midx, newdata_all);
                } else {
                    return std::make_shared<IllegalInstFault>(
                            "Only bits in mask are allowed to be set\n",
                            machInst);
                }
                break;
              default:
                xc->setMiscReg(midx, data);
                break;
            }
        }
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Fault
    Csrrci::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        if (!valid) {
            return std::make_shared<IllegalInstFault>(
                    csprintf("Illegal CSR index %#x\n", csr), machInst);
        }

        uint64_t Rd = 0;
;
        ;

        RegVal data, olddata;

        switch (csr) {
          case CSR_SATP: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            STATUS status = xc->readMiscReg(MISCREG_STATUS);
            if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {
                return std::make_shared<IllegalInstFault>(
                        "SATP access in user mode or with TVM enabled\n",
                        machInst);
            }
            break;
          }
          case CSR_MSTATUS: {
            auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);
            if (pm != PrivilegeMode::PRV_M) {
                return std::make_shared<IllegalInstFault>(
                        "MSTATUS is only accessibly in machine mode\n",
                        machInst);
            }
            break;
          }
          default:
            break;
        }

        if (csr == CSR_FCSR) {
            olddata = xc->readMiscReg(MISCREG_FFLAGS) |
                      (xc->readMiscReg(MISCREG_FRM) << FRM_OFFSET);
        } else {
            olddata = xc->readMiscReg(midx);
        }
        auto olddata_all = olddata;

        olddata &= maskVal;
        DPRINTF(RiscvMisc, "Reading CSR %s: %#x\n", csrName, olddata);
        data = olddata;

        
                    Rd = data;
                    data &= ~uimm;
                ;

        data &= maskVal;
        if (data != olddata) {
            if (bits(csr, 11, 10) == 0x3) {
                return std::make_shared<IllegalInstFault>(
                        csprintf("CSR %s is read-only\n", csrName), machInst);
            }
            auto newdata_all = data;
            // We must keep those original bits not in mask.
            // olddata and data only contain the bits visable
            // in current privilige level.
            newdata_all = (olddata_all & ~maskVal) | data;
            DPRINTF(RiscvMisc, "Writing %#x to CSR %s.\n",
                    newdata_all, csrName);
            switch (csr) {
              case CSR_FCSR:
                xc->setMiscReg(MISCREG_FFLAGS, bits(data, 4, 0));
                xc->setMiscReg(MISCREG_FRM, bits(data, 7, 5));
                break;
              case CSR_MIP: case CSR_MIE:
              case CSR_SIP: case CSR_SIE:
              case CSR_UIP: case CSR_UIE:
              case CSR_MSTATUS: case CSR_SSTATUS: case CSR_USTATUS:
                if (newdata_all != olddata_all) {
                    xc->setMiscReg(midx, newdata_all);
                } else {
                    return std::make_shared<IllegalInstFault>(
                            "Only bits in mask are allowed to be set\n",
                            machInst);
                }
                break;
              default:
                xc->setMiscReg(midx, data);
                break;
            }
        }
        
        
        {
            uint64_t final_val = Rd;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// M5Op::M5Op(([], {}))

    Fault
    M5Op::execute(ExecContext *xc,
        Trace::InstRecord *traceData) const
    {
        uint64_t a0 = 0;
;
        ;
        
            uint64_t result;
            pseudo_inst::pseudoInst<RegABI64>(xc->tcBase(), M5FUNC, result);
            a0 = result;
        
        
        {
            uint64_t final_val = a0;
            xc->setIntRegOperand(this, 0, final_val);

            if (traceData) { traceData->setData(final_val); }
        };
        return NoFault;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

#endif
