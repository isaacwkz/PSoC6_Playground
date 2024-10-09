# ThreadX + USB Demo
> The target is PSoC6 MCU, specifically, the CY8CKIT-062S2-AI evaluation board

This project serves as a template to bring up the Cortex-M4 core with ThreadX and emUSB running.

# ThreadX Porting
- ThreadX is added as a submodule in `./deps`
- Custom config files are in `./deps/custom_configs`. These files contains the TX kernel configuration and the initialization function.
## Porting Notes
The original ASM file was ported over to a C source file in order to get debugging features in that translation unit. In order to reduce the mess of `#include` yet another file (`core_m4.h`) and the corresponding changes to the CMakeLists, I have opted to manipulate the memory addresses directly. I left the corresponding `core_m4.h` functions as a comment to make it clearer.
### Trap for young players
Due to the way PSoC6 handles bootstrap, where CM0+ CPU wakes up from reset and copies the CM4's interrupt vectors from flash to RAM (both are executable but only RAM is writable), ThreadX's `SysTick_Hanlder` is not being stored properly on the vector table. I have not determined why at the point of writing, but my guess is that ThreadX's not overwriting the vector table that is stored in the flash memory.

> Table 4-1 of PSoC6 TRM, Document No. 002-24529 Rev. *K 
> |Address Range            |Region Name|Use |
> |-------------------------|-----------|--- |
> |0x0000 0000 – 0x1FFF FFFF|Code       |Program code region. You can also put data here. It includes the exception vector table, which starts at address 0.|
> |...|...|...|

It could be that there is another set of default vector table located in the boot ROM and the CM0+ CPU is copying the vector table from the boot ROM instead of the code memory.

Anyways, the fix is simple, you'll need to redirect the SysTick_Handler in the vector to the one in ThreadX like so: `NVIC_SetVector(SysTick_IRQn, SysTick_Handler);` and it's ugly memory manipulating counterpart:
```
unsigned int *vectors        = (unsigned int *)*((volatile unsigned int *)0xE000ED08);
vectors[(signed int)-1 + 16] = (unsigned int)SysTick_Handler;
```

# emUSB
Just do `make library-manager` and add the relevant files in.

# USB CDC Bandwith Test
Run `dd if=/dev/random of=/dev/tty<PSoC6> count=50000 status=progress` and it will display the average transfer rate like so:
```
25355776 bytes (25 MB, 24 MiB) copied, 39 s, 650 kB/s
50000+0 records in
50000+0 records out
25600000 bytes (26 MB, 24 MiB) copied, 39.3814 s, 650 kB/s
```

I noticed a discrepency in the transfer rates. If the MCU was taken out of reset and the `dd` command was run immediately, the average transfer is lower coming in fairly consistently at `415 kB/s` on my system:
```
25326592 bytes (25 MB, 24 MiB) copied, 61 s, 415 kB/s
50000+0 records in
50000+0 records out
25600000 bytes (26 MB, 24 MiB) copied, 61.6752 s, 415 kB/s
```

But if I open a terminal on the serial port after taking the MCU out of reset, `screen /dev/tty<PSoC6> 1`, close it then run the `dd` command again, I magically get speeds >600kB/s. ¯\\_(ツ)_/¯

Now this doesn't quite make sense to me since the 2nd run of `dd ..` does not magically make the speeds faster, only opening a terminal can make it faster. Furthermore, the "opening terminal" trick only works if you open the terminal first thing immediately after reset. :hmm: