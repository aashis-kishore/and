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