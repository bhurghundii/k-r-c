#include <stdio.h> 

#define MAX_BIT_SIZE 8
// Write a function rightrot (x, n) that returns the value of the integer x rotated to the right by n bit positions.
int main() {

}
// rotate to the right just means the bits are shifted to the right 
// but the bits are returned to the right 

// right shift the bits to the position n (x >> n) (11001 ==> 000110)
// the bits that get dropped off should get moved to the start 
//              to do this: for the bits we are dropping off we left shift them there (x << (MAX_BIT_SIZE - n)) (11001 ==> 010000)
// or it so bits are set  (000110 | 010000 ==> 010110)

unsigned rightrot(unsigned x, int n){
    return ((x >> n) | (x << (MAX_BIT_SIZE - n)));
 }