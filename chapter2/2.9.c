#include <stdio.h> 


int main() {

}


// Why: so x &= (x-1) takes out the rightmost 1 
// As you cycle, you keep removing 1s until there are no more 1s 
// The number is 0 
// So you pass through a lot less since x &= (x-1) is a O(1)

int bitcount(unsigned x){
    int b; 

    for (b = 0; x != 0; x &= (x-1)){
        b++;
    }

    return b;
}