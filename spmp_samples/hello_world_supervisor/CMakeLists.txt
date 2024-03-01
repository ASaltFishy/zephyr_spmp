# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

set(ZEPHYR_BASE /home/lrc/zephyr-spmp)
set(ZEPHYR_DIR /home/lrc/zephyr-spmp)
set(QEMU_BIN_PATH /home/lrc/zephyr-spmp/qemu/build)
set(ZEPHYR_SDK_INSTALL_DIR /home/lrc/opt/zephyr-sdk/zephyr-sdk-0.16.1)


find_package(Zephyr REQUIRED HINTS ${ZEPHYR_BASE})
project(hello_world_supervisor)

target_sources(app PRIVATE src/main.c)