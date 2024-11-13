include ../Makefile.config

KERNEL_SOURCES = kernelcore.c main.c console.c page.c keyboard.c mouse.c event_queue.c \
                 clock.c interrupt.c kmalloc.c pic.c ata.c cdromfs.c string.c bitmap.c \
                 graphics.c font.c syscall_handler.c process.c mutex.c list.c pagetable.c \
                 rtc.c kshell.c fs.c hash_set.c diskfs.c serial.c elf.c device.c kobject.c \
                 pipe.c bcache.c printf.c is_valid.c window.c

KERNEL_OBJECTS = $(KERNEL_SOURCES:.c=.o) kernel.o multiboot_header.o

# Build multiboot-compatible kernel
kernel.bin: $(KERNEL_OBJECTS)
	ld -m elf_x86_64 -T linker.ld -o kernel.elf $(KERNEL_OBJECTS)
	objcopy -O binary kernel.elf kernel.bin

# Assemble Multiboot header
multiboot_header.o: multiboot_header.asm
	nasm -f elf64 multiboot_header.asm -o multiboot_header.o

# Compile kernel sources in 64-bit mode
%.o: %.c
	gcc -m64 -ffreestanding -nostdlib -c $< -o $@

# Compile minimal kernel in 64-bit mode
kernel.o: kernel.c
	gcc -m64 -ffreestanding -nostdlib -c kernel.c -o kernel.o

clean:
	rm -rf *.bin *.o *.elf
