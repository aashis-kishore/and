#include "sarray.h"


typedef struct sarray {
    void* buffer;
    bitvectorptr_t bv;
    size_t max_num_elements;
    size_t element_size;
} sarray_t;


sarrayptr_t sa_create(size_t max_num_elements, size_t element_size) {
    if (!element_size) {
        AND_PRINT_ERR("sa_create", "Element size cannot be 0")
        return AND_PNOK;
    }
    
    max_num_elements =  (max_num_elements) ? max_num_elements : SA_DEFAULT_SIZE; 

    sarrayptr_t sarr = malloc(sizeof(sarray_t));

    if (!sarr) {
        AND_PRINT_ERR("sa_create", "Unable to allocate memory for static array")
        return AND_PNOK;
    }

    sarr->buffer = malloc(max_num_elements*element_size);

    if (!sarr->buffer) {
        AND_PRINT_ERR("sa_create", "Unable to allocate memory for array buffer")
        return AND_PNOK;
    }

    sarr->bv = bv_create(max_num_elements, BV_DEFAULT_GROWTH_FACTOR, BV_DEFAULT_LOAD_FACTOR, AND_FALSE);

    if (!sarr->bv) {
        AND_PRINT_ERR("sa_create", "Unable to create auxiliaries => (bitvector)")
        return AND_PNOK;
    }

    sarr->max_num_elements = max_num_elements;
    sarr->element_size = element_size;

    return sarr;
}

size_t sa_getMaxNumElements(sarrayptr_t sarr, int8_t* status) {
    if (!sarr) {
        AND_PRINT_ERR("sa_getMaxNumElements", "Invalid address as argument")

        if (status)
            *status = AND_NOK;

        return AND_ZERO;
    }

    if (status)
        *status = AND_OK;
    
    return sarr->max_num_elements;
}

size_t sa_getElementSize(sarrayptr_t sarr, int8_t* status) {
    if (!sarr) {
        AND_PRINT_ERR("sa_getElementSize", "Invalid address as argument")

        if (status)
            *status = AND_NOK;

        return AND_ZERO;
    }

    if (status)
        *status = AND_OK;
    
    return sarr->element_size;
}

int8_t sa_insert(sarrayptr_t sarr, void* element, size_t index, size_t element_size) {
    if (!sarr || !element) {
        AND_PRINT_ERR("sa_insert", "Invalid address(es) as argument")
        return AND_NOK;
    }

    if (index >= sarr->max_num_elements) {
        AND_PRINT_ERR("sa_insert", "Index out of bounds")
        return AND_NOK;
    }

    void* element_copy = NULL;
    if (element_size) {
        element_copy = malloc(element_size);

        if (!element_copy) {
            AND_PRINT_ERR("sa_insert", "Unable to allocate memory for element")
            return AND_NOK;
        }
        
        void* memcpy_stat = memcpy(element_copy, element, element_size);

        if (!memcpy_stat) {
            AND_PRINT_ERR("sa_insert", "Copying of element to persistent location failed")
            free(element_copy);
            return AND_NOK;
        }

        element = &element_copy;
    }

    void* element_insert_addr = (int8_t*)sarr->buffer + index*sarr->element_size;

    void* memcpy_stat = memcpy(element_insert_addr, element, sarr->element_size);

    if (!memcpy_stat) {
        AND_PRINT_ERR("sa_insert", "Unable to copy element to static array")
        free(element_copy);
        return AND_NOK;
    }

    if (bv_setBit(sarr->bv, index) == AND_NOK) {
        AND_PRINT_ERR("sa_insert", "Unable to copy element to static array")
        free(element_copy);
        return AND_NOK;
    }

    return AND_OK;
}

void* sa_delete(sarrayptr_t sarr, size_t index) {
    if (!sarr) {
        AND_PRINT_ERR("sa_delete", "Invalid address as argument")
        return AND_PNOK;
    }

    if (index >= sarr->max_num_elements) {
        AND_PRINT_ERR("sa_delete", "Index out of bounds")
        return AND_PNOK;
    }

    int8_t is_bit_clear_stat = bv_isBitClear(sarr->bv, index);

    if (bv_clearBit(sarr->bv, index) == AND_NOK) {
        AND_PRINT_ERR("sa_delete", "Unable to clear corresponding bit")
        return AND_PNOK;
    }

    void* element = (is_bit_clear_stat != AND_NOK && is_bit_clear_stat == AND_TRUE) ? AND_PNOK : (int8_t*)sarr->buffer + index*sarr->element_size;

    return element;
}

void* sa_get(sarrayptr_t sarr, size_t index) {
    if (!sarr) {
        AND_PRINT_ERR("sa_get", "Invalid address as argument")
        return AND_PNOK;
    }

    if (index >= sarr->max_num_elements) {
        AND_PRINT_ERR("sa_get", "Index out of bounds")
        return AND_PNOK;
    }

    int8_t is_bit_clear_stat = bv_isBitClear(sarr->bv, index);

    void* element = (is_bit_clear_stat != AND_NOK && is_bit_clear_stat == AND_TRUE) ? AND_PNOK : (int8_t*)sarr->buffer + index*sarr->element_size;

    return element;
}

void* sa_swap(sarrayptr_t sarr, size_t index_x, size_t index_y) {
    if (!sarr) {
        AND_PRINT_ERR("sa_swap", "Invalid address as argument")
        return AND_PNOK;
    }

    if (index_x == index_y) {
        return (int8_t*)sarr->buffer + index_x*sarr->element_size;
    }

    void* tmp_elmnt_store = malloc(sarr->element_size);

    if (!tmp_elmnt_store) {
        AND_PRINT_ERR("sa_swap", "Unable to allocate memory for temporary storage")
        return AND_PNOK;
    }

    void* index_x_addr = (int8_t*)sarr->buffer + index_x*sarr->element_size;
    void* index_y_addr = (int8_t*)sarr->buffer + index_y*sarr->element_size;

    void* tmp_memcpy_stat = memcpy(tmp_elmnt_store, index_x_addr, sarr->element_size);

    if (!tmp_memcpy_stat) {
        AND_PRINT_ERR("sa_swap", "Unable to copy element to temporary location");
        return AND_PNOK;
    }

    void* top_memcpy_stat = memcpy(index_x_addr, index_y_addr, sarr->element_size);

    if (!top_memcpy_stat) {
        AND_PRINT_ERR("sa_swap", "Unable to copy element to top location");
        return AND_PNOK;
    }

    void* index_y_memcpy_stat = memcpy(index_y_addr, tmp_elmnt_store, sarr->element_size);

    if (!index_y_memcpy_stat) {
        AND_PRINT_ERR("sa_swap", "Unable to copy element to prev-top location");
        return AND_PNOK;
    }

    free(tmp_elmnt_store);

    return index_y_addr;

}

int8_t sa_destroy(sarrayptr_t sarr, AND_BOOL has_mem_alloced_element) {
    if (!sarr) {
        AND_PRINT_ERR("sa_destroy", "Invalid array address")
        return AND_NOK;
    }

    if (has_mem_alloced_element) {
        uint32_t* buffer_clone = bv_getBuffer(sarr->bv);

        for (size_t i=0; i < sarr->max_num_elements; i++) {
            size_t index = i % (bv_getVectorSize(sarr->bv, NULL)*BV_CHUNK_SIZE);
            uint32_t mask = 1<<((BV_CHUNK_SIZE-1) - index);

            if (buffer_clone[index/BV_CHUNK_SIZE] & mask) {
                void* current_element = (void*)(*((uintptr_t*)sarr->buffer + i));
                free(current_element);
            }
        }

        free(buffer_clone);
    }

    if (bv_destroy(sarr->bv) == AND_NOK) {
        AND_PRINT_WARN("sa_destroy", "Unable to destroy auxiliary => (bitvector)")
    }

    free(sarr->buffer);
    free(sarr);

    return AND_OK;
}