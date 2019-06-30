#ifndef _SLLIST_H
#define _SLLIST_H

#include "and.h"

typedef struct sllist* sllistptr_t;

typedef enum {
    SLL_FIXED_START,
    SLL_FIXED_END,
} SLL_LIST_MODE;

sllistptr_t sll_create(size_t, SLL_LIST_MODE);
size_t sll_getNumElements(sllistptr_t, int8_t*);
size_t sll_getElementSize(sllistptr_t, int8_t*);
int8_t sll_insert(sllistptr_t, void*, size_t);
void* sll_delete(sllistptr_t, size_t);
void* sll_get(sllistptr_t, size_t);
void* sll_swap(sllistptr_t, size_t, size_t);
int8_t sll_destroy(sllistptr_t, AND_BOOL);

#endif