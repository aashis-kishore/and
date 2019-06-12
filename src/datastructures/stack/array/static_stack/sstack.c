#include "sstack.h"
#include "prntmsgs.h"


typedef struct sstack {
    void* buffer;
    size_t top;
    size_t num_elmnts;
    size_t elmnt_size;
    SSTK_BOOL empty;
} sstack_t;


sstackptr_t sstk_create(size_t num_elmnts, size_t elmnt_size) {
    if (!elmnt_size) {
        DTALGM_PRINT_ERR("sstk_create", "Invalid element size")
        return SSTK_PNOK;
    }

    num_elmnts = num_elmnts ? num_elmnts : SSTK_DEFAULT_SIZE;

    sstackptr_t sstk = malloc(sizeof(sstack_t));

    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_create", "Memory allocation for stack failed")
        return SSTK_PNOK;
    }

    sstk->buffer = malloc(num_elmnts*elmnt_size);

    if (!sstk->buffer) {
        DTALGM_PRINT_ERR("sstk_create", "Memory allocation for stack buffer failed")
        return SSTK_PNOK;
    }

    sstk->top = 0;
    sstk->num_elmnts = num_elmnts;
    sstk->elmnt_size = elmnt_size;
    sstk->empty = SSTK_TRUE;

    return sstk;
}

int8_t sstk_isEmpty(sstackptr_t sstk) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_isEmpty", "Invalid address as argument")
        return SSTK_NOK;
    }

    return sstk->empty;
}

int8_t sstk_isFull(sstackptr_t sstk) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_isFull", "Invalid address as argument")
        return SSTK_NOK;
    }

    return (sstk->top == sstk->num_elmnts-1) ? SSTK_TRUE : SSTK_FALSE;
}

int8_t sstk_push(sstackptr_t sstk, void* elmnt, size_t elmnt_size) {
    if (!sstk || !elmnt) {
        DTALGM_PRINT_ERR("sstk_push", "Invalid address as argument")
        return SSTK_NOK;
    }

    if (sstk_isFull(sstk)) {
        DTALGM_PRINT_ERR("sstk_push", "Unable to perform push, stack is full.")
        return SSTK_NOK;
    }

    if (!(sstk->empty == SSTK_TRUE))
        sstk->top++;
    else
        sstk->empty = SSTK_FALSE;
        

    if (elmnt_size) {
        void* elmnt_cpy = malloc(elmnt_size);

        if (!elmnt_cpy) {
            DTALGM_PRINT_ERR("sstk_push", "Memory allocation for element copy failed")
            return SSTK_NOK;
        }
        
        void* memcpy_stat = memcpy(elmnt_cpy, elmnt, elmnt_size);

        if (!memcpy_stat) {
            DTALGM_PRINT_ERR("sstk_push", "Copying of element to permanent location failed")
            return SSTK_NOK;
        }

        elmnt = &elmnt_cpy;
    }

    void* elmnt_insrt_addr = (int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size;

    void* memcpy_stat = memcpy(elmnt_insrt_addr, elmnt, sstk->elmnt_size);

    if (!memcpy_stat) {
        DTALGM_PRINT_ERR("sstk_push", "Unable to copy element to stack")
        return SSTK_NOK;
    }

    return SSTK_OK;
}

void* sstk_pop(sstackptr_t sstk, SSTK_BOOL mem_allocd_elmnt) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_pop", "Invalid address as argument")
        return SSTK_PNOK;
    }

    if ((sstk->empty & SSTK_TRUE) == SSTK_TRUE) {
        DTALGM_PRINT_ERR("sstk_pop", "Unable to perform pop, stack is empty")
        return SSTK_PNOK;
    }

    void* elmnt = (int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size;

    if (sstk->top != 0)
        sstk->top--;
    else
        sstk->empty = SSTK_TRUE;

    return elmnt;
}

void* sstk_peek(sstackptr_t sstk, size_t rev_index) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_peek", "Invalid address as argument")
        return SSTK_PNOK; 
    }

    if(sstk->empty) {
        DTALGM_PRINT_ERR("sstk_peek", "Unable to peek, stack is empty")
        return SSTK_PNOK;
    }

    rev_index = rev_index % (sstk->top + 1);
    void* elmnt_addr = (int8_t*)sstk->buffer + (sstk->top*sstk->elmnt_size - rev_index*sstk->elmnt_size);

    return elmnt_addr;
}

static inline void* _swap(sstackptr_t sstk) {
    void* tmp_elmnt_store = malloc(sstk->elmnt_size);

    if (!tmp_elmnt_store) {
        DTALGM_PRINT_ERR("sstk_swap", "Unable to allocate memory for temporary storage")
        return SSTK_PNOK;
    }

    void* top_addr = (int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size;
    void* prev_top_addr = (int8_t*)sstk->buffer + (sstk->top-1)*sstk->elmnt_size;

    void* tmp_memcpy_stat = memcpy(tmp_elmnt_store, top_addr, sstk->elmnt_size);

    if (!tmp_memcpy_stat) {
        DTALGM_PRINT_ERR("sstk_swap", "Unable to copy element to temporary location");
        return SSTK_PNOK;
    }

    void* top_memcpy_stat = memcpy(top_addr, prev_top_addr, sstk->elmnt_size);

    if (!top_memcpy_stat) {
        DTALGM_PRINT_ERR("sstk_swap", "Unable to copy element to top location");
        return SSTK_PNOK;
    }

    void* prev_top_memcpy_stat = memcpy(prev_top_addr, tmp_elmnt_store, sstk->elmnt_size);

    if (!prev_top_memcpy_stat) {
        DTALGM_PRINT_ERR("sstk_swap", "Unable to copy element to prev-top location");
        return SSTK_PNOK;
    }

    free(tmp_elmnt_store);

    return prev_top_addr;

}

void* sstk_swap(sstackptr_t sstk) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_swap", "Invalid address as argument")
        return SSTK_PNOK;
    }

    if (sstk->empty) {
        DTALGM_PRINT_ERR("sstk_swap", "Unable to perform swap, stack is empty")
        return SSTK_PNOK;
    }

    if (sstk->top == 0) {
        DTALGM_PRINT_WARN("sstk_swap", "Unable to perform swap, stack contains just one element")
        return ((int8_t*)sstk->buffer + sstk->top*sstk->elmnt_size);
    }

    return _swap(sstk);
}

int8_t sstk_destroy(sstackptr_t sstk, SSTK_BOOL mem_allocd_elmnt) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_destroy", "Invalid address as argument")
        return SSTK_NOK;
    }

    if ((mem_allocd_elmnt & SSTK_TRUE) == SSTK_TRUE) {
        for (size_t i=0; i <= sstk->top; i++) {
            void* currnt_elmnt = (void*)(*((uintptr_t*)sstk->buffer + i));
            free(currnt_elmnt);
        }
    }

    free(sstk->buffer);
    free(sstk);

    return SSTK_OK;
}