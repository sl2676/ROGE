# Copyright (c) 2022 Barcelona Supercomputing Center
# All rights reserved.
#
# The license below extends only to copyright in the software and shall
# not be construed as granting a license to any other intellectual
# property including but not limited to intellectual property relating
# to a hardware implementation of the functionality of the software
# licensed hereunder.  You may use the software subject to the license
# terms below provided that you ensure that this notice is replicated
# unmodified and in its entirety in all distributions of the software,
# modified or unmodified, in source code or in binary form.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met: redistributions of source code must retain the above copyright
# notice, this list of conditions and the following disclaimer;
# redistributions in binary form must reproduce the above copyright
# notice, this list of conditions and the following disclaimer in the
# documentation and/or other materials provided with the distribution;
# neither the name of the copyright holders nor the names of its
# contributors may be used to endorse or promote products derived from
# this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
# OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
# SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
# LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Authors: Guillem Lopez Paradis

# here there is the code of pmu
DIR =verilator_pmu_vcd

TRACE="${VERILATOR_ROOT}/include/verilated_vcd_c.cpp"

PMU_DIR=./bsc_pmu/hdl
PMU_DIR_RDC=./bsc_pmu/submodules/RDC/hdl
PMU_DIR_MCCU=./bsc_pmu/submodules/MCCU/hdl
PMU_DIR_QUOTA=./bsc_pmu/submodules/quota/hdl
PMU_DIR_OVFW=./bsc_pmu/submodules/overflow/hdl
PMU_DIR_CROSS=./bsc_pmu/submodules/crossbar/hdl
PMU_DIR_SIP=./bsc_pmu/submodules/seu_ip/hdl

build_static:
	cd $(DIR) && make OPT="-O3 -march=native -fno-stack-protector -fPIC" -f VAXI_PMU.mk && cd ..

clone:
	git clone --recurse-submodules git@gitlab-internal.bsc.es:caos_hw/hdl_ip/bsc_pmu.git -b develop

verilate_vcd: $(OBJS)
	$(VERILATOR_ROOT)/bin/verilator -cc --trace AXI_PMU.sv  \
	--Mdir $(DIR) \
	-I$(PMU_DIR_MCCU) -I$(PMU_DIR_RDC)  \
	-I$(PMU_DIR_QUOTA) -I$(PMU_DIR_OVFW) \
	-I$(PMU_DIR_CROSS) -I$(PMU_DIR_SIP) -I$(PMU_DIR)

create_library_pmu: wrapper_pmu.cc
	g++ -O3 -I$(DIR) -I$(VERILATOR_ROOT)/include wrapper_pmu.cc \
	$(DIR)/*.cpp rtl_packet_pmu.hh \
	$(VERILATOR_ROOT)/include/verilated.cpp \
	-I$(VERILATOR_ROOT)/include/vltstd \
	$(TRACE) \
	 -lz -fpic  -shared -o libVerilatorPMU.so

create_library_pmu_from_static: wrapper_pmu.cc
	g++ -O3 -march=native -I$(DIR) -I$(VERILATOR_ROOT)/include wrapper_pmu.cc  \
	$(VERILATOR_ROOT)/include/verilated.cpp \
	-I$(VERILATOR_ROOT)/include/vltstd \
	${TRACE} \
	-Wl,--whole-archive $(DIR)/VAXI_PMU__ALL.a -Wl,--no-whole-archive  \
	 -lz -fpic  -shared -o libVerilatorPMU.so \

main: main_pmu.cpp 
	g++ -I$(DIR) -I$(VERILATOR_ROOT)/include main_pmu.cpp \
	-I$(VERILATOR_ROOT)/include/vltstd \
	-L . -o main_pmu -lVerilatorPMU


# this is to make it visible outsite command line
.PHONY: clean create_library_pmu main verilate_vcd

install:
	cp wrapper_pmu.hh ..
	cp libVerilatorPMU.so ..
	cp rtl_packet_pmu.hh ..

clean:
	rm -rf $(DIR) ../wrapper_pmu.cc ../wrapper_pmu.hh \
	../libVerilatorPMU.so ../rtl_packet_pmu.hh libVerilatorPMU.so 

