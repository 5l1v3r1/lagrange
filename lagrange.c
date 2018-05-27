#include "lagrange.h"
#include "galois.h"

/* lagrange_new()
 *
 * Create a new polynomial_t type, in the standard form:
 *    x^a ± x^a-1 ± x^a-2 ± ... x^a-n
 * where a = degree of the polynomial
 *
 * We can use this polynomial_t type in order to
 *  1. Test against (x,y) points (hence, providing a preset number of coefficients)
 *  2. Reconstruct coefficients (hence, initializing the structure with NULLs)
 *
 *
 * NOTE: Since arrays passed to functions automatically defer to pointers, we can
 * obtain the degree within the function parameter by calling the SIZEOF(..)
 * helper macro.
 *
 * NOTE: when actually utilizing reduction mode, the coefficients array must be filled
 * with either 1s or 0s. Notice how that this will represent an actual decimal value.
 * For example, {0, 0, 1, 1} is a decimal 3.
 *
 *  i.e
 *      // Standard interpolation without finite fields
 *      // 3x^3 + 4x^2 + 9x + 5 in the field Q
 *      u8 coefficients[4] = {3, 4, 9, 5};
 *      lagrange_t * poly1 = lagrange_new(coefficients, SIZEOF(coefficients));
 *
*/
lagrange_t *
lagrange_new(u8 coefficients[], u8 size)
{
    /* number of terms - 1 = degree */
    u8 degree;
    degree = size - 1;

    /* create a new heap-allocated lagrange_t type */
    lagrange_t *lt = (lagrange_t*) malloc(sizeof(lagrange_t));

    /* error-checking: check if GALOIS_MODE is set ensure coefficients */
    #ifndef GALOIS_MODE
    // continues on with code execution
    #else

      /* check coefficients to be binary, since they must be within the field of Gf(2) */
      for ( u8 i = 0; i <= size; i++ ){
          if ( coefficients[i] != 0 && coefficients[i] != 1 ){
            fprintf(stderr, "GALOIS_MODE: coefficients must be binary 0 or 1\n");
            exit(1);
          }
      }

      // TODO: should you even check degree ??

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
 *      lagrange_coordinate * one = (lagrange_coordinate) lagrange_create_point(0, 3);
 *      // .. etc. etc.
 *      lagrange_coordinate * set[1] = { one, two, three, four, five };
 *
 *      lagrange_t * poly1 = lagrange_new(NULL, NULL);
 *      lagrange_reconstruct(poly1, set, SIZEOF(set));
 *
*/

void
lagrange_reconstruct(lagrange_t * polynomial, lagrange_coordinate * coordinates[], u8 size)
{
    /* error-check: check for repeating x terms */
    for ( u8 i = 0; i < size - 1; i++ ){
        for ( u8 j = i + 1; j < size; j++ ){
          if (coordinates[i]->x == coordinates[j]->x) {
            fprintf(stderr, "lagrange_reconstruct: x points repeat: (%zu, %zu) and (%zu, %zu)\n",
              coordinates[i]->x, coordinates[i]->y, coordinates[j]->x, coordinates[j]->y);
            exit(1);
          }
        }
    }

  // Perform interpolation for coordinate points
  // Fill up polynomial struct with result

}

/* lagrange_test()
 *
 * Using a preset of coordinates and a preset lagrange_t polynomial, test to
 * see if the coordinates correspond with points plotted on a polynomial
 *
 * The process for completing this operation is as follows:
 *  1. Create a new lagrange_t polynomial with coefficients and degree
 *  2. Create a set of coordinates for polynomial
 *  3. Reconstruct polynomial from coordinates, check against previous lagrange_t type.
 *
 * i.e
 *      // .. create points
 *      lagrange_coordinate * test_set[5] = { one, two, three, four, five };
 *      u8 test_coefficients[5] = { 1, 2, 3, 4, 5 };
 *
 *      lagrange_t * testpoly = lagrange_new(test_coefficients, SIZEOF(test_coefficients));
 *      lagrange_test(testpoly, test_set, SIZEOF(test_set));
*/

void
lagrange_test(lagrange_t * polynomial, lagrange_coordinate * coordinates[], u8 size)
{
   /* error-check: ensure polynomial coefficients match number of coordinates
    * where points + 1 = degree and points = number of terms (coefficients and constant)
    */
    if ( polynomial->degree != size - 1 ){
      fprintf(stderr, "lagrange_test: FAIL - degree of polynomial must be equal to number of points - 1\n");
      exit(1);
    }

    /* error-check: check for repeating x terms */
    for ( u8 i = 0; i < size - 1; i++ ){
      for ( u8 j = i + 1; j < size; j++ ){
        if (coordinates[i]->x == coordinates[j]->x) {
          fprintf(stderr, "lagrange_test: FAIL - x points repeat: (%zu, %zu) and (%zu, %zu)\n",
            coordinates[i]->x, coordinates[i]->y, coordinates[j]->x, coordinates[j]->y);
          exit(1);
        }
      }
    }

    // Perform interpolation for test_poly
    // Perform interpolation for coordinate points
}
