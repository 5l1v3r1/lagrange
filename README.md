# lagrange

__lagrange__ is a library built for fast polynomial interpolation within a Galois-256 finite field.

## intro

__lagrange__ is an incredibly fast and lightweight library for polynomial interpolation within finite fields, specifically `Gf(256)`. 
This library is optimal for operations within cryptography, distributed computing or even just simple mathematical computation. 
It relies on no other dependencies outside the C Standard Library, and creates abstractions that empower the programmer 
to code without going back to scratch.

## build

__lagrange__ only utilize standard library functions, so you can
compile it with the header and `.c` files in your project.

To test the example `test-lagrange.c`, compile as so:

```
$ gcc test-lagrange.c lagrange.c galois.c -o lagrange
```

## license

[mit](https://codemuch.tech/license.txt)
