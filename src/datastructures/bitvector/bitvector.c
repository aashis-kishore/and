#include "bitvector.h"


typedef struct bitvector {
    uint32_t* buffer;
    size_t vector_size;
    uint8_t growth_factor;
    uint8_t load_factor;
    AND_BOOL is_dynamic;
    size_t num_bits_set;
} bitvector_t;


bitvectorptr_t bv_create(size_t vector_size, uint8_t growth_factor, uint8_t load_factor, AND_BOOL is_dynamic) {
    vector_size = (vector_size == 0) ? BV_DEFAULT_VECTOR_SIZE : vector_size;
    growth_factor = (growth_factor == 0) ? BV_DEFAULT_GROWTH_FACTOR : growth_factor;
    load_factor = (load_factor == 0) ? BV_DEFAULT_LOAD_FACTOR : load_factor;

    if (growth_factor < 125 || growth_factor > 200) {
        AND_PRINT_ERR("bv_create", "Growth factor is not within allowed limits")
        return AND_PNOK;
    }

    if (load_factor < 25 || load_factor > 100) {
        AND_PRINT_ERR("bv_create", "Load factor is not within allowed limits")
        return AND_PNOK;
    }

    bitvectorptr_t bv = malloc(sizeof(bitvector_t));

    if (!bv) {
        AND_PRINT_ERR("bv_create", "Failed to allocate memory for bitvector")
        return AND_PNOK;
    }

    bv->vector_size = ceil(vector_size/sizeof(uint32_t));
    bv->buffer = calloc(bv->vector_size, sizeof(uint32_t));

    if (!bv->buffer) {
        AND_PRINT_ERR("bv_create", "Failed to allocate memory for buffer")
        free(bv);
        return AND_PNOK;
    }

    bv->growth_factor = growth_factor;
    bv->load_factor = load_factor;
    bv->is_dynamic = is_dynamic;
    bv->num_bits_set = 0;

    return bv;
}

int8_t bv_destroy(bitvectorptr_t bv) {
    if (!bv) {
        AND_PRINT_ERR("bv_destroy", "Invalid address as argument")
        return AND_NOK;
    }

    free(bv->buffer);
    free(bv);

    return AND_OK;
}