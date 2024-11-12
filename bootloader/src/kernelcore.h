
#ifndef KERNELCORE_H
#define KERNELCORE_H

#include "kernel/types.h"

extern uint16_t video_xbytes;
extern uint16_t video_xres;
extern uint16_t video_yres;
extern uint8_t *video_buffer;

extern uint16_t total_memory;
extern uint32_t kernel_size;

extern void halt();
extern void reboot();

extern void intr_return();

extern void *interrupt_stack_pointer;

#endif
