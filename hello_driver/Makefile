# Makefile for hello_driver kernel module
# For ARM64 Android Kernel 4.19.x

ifneq ($(KERNELRELEASE),)
obj-m := hello_driver.o
hello_driver-objs := main.o
else
# Kernel source directory
KDIR := $(abspath ..)
PWD := $(shell pwd)

export ARCH := arm64
export SUBARCH := arm64
export CROSS_COMPILE := aarch64-linux-gnu-
export CC := clang
export LLVM := 1
export LLVM_IAS := 1

all modules:
	@echo "Building hello_driver kernel module..."
	make -C "$(KDIR)" M="$(PWD)" modules

clean:
	rm -f *.ko *.o *.mod.o *.mod.c *.symvers *.order .*.cmd
	rm -rf .tmp_versions Module.symvers modules.order

.PHONY: all modules clean
endif
