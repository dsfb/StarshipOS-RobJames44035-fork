#include ../Makefile.config

# Define cross compiler
KERNEL_CCFLAGS=-Wall -c -ffreestanding -fno-pie -g -std=gnu99
CC=/home/rajames/PROJECTS/StarshipOS/gcc_elf/build/bin/x86_64-elf-cpp
LD=/home/rajames/PROJECTS/StarshipOS/binutils/build/x86_64-elf/bin/ld -melf_i386
OBJCOPY=/home/rajames/PROJECTS/StarshipOS/binutils/build/x86_64-elf/bin/objcopy
#AR=ar

# Update compiler and linker to use cross-compiler
#CC = $(CROSS_COMPILE)gcc
#LD = $(CROSS_COMPILE)ld
#OBJCOPY = $(CROSS_COMPILE)objcopy
#NASM = nasm

KERNEL_SOURCES = kernelcore.c main.c console.c page.c keyboard.c mouse.c event_queue.c \
                 clock.c interrupt.c kmalloc.c pic.c ata.c cdromfs.c string.c bitmap.c \
                 graphics.c font.c syscall_handler.c process.c mutex.c list.c pagetable.c \
                 rtc.c kshell.c fs.c hash_set.c diskfs.c serial.c elf.c device.c kobject.c \
                 pipe.c bcache.c printf.c is_valid.c window.c

KERNEL_OBJECTS = $(KERNEL_SOURCES:.c=.o) kernel.o multiboot_header.o

# Build multiboot-compatible kernel
kernel.elf: $(KERNEL_OBJECTS)
	$(LD) -n -o kernel.elf -T linker.ld $(KERNEL_OBJECTS)

kernel.bin: kernel.elf
	$(OBJCOPY) -O binary kernel.elf kernel.bin

# Assemble Multiboot header
multiboot_header.o: multiboot_header.asm
	$(NASM) -f elf64 multiboot_header.asm -o multiboot_header.o

# Compile kernel sources in 64-bit mode
%.o: %.c
	$(CC) -m64 -ffreestanding -nostdlib $< -o $@

# Compile minimal kernel in 64-bit mode
kernel.o: kernel.c
	$(CC) -m64 -ffreestanding -nostdlib kernel.c -o kernel.o

clean:
	rm -rf *.bin *.o *.elf
