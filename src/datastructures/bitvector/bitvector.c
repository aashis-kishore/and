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
    bv->max_size_before_resize = (bv->vector_size*BV_CHUNK_SIZE)*((float)bv->load_factor/100);

    return bv;
}

size_t bv_getVectorSize(bitvectorptr_t bv, int8_t* status) {
    if (!bv) {
        AND_PRINT_ERR("bv_getVectorSize", "Invalid address as argument")
        if (status)
            *status = AND_NOK;
        return AND_OK;  // OK AND NOK => NOK
    }

    if (status)
        *status = AND_OK;

    return bv->vector_size;
}

size_t bv_getNumBitsSet(bitvectorptr_t bv, int8_t* status) {
    if (!bv) {
        AND_PRINT_ERR("bv_getNumBitsSet", "Invalid address as argument")
        if (status)
            *status = AND_NOK;
        return AND_OK;
    }

    if (status)
        *status = AND_OK;

    return bv->num_bits_set;
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

size_t bv_numBitsSetInRange(bitvectorptr_t bv, size_t lindex, size_t uindex, int8_t* status) {
    // TODO

    return AND_NOK;
}

size_t bv_numBitsClearInRange(bitvectorptr_t bv, size_t lindex, size_t uindex, int8_t* status) {
    if (status)
        *status = AND_NOK;

    if (!bv) {
        AND_PRINT_ERR("bv_numBitsClearRange", "Invalid address as argument")
        return AND_ZERO;
    }

    if (lindex >= uindex) {
        AND_PRINT_ERR("bv_numBitsClearRange", "Index values not allowed")
        return AND_ZERO;
    }

    if (uindex >= bv->vector_size*BV_CHUNK_SIZE) {
        AND_PRINT_ERR("bv_numBitsClearRange", "Index out of bounds")
        return AND_ZERO;
    }

    size_t chunk_lindex = lindex/BV_CHUNK_SIZE, chunk_uindex = uindex/BV_CHUNK_SIZE, num_bits_clear_in_range = 0;
    size_t shift_factor;
    uint32_t mask, remnant_bits;

    for (size_t index = chunk_lindex; index <= chunk_uindex; index++) {
        if (index == chunk_lindex && lindex != 0) {
            shift_factor = (index+1)*BV_CHUNK_SIZE - lindex;
            mask = (1<<shift_factor) - 1;
            remnant_bits = bv->buffer[index] & mask;
        } else if (index == chunk_uindex) {
            shift_factor = (index+1)*BV_CHUNK_SIZE - uindex;
            mask = (1<<shift_factor) - 1;
            remnant_bits = bv->buffer[index] & ~mask;
        } else {
            remnant_bits = bv->buffer[index] & ~0;
        }

        for (uint8_t i=0; i<BV_CHUNK_SIZE; i++) {
            if (!(remnant_bits&1))
                num_bits_clear_in_range++;
            remnant_bits >>= 1;
        }
    }

    num_bits_clear_in_range -= (lindex - chunk_lindex*BV_CHUNK_SIZE) + ((chunk_uindex+1)*BV_CHUNK_SIZE - uindex -1);

    if (status)
        *status = AND_OK;
    
    return num_bits_clear_in_range;
}

static bitvectorptr_t _resize(bitvectorptr_t bv, size_t new_vector_size) {
    void* new_buffer = calloc(new_vector_size, sizeof(uint32_t));

    if (!new_buffer) {
        AND_PRINT_ERR("_resize", "Unable to resize bitvector")
        return AND_PNOK;
    }

    void* memcpy_stat = memcpy(new_buffer, bv->buffer, bv->vector_size*sizeof(uint32_t));

    if (!memcpy_stat) {
        AND_PRINT_ERR("_resize", "Unable to copy contents of bitvector")
        return AND_PNOK;
    }
    
    free(bv->buffer);

    bv->buffer = new_buffer;
    bv->vector_size = new_vector_size;
    bv->max_size_before_resize = (bv->vector_size*BV_CHUNK_SIZE)*((float)bv->load_factor/100);

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
        size_t new_vector_size = bv->vector_size;

        if (index > bv->vector_size*BV_CHUNK_SIZE-1) {
            size_t prospective_last_index;

            do {
                prospective_last_index = new_vector_size*BV_CHUNK_SIZE*(float)bv->growth_factor/100-1;
                new_vector_size = ceil((new_vector_size*BV_CHUNK_SIZE*(float)bv->growth_factor/100)/BV_CHUNK_SIZE);
            } while(index > prospective_last_index);

        } else if (bv->num_bits_set > bv->max_size_before_resize)
            new_vector_size = ceil((bv->vector_size*BV_CHUNK_SIZE*(float)bv->growth_factor/100)/BV_CHUNK_SIZE);

        if (bv->vector_size < new_vector_size) {
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

    if (!bv->is_dynamic) {
        size_t max_index = bv->vector_size*BV_CHUNK_SIZE - 1;

        if (index > max_index) {
            AND_PRINT_ERR("bv_clearBit", "Index out of bounds")
            return AND_NOK;
        }
    }

    if (bv->is_dynamic) {
        if (index > bv->vector_size*BV_CHUNK_SIZE-1) {
            size_t new_vector_size = bv->vector_size, prospective_last_index;

            do {
                prospective_last_index = new_vector_size*BV_CHUNK_SIZE*(float)bv->growth_factor/100-1;
                new_vector_size = ceil((new_vector_size*BV_CHUNK_SIZE*(float)bv->growth_factor/100)/BV_CHUNK_SIZE);
            } while(index > prospective_last_index);

            bitvectorptr_t new_bv = _resize(bv, new_vector_size);
            
            if (!new_bv) {
                AND_PRINT_ERR("bv_clearBit", "Vector resizing failed")
                return AND_NOK;
            }
        }
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

int8_t bv_clearBitRange(bitvectorptr_t bv, size_t lindex, size_t uindex) {
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