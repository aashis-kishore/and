#ifndef _SARRAY_H
#define _SARRAY_H

#include "and.h"

typedef struct sarray* sarrayptr_t;

#define SA_DEFAULT_SIZE ((size_t)32)

sarrayptr_t sa_create(size_t, size_t);
int8_t sa_insert(sarrayptr_t, void*, size_t, size_t);
void* sa_get(sarrayptr_t, size_t);
int8_t sa_destroy(sarrayptr_t, AND_BOOL);

#endif