ENTRY(_start)

SECTIONS
{
    . = 1M;

    .multiboot_header ALIGN(8) : {
        *(.multiboot_header)
    }

    .text ALIGN(8) : {
        *(.text)
    }

    .rodata ALIGN(8) : {
        *(.rodata)
    }

    .data ALIGN(8) : {
        *(.data)
    }

    .bss ALIGN(8) : {
        *(.bss)
        *(COMMON)
    }

    /DISCARD/ : { *(.eh_frame) }
}
