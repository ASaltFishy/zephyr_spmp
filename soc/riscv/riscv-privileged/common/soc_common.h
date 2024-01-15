/*
 * Copyright (c) 2017 Jean-Paul Etienne <fractalclone@gmail.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file configuration macros for riscv SOCs supporting the riscv
 *       privileged architecture specification
 */

#ifndef __SOC_COMMON_H_
#define __SOC_COMMON_H_

/* IRQ numbers */
#define RISCV_MACHINE_SOFT_IRQ       3  /* Machine Software Interrupt */
#define RISCV_MACHINE_EXT_IRQ        11 /* Machine External Interrupt */
#define RISCV_SUPERVISOR_SOFT_IRQ        1 /* Supervisor Software Interrupt */
#define RISCV_SUPERVISOR_EXT_IRQ        9 /* Supervisor External Interrupt */


/* ECALL Exception numbers */
#define SOC_MCAUSE_ECALL_EXP         11 /* Machine ECALL instruction */
#define SOC_MCAUSE_USER_ECALL_EXP    8  /* User ECALL instruction */
#define SOC_SCAUSE_S_CALL_EXP       9
#define SOC_SCAUSE_U_CALL_EXP       8

/* SOC-specific MCAUSE bitfields */
#ifdef CONFIG_64BIT
/* Interrupt Mask */
#define SOC_MCAUSE_IRQ_MASK          (1 << 63)
#define SOC_SCAUSE_IRQ_MASK          (1 << 63)
#else
/* Interrupt Mask */
#define SOC_MCAUSE_IRQ_MASK          (1 << 31)
#define SOC_SCAUSE_IRQ_MASK          (1 << 31)
#endif

/* Exception code Mask 0x7FFFFFFFFFFFFFFF if CONFIG_64BIT */
#define SOC_MCAUSE_EXP_MASK          CONFIG_RISCV_SOC_MCAUSE_EXCEPTION_MASK
#define SOC_SCAUSE_EXP_MASK          CONFIG_RISCV_SOC_MCAUSE_EXCEPTION_MASK

#ifndef _ASMLANGUAGE

#include <zephyr/drivers/interrupt_controller/riscv_clic.h>
#include <zephyr/drivers/interrupt_controller/riscv_plic.h>

#if defined(CONFIG_RISCV_SOC_INTERRUPT_INIT)
void soc_interrupt_init(void);
#endif

#endif /* !_ASMLANGUAGE */

#endif /* __SOC_COMMON_H_ */
