#include "viewmemutils.h"


void vmu_printAsBinary(size_t decimal_num, VMU_WIDTH num_width) {
    for (size_t i=0; i<num_width; i++) {
        (decimal_num & 1) ? printf(VMU_GREEN" 1 "VMU_RESET) : printf(" 0 ");

        decimal_num >>= 1;
    }
    printf("\n");
}