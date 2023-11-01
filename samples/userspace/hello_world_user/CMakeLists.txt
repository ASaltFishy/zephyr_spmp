# SPDX-License-Identifier: Apache-2.0
# add_definitions("-Wall -g -O0")

cmake_minimum_required(VERSION 3.20.0)

set(ZEPHYR_BASE /home/lrc/zephyr-spmp)
set(ZEPHYR_DIR /home/lrc/zephyr-spmp)
set(ZEPHYR_SDK_INSTALL_DIR /home/lrc/opt/zephyr-sdk/zephyr-sdk-0.16.1)

find_package(Zephyr REQUIRED HINTS ${ZEPHYR_BASE})
project(hello_world_user)

target_sources(app PRIVATE src/main.c)

# Code relocation feature
zephyr_code_relocate(FILES src/main.c  LOCATION RAM1_TEXT_DATA_BSS_RODATA)


# zephyr_linker_sources(SECTIONS custom-sections.ld)
