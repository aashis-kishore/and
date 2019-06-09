#include <stdio.h>
#include "check.h"
#include "prntmsgs.h"


int main(void) {
    DTALGM_PRINT("Test of 'DTALGM_PRINT' works")
    DTALGM_PRINT_WARN("pseudo_func_name", "Test of 'DTALGM_PRINT_WARN' works")
    DTALGM_PRINT_ERR("pseudo_func_name", "Test of 'DTALGM_PRINT_ERR' works")

    int arr[2] = {12, 24};

    DTALGM_PRINT("Testing 'dtalgm_prnt_arr_as_byts(void*, size_t)'")
    dtalgm_prnt_arr_as_byts(arr, 8);
    DTALGM_PRINT("Test of 'dtalgm_prnt_arr_as_byts' works")

    return 0;
}