#include "lagrange.h"
#include "galois.h"


/* Create a new polynomial_t type

    i.e
        3x^3 + 4x^2 + 9x + 5

        u8 coefficients[4] = {3, 4, 9, 5};
*/
lagrange_t * 
new_polynomial(u8 coefficients[]){

    /* Create a new lagrange_t object, set the degree */
    lagrange_t *lt = (lagrange_t*) malloc(sizeof(lagrange_t));
    u8 degree = 0;

    /* The number of terms in a polynomial = degree + 1
          i.e degree of 3 = 4 terms
          x^3 + x^2 + x + k
    */
    degree = sizeof(coefficients) / sizeof(u8) + 1;

    lt->coefficients = coefficients;
    lt->degree = degree;

    return lt;
}
