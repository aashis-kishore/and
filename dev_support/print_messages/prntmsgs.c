#include "prntmsgs.h"

void dtalgm_prnt_arr_as_byts(void* arr, size_t num_byts) {
    if (!arr) {
        DTALGM_PRINT_ERR("dtalgm_prnt_arr_as_byts", "Invalid address in argument")
        return;
    }

    printf("\n========================= dtalgm_prnt_arr_as_byts ===============================\n");
    for (size_t i = 0; i < num_byts; i++) {
        uint8_t currnt_byt = *((uint8_t*)arr + i);
        printf("%" PRIu8 "\t", currnt_byt);
    }
    printf("\n=================================================================================\n");
}