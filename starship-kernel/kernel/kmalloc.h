
#ifndef KMALLOC_H
#define KMALLOC_H

void *kmalloc(int length);
void kfree(void *ptr);

void kmalloc_init(char *start, int length);
void kmalloc_debug();
int kmalloc_test();

#endif
