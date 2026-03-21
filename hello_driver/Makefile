# Makefile for hello_driver kernel module
# For ARM64 Android Kernel 4.19.x

MODULE_NAME := hello_driver
RESMAN_CORE_OBJS := main.o
RESMAN_GLUE_OBJS :=

ifneq ($(KERNELRELEASE),)
    $(MODULE_NAME)-objs := $(RESMAN_GLUE_OBJS) $(RESMAN_CORE_OBJS)
    obj-m := hello_driver.o
else
    # Kernel source directory (always one level up from hello_driver/)
    KDIR := $(abspath ..)
    PWD := $(shell pwd)

export ARCH := arm64
export SUBARCH := arm64
export CROSS_COMPILE := aarch64-linux-gnu-
export CLANG_TRIPLE := aarch64-linux-gnu-
export CC := clang
export LLVM := 1
export LLVM_IAS := 1

all:
	@echo "========================================"
	@echo "Building hello_driver kernel module..."
	@echo "Kernel source: $(KDIR)"
	@echo "Module dir:    $(PWD)"
	@echo "ARCH:          $(ARCH)"
	@echo "Cross Compiler: $(CROSS_COMPILE)"
	@echo "========================================"
	make -C "$(KDIR)" M="$(PWD)" modules

clean:
	@echo "Cleaning build artifacts..."
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers *.order .*.cmd
	rm -rf .tmp_versions Module.symvers modules.order
	@echo "Clean complete."

.PHONY: all clean
endif
