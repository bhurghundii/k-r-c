#include <stdio.h>

// Verify that the expression getchar ( ) |= EOF is 0 or .1
// c has No booleans and therefore, either the character if 1 or 0
int main() {
    int c;
    while ((c = getchar()) != EOF)
       putchar(c);
}