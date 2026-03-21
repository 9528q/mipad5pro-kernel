# Makefile for hello_driver kernel module
# For ARM64 Android Kernel 4.19.x

MODULE_NAME := hello_driver
RESMAN_CORE_OBJS := main.o
RESMAN_GLUE_OBJS :=

ifneq ($(KERNELRELEASE),)
    $(MODULE_NAME)-objs := $(RESMAN_GLUE_OBJS) $(RESMAN_CORE_OBJS)
    obj-m := hello_driver.o
else
    # Kernel source directory
    KDIR := $(shell cd "$(dir $(lastword $(MAKEFILE_LIST))).." && pwd)
    # Current directory
    PWD := $(shell pwd)

export ARCH := arm64
export SUBARCH := arm64
export CROSS_COMPILE := aarch64-linux-gnu-
export CLANG_TRIPLE := aarch64-linux-gnu-
export CC := clang

all:
	@echo "========================================"
	@echo "Building hello_driver kernel module..."
	@echo "Kernel: $(KDIR)"
	@echo "ARCH: $(ARCH)"
	@echo "Cross Compiler: $(CROSS_COMPILE)"
	@echo "========================================"
	make -C $(KDIR) M=$(PWD) modules

clean:
	@echo "Cleaning build artifacts..."
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers *.order .*.cmd
	rm -rf .tmp_versions Module.symvers modules.order
	@echo "Clean complete."

.PHONY: all clean
endif
