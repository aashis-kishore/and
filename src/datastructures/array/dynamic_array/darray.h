#ifndef _DARRAY_H
#define _DARRAY_H

#include "and.h"
#include "bitvector.h"

typedef struct darray* darrayptr_t;

#define DA_DEFAULT_SIZE ((size_t)32)

#define DA_MIN_GROWTH_FACTOR ((uint8_t)125)
#define DA_MAX_GROWTH_FACTOR ((uint8_t)200)

#ifndef DA_DEFAULT_GROWTH_FACTOR
    #define DA_DEFAULT_GROWTH_FACTOR ((uint8_t)150)
#endif

#define DA_MIN_LOAD_FACTOR ((uint8_t)25)
#define DA_MAX_LOAD_FACTOR ((uint8_t)100)

#ifndef DA_DEFAULT_LOAD_FACTOR
    #define DA_DEFAULT_LOAD_FACTOR ((uint8_t)75)
#endif

darrayptr_t da_create(size_t, size_t, uint8_t, uint8_t);
size_t da_getNumElements(darrayptr_t, int8_t*);
size_t da_getMaxNumElements(darrayptr_t, int8_t*);
size_t da_getElementSize(darrayptr_t, int8_t*);
size_t da_getGrowthFactor(darrayptr_t, int8_t*);
size_t da_getLoadFactor(darrayptr_t, int8_t*);
int8_t da_insert(darrayptr_t, void*, size_t, size_t);
void* da_delete(darrayptr_t, size_t);
void* da_get(darrayptr_t, size_t);
void* da_swap(darrayptr_t, size_t, size_t);
int8_t da_destroy(darrayptr_t, AND_BOOL);

#endif