#ifndef STRING_H
#define STRING_H

#include "kernel/types.h"

void strcpy(char *d, const char *s);
void strncpy(char *d, const char *s, unsigned length);
char * strdup(const char *s);
int strcmp(const char *a, const char *b);
int strncmp(const char *a, const char *b, unsigned length);
char *strdup(const char *s);
unsigned strlen(const char *s);
char *strcat(char *d, const char *s);
char *uint_to_string(uint32_t u, char *str);
char *strrev(char *s);

char *strtok(char *s, const char *delim);

int str2int(const char *s, int *d);

const char *strchr(const char *s, char ch);

void memset(void *d, char value, unsigned length);
void memcpy(void *d, const void *s, unsigned length);

void printf(const char *s, ...);

#endif
