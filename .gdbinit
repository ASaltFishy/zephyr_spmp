target remote localhost:1234
dir /home/lrc/zephyr-spmp
# file /home/lrc/zephyr-spmp/opensbi/build/platform/generic/firmware/fw_jump.elf
file /home/lrc/zephyr-spmp/samples/userspace/linpack_float/build/zephyr/zephyr.elf

# initialize: 
b *0x80200000
# b z_cstart
# b __initialize
# b __reset

# b z_riscv_pmp_init
# b z_riscv_write_pmp_entries
# b z_riscv_pmp_usermode_prepare
# b z_cbvprintf_impl
b z_thread_entry

# b arch_is_user_context

# b /home/lrc/zephyr-spmp/lib/os/cbprintf_complete.c:1582

# b /home/lrc/zephyr-spmp/arch/riscv/core/thread.c:110
# b switch_to_main_thread
# b arch_new_thread
# b /home/lrc/zephyr-spmp/arch/riscv/core/isr.S:614
# b arch_user_mode_enter
# b is_user_syscall

# b sbi_hart_pmp_configure
b _isr_wrapper
# b __soc_is_irq

# b /home/lrc/zephyr-spmp/kernel/init.c:547
b sbi_ecall_handler
b sbi_trap_handler


b user_function
b linpack
b malloc

b k_mem_domain_add_partition

layout src

