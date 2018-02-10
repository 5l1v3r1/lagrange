#include "lagrange.h"
#include "galois.h"


/* new_polynomial()
 *
 * Create a new polynomial_t type.
 *
 * We can use this polynomial_t type in order to
 * either construct points, or to compare (assert) with the reconstruction
 * of the same polynomial with a set of points
 *
 *  i.e
 *      3x^3 + 4x^2 + 9x + 5
 *      u8 coefficients[4] = {3, 4, 9, 5};
 *      lagrange_t * poly1 = new_polynomial(coefficients);
 *      
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

/* Since each lagrange_t is heapsized, we must ensure that they disappear
 * after execution of necessary functions
*/

void lagrange_free(lagrange_t * poly){
    free(poly);
}

void create_points(lagrange_t poly); // return randomly generated points

void lagrange_reconstruct(lagrange_t poly, u8 xvalues[]); // reconstruct polynomial and compare with original poly type coefficients






