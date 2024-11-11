#!/bin/bash
set -e

BUILD_DIR="iso"

# Clean up previous build
rm -rf $BUILD_DIR
mkdir -p $BUILD_DIR/boot/grub

# Choose bootloader (grub/custom)
if [ "$1" == "grub" ]; then
    echo "Using GRUB as bootloader..."
    # Copy GRUB configuration
    cp grub/src/main/resources/grub.cfg $BUILD_DIR/boot/grub/
    # Copy kernel binary (ensure this exists after kernel build)
    cp kernel/src/kernel.bin $BUILD_DIR/boot/
    # Create ISO with GRUB
    grub-mkrescue -o StarshipOS.iso $BUILD_DIR
elif [ "$1" == "custom" ]; then
    echo "Using custom bootloader..."
    # Copy custom bootloader binary (ensure this exists after bootloader build)
    cp bootloader/target/bootloader.bin $BUILD_DIR/boot/
    # Copy kernel binary (ensure this exists after kernel build)
    cp kernel/src/kernel.bin $BUILD_DIR/boot/
    # Create a minimal bootable image with custom bootloader
    cat bootloader/target/bootloader.bin kernel/src/kernel.bin > StarshipOS.img
else
    echo "Usage: $0 {grub|custom}"
    exit 1
fi

# Cleanup
rm -rf $BUILD_DIR

echo "Build complete. Output: StarshipOS.iso or StarshipOS.img"
