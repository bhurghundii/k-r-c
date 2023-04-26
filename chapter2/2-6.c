#include <stdio.h> 

int main() {

}

// clear the n right most bits in x  (~0 << n)
// then shift the mask to the position ~(~0 << n) << (p-n)
// complement it and get the mask ~(~(~0 << n) << (p-n))
// this clears x  (x & ~(~(~0 << n) << (p-n)))

// clear all the bits except for right most n bits at y  (~0 << n)
// then shift the mask to the position ~(~0 << n) << (p-n)
// we only want the bits here to mask (y & ~(~0 << n)) << (p-n))

unsigned setbits(unsigned x, int p, int n, unsigned y){
    return (x & ~(~(~0 << n) << (p-n)) | (y & ~(~0 << n)) << (p-n));
 }