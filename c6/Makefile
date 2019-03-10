MOD_NAME := c8
ifneq ($(KERNELRELEASE),)
	obj-m := $(MOD_NAME).o
	$(MOD_NAME)-objs := test.o test_list.o 
else
	KERNEL_DIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
	MOD_FOUND := $(shell lsmod | grep ^$(MOD_NAME) | cut -d' ' -f1 | head -1)
default:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) modules

install:

ifneq ($(MOD_FOUND),)
	@if [ $(MOD_FOUND) != '' ]; then \
		echo "hello" ;\
	fi
	sudo rmmod $(MOD_NAME)
endif
	sudo insmod $(MOD_NAME).ko

clean:
	$(RM)  -rf *.o *.ko *.mod.c  \.*.cmd .tmp_versions  modules.order Module.symvers

endif