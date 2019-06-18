#ifndef _VIEWMEMUTILS_H
#define _VIEWMEMUTILS_H

#include <stdio.h>
#include <stdlib.h>

#define VMU_RESET "\e[0m"
#define VMU_RED "\e[1;91m"
#define VMU_GREEN "\e[1;32m"
#define VMU_YELLOW "\e[1;93m"
#define VMU_BLUE "\e[1;36m"
#define VMU_WHITE "\e[1;89m"
#define VMU_GREY "\e[1;90m"

typedef enum {
    VMU_BYTE = 8,
    VMU_DBYTE = 16,
    VMU_RUNE = 32,
    VMU_DRUNE = 64
} VMU_WIDTH;


void vmu_printAsBinary(size_t, VMU_WIDTH);

#endif