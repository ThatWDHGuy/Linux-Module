main_mod_name = test_module
obj-m := $(main_mod_name).o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

insert:
	sudo insmod $(main_mod_name).ko

remove:
	sudo rmmod $(main_mod_name)
