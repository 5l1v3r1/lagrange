#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define NUM_OF_TERMS 4

typedef uint8_t u8;

typedef struct {
    u8 coefficients[NUM_OF_TERMS];
    u8 degree;
} lagrange_t;

lagrange_t * 
new_polynomial(u8 coefficients[]); 

void
lagrange_free(lagrange_t * poly);

#endif
