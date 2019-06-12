#ifndef _SSTACK_H
#define _SSTACK_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "and.h"

typedef struct sstack* sstackptr_t;

#define SSTK_DEFAULT_SIZE ((size_t)32)

sstackptr_t sstk_create(size_t, size_t);
int8_t sstk_isEmpty(sstackptr_t);
int8_t sstk_isFull(sstackptr_t);
int8_t sstk_push(sstackptr_t, void*, size_t);
void* sstk_pop(sstackptr_t, SSTK_BOOL);
void* sstk_peek(sstackptr_t, size_t);
void* sstk_swap(sstackptr_t);
int8_t sstk_destroy(sstackptr_t, SSTK_BOOL);

#endif