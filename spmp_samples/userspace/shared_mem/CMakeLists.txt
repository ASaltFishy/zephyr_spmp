# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(shared_mem)

set(ZEPHYR_BASE /home/lrc/zephyr-spmp)
set(ZEPHYR_DIR /home/lrc/zephyr-spmp)
set(QEMU_BIN_PATH /home/lrc/zephyr-spmp/qemu/build)
set(ZEPHYR_SDK_INSTALL_DIR /home/lrc/opt/zephyr-sdk/zephyr-sdk-0.16.1)


FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
#add_definitions( -DALTMSG)
#add_definitions( -DDBUG)
