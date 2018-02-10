#include "galois.h"

static galois_t 
galois_add(galois_t a, galois_t b) {
	return a^b;
}

static galois_t 
galois_subtract(galois_t a, galois_t b) {
    return a^b;
}

static galois_t 
galois_multiply(galois_t a, galois_t b) {
   // TODO
}

static galois_t
galois_divide(galois_t a, galois_t b){
    
    /* where numerator is 0, returning 0 as quotient for any arithmetic */
    if ( a == 0 )
        return 0;

    /* where denominator is 0, resulting in division by zero */
    if ( b == 0 ){
        fprintf(stderr, "division by zero");
        exit(1);
    }
    
    // TODO

}
