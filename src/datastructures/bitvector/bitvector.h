#ifndef _BITVECTOR_H
#define _BITVECTOR_H

#include <math.h>
#include "and.h"

typedef struct bitvector* bitvectorptr_t;

#define BV_DEFAULT_VECTOR_SIZE ((size_t)256)
#define BV_DEFAULT_GROWTH_FACTOR ((uint8_t)150)
#define BV_DEFAULT_LOAD_FACTOR ((uint8_t)75)
#define BV_CHUNK_SIZE ((size_t)32)


bitvectorptr_t bv_create(size_t, uint8_t, uint8_t, AND_BOOL);
size_t bv_getVectorSize(bitvectorptr_t, int8_t*);
size_t bv_getNumBitsSet(bitvectorptr_t, int8_t*);
uint32_t* bv_getBuffer(bitvectorptr_t);
int8_t bv_isBitSet(bitvectorptr_t, size_t);
int8_t bv_isBitClear(bitvectorptr_t, size_t);
size_t bv_numBitsSetInRange(bitvectorptr_t, size_t, size_t, int8_t*);
size_t bv_numBitsClearInRange(bitvectorptr_t, size_t, size_t, int8_t*);
int8_t bv_setBit(bitvectorptr_t, size_t);
int8_t bv_clearBit(bitvectorptr_t, size_t);
int8_t bv_toggleBit(bitvectorptr_t, size_t);
int8_t bv_setBitRange(bitvectorptr_t, size_t, size_t);
int8_t bv_clearBitRange(bitvectorptr_t, size_t, size_t);
int8_t bv_toggleBitRange(bitvectorptr_t, size_t, size_t);
int8_t bv_destroy(bitvectorptr_t);

#endif