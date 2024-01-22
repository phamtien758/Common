/*
 * File: type.h
 * Author: phamtien758
 * 
 */

#ifndef TYPE_H
#define TYPE_H

#include <stdint.h>

#define _R    volatile const
#define _W    volatile
#define _RW   volatile

#define ENABLE  1
#define DISABLE 0

#define TRUE    1
#define FALSE   0

typedef enum
{
    RET_NOT_OK = 0,
    RET_OK     = 1
}ReturnType; 

#endif /* TYPE_H */
