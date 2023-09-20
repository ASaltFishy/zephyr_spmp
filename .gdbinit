target remote localhost:1234
dir /home/lrc/zephyr-spmp
file samples/hello_world/build/zephyr/zephyr.elf
b *0x80200000