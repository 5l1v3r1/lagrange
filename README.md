# lagrange

__lagrange__ is a library built for fast polynomial interpolation within a Galois-256 finite field.

## Research

__lagrange__ is a research project built for [turingmachines](https://turingmachines.github.io). A research paper dedicated to understanding polynomial interpolation and how this library was implemented, you can find the paper [here on Academia](https://www.academia.edu/36564354/Lagrange_design_of_a_low-level_mathematical_library_for_polynomial_interpolation_over_Galois_finite_fields).

### Abtract

> Mathematical operations and algorithms have important for theﬁelds of computation and cryptography. The design and implementation of mathematical libraries in programming languages have become a topic of interest. More and more developers seek to write critical code without wasting time in using large libraries that have a need for auditing and review, or use pre-existing libraries that integrate unused features, presenting performance setbacks. This paper introduces an implementation of a library for one of these mathematical concepts, Lagrange polynomial interpolation, over Gf(256). We intro-duce the mathematical theory behind polynomial interpolation, anddeﬁne ﬁnite ﬁelds and their role in polynomial interpolation. Finally,we implement a mathematical library in the C programming language,deriving source code from previously designed cryptography libraries and discuss the performance and other improvements we can implement.

## Quick Introduction

__lagrange__ is an incredibly fast and lightweight library for polynomial interpolation within finite fields, specifically `Gf(256)`. This library is optimal for operations within cryptography, distributed computing or even just simple mathematical computation. It relies on no other dependencies outside the C Standard Library, and creates abstractions that empower the programmer to code without going back to scratch.

## Building & Installing

__lagrange__ only utilizes core `glibc` libraries and can be plugged into any project.

To test the example `test-lagrange.c`, compile as so:

```
gcc test-lagrange.c lagrange.c -o lagrange
```

Perfect and minimal!

## Example

```
#include "lagrange.h"

#define GALOIS_MODE 0

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
```
