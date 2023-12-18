target remote localhost:1234
dir /home/lrc/zephyr-spmp
# file /home/lrc/zephyr-spmp/opensbi/build/platform/generic/firmware/fw_jump.elf
file /home/lrc/zephyr-spmp/samples/userspace/hello_world_user/build/zephyr/zephyr.elf

b _start
b z_thread_entry
# b z_riscv_pmp_init
# b set_pmp_entry
# b *0x80200000
# b z_cstart
# b __initialize
# b __reset
# b arch_kernel_init
# b boot_first_core
# b boot_secondary_core

b sbi_ecall_hsm_handler
# b z_riscv_pmp_init
# b z_riscv_write_pmp_entries
# b z_riscv_pmp_usermode_prepare
# b z_cbvprintf_impl
# b z_thread_entry

# b arch_is_user_context

# b /home/lrc/zephyr-spmp/lib/os/cbprintf_complete.c:1582

# b /home/lrc/zephyr-spmp/arch/riscv/core/thread.c:110
# b switch_to_main_thread
# b arch_new_thread
# b /home/lrc/zephyr-spmp/arch/riscv/core/isr.S:614
# b arch_user_mode_enter
# b is_user_syscall

b _isr_wrapper
# b arch_irq_enable
b z_riscv_thread_start



# b sbi_ecall_handler
# b sbi_trap_handler
# b wake_coldboot_harts
# b init_coldboot
# b sbi_domain_finalize
# b sbi_domain_register   
# b sbi_domain_init
b sbi_hart_switch_mode
b sbi_ecall_ipi_handler
b sbi_hsm_hart_interruptible_mask

b main
b ipi_handler
b helloLoop
b threadA
b threadB
# b arch_start_cpu

# b z_riscv_switch
# b z_impl_k_thread_start
# b check_reschedule
# b arch_cpu_idle

b main

b  z_riscv_fatal_error
layout src

