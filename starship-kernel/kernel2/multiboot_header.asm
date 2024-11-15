section .multiboot_header
    align 4
    dd 0x1BADB002          ; Magic number
    dd 0x00                ; Flags
    dd -(0x1BADB002 + 0x00); Checksum

section .text
extern kmain

global _start
_start:
    ; Initialize stack pointer here if needed
    call kmain
    cli
    hlt
