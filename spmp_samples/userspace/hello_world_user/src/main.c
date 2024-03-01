/*
 * Copyright (c) 2020 BayLibre, SAS
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include "spmp.h"
#define USER_STACKSIZE 2048

void dump_spmp() {
    printf("\n-----------------DUMP SPMP---------------\n");
    printf("spmpaddr0: 0x%lx\n", SMPU_READ_CFG(0x1b0) << 2);
    printf("spmpaddr1: 0x%lx\n", SMPU_READ_CFG(0x1b1) << 2);
    printf("spmpaddr2: 0x%lx\n", SMPU_READ_CFG(0x1b2) << 2);
    printf("spmpaddr3: 0x%lx\n", SMPU_READ_CFG(0x1b3) << 2);
    printf("spmpaddr4: 0x%lx\n", SMPU_READ_CFG(0x1b4) << 2);
    printf("spmpaddr5: 0x%lx\n", SMPU_READ_CFG(0x1b5) << 2);
    printf("spmpaddr6: 0x%lx\n", SMPU_READ_CFG(0x1b6) << 2);
    printf("spmpaddr7: 0x%lx\n", SMPU_READ_CFG(0x1b7) << 2);
    printf("spmpaddr8: 0x%lx\n", SMPU_READ_CFG(0x1b8) << 2);
    printf("spmpaddr9: 0x%lx\n", SMPU_READ_CFG(0x1b9) << 2);
    printf("spmpaddr10: 0x%lx\n", SMPU_READ_CFG(0x1ba) << 2);
    printf("spmpaddr11: 0x%lx\n", SMPU_READ_CFG(0x1bb) << 2);
    printf("spmpaddr12: 0x%lx\n", SMPU_READ_CFG(0x1bc) << 2);
    printf("spmpaddr13: 0x%lx\n", SMPU_READ_CFG(0x1bd) << 2);
    printf("spmpaddr14: 0x%lx\n", SMPU_READ_CFG(0x1be) << 2);
    printf("spmpaddr15: 0x%lx\n", SMPU_READ_CFG(0x1bf) << 2);

    // print SPMP registers
    printf("spmpcfg0: 0x%lx\n", SMPU_READ_CFG(0x1a0));
    printf("-----------------DUMP SPMP---------------\n\n");

}


struct k_thread user_thread;
K_THREAD_STACK_DEFINE(user_stack, USER_STACKSIZE);

static void user_function(void *p1, void *p2, void *p3) {
    printf("Hello World from %s (%s)\n",
           k_is_user_context() ? "UserSpace!" : "privileged mode.",
           CONFIG_BOARD);
    __ASSERT(k_is_user_context(), "User mode execution was expected");
}

int main(void) {
    dump_spmp();
    k_thread_create(&user_thread, user_stack, USER_STACKSIZE,
                    user_function, NULL, NULL, NULL,
                    -1, K_USER, K_MSEC(0));
    return 0;
}
