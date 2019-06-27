#include "darray.h"


typedef struct darray {
    void* buffer;
    bitvectorptr_t bv;
    size_t num_elements;
    size_t max_num_elements;
    size_t element_size;
    uint8_t growth_factor;
    uint8_t load_factor;
} darray_t;


darrayptr_t da_create(size_t max_num_elements, size_t element_size, uint8_t growth_factor, uint8_t load_factor) {
    if (!element_size) {
        AND_PRINT_ERR("da_create", "'element_size' cannot be zero")
        return AND_PNOK;
    }

    max_num_elements = (max_num_elements < DA_DEFAULT_SIZE) ? DA_DEFAULT_SIZE : max_num_elements;
    growth_factor = (growth_factor == 0) ? DA_DEFAULT_GROWTH_FACTOR : growth_factor;
    load_factor = (load_factor == 0) ? DA_DEFAULT_LOAD_FACTOR : load_factor;

    if (growth_factor < DA_MIN_GROWTH_FACTOR || growth_factor > DA_MAX_GROWTH_FACTOR) {
        AND_PRINT_ERR("da_create", "Growth factor is not within allowed limits")
        return AND_PNOK;
    }

    if (load_factor < DA_MIN_LOAD_FACTOR || load_factor > DA_MAX_LOAD_FACTOR) {
        AND_PRINT_ERR("da_create", "Load factor is not within allowed limits")
        return AND_PNOK;
    }

    darrayptr_t darr = malloc(sizeof(darray_t));

    if (!darr) {
        AND_PRINT_ERR("da_create", "Unable to allocate memory for dynamic array")
        return AND_PNOK;
    }

    darr->buffer = malloc(max_num_elements*element_size);

    if (!darr->buffer) {
        AND_PRINT_ERR("da_create", "Unable to allocate memory for array buffer")
        free(darr);
        return AND_PNOK;
    }

    darr->bv = bv_create(max_num_elements, growth_factor, load_factor, AND_TRUE);

    if (!darr->bv) {
        AND_PRINT_ERR("da_create", "Unable to create auxiliaries => (bitvector)")
        free(darr->buffer);
        free(darr);
        return AND_PNOK;
    }

    darr->max_num_elements = max_num_elements;
    darr->num_elements = 0;
    darr->element_size = element_size;
    darr->growth_factor = growth_factor;
    darr->load_factor = load_factor;

    return darr;
}

size_t da_getNumElements(darrayptr_t darr, int8_t* status) {
    if (!darr) {
        if (status)
            *status = AND_NOK;
        return AND_ZERO;
    }

    if (status)
        *status = AND_OK;
        
    return darr->num_elements;
}

size_t da_getMaxNumElements(darrayptr_t darr, int8_t* status) {
    // TODO
    return AND_ZERO;
}

size_t da_getElementSize(darrayptr_t darr, int8_t* status) {
    // TODO
    return AND_ZERO;
}

size_t da_getGrowthFactor(darrayptr_t darr, int8_t* status) {
    // TODO
    return AND_ZERO;
}

size_t da_getLoadFactor(darrayptr_t darr, int8_t* status) {
    // TODO
    return AND_ZERO;
}

int8_t da_insert(darrayptr_t darr, void* element, size_t index, size_t element_size) {
    // TODO
    return AND_NOK;
}

void* da_delete(darrayptr_t darr, size_t index) {
    // TODO
    return AND_PNOK;
}

void* da_get(darrayptr_t darr, size_t index) {
    // TODO
    return AND_PNOK;
}

void* da_swap(darrayptr_t darr, size_t index_x, size_t index_y) {
    // TODO
    return AND_PNOK;
}

int8_t da_destroy(darrayptr_t darr, AND_BOOL has_mem_alloced_element) {
    if (!darr) {
        AND_PRINT_ERR("da_destroy", "Invalid address as argument")
        return AND_NOK;
    }

    if (has_mem_alloced_element) {
        uint32_t* buffer_clone = bv_getBuffer(darr->bv);

        for (size_t i=0; i < darr->max_num_elements; i++) {
            size_t index = i % (bv_getVectorSize(darr->bv, NULL)*BV_CHUNK_SIZE);
            uint32_t mask = 1<<((BV_CHUNK_SIZE-1) - index);

            if (buffer_clone[index/BV_CHUNK_SIZE] & mask) {
                void* current_element = (void*)(*((uintptr_t*)darr->buffer + i));
                free(current_element);
            }
        }

        free(buffer_clone);
    }

    if (bv_destroy(darr->bv) == AND_NOK) {
        AND_PRINT_WARN("da_destroy", "Unable to destroy auxiliary => (bitvector)")
    }

    free(darr->buffer);
    free(darr);

    return AND_NOK;
}