#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t u8;

typedef struct {
    u8[] coefficients;
    u8[] xvalues;
    int degree;
} lagrange_t;


lagrange_t new_polynomial(u8[] coefficients, u8[] xvalues){
    // Create a new lagrange_t object, set the degree
    lagrange_t lt = (lagrange_t*) malloc(sizeof(lagrange_t);
    int degree = 0;

    // TODO: check size of each. xvalues must be greater than the degree by minimum of 1
    // TODO: figure out degree by number of coefficients
 
    lt->coefficients = coefficients;
    lt->xvalues = xvalues;
    lt->degree = degree;

    return lt;

}

int main(){

    lagrange_t poly = new_polynomial();

}
