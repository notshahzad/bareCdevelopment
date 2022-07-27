ASM = i686-elf-as
GCC = i686-elf-gcc
KERNEL = shitOs
EMU = qemu-system-i386
build: boot.s kernel.c linker.ld
	$(ASM) boot.s -o boot.o
	$(GCC) -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	$(GCC) -T linker.ld -o myos.bin -ffreestanding -O2 -nostdlib boot.o kernel.o -lgcc
	mkdir -p myos/boot/grub
	cp ./grub.cfg -r myos/boot/grub/grub.cfg
	mv ./myos.bin ./myos/boot/myos.bin
	grub-mkrescue -o $(KERNEL).iso ./myos
	mv $(KERNEL).iso ../build

run:
	$(EMU) -cdrom ../build/$(KERNEL).iso
clean:
	rm -rf boot.o
	rm -rf kernel.o
	rm -rf myos.bin
	rm -rf myos
