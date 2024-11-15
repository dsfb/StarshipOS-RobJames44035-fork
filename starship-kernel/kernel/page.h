
#ifndef PAGE_H
#define PAGE_H

#include "kernel/types.h"

void  page_init();
void *page_alloc(bool zeroit);
void  page_free(void *addr);
void  page_stats( uint32_t *nfree, uint32_t *ntotal );

#endif
