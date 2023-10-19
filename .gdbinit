target remote localhost:1234
dir /home/lrc/zephyr-spmp
# file /home/lrc/zephyr-spmp/opensbi/build/platform/generic/firmware/fw_jump.elf
file /home/lrc/zephyr-spmp/samples/userspace/hello_world_user/build/zephyr/zephyr.elf

# initialize: 
# b *0x80200000
# b z_cstart
# b __initialize
# b __reset

# b /home/lrc/zephyr-spmp/arch/riscv/core/thread.c:110
# b switch_to_main_thread
# b arch_new_thread
# b /home/lrc/zephyr-spmp/arch/riscv/core/isr.S:614
b arch_user_mode_enter
b is_user_syscall

b sbi_hart_pmp_configure
b _isr_wrapper
# b __soc_is_irq

b /home/lrc/zephyr-spmp/kernel/init.c:547
b sbi_ecall_handler
b sbi_trap_handler


b user_function

layout src

