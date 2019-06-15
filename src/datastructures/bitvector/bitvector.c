#include "bitvector.h"


typedef struct bitvector {
    uint32_t* buffer;
    size_t vector_size;
    uint8_t growth_factor;
    uint8_t load_factor;
    AND_BOOL is_dynamic;
    size_t num_bits_set;
    size_t max_size_before_resize;
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

    bv->vector_size = ceil(vector_size/BV_CHUNK_SIZE);
    bv->buffer = calloc(bv->vector_size, BV_CHUNK_SIZE);

    if (!bv->buffer) {
        AND_PRINT_ERR("bv_create", "Failed to allocate memory for buffer")
        free(bv);
        return AND_PNOK;
    }

    bv->growth_factor = growth_factor;
    bv->load_factor = load_factor;
    bv->is_dynamic = is_dynamic;
    bv->num_bits_set = 0;
    bv->max_size_before_resize = (bv->vector_size*BV_CHUNK_SIZE)*((float)bv->load_factor/100);

    return bv;
}

int8_t bv_isBitSet(bitvectorptr_t bv, size_t index) {
    if (!bv) {
        AND_PRINT_ERR("bv_isBitSet", "Invalid address as argument")
        return AND_NOK;
    }

    index = index % (bv->vector_size*BV_CHUNK_SIZE);
    uint32_t mask = 1<<((BV_CHUNK_SIZE-1) - index);
    return !!(bv->buffer[index/BV_CHUNK_SIZE] & mask);
}

int8_t bv_isBitClear(bitvectorptr_t bv, size_t index) {
    if (!bv) {
        AND_PRINT_ERR("bv_isBitClear", "Invalid address as argument")
        return AND_NOK;
    }

    index = index % (bv->vector_size*BV_CHUNK_SIZE);
    uint32_t mask = 1<<((BV_CHUNK_SIZE-1) - index);
    return !(bv->buffer[index/BV_CHUNK_SIZE] & mask);
}

size_t bv_numBitSetInRange(bitvectorptr_t bv, size_t lindex, size_t uindex, int8_t* status) {
    // TODO

    return AND_NOK;
}

static bitvectorptr_t _resize(bitvectorptr_t bv, size_t new_vector_size) {
    void* new_buffer = realloc(bv->buffer, new_vector_size*sizeof(uint32_t));

    if (!new_buffer) {
        AND_PRINT_ERR("_resize", "Unable to resize vector")
        return AND_PNOK;
    }

    size_t old_vector_size = bv->vector_size;

    bv->buffer = new_buffer;
    bv->vector_size = new_vector_size;
    bv->max_size_before_resize = (bv->vector_size*BV_CHUNK_SIZE)*((float)bv->load_factor/100);

    int8_t clear_bit_range_stat = bv_clearBitRange(bv, old_vector_size*BV_CHUNK_SIZE, bv->vector_size-1*BV_CHUNK_SIZE-1);

    if (clear_bit_range_stat == AND_NOK) {
        AND_PRINT_ERR("bv_setBit", "Unable to clear bit range")
        return AND_PNOK;
    }

    return bv;
}

int8_t bv_setBit(bitvectorptr_t bv, size_t index) {
    if (!bv) {
        AND_PRINT_ERR("bv_setBit", "Invalid address as argument")
        return AND_NOK;
    }

    if (!bv->is_dynamic) {
        size_t max_index = bv->vector_size*BV_CHUNK_SIZE - 1;

        if (index > max_index) {
            AND_PRINT_ERR("bv_setBit", "Index out of bounds")
            return AND_NOK;
        }
    }

    if (bv->is_dynamic) {
        if (bv->num_bits_set > bv->max_size_before_resize) {
            size_t new_vector_size = ceil(((bv->vector_size*BV_CHUNK_SIZE)*((float)bv->growth_factor/100))/BV_CHUNK_SIZE);
            bitvectorptr_t new_bv = _resize(bv, new_vector_size);
            
            if (!new_bv) {
                AND_PRINT_ERR("bv_setBit", "Vector resizing failed")
                return AND_NOK;
            }
        }
    }

    index = index % (bv->vector_size*BV_CHUNK_SIZE);

    uint32_t mask = 1<<((BV_CHUNK_SIZE-1) - index);

    uint32_t is_bit_set = !!(bv->buffer[index/BV_CHUNK_SIZE] & mask);
    if (!is_bit_set)
        bv->num_bits_set++;

    bv->buffer[index/BV_CHUNK_SIZE] |= mask;

    return AND_OK;    
}

int8_t bv_clearBit(bitvectorptr_t bv, size_t index) {
    if (!bv) {
        AND_PRINT_ERR("bv_clearBit", "Invalid address as argument")
        return AND_NOK;
    }

    index = index % (bv->vector_size*BV_CHUNK_SIZE);

    uint32_t mask = 1<<((BV_CHUNK_SIZE-1) - index);

    uint32_t is_bit_clear = !(bv->buffer[index/BV_CHUNK_SIZE] & mask);
    if (!is_bit_clear)
        bv->num_bits_set--;

    bv->buffer[index/BV_CHUNK_SIZE] &= ~mask;

    return AND_OK;
}

int8_t bv_setBitRange(bitvectorptr_t bv, size_t lindex, size_t uindex) {
    // TODO

    return AND_NOK;
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