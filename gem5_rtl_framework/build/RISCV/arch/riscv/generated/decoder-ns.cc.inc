// DO NOT EDIT
// This file was automatically generated from an ISA description:
//   riscv/isa/main.isa

#if !defined(__SPLIT) || (__SPLIT == 1)

// CIAddi4spnOp::c_addi4spn((['\n            imm = CIMM8<1:1> << 2 |\n                  CIMM8<0:0> << 3 |\n                  CIMM8<7:6> << 4 |\n                  CIMM8<5:2> << 6;\n        ', '\n            if (machInst == 0)\n                return std::make_shared<IllegalInstFault>("zero instruction",\n                                                           machInst);\n            Rp2 = sp + imm;\n        ', 'uint64_t'], {}))

    C_addi4spn::C_addi4spn(MachInst machInst)
        : ImmOp<uint64_t>("c_addi4spn", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP2 + 8));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
            imm = bits(CIMM8, 1, 1) << 2 |
                  bits(CIMM8, 0, 0) << 3 |
                  bits(CIMM8, 7, 6) << 4 |
                  bits(CIMM8, 5, 2) << 6;
        ;
    }

// CompressedLoad::c_fld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                if (status.fs == FPUStatus::OFF)\n                    return std::make_shared<IllegalInstFault>("FPU is off",\n                                                               machInst);\n\n                Fp2_bits = Mem;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_fld::C_fld(ExtMachInst machInst):
        Load("c_fld", machInst, FloatMemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FP2 + 8));
	_numFPDestRegs++;
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// CompressedLoad::c_lw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Rp2_sd = Mem_sw;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_lw::C_lw(ExtMachInst machInst):
        Load("c_lw", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP2 + 8));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        
                offset = bits(CIMM2, 1, 1) << 2 |
                         CIMM3 << 3 |
                         bits(CIMM2, 0, 0) << 6;
            ;
    }

// CompressedLoad::c_ld(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                Rp2_sd = Mem_sd;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_ld::C_ld(ExtMachInst machInst):
        Load("c_ld", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP2 + 8));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// CompressedStore::c_fsd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                if (status.fs == FPUStatus::OFF)\n                    return std::make_shared<IllegalInstFault>("FPU is off",\n                                                               machInst);\n\n                Mem = Fp2_bits;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_fsd::C_fsd(ExtMachInst machInst):
        Store("c_fsd", machInst, FloatMemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FP2 + 8));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// CompressedStore::c_sw(['\n                offset = CIMM2<1:1> << 2 |\n                         CIMM3 << 3 |\n                         CIMM2<0:0> << 6;\n            ', '\n                Mem_uw = Rp2_uw;\n            '],{'ea_code': '\n                EA = Rp1 + offset;\n            '})

    C_sw::C_sw(ExtMachInst machInst):
        Store("c_sw", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM2, 1, 1) << 2 |
                         CIMM3 << 3 |
                         bits(CIMM2, 0, 0) << 6;
            ;
    }

// CompressedStore::c_sd(['\n                offset = CIMM3 << 3 | CIMM2 << 6;\n            ', '\n                    Mem_ud = Rp2_ud;\n            ', '\n                EA = Rp1 + offset;\n            '],{})

    C_sd::C_sd(ExtMachInst machInst):
        Store("c_sd", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        
                offset = CIMM3 << 3 | CIMM2 << 6;
            ;
    }

// Unknown::unknown(([], {}))

// CIOp::c_addi(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if ((RC1 == 0) != (imm == 0)) {\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    } else { // imm == 0\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                }\n                Rc1_sd = Rc1_sd + imm;\n            '],{})

    C_addi::C_addi(MachInst machInst)
        : ImmOp<int64_t>("c_addi", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC1));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                imm = CIMM5;
                if (CIMM1 > 0)
                    imm |= ~((uint64_t)0x1F);
            ;
    }

// CIOp::c_addiw(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = (int32_t)Rc1_sd + imm;\n            '],{})

    C_addiw::C_addiw(MachInst machInst)
        : ImmOp<int64_t>("c_addiw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC1));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                imm = CIMM5;
                if (CIMM1 > 0)
                    imm |= ~((uint64_t)0x1F);
            ;
    }

// CIOp::c_li(['\n                imm = CIMM5;\n                if (CIMM1 > 0)\n                    imm |= ~((uint64_t)0x1F);\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = imm;\n            '],{})

    C_li::C_li(MachInst machInst)
        : ImmOp<int64_t>("c_li", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                imm = CIMM5;
                if (CIMM1 > 0)
                    imm |= ~((uint64_t)0x1F);
            ;
    }

// CIOp::c_addi16sp(['\n                    imm = CIMM5<4:4> << 4 |\n                          CIMM5<0:0> << 5 |\n                          CIMM5<3:3> << 6 |\n                          CIMM5<2:1> << 7;\n                    if (CIMM1 > 0)\n                        imm |= ~((int64_t)0x1FF);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    sp_sd = sp_sd + imm;\n                '],{})

    C_addi16sp::C_addi16sp(MachInst machInst)
        : ImmOp<int64_t>("c_addi16sp", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, StackPointerReg));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = bits(CIMM5, 4, 4) << 4 |
                          bits(CIMM5, 0, 0) << 5 |
                          bits(CIMM5, 3, 3) << 6 |
                          bits(CIMM5, 2, 1) << 7;
                    if (CIMM1 > 0)
                        imm |= ~((int64_t)0x1FF);
                ;
    }

// CIOp::c_lui(['\n                    imm = CIMM5 << 12;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1FFFF);\n                ', '\n                    if (RC1 == 0 || RC1 == 2) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rc1_sd = imm;\n                '],{})

    C_lui::C_lui(MachInst machInst)
        : ImmOp<int64_t>("c_lui", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5 << 12;
                    if (CIMM1 > 0)
                        imm |= ~((uint64_t)0x1FFFF);
                ;
    }

// CIOp::c_srli(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rp1 = Rp1 >> imm;\n                ', 'uint64_t'],{})

    C_srli::C_srli(MachInst machInst)
        : ImmOp<uint64_t>("c_srli", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5 | (CIMM1 << 5);
                ;
    }

// CIOp::c_srai(['\n                    imm = CIMM5 | (CIMM1 << 5);\n                ', '\n                    if (imm == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "immediate = 0", machInst);\n                    }\n                    Rp1_sd = Rp1_sd >> imm;\n                ', 'uint64_t'],{})

    C_srai::C_srai(MachInst machInst)
        : ImmOp<uint64_t>("c_srai", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5 | (CIMM1 << 5);
                ;
    }

// CIOp::c_andi(['\n                    imm = CIMM5;\n                    if (CIMM1 > 0)\n                        imm |= ~((uint64_t)0x1F);\n                ', '\n                    Rp1 = Rp1 & imm;\n                ', 'uint64_t'],{})

    C_andi::C_andi(MachInst machInst)
        : ImmOp<uint64_t>("c_andi", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
                    imm = CIMM5;
                    if (CIMM1 > 0)
                        imm |= ~((uint64_t)0x1F);
                ;
    }

// CompressedROp::c_sub(['\n                            Rp1 = Rp1 - Rp2;\n                        '],{})

    C_sub::C_sub(MachInst machInst)
        : RegOp("c_sub", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;;
    }

// CompressedROp::c_xor(['\n                            Rp1 = Rp1 ^ Rp2;\n                        '],{})

    C_xor::C_xor(MachInst machInst)
        : RegOp("c_xor", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;;
    }

// CompressedROp::c_or(['\n                            Rp1 = Rp1 | Rp2;\n                        '],{})

    C_or::C_or(MachInst machInst)
        : RegOp("c_or", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;;
    }

// CompressedROp::c_and(['\n                            Rp1 = Rp1 & Rp2;\n                        '],{})

    C_and::C_and(MachInst machInst)
        : RegOp("c_and", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// CompressedROp::c_subw(['\n                            Rp1_sd = (int32_t)Rp1_sd - Rp2_sw;\n                        '],{})

    C_subw::C_subw(MachInst machInst)
        : RegOp("c_subw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;;
    }

// CompressedROp::c_addw(['\n                            Rp1_sd = (int32_t)Rp1_sd + Rp2_sw;\n                        '],{})

    C_addw::C_addw(MachInst machInst)
        : RegOp("c_addw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RP1 + 8));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP2 + 8));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// CJOp::c_j((['\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl'], {}))

    C_j::C_j(MachInst machInst)
        : ImmOp<int64_t>("c_j", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsUncondControl] = true;;
        
           imm =             CJUMPIMM3TO1 << 1 |
                             CJUMPIMM4TO4 << 4 |
                             CJUMPIMM5TO5 << 5 |
                             CJUMPIMM6TO6 << 6 |
                             CJUMPIMM7TO7 << 7 |
                             CJUMPIMM9TO8 << 8 |
                             CJUMPIMM10TO10 << 10;
            if (CJUMPIMMSIGN)
                imm |= ~((int64_t)0x7FF);
    ;
    }

// CBOp::c_beqz(['\n                if (Rp1 == 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    C_beqz::C_beqz(MachInst machInst)
        : ImmOp<int64_t>("c_beqz", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = bits(CIMM5, 2, 1) << 1 |
                      bits(CIMM3, 1, 0) << 3 |
                      bits(CIMM5, 0, 0) << 5 |
                      bits(CIMM5, 4, 3) << 6;
                if (bits(CIMM3, 2, 2) > 0)
                    imm |= ~((int64_t)0xFF);
               ;
    }

// CBOp::c_bnez(['\n                if (Rp1 != 0)\n                    NPC = PC + imm;\n                else\n                    NPC = NPC;\n            ', 'IsDirectControl', 'IsCondControl'],{})

    C_bnez::C_bnez(MachInst machInst)
        : ImmOp<int64_t>("c_bnez", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RP1 + 8));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = bits(CIMM5, 2, 1) << 1 |
                      bits(CIMM3, 1, 0) << 3 |
                      bits(CIMM5, 0, 0) << 5 |
                      bits(CIMM5, 4, 3) << 6;
                if (bits(CIMM3, 2, 2) > 0)
                    imm |= ~((int64_t)0xFF);
               ;
    }

// Unknown::unknown(([], {}))

// CIOp::c_slli((['\n            imm = CIMM5 | (CIMM1 << 5);\n        ', '\n            if (imm == 0) {\n                return std::make_shared<IllegalInstFault>(\n                        "immediate = 0", machInst);\n            }\n            if (RC1 == 0) {\n                return std::make_shared<IllegalInstFault>(\n                        "source reg x0", machInst);\n            }\n            Rc1 = Rc1 << imm;\n        ', 'uint64_t'], {}))

    C_slli::C_slli(MachInst machInst)
        : ImmOp<uint64_t>("c_slli", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC1));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        
            imm = CIMM5 | (CIMM1 << 5);
        ;
    }

// CompressedLoad::c_fldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                Fc1_bits = Mem;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_fldsp::C_fldsp(ExtMachInst machInst):
        Load("c_fldsp", machInst, FloatMemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FC1));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        
                offset = bits(CIMM5, 4, 3) << 3 |
                         CIMM1 << 5 |
                         bits(CIMM5, 2, 0) << 6;
            ;
    }

// CompressedLoad::c_lwsp(['\n                offset = CIMM5<4:2> << 2 |\n                         CIMM1 << 5 |\n                         CIMM5<1:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = Mem_sw;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_lwsp::C_lwsp(ExtMachInst machInst):
        Load("c_lwsp", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        
                offset = bits(CIMM5, 4, 2) << 2 |
                         CIMM1 << 5 |
                         bits(CIMM5, 1, 0) << 6;
            ;
    }

// CompressedLoad::c_ldsp(['\n                offset = CIMM5<4:3> << 3 |\n                         CIMM1 << 5 |\n                         CIMM5<2:0> << 6;\n            ', '\n                if (RC1 == 0) {\n                    return std::make_shared<IllegalInstFault>(\n                            "source reg x0", machInst);\n                }\n                Rc1_sd = Mem_sd;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_ldsp::C_ldsp(ExtMachInst machInst):
        Load("c_ldsp", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        
                offset = bits(CIMM5, 4, 3) << 3 |
                         CIMM1 << 5 |
                         bits(CIMM5, 2, 0) << 6;
            ;
    }

// Jump::c_jr((['\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    NPC = Rc1;\n                ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    C_jr::C_jr(MachInst machInst)
        : ImmOp<int64_t>("c_jr", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC1));
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        imm = sext<12>(IMM12);;
    }

// CROp::c_mv((['\n                    if (RC1 == 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x0", machInst);\n                    }\n                    Rc1 = Rc2;\n                '], {}))

    C_mv::C_mv(MachInst machInst)
        : CompRegOp("c_mv", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC2));
	flags[IsInteger] = true;;
    }

// SystemOp::c_ebreak((['\n                    if (RC2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    return std::make_shared<BreakpointFault>(xc->pcState());\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'], {}))

    C_ebreak::C_ebreak(MachInst machInst)
        : SystemOp("c_ebreak", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// Jump::c_jalr((['\n                        if (RC1 == 0) {\n                            return std::make_shared<IllegalInstFault>(\n                                    "source reg x0", machInst);\n                        }\n                        ra = NPC;\n                        NPC = Rc1;\n                    ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    C_jalr::C_jalr(MachInst machInst)
        : ImmOp<int64_t>("c_jalr", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, ReturnAddrReg));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC1));
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        imm = sext<12>(IMM12);;
    }

// CompressedROp::c_add((['\n                        Rc1_sd = Rc1_sd + Rc2_sd;\n                    '], {}))

    C_add::C_add(MachInst machInst)
        : RegOp("c_add", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC1));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RC1));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// CompressedStore::c_fsdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem_ud = Fc2_bits;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_fsdsp::C_fsdsp(ExtMachInst machInst):
        Store("c_fsdsp", machInst, FloatMemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FC2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM6, 5, 3) << 3 |
                         bits(CIMM6, 2, 0) << 6;
            ;
    }

// CompressedStore::c_swsp(['\n                offset = CIMM6<5:2> << 2 |\n                         CIMM6<1:0> << 6;\n            ', '\n                Mem_uw = Rc2_uw;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_swsp::C_swsp(ExtMachInst machInst):
        Store("c_swsp", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC2));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM6, 5, 2) << 2 |
                         bits(CIMM6, 1, 0) << 6;
            ;
    }

// CompressedStore::c_sdsp(['\n                offset = CIMM6<5:3> << 3 |\n                         CIMM6<2:0> << 6;\n            ', '\n                Mem = Rc2;\n            ', '\n                EA = sp + offset;\n            '],{})

    C_sdsp::C_sdsp(ExtMachInst machInst):
        Store("c_sdsp", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, StackPointerReg));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RC2));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        
                offset = bits(CIMM6, 5, 3) << 3 |
                         bits(CIMM6, 2, 0) << 6;
            ;
    }

// Unknown::unknown(([], {}))

// Load::lb(['\n                    Rd_sd = Mem_sb;\n                '],{})

    Lb::Lb(ExtMachInst machInst):
        Load("lb", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lh(['\n                    Rd_sd = Mem_sh;\n                '],{})

    Lh::Lh(ExtMachInst machInst):
        Load("lh", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lw(['\n                    Rd_sd = Mem_sw;\n                '],{})

    Lw::Lw(ExtMachInst machInst):
        Load("lw", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::ld(['\n                    Rd_sd = Mem_sd;\n                '],{})

    Ld::Ld(ExtMachInst machInst):
        Load("ld", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lbu(['\n                    Rd = Mem_ub;\n                '],{})

    Lbu::Lbu(ExtMachInst machInst):
        Load("lbu", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lhu(['\n                    Rd = Mem_uh;\n                '],{})

    Lhu::Lhu(ExtMachInst machInst):
        Load("lhu", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::lwu(['\n                    Rd = Mem_uw;\n                '],{})

    Lwu::Lwu(ExtMachInst machInst):
        Load("lwu", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// Load::flw(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                    "FPU is off", machInst);\n                    freg_t fd;\n                    fd = freg(f32(Mem_uw));\n                    Fd_bits = fd.v;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Flw::Flw(ExtMachInst machInst):
        Load("flw", machInst, FloatMemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Load::fld(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                    "FPU is off", machInst);\n                    freg_t fd;\n                    fd = freg(f64(Mem));\n                    Fd_bits = fd.v;\n                '],{'inst_flags': 'FloatMemReadOp'})

    Fld::Fld(ExtMachInst machInst):
        Load("fld", machInst, FloatMemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsLoad] = true;;
        offset = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// FenceOp::fence(['\n                ', 'uint64_t', 'IsReadBarrier', 'IsWriteBarrier', 'No_OpClass'],{})

    Fence::Fence(MachInst machInst)
        : ImmOp<uint64_t>("fence", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsReadBarrier] = true;
	flags[IsWriteBarrier] = true;;
        imm = sext<12>(IMM12);;
    }

// FenceOp::fence_i(['\n                ', 'uint64_t', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    Fence_i::Fence_i(MachInst machInst)
        : ImmOp<uint64_t>("fence_i", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// IOp::addi(['\n                    Rd_sd = Rs1_sd + imm;\n                '],{})

    Addi::Addi(MachInst machInst)
        : ImmOp<int64_t>("addi", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::slli(['\n                    Rd = Rs1 << imm;\n                '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    Slli::Slli(MachInst machInst)
        : ImmOp<uint64_t>("slli", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
         imm = SHAMT6; ;
    }

// IOp::slti(['\n                    Rd = (Rs1_sd < imm) ? 1 : 0;\n                '],{})

    Slti::Slti(MachInst machInst)
        : ImmOp<int64_t>("slti", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::sltiu(['\n                    Rd = (Rs1 < imm) ? 1 : 0;\n                ', 'uint64_t'],{})

    Sltiu::Sltiu(MachInst machInst)
        : ImmOp<uint64_t>("sltiu", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::xori(['\n                    Rd = Rs1 ^ imm;\n                ', 'uint64_t'],{})

    Xori::Xori(MachInst machInst)
        : ImmOp<uint64_t>("xori", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::srli(['\n                        Rd = Rs1 >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    Srli::Srli(MachInst machInst)
        : ImmOp<uint64_t>("srli", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
         imm = SHAMT6; ;
    }

// IOp::srai(['\n                        Rd_sd = Rs1_sd >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT6; '})

    Srai::Srai(MachInst machInst)
        : ImmOp<uint64_t>("srai", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
         imm = SHAMT6; ;
    }

// Unknown::unknown(([], {}))

// IOp::ori(['\n                    Rd = Rs1 | imm;\n                ', 'uint64_t'],{})

    Ori::Ori(MachInst machInst)
        : ImmOp<uint64_t>("ori", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::andi(['\n                    Rd = Rs1 & imm;\n                ', 'uint64_t'],{})

    Andi::Andi(MachInst machInst)
        : ImmOp<uint64_t>("andi", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// UOp::auipc((['\n            Rd = PC + (sext<20>(imm) << 12);\n        '], {}))

    Auipc::Auipc(MachInst machInst)
        : ImmOp<int64_t>("auipc", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        imm = IMM20;;
    }

// IOp::addiw(['\n                    Rd_sd = Rs1_sw + imm;\n                ', 'int32_t'],{})

    Addiw::Addiw(MachInst machInst)
        : ImmOp<int32_t>("addiw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
        imm = sext<12>(IMM12);;
    }

// IOp::slliw(['\n                    Rd_sd = Rs1_sw << imm;\n                '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    Slliw::Slliw(MachInst machInst)
        : ImmOp<uint64_t>("slliw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
         imm = SHAMT5; ;
    }

// IOp::srliw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> imm);\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    Srliw::Srliw(MachInst machInst)
        : ImmOp<uint64_t>("srliw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
         imm = SHAMT5; ;
    }

// IOp::sraiw(['\n                        Rd_sd = Rs1_sw >> imm;\n                    '],{'imm_type': 'uint64_t', 'imm_code': ' imm = SHAMT5; '})

    Sraiw::Sraiw(MachInst machInst)
        : ImmOp<uint64_t>("sraiw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;;
         imm = SHAMT5; ;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// Store::sb(['\n                    Mem_ub = Rs2_ub;\n                '],{})

    Sb::Sb(ExtMachInst machInst):
        Store("sb", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::sh(['\n                    Mem_uh = Rs2_uh;\n                '],{})

    Sh::Sh(ExtMachInst machInst):
        Store("sh", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::sw(['\n                    Mem_uw = Rs2_uw;\n                '],{})

    Sw::Sw(ExtMachInst machInst):
        Store("sw", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::sd(['\n                    Mem_ud = Rs2_ud;\n                '],{})

    Sd::Sd(ExtMachInst machInst):
        Store("sd", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Unknown::unknown(([], {}))

// Store::fsw(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                "FPU is off", machInst);\n\n                    Mem_uw = (uint32_t)Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fsw::Fsw(ExtMachInst machInst):
        Store("fsw", machInst, FloatMemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Store::fsd(['\n                    STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                    if (status.fs == FPUStatus::OFF)\n                        return std::make_shared<IllegalInstFault>(\n                                "FPU is off", machInst);\n\n                    Mem_ud = Fs2_bits;\n                '],{'inst_flags': 'FloatMemWriteOp'})

    Fsd::Fsd(ExtMachInst machInst):
        Store("fsd", machInst, FloatMemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;
	flags[IsStore] = true;;
        offset = sext<12>(IMM5 | (IMM7 << 5));;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_w((['\n                    Rd_sd = Mem_sw;\n                '], {'mem_flags': 'LLSC'}))

    Lr_w::Lr_w(ExtMachInst machInst):
        LoadReserved("lr_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr lrsc;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        lrsc = new Lr_wMicro(machInst, this);

        if (!RL) {
            lrsc->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            lrsc->setFlag(IsLastMicroop);
        } else {
            lrsc->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, lrsc, acq_fence};
        } else if (RL) {
            microops = {rel_fence, lrsc};
        } else if (AQ) {
            microops = {lrsc, acq_fence};
        } else {
            microops = {lrsc};
        }
    }

    Lr_w::Lr_wMicro::Lr_wMicro(
        ExtMachInst machInst, Lr_w *_p)
            : LoadReservedMicro("lr_w", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
    }

// StoreCond::sc_w((['\n                    Mem_uw = Rs2_uw;\n                ', '\n                    Rd = result;\n                '], {'inst_flags': 'IsStoreConditional', 'mem_flags': 'LLSC'}))

    Sc_w::Sc_w(ExtMachInst machInst):
        StoreCond("sc_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr lrsc;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        lrsc = new Sc_wMicro(machInst, this);

        if (!RL) {
            lrsc->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            lrsc->setFlag(IsLastMicroop);
        } else {
            lrsc->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, lrsc, acq_fence};
        } else if (RL) {
            microops = {rel_fence, lrsc};
        } else if (AQ) {
            microops = {lrsc, acq_fence};
        } else {
            microops = {lrsc};
        }
    }

    Sc_w::Sc_wMicro::Sc_wMicro(
        ExtMachInst machInst, Sc_w *_p)
            : StoreCondMicro("sc_w", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsStore] = true;
	flags[IsStoreConditional] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
    }

// AtomicMemOp::amoadd_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                          new AtomicGenericOp<int32_t>(Rs2_sw,\n                                  [](int32_t* b, int32_t a){ *b += a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoadd_w::Amoadd_w(ExtMachInst machInst)
            : AtomicMemOp("amoadd_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoadd_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoadd_w::Amoadd_wRMW::Amoadd_wRMW(
        ExtMachInst machInst, Amoadd_w *_p)
            : AtomicMemOpMicro("amoadd_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoswap_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoswap_w::Amoswap_w(ExtMachInst machInst)
            : AtomicMemOp("amoswap_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoswap_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoswap_w::Amoswap_wRMW::Amoswap_wRMW(
        ExtMachInst machInst, Amoswap_w *_p)
            : AtomicMemOpMicro("amoswap_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoxor_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b ^= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoxor_w::Amoxor_w(ExtMachInst machInst)
            : AtomicMemOp("amoxor_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoxor_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoxor_w::Amoxor_wRMW::Amoxor_wRMW(
        ExtMachInst machInst, Amoxor_w *_p)
            : AtomicMemOpMicro("amoxor_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoor_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b |= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoor_w::Amoor_w(ExtMachInst machInst)
            : AtomicMemOp("amoor_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoor_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoor_w::Amoor_wRMW::Amoor_wRMW(
        ExtMachInst machInst, Amoor_w *_p)
            : AtomicMemOpMicro("amoor_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoand_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                          new AtomicGenericOp<uint32_t>(Rs2_uw,\n                                  [](uint32_t* b, uint32_t a){ *b &= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoand_w::Amoand_w(ExtMachInst machInst)
            : AtomicMemOp("amoand_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoand_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoand_w::Amoand_wRMW::Amoand_wRMW(
        ExtMachInst machInst, Amoand_w *_p)
            : AtomicMemOpMicro("amoand_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amomin_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                      new AtomicGenericOp<int32_t>(Rs2_sw,\n                        [](int32_t* b, int32_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amomin_w::Amomin_w(ExtMachInst machInst)
            : AtomicMemOp("amomin_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amomin_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amomin_w::Amomin_wRMW::Amomin_wRMW(
        ExtMachInst machInst, Amomin_w *_p)
            : AtomicMemOpMicro("amomin_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amomax_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<int32_t> *amo_op =\n                      new AtomicGenericOp<int32_t>(Rs2_sw,\n                        [](int32_t* b, int32_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amomax_w::Amomax_w(ExtMachInst machInst)
            : AtomicMemOp("amomax_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amomax_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amomax_w::Amomax_wRMW::Amomax_wRMW(
        ExtMachInst machInst, Amomax_w *_p)
            : AtomicMemOpMicro("amomax_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amominu_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                      new AtomicGenericOp<uint32_t>(Rs2_uw,\n                        [](uint32_t* b, uint32_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amominu_w::Amominu_w(ExtMachInst machInst)
            : AtomicMemOp("amominu_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amominu_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amominu_w::Amominu_wRMW::Amominu_wRMW(
        ExtMachInst machInst, Amominu_w *_p)
            : AtomicMemOpMicro("amominu_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amomaxu_w((['\n                    Rd_sd = Mem_sw;\n                ', '\n                    TypedAtomicOpFunctor<uint32_t> *amo_op =\n                      new AtomicGenericOp<uint32_t>(Rs2_uw,\n                        [](uint32_t* b, uint32_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amomaxu_w::Amomaxu_w(ExtMachInst machInst)
            : AtomicMemOp("amomaxu_w", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amomaxu_wRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amomaxu_w::Amomaxu_wRMW::Amomaxu_wRMW(
        ExtMachInst machInst, Amomaxu_w *_p)
            : AtomicMemOpMicro("amomaxu_w[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// Unknown::unknown(([], {}))

// LoadReserved::lr_d((['\n                    Rd_sd = Mem_sd;\n                '], {'mem_flags': 'LLSC'}))

    Lr_d::Lr_d(ExtMachInst machInst):
        LoadReserved("lr_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr lrsc;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        lrsc = new Lr_dMicro(machInst, this);

        if (!RL) {
            lrsc->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            lrsc->setFlag(IsLastMicroop);
        } else {
            lrsc->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, lrsc, acq_fence};
        } else if (RL) {
            microops = {rel_fence, lrsc};
        } else if (AQ) {
            microops = {lrsc, acq_fence};
        } else {
            microops = {lrsc};
        }
    }

    Lr_d::Lr_dMicro::Lr_dMicro(
        ExtMachInst machInst, Lr_d *_p)
            : LoadReservedMicro("lr_d", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
    }

// StoreCond::sc_d((['\n                    Mem = Rs2;\n                ', '\n                    Rd = result;\n                '], {'mem_flags': 'LLSC', 'inst_flags': 'IsStoreConditional'}))

    Sc_d::Sc_d(ExtMachInst machInst):
        StoreCond("sc_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr lrsc;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        lrsc = new Sc_dMicro(machInst, this);

        if (!RL) {
            lrsc->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            lrsc->setFlag(IsLastMicroop);
        } else {
            lrsc->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, lrsc, acq_fence};
        } else if (RL) {
            microops = {rel_fence, lrsc};
        } else if (AQ) {
            microops = {lrsc, acq_fence};
        } else {
            microops = {lrsc};
        }
    }

    Sc_d::Sc_dMicro::Sc_dMicro(
        ExtMachInst machInst, Sc_d *_p)
            : StoreCondMicro("sc_d", machInst, MemWriteOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsStore] = true;
	flags[IsStoreConditional] = true;
	memAccessFlags = memAccessFlags | Request::LLSC;;
    }

// AtomicMemOp::amoadd_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                          new AtomicGenericOp<int64_t>(Rs2_sd,\n                                  [](int64_t* b, int64_t a){ *b += a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoadd_d::Amoadd_d(ExtMachInst machInst)
            : AtomicMemOp("amoadd_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoadd_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoadd_d::Amoadd_dRMW::Amoadd_dRMW(
        ExtMachInst machInst, Amoadd_d *_p)
            : AtomicMemOpMicro("amoadd_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoswap_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                  [](uint64_t* b, uint64_t a){ *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoswap_d::Amoswap_d(ExtMachInst machInst)
            : AtomicMemOp("amoswap_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoswap_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoswap_d::Amoswap_dRMW::Amoswap_dRMW(
        ExtMachInst machInst, Amoswap_d *_p)
            : AtomicMemOpMicro("amoswap_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoxor_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b ^= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoxor_d::Amoxor_d(ExtMachInst machInst)
            : AtomicMemOp("amoxor_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoxor_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoxor_d::Amoxor_dRMW::Amoxor_dRMW(
        ExtMachInst machInst, Amoxor_d *_p)
            : AtomicMemOpMicro("amoxor_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoor_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b |= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoor_d::Amoor_d(ExtMachInst machInst)
            : AtomicMemOp("amoor_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoor_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoor_d::Amoor_dRMW::Amoor_dRMW(
        ExtMachInst machInst, Amoor_d *_p)
            : AtomicMemOpMicro("amoor_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amoand_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                          new AtomicGenericOp<uint64_t>(Rs2_ud,\n                                 [](uint64_t* b, uint64_t a){ *b &= a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amoand_d::Amoand_d(ExtMachInst machInst)
            : AtomicMemOp("amoand_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amoand_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amoand_d::Amoand_dRMW::Amoand_dRMW(
        ExtMachInst machInst, Amoand_d *_p)
            : AtomicMemOpMicro("amoand_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amomin_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                      new AtomicGenericOp<int64_t>(Rs2_sd,\n                        [](int64_t* b, int64_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amomin_d::Amomin_d(ExtMachInst machInst)
            : AtomicMemOp("amomin_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amomin_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amomin_d::Amomin_dRMW::Amomin_dRMW(
        ExtMachInst machInst, Amomin_d *_p)
            : AtomicMemOpMicro("amomin_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amomax_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<int64_t> *amo_op =\n                      new AtomicGenericOp<int64_t>(Rs2_sd,\n                        [](int64_t* b, int64_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amomax_d::Amomax_d(ExtMachInst machInst)
            : AtomicMemOp("amomax_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amomax_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amomax_d::Amomax_dRMW::Amomax_dRMW(
        ExtMachInst machInst, Amomax_d *_p)
            : AtomicMemOpMicro("amomax_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amominu_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                      new AtomicGenericOp<uint64_t>(Rs2_ud,\n                        [](uint64_t* b, uint64_t a){ if (a < *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amominu_d::Amominu_d(ExtMachInst machInst)
            : AtomicMemOp("amominu_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amominu_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amominu_d::Amominu_dRMW::Amominu_dRMW(
        ExtMachInst machInst, Amominu_d *_p)
            : AtomicMemOpMicro("amominu_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// AtomicMemOp::amomaxu_d((['\n                    Rd_sd = Mem_sd;\n                ', '\n                    TypedAtomicOpFunctor<uint64_t> *amo_op =\n                      new AtomicGenericOp<uint64_t>(Rs2_ud,\n                        [](uint64_t* b, uint64_t a){ if (a > *b) *b = a; });\n                '], {'mem_flags': 'ATOMIC_RETURN_OP'}))

    Amomaxu_d::Amomaxu_d(ExtMachInst machInst)
            : AtomicMemOp("amomaxu_d", machInst, IntAluOp)
    {
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;

        StaticInstPtr rel_fence;
        StaticInstPtr rmw_op;
        StaticInstPtr acq_fence;

        // set up release fence
        if (RL) {
            rel_fence = new MemFenceMicro(machInst, No_OpClass);
            rel_fence->setFlag(IsFirstMicroop);
            rel_fence->setFlag(IsReadBarrier);
            rel_fence->setFlag(IsWriteBarrier);
            rel_fence->setFlag(IsDelayedCommit);
        }

        // set up atomic rmw op
        rmw_op = new Amomaxu_dRMW(machInst, this);

        if (!RL) {
            rmw_op->setFlag(IsFirstMicroop);
        }

        if (!AQ) {
            rmw_op->setFlag(IsLastMicroop);
        } else {
            rmw_op->setFlag(IsDelayedCommit);
        }

        // set up acquire fence
        if (AQ) {
            acq_fence = new MemFenceMicro(machInst, No_OpClass);
            acq_fence->setFlag(IsLastMicroop);
            acq_fence->setFlag(IsReadBarrier);
            acq_fence->setFlag(IsWriteBarrier);
        }

        if (RL && AQ) {
            microops = {rel_fence, rmw_op, acq_fence};
        } else if (RL) {
            microops = {rel_fence, rmw_op};
        } else if (AQ) {
            microops = {rmw_op, acq_fence};
        } else {
            microops = {rmw_op};
        }
    }

    Amomaxu_d::Amomaxu_dRMW::Amomaxu_dRMW(
        ExtMachInst machInst, Amomaxu_d *_p)
            : AtomicMemOpMicro("amomaxu_d[l]", machInst, MemReadOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsLoad] = true;
	memAccessFlags = memAccessFlags | Request::ATOMIC_RETURN_OP;;

        // overwrite default flags
        flags[IsLoad] = false;
        flags[IsStore] = false;
        flags[IsAtomic] = true;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// ROp::add(['\n                        Rd = Rs1_sd + Rs2_sd;\n                    '],{})

    Add::Add(MachInst machInst)
        : RegOp("add", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::mul(['\n                        Rd = Rs1_sd*Rs2_sd;\n                    ', 'IntMultOp'],{})

    Mul::Mul(MachInst machInst)
        : RegOp("mul", machInst, IntMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::sub(['\n                        Rd = Rs1_sd - Rs2_sd;\n                    '],{})

    Sub::Sub(MachInst machInst)
        : RegOp("sub", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::sll(['\n                        Rd = Rs1 << Rs2<5:0>;\n                    '],{})

    Sll::Sll(MachInst machInst)
        : RegOp("sll", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::mulh(['\n                        bool negate = (Rs1_sd < 0) != (Rs2_sd < 0);\n\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)abs(Rs2_sd);\n                        uint64_t Rs2_hi = (uint64_t)abs(Rs2_sd) >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs2_lo*Rs1_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2_sd == 0 ? 1 : 0)\n                                    : res;\n                    ', 'IntMultOp'],{})

    Mulh::Mulh(MachInst machInst)
        : RegOp("mulh", machInst, IntMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::slt(['\n                        Rd = (Rs1_sd < Rs2_sd) ? 1 : 0;\n                    '],{})

    Slt::Slt(MachInst machInst)
        : RegOp("slt", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::mulhsu(['\n                        bool negate = Rs1_sd < 0;\n                        uint64_t Rs1_lo = (uint32_t)abs(Rs1_sd);\n                        uint64_t Rs1_hi = (uint64_t)abs(Rs1_sd) >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        uint64_t res = hi +\n                                       (mid1 >> 32) +\n                                       (mid2 >> 32) +\n                                       carry;\n                        Rd = negate ? ~res + (Rs1_sd*Rs2 == 0 ? 1 : 0) : res;\n                    ', 'IntMultOp'],{})

    Mulhsu::Mulhsu(MachInst machInst)
        : RegOp("mulhsu", machInst, IntMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::sltu(['\n                        Rd = (Rs1 < Rs2) ? 1 : 0;\n                    '],{})

    Sltu::Sltu(MachInst machInst)
        : RegOp("sltu", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::mulhu(['\n                        uint64_t Rs1_lo = (uint32_t)Rs1;\n                        uint64_t Rs1_hi = Rs1 >> 32;\n                        uint64_t Rs2_lo = (uint32_t)Rs2;\n                        uint64_t Rs2_hi = Rs2 >> 32;\n\n                        uint64_t hi = Rs1_hi*Rs2_hi;\n                        uint64_t mid1 = Rs1_hi*Rs2_lo;\n                        uint64_t mid2 = Rs1_lo*Rs2_hi;\n                        uint64_t lo = Rs1_lo*Rs2_lo;\n                        uint64_t carry = ((uint64_t)(uint32_t)mid1\n                                + (uint64_t)(uint32_t)mid2 + (lo >> 32)) >> 32;\n\n                        Rd = hi + (mid1 >> 32) + (mid2 >> 32) + carry;\n                    ', 'IntMultOp'],{})

    Mulhu::Mulhu(MachInst machInst)
        : RegOp("mulhu", machInst, IntMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::xor(['\n                        Rd = Rs1 ^ Rs2;\n                    '],{})

    Xor::Xor(MachInst machInst)
        : RegOp("xor", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::div(['\n                        if (Rs2_sd == 0) {\n                            Rd_sd = -1;\n                        } else if (\n                                Rs1_sd == std::numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd_sd = std::numeric_limits<int64_t>::min();\n                        } else {\n                            Rd_sd = Rs1_sd/Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Div::Div(MachInst machInst)
        : RegOp("div", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::srl(['\n                        Rd = Rs1 >> Rs2<5:0>;\n                    '],{})

    Srl::Srl(MachInst machInst)
        : RegOp("srl", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::divu(['\n                        if (Rs2 == 0) {\n                            Rd = std::numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd = Rs1/Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Divu::Divu(MachInst machInst)
        : RegOp("divu", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::sra(['\n                        Rd_sd = Rs1_sd >> Rs2<5:0>;\n                    '],{})

    Sra::Sra(MachInst machInst)
        : RegOp("sra", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::or(['\n                        Rd = Rs1 | Rs2;\n                    '],{})

    Or::Or(MachInst machInst)
        : RegOp("or", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::rem(['\n                        if (Rs2_sd == 0) {\n                            Rd = Rs1_sd;\n                        } else if (\n                                Rs1_sd == std::numeric_limits<int64_t>::min()\n                                && Rs2_sd == -1) {\n                            Rd = 0;\n                        } else {\n                            Rd = Rs1_sd%Rs2_sd;\n                        }\n                    ', 'IntDivOp'],{})

    Rem::Rem(MachInst machInst)
        : RegOp("rem", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::and(['\n                        Rd = Rs1 & Rs2;\n                    '],{})

    And::And(MachInst machInst)
        : RegOp("and", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::remu(['\n                        if (Rs2 == 0) {\n                            Rd = Rs1;\n                        } else {\n                            Rd = Rs1%Rs2;\n                        }\n                    ', 'IntDivOp'],{})

    Remu::Remu(MachInst machInst)
        : RegOp("remu", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

// UOp::lui((['\n            Rd = (uint64_t)(sext<20>(imm) << 12);\n        '], {}))

    Lui::Lui(MachInst machInst)
        : ImmOp<int64_t>("lui", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	flags[IsInteger] = true;;
        imm = IMM20;;
    }

// ROp::addw(['\n                        Rd_sd = Rs1_sw + Rs2_sw;\n                    '],{})

    Addw::Addw(MachInst machInst)
        : RegOp("addw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::mulw(['\n                        Rd_sd = (int32_t)(Rs1_sw*Rs2_sw);\n                    ', 'IntMultOp'],{})

    Mulw::Mulw(MachInst machInst)
        : RegOp("mulw", machInst, IntMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::subw(['\n                        Rd_sd = Rs1_sw - Rs2_sw;\n                    '],{})

    Subw::Subw(MachInst machInst)
        : RegOp("subw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::sllw(['\n                    Rd_sd = Rs1_sw << Rs2<4:0>;\n                '],{})

    Sllw::Sllw(MachInst machInst)
        : RegOp("sllw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::divw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = -1;\n                    } else if (Rs1_sw == std::numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = std::numeric_limits<int32_t>::min();\n                    } else {\n                        Rd_sd = Rs1_sw/Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Divw::Divw(MachInst machInst)
        : RegOp("divw", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::srlw(['\n                        Rd_sd = (int32_t)(Rs1_uw >> Rs2<4:0>);\n                    '],{})

    Srlw::Srlw(MachInst machInst)
        : RegOp("srlw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::divuw(['\n                        if (Rs2_uw == 0) {\n                            Rd_sd = std::numeric_limits<uint64_t>::max();\n                        } else {\n                            Rd_sd = (int32_t)(Rs1_uw/Rs2_uw);\n                        }\n                    ', 'IntDivOp'],{})

    Divuw::Divuw(MachInst machInst)
        : RegOp("divuw", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::sraw(['\n                        Rd_sd = Rs1_sw >> Rs2<4:0>;\n                    '],{})

    Sraw::Sraw(MachInst machInst)
        : RegOp("sraw", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// ROp::remw(['\n                    if (Rs2_sw == 0) {\n                        Rd_sd = Rs1_sw;\n                    } else if (Rs1_sw == std::numeric_limits<int32_t>::min()\n                            && Rs2_sw == -1) {\n                        Rd_sd = 0;\n                    } else {\n                        Rd_sd = Rs1_sw%Rs2_sw;\n                    }\n                ', 'IntDivOp'],{})

    Remw::Remw(MachInst machInst)
        : RegOp("remw", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// ROp::remuw(['\n                    if (Rs2_uw == 0) {\n                        Rd_sd = (int32_t)Rs1_uw;\n                    } else {\n                        Rd_sd = (int32_t)(Rs1_uw%Rs2_uw);\n                    }\n                ', 'IntDivOp'],{})

    Remuw::Remuw(MachInst machInst)
        : RegOp("remuw", machInst, IntDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),\n                                         f32(freg(Fs2_bits)),\n                                         f32(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fmadd_s::Fmadd_s(MachInst machInst)
        : RegOp("fmadd_s", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// FPROp::fmadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),\n                                         f64(freg(Fs2_bits)),\n                                         f64(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fmadd_d::Fmadd_d(MachInst machInst)
        : RegOp("fmadd_d", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(freg(Fs1_bits)),\n                                    f32(freg(Fs2_bits)),\n                                    f32(f32(freg(Fs3_bits)).v ^\n                                        mask(31, 31))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fmsub_s::Fmsub_s(MachInst machInst)
        : RegOp("fmsub_s", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// FPROp::fmsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(freg(Fs1_bits)),\n                                    f64(freg(Fs2_bits)),\n                                    f64(f64(freg(Fs3_bits)).v ^\n                                        mask(63, 63))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fmsub_d::Fmsub_d(MachInst machInst)
        : RegOp("fmsub_d", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^\n                                             mask(31, 31)),\n                                         f32(freg(Fs2_bits)),\n                                         f32(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fnmsub_s::Fnmsub_s(MachInst machInst)
        : RegOp("fnmsub_s", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// FPROp::fnmsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^\n                                             mask(63, 63)),\n                                         f64(freg(Fs2_bits)),\n                                         f64(freg(Fs3_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fnmsub_d::Fnmsub_d(MachInst machInst)
        : RegOp("fnmsub_d", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fnmadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mulAdd(f32(f32(freg(Fs1_bits)).v ^\n                                             mask(31, 31)),\n                                    f32(freg(Fs2_bits)),\n                                    f32(f32(freg(Fs3_bits)).v ^\n                                        mask(31, 31))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fnmadd_s::Fnmadd_s(MachInst machInst)
        : RegOp("fnmadd_s", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// FPROp::fnmadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mulAdd(f64(f64(freg(Fs1_bits)).v ^\n                                             mask(63, 63)),\n                                    f64(freg(Fs2_bits)),\n                                    f64(f64(freg(Fs3_bits)).v ^\n                                        mask(63, 63))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultAccOp'],{})

    Fnmadd_d::Fnmadd_d(MachInst machInst)
        : RegOp("fnmadd_d", machInst, FloatMultAccOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS3));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fadd_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_add(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fadd_s::Fadd_s(MachInst machInst)
        : RegOp("fadd_s", machInst, FloatAddOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fadd_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_add(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fadd_d::Fadd_d(MachInst machInst)
        : RegOp("fadd_d", machInst, FloatAddOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsub_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_sub(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fsub_s::Fsub_s(MachInst machInst)
        : RegOp("fsub_s", machInst, FloatAddOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsub_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_sub(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatAddOp'],{})

    Fsub_d::Fsub_d(MachInst machInst)
        : RegOp("fsub_d", machInst, FloatAddOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fmul_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_mul(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultOp'],{})

    Fmul_s::Fmul_s(MachInst machInst)
        : RegOp("fmul_s", machInst, FloatMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fmul_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_mul(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatMultOp'],{})

    Fmul_d::Fmul_d(MachInst machInst)
        : RegOp("fmul_d", machInst, FloatMultOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fdiv_s(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_div(f32(freg(Fs1_bits)),\n                                      f32(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatDivOp'],{})

    Fdiv_s::Fdiv_s(MachInst machInst)
        : RegOp("fdiv_s", machInst, FloatDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fdiv_d(['\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_div(f64(freg(Fs1_bits)),\n                                      f64(freg(Fs2_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatDivOp'],{})

    Fdiv_d::Fdiv_d(MachInst machInst)
        : RegOp("fdiv_d", machInst, FloatDivOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsgnj_s(['\n                        Fd_bits = boxF32(insertBits(unboxF32(Fs2_bits), 30, 0,\n                                                    unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    Fsgnj_s::Fsgnj_s(MachInst machInst)
        : RegOp("fsgnj_s", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjn_s(['\n                        Fd_bits = boxF32(insertBits(unboxF32(~Fs2_bits), 30, 0,\n                                                    unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    Fsgnjn_s::Fsgnjn_s(MachInst machInst)
        : RegOp("fsgnjn_s", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjx_s(['\n                        Fd_bits = boxF32(insertBits(\n                                    unboxF32(Fs1_bits) ^ unboxF32(Fs2_bits),\n                                    30, 0, unboxF32(Fs1_bits)));\n                        ', 'FloatMiscOp'],{})

    Fsgnjx_s::Fsgnjx_s(MachInst machInst)
        : RegOp("fsgnjx_s", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fsgnj_d(['\n                        Fd_bits = insertBits(Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    Fsgnj_d::Fsgnj_d(MachInst machInst)
        : RegOp("fsgnj_d", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjn_d(['\n                        Fd_bits = insertBits(~Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    Fsgnjn_d::Fsgnjn_d(MachInst machInst)
        : RegOp("fsgnjn_d", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fsgnjx_d(['\n                        Fd_bits = insertBits(\n                                Fs1_bits ^ Fs2_bits, 62, 0, Fs1_bits);\n                    ', 'FloatMiscOp'],{})

    Fsgnjx_d::Fsgnjx_d(MachInst machInst)
        : RegOp("fsgnjx_d", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_s(['\n                        bool less = f32_lt_quiet(f32(freg(Fs1_bits)),\n                            f32(freg(Fs2_bits))) ||\n                            (f32_eq(f32(freg(Fs1_bits)),\n                            f32(freg(Fs2_bits))) &&\n                            bits(f32(freg(Fs1_bits)).v, 31));\n\n                        Fd_bits = less ||\n                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&\n                            isNaNF32UI(f32(freg(Fs2_bits)).v))\n                            Fd_bits = f32(defaultNaNF32UI).v;\n                        ', 'FloatCmpOp'],{})

    Fmin_s::Fmin_s(MachInst machInst)
        : RegOp("fmin_s", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fmax_s(['\n                        bool greater = f32_lt_quiet(f32(freg(Fs2_bits)),\n                            f32(freg(Fs1_bits))) ||\n                            (f32_eq(f32(freg(Fs2_bits)),\n                            f32(freg(Fs1_bits))) &&\n                            bits(f32(freg(Fs2_bits)).v, 31));\n\n                        Fd_bits = greater ||\n                            isNaNF32UI(f32(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF32UI(f32(freg(Fs1_bits)).v) &&\n                            isNaNF32UI(f32(freg(Fs2_bits)).v))\n                            Fd_bits = f32(defaultNaNF32UI).v;\n                        ', 'FloatCmpOp'],{})

    Fmax_s::Fmax_s(MachInst machInst)
        : RegOp("fmax_s", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmin_d(['\n                        bool less = f64_lt_quiet(f64(freg(Fs1_bits)),\n                            f64(freg(Fs2_bits))) ||\n                            (f64_eq(f64(freg(Fs1_bits)),\n                            f64(freg(Fs2_bits))) &&\n                            bits(f64(freg(Fs1_bits)).v, 63));\n\n                        Fd_bits = less ||\n                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&\n                            isNaNF64UI(f64(freg(Fs2_bits)).v))\n                            Fd_bits = f64(defaultNaNF64UI).v;\n                    ', 'FloatCmpOp'],{})

    Fmin_d::Fmin_d(MachInst machInst)
        : RegOp("fmin_d", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// FPROp::fmax_d(['\n                        bool greater =\n                            f64_lt_quiet(f64(freg(Fs2_bits)),\n                            f64(freg(Fs1_bits))) ||\n                            (f64_eq(f64(freg(Fs2_bits)),\n                            f64(freg(Fs1_bits))) &&\n                            bits(f64(freg(Fs2_bits)).v, 63));\n\n                        Fd_bits = greater ||\n                            isNaNF64UI(f64(freg(Fs2_bits)).v) ?\n                            freg(Fs1_bits).v : freg(Fs2_bits).v;\n                        if (isNaNF64UI(f64(freg(Fs1_bits)).v) &&\n                            isNaNF64UI(f64(Fs2_bits).v))\n                            Fd_bits = f64(defaultNaNF64UI).v;\n                    ', 'FloatCmpOp'],{})

    Fmax_d::Fmax_d(MachInst machInst)
        : RegOp("fmax_d", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_d(['\n                    if (CONV_SGN != 1) {\n                        return std::make_shared<IllegalInstFault>(\n                                "CONV_SGN != 1", machInst);\n                    }\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f64_to_f32(f64(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fcvt_s_d::Fcvt_s_d(MachInst machInst)
        : RegOp("fcvt_s_d", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;;
    }

// FPROp::fcvt_d_s(['\n                    if (CONV_SGN != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "CONV_SGN != 0", machInst);\n                    }\n                    RM_REQUIRED;\n                    freg_t fd;\n                    fd = freg(f32_to_f64(f32(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fcvt_d_s::Fcvt_d_s(MachInst machInst)
        : RegOp("fcvt_d_s", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;;
    }

// FPROp::fsqrt_s(['\n                    if (RS2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    freg_t fd;\n                    RM_REQUIRED;\n                    fd = freg(f32_sqrt(f32(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatSqrtOp'],{})

    Fsqrt_s::Fsqrt_s(MachInst machInst)
        : RegOp("fsqrt_s", machInst, FloatSqrtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;;
    }

// FPROp::fsqrt_d(['\n                    if (RS2 != 0) {\n                        return std::make_shared<IllegalInstFault>(\n                                "source reg x1", machInst);\n                    }\n                    freg_t fd;\n                    RM_REQUIRED;\n                    fd = freg(f64_sqrt(f64(freg(Fs1_bits))));\n                    Fd_bits = fd.v;\n                ', 'FloatSqrtOp'],{})

    Fsqrt_d::Fsqrt_d(MachInst machInst)
        : RegOp("fsqrt_d", machInst, FloatSqrtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;;
    }

// FPROp::fle_s(['\n                        Rd = f32_le(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fle_s::Fle_s(MachInst machInst)
        : RegOp("fle_s", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::flt_s(['\n                        Rd = f32_lt(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Flt_s::Flt_s(MachInst machInst)
        : RegOp("flt_s", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::feq_s(['\n                        Rd = f32_eq(f32(freg(Fs1_bits)), f32(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Feq_s::Feq_s(MachInst machInst)
        : RegOp("feq_s", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fle_d(['\n                        Rd = f64_le(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Fle_d::Fle_d(MachInst machInst)
        : RegOp("fle_d", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::flt_d(['\n                        Rd = f64_lt(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Flt_d::Flt_d(MachInst machInst)
        : RegOp("flt_d", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::feq_d(['\n                        Rd = f64_eq(f64(freg(Fs1_bits)), f64(freg(Fs2_bits)));\n                    ', 'FloatCmpOp'],{})

    Feq_d::Feq_d(MachInst machInst)
        : RegOp("feq_d", machInst, FloatCmpOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS2));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_s(['\n                        RM_REQUIRED;\n                        Rd_sd = sext<32>(f32_to_i32(f32(freg(Fs1_bits)), rm,\n                                                    true));\n                    ', 'FloatCvtOp'],{})

    Fcvt_w_s::Fcvt_w_s(MachInst machInst)
        : RegOp("fcvt_w_s", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_wu_s(['\n                        RM_REQUIRED;\n                        Rd = sext<32>(f32_to_ui32(f32(freg(Fs1_bits)), rm,\n                                                  true));\n                    ', 'FloatCvtOp'],{})

    Fcvt_wu_s::Fcvt_wu_s(MachInst machInst)
        : RegOp("fcvt_wu_s", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_l_s(['\n                        RM_REQUIRED;\n                        Rd_sd = f32_to_i64(f32(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fcvt_l_s::Fcvt_l_s(MachInst machInst)
        : RegOp("fcvt_l_s", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_lu_s(['\n                        RM_REQUIRED;\n                        Rd = f32_to_ui64(f32(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fcvt_lu_s::Fcvt_lu_s(MachInst machInst)
        : RegOp("fcvt_lu_s", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_w_d(['\n                        RM_REQUIRED;\n                        Rd_sd = sext<32>(f64_to_i32(f64(freg(Fs1_bits)), rm,\n                                                    true));\n                    ', 'FloatCvtOp'],{})

    Fcvt_w_d::Fcvt_w_d(MachInst machInst)
        : RegOp("fcvt_w_d", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_wu_d(['\n                        RM_REQUIRED;\n                        Rd = sext<32>(f64_to_ui32(f64(freg(Fs1_bits)), rm,\n                                                  true));\n                    ', 'FloatCvtOp'],{})

    Fcvt_wu_d::Fcvt_wu_d(MachInst machInst)
        : RegOp("fcvt_wu_d", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_l_d(['\n                        RM_REQUIRED;\n                        Rd_sd = f64_to_i64(f64(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fcvt_l_d::Fcvt_l_d(MachInst machInst)
        : RegOp("fcvt_l_d", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_lu_d(['\n                        RM_REQUIRED;\n                        Rd = f64_to_ui64(f64(freg(Fs1_bits)), rm, true);\n                    ', 'FloatCvtOp'],{})

    Fcvt_lu_d::Fcvt_lu_d(MachInst machInst)
        : RegOp("fcvt_lu_d", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_s_w(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(i32_to_f32((int32_t)Rs1_sw));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fcvt_s_w::Fcvt_s_w(MachInst machInst)
        : RegOp("fcvt_s_w", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_s_wu(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(ui32_to_f32((int32_t)Rs1_uw));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fcvt_s_wu::Fcvt_s_wu(MachInst machInst)
        : RegOp("fcvt_s_wu", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_s_l(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(i64_to_f32(Rs1_ud));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fcvt_s_l::Fcvt_s_l(MachInst machInst)
        : RegOp("fcvt_s_l", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_s_lu(['\n                        RM_REQUIRED;\n                        freg_t fd;\n                        fd = freg(ui64_to_f32(Rs1));\n                        Fd_bits = fd.v;\n                        ', 'FloatCvtOp'],{})

    Fcvt_s_lu::Fcvt_s_lu(MachInst machInst)
        : RegOp("fcvt_s_lu", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fcvt_d_w(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_sw;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_w::Fcvt_d_w(MachInst machInst)
        : RegOp("fcvt_d_w", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_d_wu(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_uw;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_wu::Fcvt_d_wu(MachInst machInst)
        : RegOp("fcvt_d_wu", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_d_l(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1_sd;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_l::Fcvt_d_l(MachInst machInst)
        : RegOp("fcvt_d_l", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fcvt_d_lu(['\n                        RM_REQUIRED;\n                        Fd = (double)Rs1;\n                    ', 'FloatCvtOp'],{})

    Fcvt_d_lu::Fcvt_d_lu(MachInst machInst)
        : RegOp("fcvt_d_lu", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_s(['\n                        Rd = (uint32_t)Fs1_bits;\n                        if ((Rd&0x80000000) != 0) {\n                            Rd |= (0xFFFFFFFFULL << 32);\n                        }\n                    ', 'FloatCvtOp'],{})

    Fmv_x_s::Fmv_x_s(MachInst machInst)
        : RegOp("fmv_x_s", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RD));
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fclass_s(['\n                        Rd = f32_classify(f32(freg(Fs1_bits)));\n                    ', 'FloatMiscOp'],{})

    Fclass_s::Fclass_s(MachInst machInst)
        : RegOp("fclass_s", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_x_d(['\n                        Rd = freg(Fs1_bits).v;\n                    ', 'FloatCvtOp'],{})

    Fmv_x_d::Fmv_x_d(MachInst machInst)
        : RegOp("fmv_x_d", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fclass_d(['\n                        Rd = f64_classify(f64(freg(Fs1_bits)));\n                    ', 'FloatMiscOp'],{})

    Fclass_d::Fclass_d(MachInst machInst)
        : RegOp("fclass_d", machInst, FloatMiscOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(FloatRegClass, FS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// FPROp::fmv_s_x(['\n                    freg_t fd;\n                    fd = freg(f32(Rs1_uw));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fmv_s_x::Fmv_s_x(MachInst machInst)
        : RegOp("fmv_s_x", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// FPROp::fmv_d_x(['\n                    freg_t fd;\n                    fd = freg(f64(Rs1));\n                    Fd_bits = fd.v;\n                ', 'FloatCvtOp'],{})

    Fmv_d_x::Fmv_d_x(MachInst machInst)
        : RegOp("fmv_d_x", machInst, FloatCvtOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(FloatRegClass, FD));
	_numFPDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsFloating] = true;
	flags[IsInteger] = true;;
    }

// Unknown::unknown(([], {}))

// BOp::beq(['\n                    if (Rs1 == Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Beq::Beq(MachInst machInst)
        : ImmOp<int64_t>("beq", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bne(['\n                    if (Rs1 != Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bne::Bne(MachInst machInst)
        : ImmOp<int64_t>("bne", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::blt(['\n                    if (Rs1_sd < Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Blt::Blt(MachInst machInst)
        : ImmOp<int64_t>("blt", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bge(['\n                    if (Rs1_sd >= Rs2_sd) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bge::Bge(MachInst machInst)
        : ImmOp<int64_t>("bge", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bltu(['\n                    if (Rs1 < Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bltu::Bltu(MachInst machInst)
        : ImmOp<int64_t>("bltu", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// BOp::bgeu(['\n                    if (Rs1 >= Rs2) {\n                        NPC = PC + imm;\n                    } else {\n                        NPC = NPC;\n                    }\n                ', 'IsDirectControl', 'IsCondControl'],{})

    Bgeu::Bgeu(MachInst machInst)
        : ImmOp<int64_t>("bgeu", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsCondControl] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;;
        
                imm = BIMM12BITS4TO1 << 1  |
                      BIMM12BITS10TO5 << 5 |
                      BIMM12BIT11 << 11    |
                      IMMSIGN << 12;
                imm = sext<13>(imm);
               ;
    }

// Unknown::unknown(([], {}))

// Jump::jalr((['\n                Rd = NPC;\n                NPC = (imm + Rs1) & (~0x1);\n            ', 'IsIndirectControl', 'IsUncondControl', 'IsCall'], {}))

    Jalr::Jalr(MachInst machInst)
        : ImmOp<int64_t>("jalr", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsIndirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        imm = sext<12>(IMM12);;
    }

// Unknown::unknown(([], {}))

// JOp::jal((['\n            Rd = NPC;\n            NPC = PC + imm;\n        ', 'IsDirectControl', 'IsUncondControl', 'IsCall'], {}))

    Jal::Jal(MachInst machInst)
        : ImmOp<int64_t>("jal", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	flags[IsCall] = true;
	flags[IsControl] = true;
	flags[IsDirectControl] = true;
	flags[IsInteger] = true;
	flags[IsUncondControl] = true;;
        
                imm = UJIMMBITS10TO1 << 1   |
                      UJIMMBIT11 << 11      |
                      UJIMMBITS19TO12 << 12 |
                      IMMSIGN << 20;
                imm = sext<21>(imm);
               ;
    }

// SystemOp::ecall(['\n                            return std::make_shared<SyscallFault>(\n                                (PrivilegeMode)xc->readMiscReg(MISCREG_PRV));\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsSyscall', 'No_OpClass'],{})

    Ecall::Ecall(MachInst machInst)
        : SystemOp("ecall", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;
	flags[IsSyscall] = true;;
    }

// SystemOp::ebreak(['\n                            return std::make_shared<BreakpointFault>(\n                                xc->pcState());\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Ebreak::Ebreak(MachInst machInst)
        : SystemOp("ebreak", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// SystemOp::uret(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            status.uie = status.upie;\n                            status.upie = 1;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_UEPC);\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    Uret::Uret(MachInst machInst)
        : SystemOp("uret", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsNonSpeculative] = true;
	flags[IsReturn] = true;
	flags[IsSerializeAfter] = true;;
    }

// Unknown::unknown(([], {}))

// SystemOp::sret(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            auto pm = (PrivilegeMode)xc->readMiscReg(\n                                MISCREG_PRV);\n                            if (pm == PRV_U ||\n                                (pm == PRV_S && status.tsr == 1)) {\n                                return std::make_shared<IllegalInstFault>(\n                                            "sret in user mode or TSR enabled",\n                                            machInst);\n                                NPC = NPC;\n                            } else {\n                                xc->setMiscReg(MISCREG_PRV, status.spp);\n                                status.sie = status.spie;\n                                status.spie = 1;\n                                status.spp = PRV_U;\n                                xc->setMiscReg(MISCREG_STATUS, status);\n                                NPC = xc->readMiscReg(MISCREG_SEPC);\n                            }\n                        ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    Sret::Sret(MachInst machInst)
        : SystemOp("sret", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsNonSpeculative] = true;
	flags[IsReturn] = true;
	flags[IsSerializeAfter] = true;;
    }

// SystemOp::wfi(['\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            auto pm = (PrivilegeMode)xc->readMiscReg(\n                                MISCREG_PRV);\n                            if (pm == PRV_U ||\n                                (pm == PRV_S && status.tw == 1)) {\n                                return std::make_shared<IllegalInstFault>(\n                                            "wfi in user mode or TW enabled",\n                                            machInst);\n                            }\n                            // don\'t do anything for now\n                        ', 'No_OpClass'],{})

    Wfi::Wfi(MachInst machInst)
        : SystemOp("wfi", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;;
    }

// Unknown::unknown(([], {}))

// SystemOp::sfence_vma(['\n                        STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                        auto pm = (PrivilegeMode)xc->readMiscReg(MISCREG_PRV);\n                        if (pm == PRV_U || (pm == PRV_S && status.tvm == 1)) {\n                            return std::make_shared<IllegalInstFault>(\n                                        "sfence in user mode or TVM enabled",\n                                        machInst);\n                        }\n                        xc->tcBase()->getMMUPtr()->demapPage(Rs1, Rs2);\n                    ', 'IsNonSpeculative', 'IsSerializeAfter', 'No_OpClass'],{})

    Sfence_vma::Sfence_vma(MachInst machInst)
        : SystemOp("sfence_vma", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS2));
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// SystemOp::mret(['\n                        if (xc->readMiscReg(MISCREG_PRV) != PRV_M) {\n                            return std::make_shared<IllegalInstFault>(\n                                        "mret at lower privilege", machInst);\n                            NPC = NPC;\n                        } else {\n                            STATUS status = xc->readMiscReg(MISCREG_STATUS);\n                            xc->setMiscReg(MISCREG_PRV, status.mpp);\n                            status.mie = status.mpie;\n                            status.mpie = 1;\n                            status.mpp = PRV_U;\n                            xc->setMiscReg(MISCREG_STATUS, status);\n                            NPC = xc->readMiscReg(MISCREG_MEPC);\n                        }\n                    ', 'IsSerializeAfter', 'IsNonSpeculative', 'IsReturn'],{})

    Mret::Mret(MachInst machInst)
        : SystemOp("mret", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	flags[IsControl] = true;
	flags[IsNonSpeculative] = true;
	flags[IsReturn] = true;
	flags[IsSerializeAfter] = true;;
    }

// Unknown::unknown(([], {}))

// CSROp::csrrw(['\n                    Rd = data;\n                    data = Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrw::Csrrw(MachInst machInst)
        : CSROp("csrrw", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// CSROp::csrrs(['\n                    Rd = data;\n                    data |= Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrs::Csrrs(MachInst machInst)
        : CSROp("csrrs", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// CSROp::csrrc(['\n                    Rd = data;\n                    data &= ~Rs1;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrc::Csrrc(MachInst machInst)
        : CSROp("csrrc", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	setSrcRegIdx(_numSrcRegs++, RegId(IntRegClass, RS1));
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// CSROp::csrrwi(['\n                    Rd = data;\n                    data = uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrwi::Csrrwi(MachInst machInst)
        : CSROp("csrrwi", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// CSROp::csrrsi(['\n                    Rd = data;\n                    data |= uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrsi::Csrrsi(MachInst machInst)
        : CSROp("csrrsi", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// CSROp::csrrci(['\n                    Rd = data;\n                    data &= ~uimm;\n                ', 'IsSerializeAfter', 'IsNonSpeculative', 'No_OpClass'],{})

    Csrrci::Csrrci(MachInst machInst)
        : CSROp("csrrci", machInst, No_OpClass)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, RD));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// Unknown::unknown(([], {}))

// M5Op::M5Op(([], {}))

    M5Op::M5Op(MachInst machInst)
        : PseudoOp("M5Op", machInst, IntAluOp)
    {
        
    setRegIdxArrays(
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::srcRegIdxArr),
        reinterpret_cast<RegIdArrayPtr>(
            &std::remove_pointer_t<decltype(this)>::destRegIdxArr));
            ;
        
	_numSrcRegs = 0;
	_numDestRegs = 0;
	_numFPDestRegs = 0;
	_numVecDestRegs = 0;
	_numVecElemDestRegs = 0;
	_numVecPredDestRegs = 0;
	_numIntDestRegs = 0;
	_numCCDestRegs = 0;
	setDestRegIdx(_numDestRegs++, RegId(IntRegClass, 10));
	_numIntDestRegs++;
	flags[IsInteger] = true;
	flags[IsNonSpeculative] = true;
	flags[IsSerializeAfter] = true;;
    }

// Unknown::unknown(([], {}))

// Unknown::unknown(([], {}))

#endif
