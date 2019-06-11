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

int8_t sstk_destroy(sstackptr_t sstk, SSTK_BOOL mem_allocd_elmnt) {
    if (!sstk) {
        DTALGM_PRINT_ERR("sstk_destroy", "Invalid address as argument")
        return SSTK_NOK;
    }

    if ((mem_allocd_elmnt & SSTK_TRUE) == SSTK_TRUE) {
        for (size_t i=0; i < sstk->num_elmnts; i++) {
            void* currnt_elmnt = (void*)(*((uintptr_t*)sstk->buffer + i));
            free(currnt_elmnt);
        }
    }

    free(sstk->buffer);
    free(sstk);

    return SSTK_OK;
}