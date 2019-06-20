#include "sstack.h"


typedef struct sstack {
    sarrayptr_t buffer;
    size_t top;
    size_t num_elements;
    size_t element_size;
    AND_BOOL empty;
} sstack_t;


sstackptr_t ss_create(size_t num_elements, size_t element_size) {
    if (!element_size) {
        AND_PRINT_ERR("ss_create", "Invalid element size")
        return AND_PNOK;
    }

    num_elements = num_elements ? num_elements : SS_DEFAULT_SIZE;

    sstackptr_t sstk = malloc(sizeof(sstack_t));

    if (!sstk) {
        AND_PRINT_ERR("ss_create", "Unable to allocate memory for 'stack'")
        return AND_PNOK;
    }

    sstk->buffer = sa_create(num_elements, element_size);

    if (!sstk->buffer) {
        AND_PRINT_ERR("ss_create", "Unable to allocate memory for 'stack-buffer'")
        free(sstk);
        return AND_PNOK;
    }

    sstk->top = 0;
    sstk->num_elements = num_elements;
    sstk->element_size = element_size;
    sstk->empty = AND_TRUE;

    return sstk;
}

int8_t ss_isEmpty(sstackptr_t sstk) {
    if (!sstk) {
        AND_PRINT_ERR("ss_isEmpty", "Invalid address as argument")
        return AND_NOK;
    }

    return sstk->empty;
}

int8_t ss_isFull(sstackptr_t sstk) {
    if (!sstk) {
        AND_PRINT_ERR("ss_isFull", "Invalid address as argument")
        return AND_NOK;
    }

    return (sstk->top == sstk->num_elements-1) ? AND_TRUE : AND_FALSE;
}

int8_t ss_push(sstackptr_t sstk, void* element, size_t element_size) {
    if (!sstk || !element) {
        AND_PRINT_ERR("ss_push", "Invalid address as argument")
        return AND_NOK;
    }

    if (ss_isFull(sstk)) {
        AND_PRINT_ERR("ss_push", "Unable to perform push, stack is full.")
        return AND_NOK;
    }

    if (!(sstk->empty == AND_TRUE))
        sstk->top++;
    else
        sstk->empty = AND_FALSE;
        
    int8_t insert_stat = sa_insert(sstk->buffer, element, sstk->top, element_size);

    if (insert_stat == AND_NOK) {
        AND_PRINT_ERR("ss_push", "Unable to perform push")
        return AND_NOK;
    }

    return AND_OK;
}

void* ss_pop(sstackptr_t sstk) {
    if (!sstk) {
        AND_PRINT_ERR("ss_pop", "Invalid address as argument")
        return AND_PNOK;
    }

    if ((sstk->empty & AND_TRUE) == AND_TRUE) {
        AND_PRINT_ERR("ss_pop", "Unable to perform pop, stack is empty")
        return AND_PNOK;
    }

    void* element_addr = sa_delete(sstk->buffer, sstk->top);

    if (sstk->top != 0)
        sstk->top--;
    else
        sstk->empty = AND_TRUE;

    return element_addr;
}

void* ss_peek(sstackptr_t sstk, size_t index) {
    if (!sstk) {
        AND_PRINT_ERR("ss_peek", "Invalid address as argument")
        return AND_PNOK; 
    }

    if(sstk->empty) {
        AND_PRINT_ERR("ss_peek", "Unable to peek, stack is empty")
        return AND_PNOK;
    }

    index = index % (sstk->top + 1);
    void* element_addr = sa_get(sstk->buffer, sstk->top-index);

    return element_addr;
}

void* ss_swap(sstackptr_t sstk) {
    if (!sstk) {
        AND_PRINT_ERR("ss_swap", "Invalid address as argument")
        return AND_PNOK;
    }

    if (sstk->empty) {
        AND_PRINT_ERR("ss_swap", "Unable to perform swap, stack is empty")
        return AND_PNOK;
    }

    if (sstk->top == 0) {
        AND_PRINT_WARN("ss_swap", "Unable to perform swap, stack contains just one element")
        return sa_get(sstk->buffer, sstk->top);
    }

    void* prev_top_addr = sa_swap(sstk->buffer, sstk->top, sstk->top-1);

    if (!prev_top_addr) {
        AND_PRINT_ERR("ss_swap", "Unable to swap elements")
        return AND_PNOK;
    }

    return prev_top_addr;
}

int8_t ss_destroy(sstackptr_t sstk, AND_BOOL has_mem_allocd_elmnt) {
    if (!sstk) {
        AND_PRINT_ERR("ss_destroy", "Invalid address as argument")
        return AND_NOK;
    }

    sa_destroy(sstk->buffer, has_mem_allocd_elmnt);

    free(sstk->buffer);
    free(sstk);

    return AND_OK;
}