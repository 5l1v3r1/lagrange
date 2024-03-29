/*
 * test.c
 *
 *      Simple unit testing suite for polynomial interpolation
 */

#include "lagrange.h"

int main(){
    lagrange_coordinate one = lagrange_create_point(1, 4);
    lagrange_coordinate two = lagrange_create_point(2, 15);
    lagrange_coordinate three = lagrange_create_point(3, 40);
    lagrange_coordinate four = lagrange_create_point(4, 85);

    lagrange_coordinate test_set[4] = { one, two, three, four }; // three coordinate points
    u8 test_coefficients[4] = { 1, 1, 1, 1 };             // degree of 3

    lagrange_t testpoly = lagrange_new(test_coefficients, SIZEOF(test_coefficients));
    lagrange_test(testpoly, test_set, SIZEOF(test_set));
}
