#include "lagrange.h"
#include "galois.h"

static void
die(int code, char * msg)
{
    fprintf(code, "Program exited with status %d. Reason:  %s\n",
            code, msg);
    exit(code);
}


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
 * NOTE: Since arrays passed to functions automatically defer to pointers, we can
 * obtain the degree within the function parameter by calling the SIZEOF(..)
 * helper macro.
 *
 *
*/
lagrange_t
lagrange_new(u8 * coefficients, u8 size)
{
    lagrange_t lt;
    lt.coefficients = coefficients;
    lt.degree = size - 1;
    return lt;
}



lagrange_coordinate
lagrange_create_point(u8 x, u8 y)
{
    lagrange_coordinate lc;
    lc.x = x;
    lc.y = y;
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
 *      // .. etc. etc.
 *      lagrange_coordinate set[4] = { one, two, three, four, five };
 *
 *      lagrange_t poly1 = lagrange_new(NULL, NULL);
 *      lagrange_reconstruct(poly1, set, SIZEOF(set));
 *
 * TODO: make constant time implementation
*/
void
lagrange_reconstruct(lagrange_t polynomial, lagrange_coordinate coordinates[], u8 size)
{
    /* resultant coefficients */
    u8 coefficients[size];

    /* error-check: check for repeating x terms */
    for (u8 i = 0; i < size - 1; i++) {
        for (u8 j = i + 1; j < size; j++) {
            if (coordinates[i].x == coordinates[j].x)
                die(1, "repeating x coordinates");
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
 *      lagrange_coordinate test_set[5] = { one, two, three, four, five };
 *      u8 test_coefficients[5] = { 1, 2, 3, 4, 5 };
 *
 *      lagrange_t testpoly = lagrange_new(test_coefficients, SIZEOF(test_coefficients));
 *      lagrange_test(testpoly, test_set, SIZEOF(test_set));
*/
void
lagrange_test(lagrange_t polynomial, lagrange_coordinate coordinates[], u8 size)
{
    if (polynomial.degree != size - 1)
        die(1, "degree of polynomial must be equal to number of points - 1");

    for (u8 i = 0; i < size - 1; i++) {
        for (u8 j = i + 1; j < size; j++) {
            if (coordinates[i].x == coordinates[j].x)
                die(1, "repeating x coordinates");
        }
    }

    // Perform interpolation for test_poly
    // Perform interpolation for coordinate points
}
