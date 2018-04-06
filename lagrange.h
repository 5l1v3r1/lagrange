#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "galois.h"

#define SIZEOF(coefficients) sizeof(coefficients) / sizeof(coefficients[0])

typedef struct {
    u8 * coefficients;
    u8 degree;
} lagrange_t;

typedef struct {
    u8 x;
    u8 y;
} lagrange_coordinate;

lagrange_t *
new_polynomial(u8 coefficients[]);

void
lagrange_free(lagrange_t * poly);

#endif
