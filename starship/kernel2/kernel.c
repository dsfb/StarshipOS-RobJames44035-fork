void kmain(void) {
    const char *str = "Kernel has started...\n";
    char *vidptr = (char*)0xb8000;  // Video memory

    for (int i = 0; str[i] != '\0'; ++i) {
        vidptr[i * 2] = str[i];
        vidptr[i * 2 + 1] = 0x07;  // Light grey on black text
    }

    // Infinite loop to halt the kernel
    while (1) { }
}
