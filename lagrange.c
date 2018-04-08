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
lagrange_new(u8 coefficients[], u8 size)
{

    /* number of terms - 1 = degree */
    u8 degree = size - 1;

    /* create a new heap-allocated lagrange_t type */
    lagrange_t *lt = (lagrange_t*) malloc(sizeof(lagrange_t));

    /* error-checking: check if GALOIS_FLAG is set ensure coefficients and degree */
    #ifndef GALOIS_MODE

      /* check coefficients to be binary, since they must be within the field of Gf(2) */
      for ( u8 i = 0; i <= size; i++ ){
          if ( coefficients[i] != 0 || coefficients[i] != 1 )
            fprintf(stderr, "GALOIS_MODE: coefficients must be binary");
            exit(1);
      }

      /* check degree <= 7, since Gf(p^m) requires coefficients with degree <= m - 1 */
      if !( degree <= 7 ){
          fprintf(stderr, "GALOIS_MODE: degree specified %s must be less than 7.", degree);
          exit(1);
      }

    #endif

    /* set lagrange_t parameters */
    lt->coefficients = coefficients;
    lt->degree = degree;

    return lt;
}

lagrange_coordinate *
lagrange_create_point(u8 x, u8 y)
{

  /* create a new heap-allocated tuple-like lagrange_coordinate */
  lagrange_coordinate *lc = (lagrange_coordinate*) malloc(sizeof(lagrange_coordinate));

  /* no error-checking is necessary, as points are bound to be within unsigned 8-bit field */

  /* set lagrange_coordinate parameters */
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
