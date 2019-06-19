#include "sarray.h"


typedef struct sarray {
    void* buffer;
    bitvectorptr_t bv;
    size_t num_elements;
    size_t element_size;
} sarray_t;


sarrayptr_t sa_create(size_t num_elements, size_t element_size) {
    if (!element_size) {
        AND_PRINT_ERR("sa_create", "Element size cannot be 0")
        return AND_PNOK;
    }
    
    num_elements =  (num_elements) ? num_elements : SA_DEFAULT_SIZE; 

    sarrayptr_t sarr = malloc(sizeof(sarray_t));

    if (!sarr) {
        AND_PRINT_ERR("sa_create", "Unable to allocate memory for static array")
        return AND_PNOK;
    }

    sarr->buffer = malloc(num_elements*element_size);

    if (!sarr->buffer) {
        AND_PRINT_ERR("sa_create", "Unable to allocate memory for array buffer")
        return AND_PNOK;
    }

    sarr->bv = bv_create(num_elements, BV_DEFAULT_GROWTH_FACTOR, BV_DEFAULT_LOAD_FACTOR, AND_FALSE);

    if (!sarr->bv) {
        AND_PRINT_ERR("sa_create", "Unable to create auxiliaries => (bitvector)")
        return AND_PNOK;
    }

    sarr->num_elements = num_elements;
    sarr->element_size = element_size;

    return sarr;
}

int8_t sa_insert(sarrayptr_t sarr, void* element, size_t index, size_t element_size) {
    if (!sarr || !element) {
        AND_PRINT_ERR("sa_insert", "Invalid address(es) as argument")
        return AND_NOK;
    }

    if (index >= sarr->num_elements) {
        AND_PRINT_ERR("sa_insert", "Index out of bounds")
        return AND_NOK;
    }

    if (element_size) {
        void* element_copy = malloc(element_size);

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
        return AND_NOK;
    }

    if (bv_setBit(sarr->bv, index) == AND_NOK) {
        AND_PRINT_ERR("sa_insert", "Unable to copy element to static array")
        return AND_NOK;
    }

    return AND_OK;
}

int8_t sa_destroy(sarrayptr_t sarr, AND_BOOL has_mem_alloced_element) {
    if (!sarr) {
        AND_PRINT_ERR("sa_destroy", "Invalid array address")
        return AND_NOK;
    }

    if (has_mem_alloced_element) {
        for (size_t i=0; i < sarr->num_elements; i++) {
            int8_t status = bv_isBitSet(sarr->bv, i);
            if (status != AND_NOK && status == AND_TRUE) {
                void* currnt_elmnt = (void*)(*((uintptr_t*)sarr->buffer + i));
                free(currnt_elmnt);
            }
        }
    }

    if (bv_destroy(sarr->bv) == AND_NOK) {
        AND_PRINT_WARN("sa_destroy", "Unable to destroy auxiliary => (bitvector)")
    }

    free(sarr->buffer);
    free(sarr);

    return AND_OK;
}