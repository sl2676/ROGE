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

#include <iostream>
#include "wrapper_pmu.hh"

using namespace std;


void delay(Wrapper_pmu* wr, uint8_t cycles) {
    for (int i = 0; i < cycles; i++) {
        wr->tick();
    }
}

uint32_t read_axi(Wrapper_pmu* wr, uint32_t addr) {
    // if not S_AXI_ARREADY_o
    wr->top->S_AXI_ARADDR_i = addr;
    wr->top->S_AXI_ARVALID_i = 1;
    delay(wr, 2);
    wr->top->S_AXI_ARVALID_i = 0;
    //wr->top->S_AXI_RREADY_i = 1;
}
uint32_t disable_read_axi(Wrapper_pmu* wr) {
    // if not S_AXI_ARREADY_o
    wr->top->S_AXI_ARADDR_i = 0;
    wr->top->S_AXI_ARVALID_i = 0;
    //wr->top->S_AXI_RREADY_i = 1;
}

uint32_t write_axi(Wrapper_pmu* wr, uint32_t addr, uint32_t value) {
    // if (S_AXI_AWREADY_o != 1) ....
    wr->top->S_AXI_AWADDR_i = addr;
    wr->top->S_AXI_AWVALID_i = 1;
    delay(wr, 1);
    wr->top->S_AXI_WVALID_i = 1;
    wr->top->S_AXI_WDATA_i = value;
    delay(wr, 2);
    wr->top->S_AXI_AWVALID_i = 0;
    wr->top->S_AXI_WVALID_i = 0;
    //delay(wr, 2);
    //wr->top->S_AXI_BREADY_i = 1;
    //wr->top->S_AXI_WSTRB_i = 15; // 0x0F
}

uint32_t disable_write_axi(Wrapper_pmu* wr) {
    // if (S_AXI_AWREADY_o != 1) ....
    wr->top->S_AXI_AWADDR_i = 0;
    wr->top->S_AXI_AWVALID_i = 0;
    wr->top->S_AXI_WDATA_i = 0;
    wr->top->S_AXI_WSTRB_i = 0; // 0x0F
    wr->top->S_AXI_WVALID_i = 0;
    //wr->top->S_AXI_BREADY_i = 1;
}

void read_and_print(Wrapper_pmu* wr, uint32_t addr) {
    read_axi(wr,addr);
    while (!wr->top->S_AXI_RVALID_o) {delay(wr, 1);}
    std::cout << "Read Addr: " << std::hex << addr << ", value: " 
                          << wr->top->S_AXI_RDATA_o << std::endl;
    wr->tick();
}

void write_and_print(Wrapper_pmu* wr, uint32_t addr, uint32_t value) {
    write_axi(wr,addr, value);
    //while (!wr->top->S_AXI_RVALID_o) {delay(wr, 1);}
    std::cout << "Write Addr: " << std::hex << addr << ", value: " 
                          << value << std::endl;
    wr->tick();
}

void test_not_wrapper(Wrapper_pmu* wr) {
    // default values don't change
    //wr.top->S_AXI_BREADY_i = 1;
    wr->top->S_AXI_RREADY_i = 1;
    wr->top->S_AXI_WSTRB_i = 15; //0x0F
    wr->tick();
    
    //write_axi(&wr, 0, 1);
    delay(wr, 5);
    //wr->enableEvent(0);
    //delay(&wr, 5);
    //wr->disableEvent(0);

    for(int a=0; a < 0x8C; a+=4) {
        write_axi(wr,a,0x01);
        delay(wr, 4);
        //disable_write_axi(&wr);
        //delay(&wr, 4);
    }
    // Check we have written the conf register
    for (int a=0; a < 0x8c; a+=4) {
        read_axi(wr,a);
        while (!wr->top->S_AXI_RVALID_o) {delay(wr, 1);}
        std::cout << "Addr: " << std::hex << a 
                  << ", " << wr->top->S_AXI_RDATA_o << std::endl;
        wr->tick();
    }
    //write_and_print(&wr,76,1);
    //read_and_print(&wr,76);
    wr->writeAXI(0x4C,1);
    // enabled event put events
    //read_and_print(&wr,0);
    delay(wr, 2);
    wr->enableEvent(1);
    wr->enableEvent(2);
    wr->enableEvent(3);
    wr->enableEvent(4);
    wr->enableEvent(5);
    wr->enableEvent(6);
    wr->enableEvent(7);
    wr->enableEvent(8);
    wr->enableEvent(9);
    delay(wr, 10);
    wr->disableEvent(1);
    wr->disableEvent(2);
    wr->disableEvent(3);
    wr->disableEvent(4);
    wr->disableEvent(5);
    wr->disableEvent(6);
    wr->disableEvent(7);
    wr->disableEvent(8);
    wr->disableEvent(9);
    //read_and_print(&wr,0);
    wr->disableEvent(0);
    delay(wr, 5);
    for(int a=0; a < 80; a+=4) {
        cout << "Read wrapper: " << wr->readAXI(a) << std::endl;
        //disable_write_axi(&wr);
        //delay(&wr, 4);
    }
}

void test_counters(Wrapper_pmu* wr) {
    delay(wr,1);
    wr->writeAXI(0x4C,1);
    wr->enableEvent(0);
    wr->enableEvent(1);
    wr->enableEvent(2);
    wr->enableEvent(3);
    wr->enableEvent(4);
    wr->enableEvent(5);
    wr->enableEvent(6);
    wr->enableEvent(7);
    delay(wr,10);
    wr->disableEvent(0);
    wr->disableEvent(1);
    wr->disableEvent(2);
    wr->disableEvent(3);
    wr->disableEvent(4);
    wr->disableEvent(5);
    wr->disableEvent(6);
    wr->disableEvent(7);
    delay(wr,1);
    for (int i = 0; i < 0x4C; i+=4) {
        cout << "Read: " << wr->readAXI(i)<< std::endl;
    }
}

void test_write_all(Wrapper_pmu* wr) {
    for(int a=0; a < 0x84; a+=4) {
        wr->writeAXI(a,0xFF);
        //delay(wr, 1);
    }
    // Check we have written the conf register
    for (int a=0; a < 0x84; a+=4) {
        wr->readAXI(a);
        cout << std::hex <<  a << " Read: " << wr->readAXI(a)<< std::endl;
    }
}

void test_interrupt(Wrapper_pmu* wr) {
    delay(wr,1);
    // quota mask
    wr->addQuotaMask(0x02);
    //wr->writeAXI(0x64,0x02);
    // quota overflow
    //wr->writeAXI(0x68,98);
    wr->addQuotaOvf(9999998);
    // Enable
    wr->enablePMU();
    //wr->writeAXI(0x4C,1);
    
    delay(wr,1); 
    
    cout << "0x64 Read: " << wr->readAXI(0x64)<< std::endl;
    cout << "0x68 Read: " << wr->readAXI(0x68)<< std::endl;
    cout << "0x4C Read: " << wr->readAXI(0x4C)<< std::endl;
    // Enable events
    delay(wr,1);
    wr->enableEvent(1);
    wr->enableEvent(2);
    while (!wr->top->int_quota_o) {
        delay(wr,1);    
    }
    wr->disableEvent(1);
    wr->disableEvent(2);
    delay(wr,1);
    for (int i = 0; i < 0x84; i+=4) {
        cout << i << " Read: " << wr->readAXI(i)<< std::endl;
    }

    // SoftReset
    // Enable
    wr->writeAXI(0x4C,0x02);
    for (int i = 0; i < 0x84; i+=4) {
        cout << i << " Read: " << std::hex << wr->readAXI(i) << std::endl;
    }
    //cout << "0x60 Read: " << std::hex << wr->readAXI(0x60)<< std::endl;
}
/*
void test_new_tick(Wrapper_pmu* wr) {
    //delay(wr,1);
    // quota mask
    inputPMU in;
    memset(&in,0,sizeof(inputPMU));
    //in.inAXI.b_ready = true;
    //in.inAXI.r_ready = true;
    //in.inAXI.w_strb = 15;
    //std::cout << in.inAXI.ar_valid << std::endl;
    outputPMU out;
    wr->processInput(in);
    wr->half_tick();wr->half_tick();
    //in.inAXI.aw_addr = 0x64;
    //in.inAXI.aw_valid = true;
    wr->processInput(in);
    wr->half_tick();wr->half_tick();
    //in.inAXI.w_valid = true;
    //in.inAXI.w_data  = 1;
    out = wr->tick(in);
    while (!out.outAXI.b_valid) {
        out = wr->tick(in);
    }
    in.inAXI.w_valid   = false;
    in.inAXI.aw_valid  = false;
    out = wr->tick(in);
    // /wr->half_tick();wr->half_tick();

    cout << "0x64 Read: " << wr->readAXI(0x64)<< std::endl;
    cout << "0x68 Read: " << wr->readAXI(0x68)<< std::endl;
    cout << "0x4C Read: " << wr->readAXI(0x4C)<< std::endl;
    for (int i =0; i < 10; i++) {
        in.event1 = true;
        in.event2 = true;
        in.event3 = true;
        in.event4 = true;
        wr->tick(in);
    }

    in.inAXI.ar_addr = 0x4C;
    in.inAXI.ar_valid = true;
    wr->tick(in);
    std::cout << out.outAXI.r_valid << std::endl;
    out = wr->tick(in);
    std::cout << out.outAXI.r_valid << std::endl;
    in.inAXI.ar_valid = false;
    while (!out.outAXI.r_valid) {
        out = wr->tick(in);
    }
    std::cout << out.outAXI.r_data << std::endl;
    /*
    wr->addQuotaMask(0x02);
    //wr->writeAXI(0x64,0x02);
    // quota overflow
    //wr->writeAXI(0x68,98);
    wr->addQuotaOvf(8);
    // Enable
    wr->enablePMU();
    //wr->writeAXI(0x4C,1);
    
    delay(wr,1); 
    
    cout << "0x64 Read: " << wr->readAXI(0x64)<< std::endl;
    cout << "0x68 Read: " << wr->readAXI(0x68)<< std::endl;
    cout << "0x4C Read: " << wr->readAXI(0x4C)<< std::endl;
    // Enable events
    delay(wr,1);
    wr->enableEvent(1);
    wr->enableEvent(2);
    while (!wr->top->int_quota_o) {
        delay(wr,1);    
    }
    wr->disableEvent(1);
    wr->disableEvent(2);
    delay(wr,1);
    //for (int i = 0; i < 0x84; i+=4) {
    //    cout << i << " Read: " << wr->readAXI(i)<< std::endl;
   // }

    // SoftReset
    // Enable
    wr->writeAXI(0x4C,0x02);
    //for (int i = 0; i < 0x84; i+=4) {
    //    cout << i << " Read: " << std::hex << wr->readAXI(i) << std::endl;
   // }
    //cout << "0x60 Read: " << std::hex << wr->readAXI(0x60)<< std::endl;*/
//}

int main (int argc, char **argv) {
    //Verilated::commandArgs(argc, argv);
    //char *aux = "0";
    //Verilated::commandArgs(0, &aux);
    Wrapper_pmu wr(true, std::string("trace.fst"));
    wr.reset();
    wr.enablePMU();

    //delay(&wr,1);
    //wr.writeAXI(0x4c,0xFF);
    //wr.writeAXI(0x64,0xFF);
    //wr.writeAXI(0x68,0xFF);
    //cout << " 0x4c: Read: " << wr.readAXI(0x4C)<< std::endl;
    //test_write_all(&wr);
    test_interrupt(&wr);
    //test_new_tick(&wr);
    
    
    
  return 0;
}