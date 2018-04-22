#ifndef __LAGRANGE_H__
#define __LAGRANGE_H__

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "galois.h"

#define SIZEOF(coefficients) sizeof(coefficients) / sizeof(coefficients[0])

/*
Galois Mode - included to check if polynomial coefficients are in binary
  representation, which is necessary for interpolation in Gf(256)

#define GALOIS_MODE 0

*/

/* Represents the core lagrange_t type, which will be used to reconstruct a polynomial
 * based on its coefficients and its computed degree
*/
typedef struct {
    u8 * coefficients;
    u8 degree;
} lagrange_t;


/* Represents a tuple-like Cartesian x-y coordinate, which can be used to create
 * points for polynomial reconstruction through interpolation
*/
typedef struct {
    u8 x;
    u8 y;
} lagrange_coordinate;


lagrange_t *
lagrange_new(u8 coefficients[], u8 size);

lagrange_coordinate *
lagrange_create_point(u8 x, u8 y);

void
lagrange_reconstruct(lagrange_t * polynomial, lagrange_coordinate * coordinates[], u8 size);

void
lagrange_test(lagrange_t * polynomial, lagrange_coordinate * coordinates[], u8 size);

#endif
