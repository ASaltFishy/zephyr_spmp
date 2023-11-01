/*
 * Copyright 2022 The Chromium OS Authors
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/linker/sections.h>
#include <zephyr/devicetree.h>

#include <zephyr/linker/linker-defs.h>
#include <zephyr/linker/linker-tool.h>

/*
 * this is just an example to show relocation of code/data/bss script
 */
#define _RAM1_DATA_SECTION_NAME  .ram1_data
#define _RAM1_BSS_SECTION_NAME   .ram1_bss
#define _RAM1_TEXT_SECTION_NAME  .ram1_text
#define RAM1_ADDR  (CONFIG_SRAM_BASE_ADDRESS + RAM_SIZE2)

#define RAM_SIZE2 (CONFIG_SRAM_SIZE * 512)


/* Define a symbol for RAM1 size */
MEMORY
    {
    RAM1                  (rx) : ORIGIN = (CONFIG_SRAM_BASE_ADDRESS + RAM_SIZE2), LENGTH = RAM_SIZE2
    }

#include <zephyr/arch/riscv/common/linker.ld>

SECTIONS
{
    /* Define RAM1 start address as a symbol */
    __ram1_start_addr = ORIGIN(RAM1);

    /* Define RAM1 size as a symbol */
    __ram1_size = LENGTH(RAM1);
}
