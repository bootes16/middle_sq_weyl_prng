Simple PRNG

Implements a simple psuedo random number generator. The PRNG is a single header file class
implementing a Middle Square with Weyl Sequence PRNG.

I wanted a PRNG with decent randomness, but not necessarily cryptographicly secure, in order
to generate randome streams of 7 and 8 bit character data. This Middle Square PRNG serves that
purpose. The class is templated and allows instantiation with the output type (char, unsigned char,
int, etc.) which will affect the psuedo-random bits returned.

Also the algorithm is simple and easily ported to other languages in order to have the same
psuedo-random data reproduceable under different environments.

There is an intentional special case which is for signed char data which will return 7-bits of value
as a char which also excludes zero as a value. The requirement was a usable, random, ascii data stream.

The PRNG isn't good much beyond that as wider data types don't return a very good range of
psuedo random values. That is they return values which are mostly quite close to their
maximum.

The algorithm was sourced from: https://en.wikipedia.org/wiki/Middle-square_method

This is my implementation of the above algorithm and I claim no copyright over this source code.

