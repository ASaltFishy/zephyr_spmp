## How to run Zephyr in S-mode with SPMP extension

### Install Dependencies and Zephyr-sdk
It's the same as usaul, please refer to https://docs.zephyrproject.org/latest/develop/getting_started/index.html

### Get Code and Build Them
Clone Zephyr, QEMU and Opensbi. 
- Build QEMU 
./build-qemu.sh
- Build Opensbi
``` BASH
# First, generate .dtb file
cd {ZEPHYR_BASE}/dts/riscv
dtc -I dts -O dtb -o virt.dtb virt.dtsi

# Seconde, use this generated .dtb file to build opensbi
make PLATFORM=generic CROSS_COMPILE=riscv64-unknown-linux-gnu- FW_FDT_PATH={ZEPHYR_BASE}/dts/riscv/virt.dtb FW_JUMP=y DEBUG=1
```
### Set Environment Variables
``` bash
export ZEPHYR_SDK_INSTALL_DIR={zephyr_sdk_install_dir}
export ZEPHYR_BASE={your_zephyr_root_dir}
export QEMU_BIOS_PATH={dir_to_opensbi}/build/platform/generic/firmware
export QEMU_BIN_PATH={dir_to_qemu}/build
```
### Build the Hello_world_user Sample 