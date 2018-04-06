#include "lagrange.h"
#include "galois.h"

/* lagrange_new()
 *
 * Create a new polynomial_t type.
 *
 * We can use this polynomial_t type in order to
 *  1. Test against (x,y) points (hence, providing a preset number of coefficients)
 *  2. Reconstruct coefficients (hence, initializing the structure with NULLs)
 *
 *
 * Since arrays passed to functions automatically defer to pointers, we can
 * obtain the degree within the function parameter by calling the SIZEOF(..)
 * helper macro.
 *
 *  i.e
 *      // 3x^3 + 4x^2 + 9x + 5
 *      u8 coefficients[4] = {3, 4, 9, 5};
 *      lagrange_t * poly1 = lagrange_new(coefficients, SIZEOF(coefficients));
 *
*/

lagrange_t *
lagrange_new(u8 coefficients[], u8 degree){
    lagrange_t *lt = (lagrange_t*) malloc(sizeof(lagrange_t));

    lt->coefficients = coefficients;
    lt->degree = degree;

    return lt;
}

lagrange_coordinate *
lagrange_create_point(u8 x, u8 y)
{
  lagrange_coordinate *lc = (lagrange_coordinate*) malloc(sizeof(lagrange_coordinate));

  lc->x = x;
  lc->y = y;

  return lc;

}

/* lagrange_reconstruct()
 *
 * Using a NULLed lagrange_t and a set of coordinates, reconstruct coefficients
 *
 * Once the user creates a lagrange_t polynomial with no coefficients and no degree,
 * he/she can then reconstruct the coefficients using a set of coordinate points.
 *
 *  i.e
 *      lagrange_coordinate one = (lagrange_coordinate) lagrange_create_point(0, 3);
 *
 *      lagrange_coordinate set[1] = {one};
 *
 *      lagrange_t * poly1 = lagrange_new(NULL, NULL);
 *      lagrange_reconstruct(poly1, set, SIZEOF(set));
 *
*/

void
lagrange_reconstruct(lagrange_t * polynomial, lagrange_coordinate coordinates[], u8 size)
{


}

/* lagrange_test()
 *
 * Using a preset of coordinates and a preset lagrange_t polynomial, test to
 * see if the coordinates correspond with points plotted on a polynomial
 *
*/

void
lagrange_test(lagrange_t * polynomial, lagrange_coordinate coordinates[], u8 size)
{

}
