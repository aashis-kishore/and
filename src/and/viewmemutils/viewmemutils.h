#ifndef _VIEWMEMUTILS_H
#define _VIEWMEMUTILS_H

#include <stdio.h>
#include <stdlib.h>


typedef enum {
    VMU_BYTE = 8,
    VMU_DBYTE = 16,
    VMU_RUNE = 32,
    VMU_DRUNE = 64
} VMU_WIDTH;


void vmu_printAsBinary(size_t, VMU_WIDTH);

#endif