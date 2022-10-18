# Checkec C FreeRTOS Kernel

This repo contains the FreeRTOS kernel code that is converted to use Checked C. Checked C extends C with
checking to detect or prevent common programming errors such as out-of-bounds memory accesses. You can read
more about it [here](https://github.com/secure-sw-dev/checkedc-llvm-project/wiki).

The repo contains the original FreeRTOS kernel code without any modifications(available [here](./Fresh)), The output of [3C](https://machiry.github.io/files/3c.pdf)
when it was run on the kernel code (available [here](./3C_Output)) and the fully converted code (available [here](./Fixed)).

The `Fixed` repo also includes an example of working of Checked C. You can read more about it [here](./Fixed/Example/README.md).
