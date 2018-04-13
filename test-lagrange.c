#include "lagrange.h"

#define GALOIS_MODE 0

int main(){

    u8 coefficients[4] = { 0, 1, 0, 0 }; // represents decimal 5.

    lagrange_t * test_poly = lagrange_new(coefficients, SIZEOF(coefficients));

}
