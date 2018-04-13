#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "galois.h"

#define SIZEOF(coefficients) sizeof(coefficients) / sizeof(coefficients[0])

/* Reference- Implements Galois Mode - can be included to complete operations with
Galois arithmetic operations
// #define GALOIS_MODE 0
*/

typedef struct {
    u8 * coefficients;
    u8 degree;
} lagrange_t;

typedef struct {
    u8 x;
    u8 y;
} lagrange_coordinate;

// TODO: functions

#endif
