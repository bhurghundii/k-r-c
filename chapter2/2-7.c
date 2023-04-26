#include <stdio.h> 

// Write a function invert(×,p,n) that returns × with the n bits that begin at position p inverted (i.e., 1 changed into 0 and vice versa), leaving the others unchanged.
int main() {

}

// clear the n right most bits in x  (~0 << n)
// flip it to get make it the bits you want ~(~0 << n)
// move that in position ~(~0 << n) << (p + 1 - n)
// ^ ~(~0 << n) << (p + 1 - n)

unsigned invert(unsigned x, int p, int n){
    return (x ^ (~(~0 << n) << (p + 1 - n)));
 }