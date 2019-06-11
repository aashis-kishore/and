#ifndef _SSTACK_H
#define _SSTACK_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct sstack* sstackptr_t;

#define SSTK_DEFAULT_SIZE ((size_t)32)

#define SSTK_OK ((int8_t)0)
#define SSTK_NOK ((int8_t)-1)
#define SSTK_PNOK ((void*)0)

typedef enum {
    SSTK_FALSE = 0,
    SSTK_TRUE
} SSTK_BOOL;

#define sstk_getElement(data, type) *((type*)data)

sstackptr_t sstk_create(size_t, size_t);
int8_t sstk_isEmpty(sstackptr_t);
int8_t sstk_isFull(sstackptr_t);
int8_t sstk_push(sstackptr_t, void*, size_t);
void* sstk_pop(sstackptr_t, SSTK_BOOL);
int8_t sstk_destroy(sstackptr_t, SSTK_BOOL);

#endif