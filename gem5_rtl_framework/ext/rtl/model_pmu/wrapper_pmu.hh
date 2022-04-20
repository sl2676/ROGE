/*
* Copyright (c) 2022 Barcelona Supercomputing Center
* All rights reserved.
*
* The license below extends only to copyright in the software and shall
* not be construed as granting a license to any other intellectual
* property including but not limited to intellectual property relating
* to a hardware implementation of the functionality of the software
* licensed hereunder.  You may use the software subject to the license
* terms below provided that you ensure that this notice is replicated
* unmodified and in its entirety in all distributions of the software,
* modified or unmodified, in source code or in binary form.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met: redistributions of source code must retain the above copyright
* notice, this list of conditions and the following disclaimer;
* redistributions in binary form must reproduce the above copyright
* notice, this list of conditions and the following disclaimer in the
* documentation and/or other materials provided with the distribution;
* neither the name of the copyright holders nor the names of its
* contributors may be used to endorse or promote products derived from
* this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
* A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
* OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
* THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
* Authors: Guillem Lopez Paradis
*/

#include <cstdlib>
#include <iostream>

#include "VAXI_PMU.h"
#include "rtl_packet_pmu.hh"
#include "verilated.h"

// Regular fst trace
//#include "verilated_fst_c.h"

// Regular vcd trace
#include "verilated_vcd_c.h"

class Wrapper_pmu {

    public:
        Wrapper_pmu(bool traceOn, std::string name);
        ~Wrapper_pmu();

        void tick();
        void half_tick();
        // new tick function
        outputPMU tick(inputPMU input);
        uint64_t getTickCount();
        void enableTracing();
        void disableTracing();
        void advanceTickCount();
        void reset();
        void enableEvent(uint8_t ev);
        void disableEvent(uint8_t ev);
        void enablePMU();
        void disablePMU();
        void softResetPMU();
        bool interrupt();
        
        void processInput(inputPMU in);
        outputPMU processOutput();

        void addQuotaMask(uint32_t mask);
        void addQuotaOvf(uint32_t ovf);

        void writeAXI(uint32_t addr, uint32_t data);
        uint32_t readAXI(uint32_t addr);
        
        VAXI_PMU *top;
        uint64_t tickcount;
        //VerilatedFstC *fst;
        VerilatedVcdC *trace;
        std::string traceName;
        bool traceOn;
};
