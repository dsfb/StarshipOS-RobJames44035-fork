
#ifndef ELF_H
#define ELF_H

#include "kernel/types.h"
#include "process.h"
#include "fs.h"

/*
elf_load opens the given filename, and if it contains a valid
ELF executable, allocates space in the current process' pagetable,
loads the text, data, and bss into memory, and updates the
entry point value in the current process structure.
*/

int elf_load(struct process *p, struct fs_dirent *d, addr_t * entry);

#endif
