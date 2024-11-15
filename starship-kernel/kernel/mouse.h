
#ifndef MOUSE_H
#define MOUSE_H

#include "kernel/types.h"

struct mouse_state {
	uint8_t buttons;
	uint16_t x;
	uint16_t y;
};

void mouse_read( struct mouse_state *s );
void mouse_init();

#endif
