#include "sstack.h"


typedef struct sstack {
    void* buffer;
    size_t top;
    size_t num_elmnts;
    size_t elmnt_size;
    AND_BOOL empty;
} sstack_t;


sstackptr_t ss_create(size_t num_elmnts, size_t elmnt_size) {
    if (!elmnt_size) {
        AND_PRINT_ERR("ss_create", "Invalid element size")
        return AND_PNOK;
    }

    num_elmnts = num_elmnts ? num_elmnts : SS_DEFAULT_SIZE;

    sstackptr_t sstk = malloc(sizeof(sstack_t));

    if (!sstk) {
        AND_PRINT_ERR("ss_create", "Memory allocation for stack failed")
        return AND_PNOK;
    }

    sstk->buffer = malloc(num_elmnts*elmnt_size);

    if (!sstk->buffer) {
        AND_PRINT_ERR("ss_create", "Memory allocation for stack buffer failed")
        return AND_PNOK;
    }

    sstk->top = 0;
    sstk->num_elmnts = num_elmnts;
    sstk->elmnt_size = elmnt_size;
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

    return (sstk->top == sstk->num_elmnts-1) ? AND_TRUE : AND_FALSE;
}

int8_t ss_push(sstackptr_t sstk, void* elmnt, size_t elmnt_size) {
    if (!sstk || !elmnt) {
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
        

    if (elmnt_size) {
        void* elmnt_cpy = malloc(elmnt_size);

        if (!elmnt_cpy) {
            AND_PRINT_ERR("ss_push", "Memory allocation for element copy failed")
            return AND_NOK;
        }
        
        void* memcpy_stat = memcpy(elmnt_cpy, elmnt, elmnt_size);

        if (!memcpy_stat) {
            AND_PRINT_ERR("ss_push", "Copying of element to permanent location failed")
            return AND_NOK;
        }

        elmnt = &elmnt_cpy;
    }

    void* elmnt_insrt_addr = (int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size;

    void* memcpy_stat = memcpy(elmnt_insrt_addr, elmnt, sstk->elmnt_size);

    if (!memcpy_stat) {
        AND_PRINT_ERR("ss_push", "Unable to copy element to stack")
        return AND_NOK;
    }

    return AND_OK;
}

void* ss_pop(sstackptr_t sstk, AND_BOOL mem_allocd_elmnt) {
    if (!sstk) {
        AND_PRINT_ERR("ss_pop", "Invalid address as argument")
        return AND_PNOK;
    }

    if ((sstk->empty & AND_TRUE) == AND_TRUE) {
        AND_PRINT_ERR("ss_pop", "Unable to perform pop, stack is empty")
        return AND_PNOK;
    }

    void* elmnt = (int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size;

    if (sstk->top != 0)
        sstk->top--;
    else
        sstk->empty = AND_TRUE;

    return elmnt;
}

void* ss_peek(sstackptr_t sstk, size_t rev_index) {
    if (!sstk) {
        AND_PRINT_ERR("ss_peek", "Invalid address as argument")
        return AND_PNOK; 
    }

    if(sstk->empty) {
        AND_PRINT_ERR("ss_peek", "Unable to peek, stack is empty")
        return AND_PNOK;
    }

    rev_index = rev_index % (sstk->top + 1);
    void* elmnt_addr = (int8_t*)sstk->buffer + (sstk->top*sstk->elmnt_size - rev_index*sstk->elmnt_size);

    return elmnt_addr;
}

static inline void* _swap(sstackptr_t sstk) {
    void* tmp_elmnt_store = malloc(sstk->elmnt_size);

    if (!tmp_elmnt_store) {
        AND_PRINT_ERR("ss_swap", "Unable to allocate memory for temporary storage")
        return AND_PNOK;
    }

    void* top_addr = (int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size;
    void* prev_top_addr = (int8_t*)sstk->buffer + (sstk->top-1)*sstk->elmnt_size;

    void* tmp_memcpy_stat = memcpy(tmp_elmnt_store, top_addr, sstk->elmnt_size);

    if (!tmp_memcpy_stat) {
        AND_PRINT_ERR("ss_swap", "Unable to copy element to temporary location");
        return AND_PNOK;
    }

    void* top_memcpy_stat = memcpy(top_addr, prev_top_addr, sstk->elmnt_size);

    if (!top_memcpy_stat) {
        AND_PRINT_ERR("ss_swap", "Unable to copy element to top location");
        return AND_PNOK;
    }

    void* prev_top_memcpy_stat = memcpy(prev_top_addr, tmp_elmnt_store, sstk->elmnt_size);

    if (!prev_top_memcpy_stat) {
        AND_PRINT_ERR("ss_swap", "Unable to copy element to prev-top location");
        return AND_PNOK;
    }

    free(tmp_elmnt_store);

    return prev_top_addr;

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
        return ((int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size);
    }

    return _swap(sstk);
}

int8_t ss_destroy(sstackptr_t sstk, AND_BOOL mem_allocd_elmnt) {
    if (!sstk) {
        AND_PRINT_ERR("ss_destroy", "Invalid address as argument")
        return AND_NOK;
    }

    if ((mem_allocd_elmnt & AND_TRUE) == AND_TRUE) {
        for (size_t i=0; i <= sstk->top; i++) {
            void* currnt_elmnt = (void*)(*((uintptr_t*)sstk->buffer + i));
            free(currnt_elmnt);
        }
    }

    free(sstk->buffer);
    free(sstk);

    return AND_OK;
}