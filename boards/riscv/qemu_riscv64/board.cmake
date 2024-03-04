# SPDX-License-Identifier: Apache-2.0

set(SUPPORTED_EMU_PLATFORMS qemu)

set(QEMU_binary_suffix riscv64)
set(QEMU_CPU_TYPE_${ARCH} riscv64)
set(QEMU_BIOS_PATH $ENV{QEMU_BIOS_PATH})

set(QEMU_FLAGS_${ARCH}
  -nographic
  -machine virt
  -bios ${QEMU_BIOS_PATH}/fw_jump.elf
  -m 256
  )
board_set_debugger_ifnset(qemu)
