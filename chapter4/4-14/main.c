#include <stdio.h>
#define swap_int(x, y) { a = a ^ b; b = a ^ b; a = a ^b; }
#define swap(t, x, y) { t temp; temp = x, x = y, y = temp; }

int main () {
    int a = 5;
    int b = 6;

    swap(int, a, b);
    printf("a, b AFTER = %d %d\n", a, b);

}