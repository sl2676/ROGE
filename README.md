# ROGE
#### RISC-V_QEMU_FULL-SYSTEM_GEM5-RTL_FRAMEWORK_EMULATION

ROGE Software is utilized by NAU in the ESCAPADE mission, where we can emulate the control board in order to run diagnostics as well as benchmarking tests. The software consists of a Gem5 and RTL framework that uses Verilator or GHDL in order to convert HDL languages to RTL objects that we can then implement within Gem5 classes. Gem5 does not currently support RISC-V full system emulation, so the software implements QEMU as a virtualizer that works in collaboration with DIOSIX(Look in patch notes) that acts as a bare-metal hypervisor. The ESCAPADE team then can load the compression algorithm and other necessary programs through a bootloader(Berkely Boot Loader) to initiate the simulation. The main debugging tool will be GDB debugger that can run untethered or tethered in order to verify code or see the inner workings of programs. Another optional diagnostic tool that may be implemented is a performance monitoring unit(PMU) that employs PARSEC 3.0 library that can run benchmarking tests.  

**Still working on implementing mission details, however for the time being we can run full system emulation for verification as well as to show it is operable**

# SHELL_ENVIRONMENT_VAR
~~~
# Add to shell, replace paths if desired
export RISCV=~/riscv
export PATH=$RISCV/bin:$PATH
export G5=~/gem5
export SRC=$RISCV/src
export OUT=$RISCV/out
~~~

~~~
mkdir -p $RISCV/bin
mkdir -p $RISCV/out
mkdir -p $RISCV/src
~~~
# RISC-V_GNU_TOOLCHAIN
~~~
sudo apt-get install -y autoconf automake autotools-dev curl python3 libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev
git clone https://github.com/riscv/riscv-gnu-toolchain $SRC/toolchain
cd $SRC/toolchain
./configure --prefix=$RISCV --with-arch=rv32gc --with-abi=ilp32d
make linux -j$(nproc)
make newlib -j$(nproc)
~~~
# QEMU
~~~
sudo apt-get install -y git libglib2.0-dev libfdt-dev libpixman-1-dev zlib1g-dev ninja-build
git clone https://git.qemu.org/git/qemu.git $SRC/qemu
cd $SRC/qemu
./configure --target-list=riscv32-softmmu --prefix=$RISCV
make -j$(nproc)
make install
~~~
# GEM5 & RTL_FRAMEWORK
#### DEPENDENCIES
~~~
sudo apt install -y build-essential git m4 scons zlib1g zlib1g-dev libprotobuf-dev protobuf-compiler libprotoc-dev libgoogle-perftools-dev python3-dev python3-six python-is-python3 libboost-all-dev pkg-config
~~~
#### GEM5_RTL INSTALLATION
~~~
git clone https://github.com/sl2676/ROGE.git $G5
~~~
#### INSTALL_VERILATOR
~~~
# More installation details - https://verilator.org/guide/latest/install.html
# Installation example 
git clone https://github.com/verilator/verilator
​
unset VERILATOR_ROOT      # For bash
#git checkout stable      # Use most recent stable release
#git checkout v{version}  # Switch to specified release version
​
autoconf 
./configure --prefix /Specific/location
​
make -j (e.g. 2|4|8) 
[sudo] make install
​
# This must be set when compiling gem5+RTL
export VERILATOR_ROOT=/Specific/location
~~~
#### BUILD_RTL_C++_MODEL_USING_VERILATOR
FIFO example we can use for the rtl object
~~~
cd ext/rtl/model_fifo
make
make library_vcd
make install
~~~
~~~
cd $G5 && scons build/RISCV/gem5.opt -j$(nproc)

#Before executing you need to set up the LIBRARY_PATH to the place where the shared library of the RTL Object resides:
export LD_LIBRARY_PATH="gem5+RTL_FOLDER/ext/rtl"
~~~
# BAREMETAL
~~~
~~~
# LINUX_SYSTEM

#### BUSY_BOX-DISK_IMAGE
~~~
~~~
#### LINUX_KERNEL
~~~
git clone https://github.com/torvalds/linux.git $SRC/linux
cd $SRC/linux
git checkout v5.10
make ARCH=riscv CROSS_COMPILE=riscv32-unknown-linux-gnu- olddefconfig
make ARCH=riscv CROSS_COMPILE=riscv32-unknown-linux-gnu- all -j$(nproc)
cp vmlinux $OUT
~~~
#### BERKELEY_BOOTLOADER
~~~
sudo apt-get install -y device-tree-compiler
git clone https://github.com/riscv/riscv-pk.git $SRC/pk
mkdir -p $SRC/pk/build 
cd $SRC/pk/build
../configure --host=riscv32-unknown-linux-gnu --with-payload=$OUT/vmlinux --prefix=$RISCV
CFLAGS="-g" make -j$(nproc)
make install
cp bbl $OUT
~~~
#### PARSING AND DUMPING DTS
~~~
# DTB -> DTS
dtc -I dtb -O dts xxx.dtb -> xxx.dts

# DTS -> DTB
dtc -I dts -O dtb xxx.dts -> xxx.dtb
~~~

