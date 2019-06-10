#ifndef _PRNTMSGS_H
#define _PRNTMSGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

#ifdef DEBUG

    #define DTALGM_PRINT(msg) printf("%s\n", msg);
    #define DTALGM_PRINT_ERR(func_name, err_msg) printf("[ERROR] : [%s] => %s.\n", func_name, err_msg);
    #define DTALGM_PRINT_WARN(func_name, warn_msg) printf("[WARNING] : [%s] => %s.\n", func_name, warn_msg);

    void dtalgm_prnt_arr_as_byts(void*, size_t);
#else

    #define DTALGM_PRINT(msg)
    #define DTALGM_PRINT_ERR(func_name, err_msg)
    #define DTALGM_PRINT_WARN(func_name, warn_msg)
#endif
#endif