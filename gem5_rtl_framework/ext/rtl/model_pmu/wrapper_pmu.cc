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

#include "wrapper_pmu.hh"

Wrapper_pmu::Wrapper_pmu(bool traceOn, std::string name) :
        tickcount(0),
        trace(NULL),
        traceName(name),
        traceOn(traceOn) {

    top = new VAXI_PMU;

    Verilated::traceEverOn(true);
    //trace = new VerilatedFstC;
    trace = new VerilatedVcdC;
    if (!trace) {
        std::cerr << "Trace not init" << std::endl;
        return;
    }
    
    // fst, levels, options
    top->trace(trace,99);

    std::cout << traceName << std::endl;
    trace->open(traceName.c_str());
}

Wrapper_pmu::~Wrapper_pmu() {
    if (trace) {
        trace->dump(tickcount);
        trace->close();
            delete trace;
    }
    top->final();
    delete top;
    exit(EXIT_SUCCESS);
}

void Wrapper_pmu::enableTracing() {
    traceOn = true;
}

void Wrapper_pmu::disableTracing() {
    traceOn = false;
}

void Wrapper_pmu::tick() {

    top->S_AXI_ACLK_i = 1;
    top->eval();

    advanceTickCount();

    top->S_AXI_ACLK_i = 0;
    top->eval();

    advanceTickCount();
}

void Wrapper_pmu::advanceTickCount() {
    if (trace and traceOn) {
        trace->dump(tickcount);
    }
    tickcount++;
}

uint64_t Wrapper_pmu::getTickCount() {
    return tickcount;
}

void Wrapper_pmu::reset() {
    tick();
    top->S_AXI_ARESETN_i=0;
    tick();
    
    top->S_AXI_ARESETN_i=1;
    // config parameters
    top->S_AXI_BREADY_i = 1;
    top->S_AXI_RREADY_i = 1;
    top->S_AXI_WSTRB_i = 15;
    tick();

}
void Wrapper_pmu::enableEvent(uint8_t ev) {
    if (ev==0) {
        top->EV0_i = 1;
    }
    else if (ev==1) {
        top->EV1_i = 1;
    }
    else if (ev==2) {
        top->EV2_i = 1;
    }
    else if (ev==3) {
        top->EV3_i = 1;
    }
    else if (ev==4) {
        top->EV4_i = 1;
    }
    else if (ev==5) {
        top->EV5_i = 1;
    }
    else if (ev==6) {
        top->EV6_i = 1;
    }
    else if (ev==7) {
        top->EV7_i = 1;
    }
    else if (ev==8) {
        top->EV8_i = 1;
    }
    else if (ev==9) {
        top->EV9_i = 1;
    }
}

void Wrapper_pmu::disableEvent(uint8_t ev) {
    if (ev==0) {
        top->EV0_i = 0;
    }
    else if (ev==1) {
        top->EV1_i = 0;
    }
    else if (ev==2) {
        top->EV2_i = 0;
    }
    else if (ev==3) {
        top->EV3_i = 0;
    }
    else if (ev==4) {
        top->EV4_i = 0;
    }
    else if (ev==5) {
        top->EV5_i = 0;
    }
    else if (ev==6) {
        top->EV6_i = 0;
    }
    else if (ev==7) {
        top->EV7_i = 0;
    }
    else if (ev==8) {
        top->EV8_i = 0;
    }
    else if (ev==9) {
        top->EV9_i = 0;
    }
}

void Wrapper_pmu::enablePMU() {
    // register 0x4C bit 0 is the enable
    writeAXI(0x4C,1);
}

void Wrapper_pmu::disablePMU() {
    // register 0x4C bit 0 is the enable
    writeAXI(0x4C,0);
}

void Wrapper_pmu::softResetPMU() {
    // register 0x4C bit 0 is the enable
    // register 0x4C bit 1 is the reset
    writeAXI(0x4C,2);
    writeAXI(0x4C,0);
}
void Wrapper_pmu::addQuotaMask(uint32_t mask) {
    writeAXI(0x64,mask);
}

void Wrapper_pmu::addQuotaOvf(uint32_t ovf) {
    writeAXI(0x68,ovf);
}

void Wrapper_pmu::writeAXI(uint32_t addr, uint32_t data) {
    top->S_AXI_AWADDR_i = addr;
    top->S_AXI_AWVALID_i = 1;
    tick();
    top->S_AXI_WVALID_i = 1;
    top->S_AXI_WDATA_i = data;
    tick();
    tick();
    top->S_AXI_AWVALID_i = 0;
    top->S_AXI_WVALID_i = 0;
    tick();
}

uint32_t Wrapper_pmu::readAXI(uint32_t addr) {
    top->S_AXI_ARADDR_i = addr;
    top->S_AXI_ARVALID_i = 1;
    tick();
    tick();
    top->S_AXI_ARVALID_i = 0;
    while (!top->S_AXI_RVALID_o) {tick();}
    return top->S_AXI_RDATA_o; 
}

bool Wrapper_pmu::interrupt() {
    return top->int_quota_o == 1;
}


void Wrapper_pmu::processInput(inputPMU in) {
    // events
    top->EV1_i = in.event1;
    top->EV2_i = in.event2;
    top->EV3_i = in.event3;
    top->EV4_i = in.event4;
    top->EV5_i = in.event5;
    top->EV6_i = in.event6;
    top->EV7_i = in.event7;
    // axi signals
    /*
    top->S_AXI_AWADDR_i  = in.inAXI.aw_addr;
    top->S_AXI_AWVALID_i = in.inAXI.aw_valid;
    top->S_AXI_WVALID_i  = in.inAXI.w_valid;
    top->S_AXI_WDATA_i   = in.inAXI.w_data;
    top->S_AXI_WSTRB_i   = in.inAXI.w_strb;
    top->S_AXI_BREADY_i  = in.inAXI.b_ready;
    top->S_AXI_ARVALID_i = in.inAXI.ar_valid;
    top->S_AXI_ARADDR_i  = in.inAXI.ar_addr;
    top->S_AXI_RREADY_i  = in.inAXI.r_ready;*/
}

outputPMU Wrapper_pmu::processOutput() {
    outputPMU out;
    
    out.int_quota_o = top->int_quota_o;
    
    // AXI signals
    /*out.outAXI.aw_ready = top->S_AXI_AWREADY_o;
    out.outAXI.w_ready = top->S_AXI_WREADY_o;
    out.outAXI.b_valid = top->S_AXI_BVALID_o;
    out.outAXI.b_resp = top->S_AXI_BRESP_o;
    out.outAXI.ar_ready = top->S_AXI_ARREADY_o;
    out.outAXI.r_valid = top->S_AXI_RVALID_o;
    out.outAXI.r_data = top->S_AXI_RDATA_o;
    out.outAXI.r_resp = top->S_AXI_RRESP_o;*/
    
    return out;
}


// Function to be called with inputs and outputs
// of interest
outputPMU Wrapper_pmu::tick(inputPMU in) {
    
    processInput(in);
    // first part of the cycle
    top->S_AXI_ACLK_i = 1;
    top->eval();

    advanceTickCount();
    // second part of the cycle
    top->S_AXI_ACLK_i = 0;
    top->eval();

    advanceTickCount();

    return processOutput();
}

void Wrapper_pmu::half_tick() {

    top->S_AXI_ACLK_i = !top->S_AXI_ACLK_i;
    top->eval();

    advanceTickCount();

}

