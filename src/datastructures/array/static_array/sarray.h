#ifndef _SARRAY_H
#define _SARRAY_H

#include "and.h"
#include "bitvector.h"

typedef struct sarray* sarrayptr_t;

#ifndef SA_DEFAULT_SIZE
    #define SA_DEFAULT_SIZE ((size_t)32)
#endif

sarrayptr_t sa_create(size_t, size_t);
size_t sa_getNumElements(sarrayptr_t, int8_t*);
size_t sa_getMaxNumElements(sarrayptr_t, int8_t*);
size_t sa_getElementSize(sarrayptr_t, int8_t*);
int8_t sa_insert(sarrayptr_t, void*, size_t, size_t);
void* sa_delete(sarrayptr_t, size_t);
void* sa_get(sarrayptr_t, size_t);
void* sa_swap(sarrayptr_t, size_t, size_t);
int8_t sa_destroy(sarrayptr_t, AND_BOOL);

#endif