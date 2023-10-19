# SPDX-License-Identifier: Apache-2.0

set(SUPPORTED_EMU_PLATFORMS qemu)

set(QEMU_binary_suffix riscv64)
set(QEMU_CPU_TYPE_${ARCH} riscv64)

set(QEMU_FLAGS_${ARCH}
  -nographic
  -machine virt
  -bios /home/lrc/zephyr-spmp/opensbi/build/platform/generic/firmware/fw_jump.elf
  -m 256
  )
board_set_debugger_ifnset(qemu)
