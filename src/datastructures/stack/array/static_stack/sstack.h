#ifndef _SSTACK_H
#define _SSTACK_H

#include "and.h"

typedef struct sstack* sstackptr_t;

#define SS_DEFAULT_SIZE ((size_t)32)

sstackptr_t ss_create(size_t, size_t);
int8_t ss_isEmpty(sstackptr_t);
int8_t ss_isFull(sstackptr_t);
int8_t ss_push(sstackptr_t, void*, size_t);
void* ss_pop(sstackptr_t, AND_BOOL);
void* ss_peek(sstackptr_t, size_t);
void* ss_swap(sstackptr_t);
int8_t ss_destroy(sstackptr_t, AND_BOOL);

#endif