// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa

#undef QUADRANT
#define QUADRANT	bits(machInst,  1,  0)
#undef OPCODE
#define OPCODE	bits(machInst,  6,  2)
#undef ALL
#define ALL	bits(machInst, 31,  0)
#undef RD
#define RD	bits(machInst, 11,  7)
#undef FUNCT3
#define FUNCT3	bits(machInst, 14, 12)
#undef RS1
#define RS1	bits(machInst, 19, 15)
#undef RS2
#define RS2	bits(machInst, 24, 20)
#undef FUNCT7
#define FUNCT7	bits(machInst, 31, 25)
#undef SRTYPE
#define SRTYPE	bits(machInst, 30, 30)
#undef SHAMT5
#define SHAMT5	bits(machInst, 24, 20)
#undef SHAMT6
#define SHAMT6	bits(machInst, 25, 20)
#undef IMM12
#define IMM12	bits(machInst, 31, 20)
#undef SUCC
#define SUCC	bits(machInst, 23, 20)
#undef PRED
#define PRED	bits(machInst, 27, 24)
#undef IMM5
#define IMM5	bits(machInst, 11,  7)
#undef IMM7
#define IMM7	bits(machInst, 31, 25)
#undef IMM20
#define IMM20	bits(machInst, 31, 12)
#undef BIMM12BIT11
#define BIMM12BIT11	bits(machInst,  7,  7)
#undef BIMM12BITS4TO1
#define BIMM12BITS4TO1	bits(machInst, 11,  8)
#undef BIMM12BITS10TO5
#define BIMM12BITS10TO5	bits(machInst, 30, 25)
#undef IMMSIGN
#define IMMSIGN	bits(machInst, 31, 31)
#undef UJIMMBITS10TO1
#define UJIMMBITS10TO1	bits(machInst, 30, 21)
#undef UJIMMBIT11
#define UJIMMBIT11	bits(machInst, 20, 20)
#undef UJIMMBITS19TO12
#define UJIMMBITS19TO12	bits(machInst, 19, 12)
#undef FUNCT12
#define FUNCT12	bits(machInst, 31, 20)
#undef CSRIMM
#define CSRIMM	bits(machInst, 19, 15)
#undef FD
#define FD	bits(machInst, 11,  7)
#undef FS1
#define FS1	bits(machInst, 19, 15)
#undef FS2
#define FS2	bits(machInst, 24, 20)
#undef FS3
#define FS3	bits(machInst, 31, 27)
#undef ROUND_MODE
#define ROUND_MODE	bits(machInst, 14, 12)
#undef CONV_SGN
#define CONV_SGN	bits(machInst, 24, 20)
#undef FUNCT2
#define FUNCT2	bits(machInst, 26, 25)
#undef AMOFUNCT
#define AMOFUNCT	bits(machInst, 31, 27)
#undef AQ
#define AQ	bits(machInst, 26, 26)
#undef RL
#define RL	bits(machInst, 25, 25)
#undef COPCODE
#define COPCODE	bits(machInst, 15, 13)
#undef CFUNCT1
#define CFUNCT1	bits(machInst, 12, 12)
#undef CFUNCT2HIGH
#define CFUNCT2HIGH	bits(machInst, 11, 10)
#undef CFUNCT2LOW
#define CFUNCT2LOW	bits(machInst,  6,  5)
#undef RC1
#define RC1	bits(machInst, 11,  7)
#undef RC2
#define RC2	bits(machInst,  6,  2)
#undef RP1
#define RP1	bits(machInst,  9,  7)
#undef RP2
#define RP2	bits(machInst,  4,  2)
#undef FC1
#define FC1	bits(machInst, 11,  7)
#undef FC2
#define FC2	bits(machInst,  6,  2)
#undef FP2
#define FP2	bits(machInst,  4,  2)
#undef CJUMPIMM
#define CJUMPIMM	bits(machInst, 12,  2)
#undef CJUMPIMM3TO1
#define CJUMPIMM3TO1	bits(machInst,  5,  3)
#undef CJUMPIMM4TO4
#define CJUMPIMM4TO4	bits(machInst, 11, 11)
#undef CJUMPIMM5TO5
#define CJUMPIMM5TO5	bits(machInst,  2,  2)
#undef CJUMPIMM6TO6
#define CJUMPIMM6TO6	bits(machInst,  7,  7)
#undef CJUMPIMM7TO7
#define CJUMPIMM7TO7	bits(machInst,  6,  6)
#undef CJUMPIMM9TO8
#define CJUMPIMM9TO8	bits(machInst, 10,  9)
#undef CJUMPIMM10TO10
#define CJUMPIMM10TO10	bits(machInst,  8,  8)
#undef CJUMPIMMSIGN
#define CJUMPIMMSIGN	bits(machInst, 12, 12)
#undef CIMM8
#define CIMM8	bits(machInst, 12,  5)
#undef CIMM6
#define CIMM6	bits(machInst, 12,  7)
#undef CIMM5
#define CIMM5	bits(machInst,  6,  2)
#undef CIMM3
#define CIMM3	bits(machInst, 12, 10)
#undef CIMM2
#define CIMM2	bits(machInst,  6,  5)
#undef CIMM1
#define CIMM1	bits(machInst, 12, 12)
#undef M5FUNC
#define M5FUNC	bits(machInst, 31, 25)

// CIAddi4spnOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                return std::make_shared<IllegalInstFault>("zero instruction",\n                                                           machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))

    //
    // Static instruction class for "c_addi4spn".
    //
    class C_addi4spn : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_addi4spn(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                if (status.fs == FPUStatus::OFF)\n                    return std::make_shared<IllegalInstFault>("FPU is off",\n                                                               machInst);\n\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_fld".
     */
    class C_fld : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_fld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_lw".
     */
    class C_lw : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_lw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_ld".
     */
    class C_ld : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_ld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                if (status.fs == FPUStatus::OFF)\n                    return std::make_shared<IllegalInstFault>("FPU is off",\n                                                               machInst);\n\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_fsd".
     */
    class C_fsd : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_fsd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})

    /**
     * Static instruction class for "c_sw".
     */
    class C_sw : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_sw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    /**
     * Static instruction class for "c_sd".
     */
    class C_sd : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_sd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    } else { // imm == 0\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})

    //
    // Static instruction class for "c_addi".
    //
    class C_addi : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_addi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})

    //
    // Static instruction class for "c_addiw".
    //
    class C_addiw : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_addiw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = imm;\n            '],{})

    //
    // Static instruction class for "c_li".
    //
    class C_li : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_li(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})

    //
    // Static instruction class for "c_addi16sp".
    //
    class C_addi16sp : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_addi16sp(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})

    //
    // Static instruction class for "c_lui".
    //
    class C_lui : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_lui(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "c_srli".
    //
    class C_srli : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_srli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "c_srai".
    //
    class C_srai : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_srai(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "c_andi".
    //
    class C_andi : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_andi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CompressedROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})

    //
    // Static instruction class for "c_sub".
    //
    class C_sub : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_sub(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// CompressedROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})

    //
    // Static instruction class for "c_xor".
    //
    class C_xor : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_xor(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// CompressedROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})

    //
    // Static instruction class for "c_or".
    //
    class C_or : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_or(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// CompressedROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})

    //
    // Static instruction class for "c_and".
    //
    class C_and : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_and(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// CompressedROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})

    //
    // Static instruction class for "c_subw".
    //
    class C_subw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_subw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// CompressedROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})

    //
    // Static instruction class for "c_addw".
    //
    class C_addw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_addw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// CJOp::c_j((['\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl'], {}))

    //
    // Static instruction class for "c_j".
    //
    class C_j : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_j(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "c_beqz".
    //
    class C_beqz : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_beqz(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "c_bnez".
    //
    class C_bnez : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_bnez(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// Unknown::unknown(([], {}))

// CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                return std::make_shared<IllegalInstFault>(\n                        "immediate = 0", machInst);\n            }\n            if (RC1 == 0) {\n                return std::make_shared<IllegalInstFault>(\n                        "source reg x0", machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))

    //
    // Static instruction class for "c_slli".
    //
    class C_slli : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_slli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_fldsp".
     */
    class C_fldsp : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_fldsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_lwsp".
     */
    class C_lwsp : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_lwsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_ldsp".
     */
    class C_ldsp : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_ldsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Jump::c_jr((['\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "c_jr".
    //
    class C_jr : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_jr(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(ThreadContext *tc) const override;

        using StaticInst::branchTarget;
    };

// CROp::c_mv((['\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))

    //
    // Static instruction class for "c_mv".
    //
    class C_mv : public CompRegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_mv(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CompRegOp::generateDisassembly;
    };

// SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    return std::make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))

    //
    // Static instruction class for "c_ebreak".
    //
    class C_ebreak : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_ebreak(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            return std::make_shared<IllegalInstFault>(\n                                    "source reg x0", machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "c_jalr".
    //
    class C_jalr : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_jalr(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(ThreadContext *tc) const override;

        using StaticInst::branchTarget;
    };

// CompressedROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))

    //
    // Static instruction class for "c_add".
    //
    class C_add : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        C_add(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_fsdsp".
     */
    class C_fsdsp : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_fsdsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_swsp".
     */
    class C_swsp : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_swsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})

    /**
     * Static instruction class for "c_sdsp".
     */
    class C_sdsp : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        C_sdsp(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})

    /**
     * Static instruction class for "lb".
     */
    class Lb : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lb(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})

    /**
     * Static instruction class for "lh".
     */
    class Lh : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lh(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})

    /**
     * Static instruction class for "lw".
     */
    class Lw : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})

    /**
     * Static instruction class for "ld".
     */
    class Ld : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Ld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})

    /**
     * Static instruction class for "lbu".
     */
    class Lbu : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lbu(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})

    /**
     * Static instruction class for "lhu".
     */
    class Lhu : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lhu(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})

    /**
     * Static instruction class for "lwu".
     */
    class Lwu : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lwu(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Load::flw(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                    "FPU is off", machInst);\n                    freg_t fd;\n                    fd = freg(f32(Mem_uw));\n                    Fd_bits = fd.v;\n                '],{'inst_flags': 'FloatMemReadOp'})

    /**
     * Static instruction class for "flw".
     */
    class Flw : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Flw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Load::fld(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                    "FPU is off", machInst);\n                    freg_t fd;\n                    fd = freg(f64(Mem));\n                    Fd_bits = fd.v;\n                '],{'inst_flags': 'FloatMemReadOp'})

    /**
     * Static instruction class for "fld".
     */
    class Fld : public Load
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fld(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// FenceOp::fence(['\n                ', 'uint64_t', 'IsReadBarrier', 'IsWriteBarrier', 'No_OpClass'],{})

    //
    // Static instruction class for "fence".
    //
    class Fence : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Fence(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// FenceOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    //
    // Static instruction class for "fence_i".
    //
    class Fence_i : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Fence_i(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})

    //
    // Static instruction class for "addi".
    //
    class Addi : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Addi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::slli(['\n                    Rd = Rs1 << imm;\n                '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    //
    // Static instruction class for "slli".
    //
    class Slli : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Slli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})

    //
    // Static instruction class for "slti".
    //
    class Slti : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Slti(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "sltiu".
    //
    class Sltiu : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sltiu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "xori".
    //
    class Xori : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Xori(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::srli(['\n                        Rd = Rs1 >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    //
    // Static instruction class for "srli".
    //
    class Srli : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Srli(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::srai(['\n                        Rd_sd = Rs1_sd >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    //
    // Static instruction class for "srai".
    //
    class Srai : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Srai(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "ori".
    //
    class Ori : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Ori(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})

    //
    // Static instruction class for "andi".
    //
    class Andi : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Andi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// UOp::auipc((['\n            Rd = PC + (sext<20>(imm) << 12);\n        '], {}))

    //
    // Static instruction class for "auipc".
    //
    class Auipc : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Auipc(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})

    //
    // Static instruction class for "addiw".
    //
    class Addiw : public ImmOp<int32_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Addiw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::slliw(['\n                    Rd_sd = Rs1_sw << imm;\n                '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    //
    // Static instruction class for "slliw".
    //
    class Slliw : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Slliw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> imm);\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    //
    // Static instruction class for "srliw".
    //
    class Srliw : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Srliw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    //
    // Static instruction class for "sraiw".
    //
    class Sraiw : public ImmOp<uint64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sraiw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})

    /**
     * Static instruction class for "sb".
     */
    class Sb : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Sb(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})

    /**
     * Static instruction class for "sh".
     */
    class Sh : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Sh(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})

    /**
     * Static instruction class for "sw".
     */
    class Sw : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Sw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})

    /**
     * Static instruction class for "sd".
     */
    class Sd : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Sd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Store::fsw(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                "FPU is off", machInst);\n\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    /**
     * Static instruction class for "fsw".
     */
    class Fsw : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Fsw(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Store::fsd(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                "FPU is off", machInst);\n\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    /**
     * Static instruction class for "fsd".
     */
    class Fsd : public Store
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Fsd(ExtMachInst machInst);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Lr_w : public LoadReserved
    {
      public:
        // Constructor
        Lr_w(ExtMachInst machInst);

      protected:
        class Lr_wMicro;
    };

    class Lr_w::Lr_wMicro : public LoadReservedMicro
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Lr_wMicro(ExtMachInst machInst, Lr_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Sc_w : public StoreCond
    {
      public:
        // Constructor
        Sc_w(ExtMachInst machInst);

      protected:
        class Sc_wMicro;
    };

    class Sc_w::Sc_wMicro : public StoreCondMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Sc_wMicro(ExtMachInst machInst, Sc_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoadd_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                          new AtomicGenericOp<int32_t>(Rs2_sw,\n                                  [](int32_t* b, int32_t a){ *b += a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoadd_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoadd_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoadd_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoadd_w::Amoadd_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoadd_wRMW(ExtMachInst machInst, Amoadd_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoswap_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoswap_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoswap_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoswap_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoswap_w::Amoswap_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoswap_wRMW(ExtMachInst machInst, Amoswap_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoxor_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b ^= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoxor_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoxor_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoxor_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoxor_w::Amoxor_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoxor_wRMW(ExtMachInst machInst, Amoxor_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoor_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b |= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoor_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoor_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoor_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoor_w::Amoor_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoor_wRMW(ExtMachInst machInst, Amoor_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoand_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b &= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoand_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amoand_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoand_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoand_w::Amoand_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoand_wRMW(ExtMachInst machInst, Amoand_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amomin_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                      new AtomicGenericOp<int32_t>(Rs2_sw,\n                        [](int32_t* b, int32_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomin_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amomin_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amomin_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amomin_w::Amomin_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amomin_wRMW(ExtMachInst machInst, Amomin_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amomax_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                      new AtomicGenericOp<int32_t>(Rs2_sw,\n                        [](int32_t* b, int32_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomax_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amomax_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amomax_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amomax_w::Amomax_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amomax_wRMW(ExtMachInst machInst, Amomax_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amominu_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                      new AtomicGenericOp<uint32_t>(Rs2_uw,\n                        [](uint32_t* b, uint32_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amominu_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amominu_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amominu_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amominu_w::Amominu_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amominu_wRMW(ExtMachInst machInst, Amominu_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amomaxu_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                      new AtomicGenericOp<uint32_t>(Rs2_uw,\n                        [](uint32_t* b, uint32_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomaxu_w : public AtomicMemOp
    {
      public:
        // Constructor
        Amomaxu_w(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amomaxu_wRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amomaxu_w::Amomaxu_wRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amomaxu_wRMW(ExtMachInst machInst, Amomaxu_w *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Lr_d : public LoadReserved
    {
      public:
        // Constructor
        Lr_d(ExtMachInst machInst);

      protected:
        class Lr_dMicro;
    };

    class Lr_d::Lr_dMicro : public LoadReservedMicro
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Lr_dMicro(ExtMachInst machInst, Lr_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Sc_d : public StoreCond
    {
      public:
        // Constructor
        Sc_d(ExtMachInst machInst);

      protected:
        class Sc_dMicro;
    };

    class Sc_d::Sc_dMicro : public StoreCondMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Sc_dMicro(ExtMachInst machInst, Sc_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoadd_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                          new AtomicGenericOp<int64_t>(Rs2_sd,\n                                  [](int64_t* b, int64_t a){ *b += a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoadd_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoadd_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoadd_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoadd_d::Amoadd_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoadd_dRMW(ExtMachInst machInst, Amoadd_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoswap_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                  [](uint64_t* b, uint64_t a){ *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoswap_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoswap_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoswap_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoswap_d::Amoswap_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoswap_dRMW(ExtMachInst machInst, Amoswap_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoxor_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b ^= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoxor_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoxor_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoxor_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoxor_d::Amoxor_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoxor_dRMW(ExtMachInst machInst, Amoxor_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoor_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b |= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoor_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoor_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoor_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoor_d::Amoor_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoor_dRMW(ExtMachInst machInst, Amoor_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amoand_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b &= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amoand_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amoand_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amoand_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amoand_d::Amoand_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amoand_dRMW(ExtMachInst machInst, Amoand_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amomin_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                      new AtomicGenericOp<int64_t>(Rs2_sd,\n                        [](int64_t* b, int64_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomin_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amomin_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amomin_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amomin_d::Amomin_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amomin_dRMW(ExtMachInst machInst, Amomin_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amomax_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                      new AtomicGenericOp<int64_t>(Rs2_sd,\n                        [](int64_t* b, int64_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomax_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amomax_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amomax_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amomax_d::Amomax_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amomax_dRMW(ExtMachInst machInst, Amomax_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amominu_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                      new AtomicGenericOp<uint64_t>(Rs2_ud,\n                        [](uint64_t* b, uint64_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amominu_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amominu_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amominu_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amominu_d::Amominu_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amominu_dRMW(ExtMachInst machInst, Amominu_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// AtomicMemOp::amomaxu_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                      new AtomicGenericOp<uint64_t>(Rs2_ud,\n                        [](uint64_t* b, uint64_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    /**
     * Static instruction class for an AtomicMemOp operation
     */
    class Amomaxu_d : public AtomicMemOp
    {
      public:
        // Constructor
        Amomaxu_d(ExtMachInst machInst);

      protected:
        /*
         * The main RMW part of an AMO
         */
        class Amomaxu_dRMW;
    };

    /*
     * The main RMW part of an AMO
     */
    class Amomaxu_d::Amomaxu_dRMW : public AtomicMemOpMicro
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        // Constructor
        Amomaxu_dRMW(ExtMachInst machInst, Amomaxu_d *_p);

        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        Fault initiateAcc(ExecContext *, Trace::InstRecord *) const override;
        Fault completeAcc(PacketPtr, ExecContext *,
                          Trace::InstRecord *) const override;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})

    //
    // Static instruction class for "add".
    //
    class Add : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Add(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mul".
    //
    class Mul : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Mul(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})

    //
    // Static instruction class for "sub".
    //
    class Sub : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sub(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})

    //
    // Static instruction class for "sll".
    //
    class Sll : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sll(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulh".
    //
    class Mulh : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Mulh(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})

    //
    // Static instruction class for "slt".
    //
    class Slt : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Slt(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulhsu".
    //
    class Mulhsu : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Mulhsu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})

    //
    // Static instruction class for "sltu".
    //
    class Sltu : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sltu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulhu".
    //
    class Mulhu : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Mulhu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})

    //
    // Static instruction class for "xor".
    //
    class Xor : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Xor(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (\n                                Rs1_sd == std::numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = std::numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "div".
    //
    class Div : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Div(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})

    //
    // Static instruction class for "srl".
    //
    class Srl : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Srl(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = std::numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "divu".
    //
    class Divu : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Divu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})

    //
    // Static instruction class for "sra".
    //
    class Sra : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sra(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})

    //
    // Static instruction class for "or".
    //
    class Or : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Or(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (\n                                Rs1_sd == std::numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "rem".
    //
    class Rem : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Rem(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})

    //
    // Static instruction class for "and".
    //
    class And : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        And(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "remu".
    //
    class Remu : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Remu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// UOp::lui((['\n            Rd = (uint64_t)(sext<20>(imm) << 12);\n        '], {}))

    //
    // Static instruction class for "lui".
    //
    class Lui : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Lui(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        std::string generateDisassembly(Addr pc,
            const loader::SymbolTable *symtab) const override;
    };

// ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})

    //
    // Static instruction class for "addw".
    //
    class Addw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Addw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})

    //
    // Static instruction class for "mulw".
    //
    class Mulw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Mulw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})

    //
    // Static instruction class for "subw".
    //
    class Subw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Subw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})

    //
    // Static instruction class for "sllw".
    //
    class Sllw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sllw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == std::numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = std::numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    //
    // Static instruction class for "divw".
    //
    class Divw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Divw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})

    //
    // Static instruction class for "srlw".
    //
    class Srlw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Srlw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = std::numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})

    //
    // Static instruction class for "divuw".
    //
    class Divuw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Divuw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})

    //
    // Static instruction class for "sraw".
    //
    class Sraw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Sraw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == std::numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    //
    // Static instruction class for "remw".
    //
    class Remw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Remw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})

    //
    // Static instruction class for "remuw".
    //
    class Remuw : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Remuw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),\n                                         f32(freg(Fs2_bits)),\n                                         f32(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmadd_s".
    //
    class Fmadd_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmadd_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),\n                                         f64(freg(Fs2_bits)),\n                                         f64(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmadd_d".
    //
    class Fmadd_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmadd_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),\n                                    f32(freg(Fs2_bits)),\n                                    f32(f32(freg(Fs3_bits)).v ^\n                                        mask(31, 31))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmsub_s".
    //
    class Fmsub_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmsub_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),\n                                    f64(freg(Fs2_bits)),\n                                    f64(f64(freg(Fs3_bits)).v ^\n                                        mask(63, 63))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fmsub_d".
    //
    class Fmsub_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmsub_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fnmsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^\n                                             mask(31, 31)),\n                                         f32(freg(Fs2_bits)),\n                                         f32(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmsub_s".
    //
    class Fnmsub_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fnmsub_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fnmsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^\n                                             mask(63, 63)),\n                                         f64(freg(Fs2_bits)),\n                                         f64(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmsub_d".
    //
    class Fnmsub_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fnmsub_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fnmadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^\n                                             mask(31, 31)),\n                                    f32(freg(Fs2_bits)),\n                                    f32(f32(freg(Fs3_bits)).v ^\n                                        mask(31, 31))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmadd_s".
    //
    class Fnmadd_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fnmadd_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fnmadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^\n                                             mask(63, 63)),\n                                    f64(freg(Fs2_bits)),\n                                    f64(f64(freg(Fs3_bits)).v ^\n                                        mask(63, 63))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    //
    // Static instruction class for "fnmadd_d".
    //
    class Fnmadd_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[3]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fnmadd_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_add(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fadd_s".
    //
    class Fadd_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fadd_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_add(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fadd_d".
    //
    class Fadd_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fadd_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_sub(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fsub_s".
    //
    class Fsub_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsub_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_sub(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    //
    // Static instruction class for "fsub_d".
    //
    class Fsub_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsub_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmul_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mul(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultOp'],{})

    //
    // Static instruction class for "fmul_s".
    //
    class Fmul_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmul_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmul_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mul(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultOp'],{})

    //
    // Static instruction class for "fmul_d".
    //
    class Fmul_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmul_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fdiv_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_div(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatDivOp'],{})

    //
    // Static instruction class for "fdiv_s".
    //
    class Fdiv_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fdiv_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fdiv_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_div(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatDivOp'],{})

    //
    // Static instruction class for "fdiv_d".
    //
    class Fdiv_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fdiv_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnj_s(['\n                        Fd_bits = boxF32(insertBits(unboxF32(Fs2_bits), 30, 0,\n                                                    unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnj_s".
    //
    class Fsgnj_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsgnj_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjn_s(['\n                        Fd_bits = boxF32(insertBits(unboxF32(~Fs2_bits), 30, 0,\n                                                    unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjn_s".
    //
    class Fsgnjn_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsgnjn_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjx_s(['\n                        Fd_bits = boxF32(insertBits(\n                                    unboxF32(Fs1_bits) ^ unboxF32(Fs2_bits),\n                                    30, 0, unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjx_s".
    //
    class Fsgnjx_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsgnjx_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fsgnj_d(['\n                        Fd_bits = insertBits(Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnj_d".
    //
    class Fsgnj_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsgnj_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjn_d(['\n                        Fd_bits = insertBits(~Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjn_d".
    //
    class Fsgnjn_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsgnjn_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsgnjx_d(['\n                        Fd_bits = insertBits(\n                                Fs1_bits ^ Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fsgnjx_d".
    //
    class Fsgnjx_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsgnjx_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmin_s(['\n                        bool less = f32_lt_quiet(f32(freg(Fs1_bits)),\n                            f32(freg(Fs2_bits))) ||\n                            (f32_eq(f32(freg(Fs1_bits)),\n                            f32(freg(Fs2_bits))) &&\n                            bits(f32(freg(Fs1_bits)).v, 31));\n\n                        Fd_bits = less ||\n                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&\n                            isNaNF32UI(f32(freg(Fs2_bits)).v))\n                            Fd_bits = f32(defaultNaNF32UI).v;\n                        ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmin_s".
    //
    class Fmin_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmin_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmax_s(['\n                        bool greater = f32_lt_quiet(f32(freg(Fs2_bits)),\n                            f32(freg(Fs1_bits))) ||\n                            (f32_eq(f32(freg(Fs2_bits)),\n                            f32(freg(Fs1_bits))) &&\n                            bits(f32(freg(Fs2_bits)).v, 31));\n\n                        Fd_bits = greater ||\n                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&\n                            isNaNF32UI(f32(freg(Fs2_bits)).v))\n                            Fd_bits = f32(defaultNaNF32UI).v;\n                        ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmax_s".
    //
    class Fmax_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmax_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmin_d(['\n                        bool less = f64_lt_quiet(f64(freg(Fs1_bits)),\n                            f64(freg(Fs2_bits))) ||\n                            (f64_eq(f64(freg(Fs1_bits)),\n                            f64(freg(Fs2_bits))) &&\n                            bits(f64(freg(Fs1_bits)).v, 63));\n\n                        Fd_bits = less ||\n                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&\n                            isNaNF64UI(f64(freg(Fs2_bits)).v))\n                            Fd_bits = f64(defaultNaNF64UI).v;\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmin_d".
    //
    class Fmin_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmin_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmax_d(['\n                        bool greater =\n                            f64_lt_quiet(f64(freg(Fs2_bits)),\n                            f64(freg(Fs1_bits))) ||\n                            (f64_eq(f64(freg(Fs2_bits)),\n                            f64(freg(Fs1_bits))) &&\n                            bits(f64(freg(Fs2_bits)).v, 63));\n\n                        Fd_bits = greater ||\n                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&\n                            isNaNF64UI(f64(Fs2_bits).v))\n                            Fd_bits = f64(defaultNaNF64UI).v;\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fmax_d".
    //
    class Fmax_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmax_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        return std::make_shared<IllegalInstFault>(\n                                "CONV_SGN != 1", machInst);\n                    }\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_to_f32(f64(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_d".
    //
    class Fcvt_s_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_s_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "CONV_SGN != 0", machInst);\n                    }\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_to_f64(f32(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_s".
    //
    class Fcvt_d_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_d_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    freg_t fd;\n                    RM_REQUIRED;\n                    fd = freg(f32_sqrt(f32(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatSqrtOp'],{})

    //
    // Static instruction class for "fsqrt_s".
    //
    class Fsqrt_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsqrt_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    freg_t fd;\n                    RM_REQUIRED;\n                    fd = freg(f64_sqrt(f64(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatSqrtOp'],{})

    //
    // Static instruction class for "fsqrt_d".
    //
    class Fsqrt_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fsqrt_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fle_s(['\n                        Rd = f32_le(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fle_s".
    //
    class Fle_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fle_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::flt_s(['\n                        Rd = f32_lt(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "flt_s".
    //
    class Flt_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Flt_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::feq_s(['\n                        Rd = f32_eq(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "feq_s".
    //
    class Feq_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Feq_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fle_d(['\n                        Rd = f64_le(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "fle_d".
    //
    class Fle_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fle_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::flt_d(['\n                        Rd = f64_lt(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "flt_d".
    //
    class Flt_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Flt_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::feq_d(['\n                        Rd = f64_eq(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    //
    // Static instruction class for "feq_d".
    //
    class Feq_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Feq_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_s(['\n                        RM_REQUIRED;\n                        Rd_sd = sext<32>(f32_to_i32(f32(freg(Fs1_bits)), rm,\n                                                    true));\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_w_s".
    //
    class Fcvt_w_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_w_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_wu_s(['\n                        RM_REQUIRED;\n                        Rd = sext<32>(f32_to_ui32(f32(freg(Fs1_bits)), rm,\n                                                  true));\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_wu_s".
    //
    class Fcvt_wu_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_wu_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_l_s(['\n                        RM_REQUIRED;\n                        Rd_sd = f32_to_i64(f32(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_l_s".
    //
    class Fcvt_l_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_l_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_lu_s(['\n                        RM_REQUIRED;\n                        Rd = f32_to_ui64(f32(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_lu_s".
    //
    class Fcvt_lu_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_lu_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_d(['\n                        RM_REQUIRED;\n                        Rd_sd = sext<32>(f64_to_i32(f64(freg(Fs1_bits)), rm,\n                                                    true));\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_w_d".
    //
    class Fcvt_w_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_w_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_wu_d(['\n                        RM_REQUIRED;\n                        Rd = sext<32>(f64_to_ui32(f64(freg(Fs1_bits)), rm,\n                                                  true));\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_wu_d".
    //
    class Fcvt_wu_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_wu_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_l_d(['\n                        RM_REQUIRED;\n                        Rd_sd = f64_to_i64(f64(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_l_d".
    //
    class Fcvt_l_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_l_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_lu_d(['\n                        RM_REQUIRED;\n                        Rd = f64_to_ui64(f64(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_lu_d".
    //
    class Fcvt_lu_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_lu_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_w(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(i32_to_f32((int32_t)Rs1_sw));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_w".
    //
    class Fcvt_s_w : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_s_w(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_s_wu(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(ui32_to_f32((int32_t)Rs1_uw));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_wu".
    //
    class Fcvt_s_wu : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_s_wu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_s_l(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(i64_to_f32(Rs1_ud));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_l".
    //
    class Fcvt_s_l : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_s_l(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_s_lu(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(ui64_to_f32(Rs1));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_s_lu".
    //
    class Fcvt_s_lu : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_s_lu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fcvt_d_w(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_w".
    //
    class Fcvt_d_w : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_d_w(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_wu(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_wu".
    //
    class Fcvt_d_wu : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_d_wu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_l(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_l".
    //
    class Fcvt_d_l : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_d_l(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fcvt_d_lu(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fcvt_d_lu".
    //
    class Fcvt_d_lu : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fcvt_d_lu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_x_s".
    //
    class Fmv_x_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmv_x_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fclass_s(['\n                        Rd = f32_classify(f32(freg(Fs1_bits)));\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fclass_s".
    //
    class Fclass_s : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fclass_s(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmv_x_d(['\n                        Rd = freg(Fs1_bits).v;\n                    ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_x_d".
    //
    class Fmv_x_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmv_x_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fclass_d(['\n                        Rd = f64_classify(f64(freg(Fs1_bits)));\n                    ', 'FloatMiscOp'],{})

    //
    // Static instruction class for "fclass_d".
    //
    class Fclass_d : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fclass_d(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// FPROp::fmv_s_x(['\n                    freg_t fd;\n                    fd = freg(f32(Rs1_uw));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_s_x".
    //
    class Fmv_s_x : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmv_s_x(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// FPROp::fmv_d_x(['\n                    freg_t fd;\n                    fd = freg(f64(Rs1));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    //
    // Static instruction class for "fmv_d_x".
    //
    class Fmv_d_x : public RegOp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Fmv_d_x(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using RegOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "beq".
    //
    class Beq : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Beq(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bne".
    //
    class Bne : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Bne(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "blt".
    //
    class Blt : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Blt(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bge".
    //
    class Bge : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Bge(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bltu".
    //
    class Bltu : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Bltu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    //
    // Static instruction class for "bgeu".
    //
    class Bgeu : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Bgeu(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// Unknown::unknown(([], {}))

// Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "jalr".
    //
    class Jalr : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Jalr(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(ThreadContext *tc) const override;

        using StaticInst::branchTarget;
    };

// Unknown::unknown(([], {}))

// JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))

    //
    // Static instruction class for "jal".
    //
    class Jal : public ImmOp<int64_t>
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Jal(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;

        std::string
        generateDisassembly(
                Addr pc, const loader::SymbolTable *symtab) const override;

        RiscvISA::PCState
        branchTarget(const RiscvISA::PCState &branchPC) const override;

        using StaticInst::branchTarget;
    };

// SystemOp::ecall(['\n                            return std::make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})

    //
    // Static instruction class for "ecall".
    //
    class Ecall : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Ecall(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::ebreak(['\n                            return std::make_shared<BreakpointFault>(\n                                xc->pcState());\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "ebreak".
    //
    class Ebreak : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Ebreak(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::uret(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            status.uie = status.upie;\n                            status.upie = 1;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_UEPC);\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    //
    // Static instruction class for "uret".
    //
    class Uret : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Uret(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// SystemOp::sret(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            auto pm = (PrivilegeMode)xc->readMiscReg(\n                                MISCREG_PRV);\n                            if (pm == PRV_U ||\n                                (pm == PRV_S && status.tsr == 1)) {\n                                return std::make_shared<IllegalInstFault>(\n                                            "sret in user mode or TSR enabled",\n                                            machInst);\n                                NPC = NPC;\n                            } else {\n                                xc->setMiscReg(MISCREG_PRV, status.spp);\n                                status.sie = status.spie;\n                                status.spie = 1;\n                                status.spp = PRV_U;\n                                xc->setMiscReg(MISCREG_STATUS, status);\n                                NPC = xc->readMiscReg(MISCREG_SEPC);\n                            }\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    //
    // Static instruction class for "sret".
    //
    class Sret : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Sret(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::wfi(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            auto pm = (PrivilegeMode)xc->readMiscReg(\n                                MISCREG_PRV);\n                            if (pm == PRV_U ||\n                                (pm == PRV_S && status.tw == 1)) {\n                                return std::make_shared<IllegalInstFault>(\n                                            "wfi in user mode or TW enabled",\n                                            machInst);\n                            }\n                            // don\'t do anything for now\n                        ', 'No_OpClass'],{})

    //
    // Static instruction class for "wfi".
    //
    class Wfi : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Wfi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// SystemOp::sfence_vma(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);\n                        if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {\n                            return std::make_shared<IllegalInstFault>(\n                                        "sfence in user mode or TVM enabled",\n                                        machInst);\n                        }\n                        xc->tcBase()->getMMUPtr()->demapPage(Rs1, Rs2);\n                    ', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    //
    // Static instruction class for "sfence_vma".
    //
    class Sfence_vma : public SystemOp
    {
      private:
        RegId srcRegIdxArr[2]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Sfence_vma(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            return std::make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    //
    // Static instruction class for "mret".
    //
    class Mret : public SystemOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[0];

      public:
        /// Constructor.
        Mret(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using SystemOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrw".
    //
    class Csrrw : public CSROp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Csrrw(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrs".
    //
    class Csrrs : public CSROp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Csrrs(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrc".
    //
    class Csrrc : public CSROp
    {
      private:
        RegId srcRegIdxArr[1]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Csrrc(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrwi".
    //
    class Csrrwi : public CSROp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Csrrwi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrsi".
    //
    class Csrrsi : public CSROp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Csrrsi(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    //
    // Static instruction class for "csrrci".
    //
    class Csrrci : public CSROp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        Csrrci(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using CSROp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// M5Op::M5Op(([], {}))

    //
    // Static instruction class for "M5Op".
    //
    class M5Op : public PseudoOp
    {
      private:
        RegId srcRegIdxArr[0]; RegId destRegIdxArr[1];

      public:
        /// Constructor.
        M5Op(MachInst machInst);
        Fault execute(ExecContext *, Trace::InstRecord *) const override;
        using PseudoOp::generateDisassembly;
    };

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))
