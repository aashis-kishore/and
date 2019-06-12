#ifndef _AND_H
#define _AND_H

#define AND_OK ((int8_t)0)
#define AND_NOK ((int8_t)-1)
#define AND_PNOK ((void*)0)

typedef enum {
    AND_FALSE = 0,
    AND_TRUE
} AND_BOOL;

#define and_getElement(data, type) *((type*)data)

#endif