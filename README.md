# PSoC6 Playground
A series of test projects for PSoC6, specifically the CY8CKIT-062S2-AI development board

> Make sure you git clone with `--recursive` flag to pull the submodules as well

# Compiling
Cross-compilation on any platform is made possible by Docker. You may use `docker buildx bake <target>` to build specific targets, or `docker buildx bake` to build everything

# Using PyOCD
PyOCD was choosen as the debugging server due to the expandability via CMSIS packs without downloading 20 different vendor specific OpenOCD.

> Checkout https://pyocd.io/docs/installing

1. `python3 -m pip install -U pyocd`
> You may need to export the directory where pyocd is to the system PATH env
2. `pyocd pack update`
3. `pyocd pack install cy8`
> You may need to setup the udevs rules.
> [Check out this for more info](https://github.com/pyocd/pyOCD/blob/main/udev/README.md)

# ThreadX USB
> Compile target: `tx_usb`

This is a demo project that contains a ThreadX port for CM4 CPU and emUSB running CDC echo.

# [WIP] Radar
> Compile target: `radar`

This project aims to extracts all raw data from the BGT60TR13CE6327XUMA1, Infineon's 50GHz Radar sensor. The goal is to stream out raw data over USB to host computer where user is free to iterate on the DSP algorithms to process the incoming data.