TOOL=arm-linux-gnueabihf-
KERNEL_DIR = ../kernel

all:
	ARCH=arm CROSS_COMPILE=${TOOL} make -C $(KERNEL_DIR) M=`pwd` modules
clean:
	ARCH=arm CROSS_COMPILE=${TOOL} make -C $(KERNEL_DIR) M=`pwd` clean
	rm -rf *~

obj-m   += battery_irq.o gpio.o  mcspi1.o  pwm.o  usbfx2.o btn.o gpio_flash.o
