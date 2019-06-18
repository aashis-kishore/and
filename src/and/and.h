#ifndef _AND_H
#define _AND_H

#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define AND_OK ((int8_t)0)
#define AND_NOK ((int8_t)-1)
#define AND_PNOK ((void*)0)
#define AND_ZERO ((size_t)0)

typedef enum {
    AND_FALSE = 0,
    AND_TRUE
} AND_BOOL;

#define and_getElement(data, type) *((type*)data)


#ifdef DEBUG
    #include <stdio.h>
    #include "viewmemutils"
    
    #define AND_PRINT(msg) printf("%s\n", msg);
    #define AND_PRINT_ERR(func_name, err_msg) printf("[ERROR] : [%s] => %s.\n", func_name, err_msg);
    #define AND_PRINT_WARN(func_name, warn_msg) printf("[WARNING] : [%s] => %s.\n", func_name, warn_msg);
#else
    #define AND_PRINT(msg)
    #define AND_PRINT_ERR(func_name, err_msg)
    #define AND_PRINT_WARN(func_name, warn_msg)
#endif
#endif