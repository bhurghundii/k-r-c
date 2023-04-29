#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

void reverse(char s[]);
void itob(int n, char s[], int b);


// convert intenger into a base b character representation 
// tests: itob(16, s, 16) --> 16
// tests: itob(16, s, 16) --> 10

// tests: itob(10, s, 8) --> 12

int main() {

char buffer[20];
    
    printf("INT_MIN: %d\n", INT_MIN);
    itob(87, buffer, 20);
    printf("Buffer : %s\n", buffer);
        
    return 0;
}

void itob(int n, char s[], int b){
    
    int i, sign;
    sign = n;
    
    i = 0;
    do {
        int m = abs(n % b);
        if (m > 9) {
            m = m + 7;
        }
        s[i++] = m + '0';
    } while ( n /= b );
    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;
    for ( i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// notes - this only we need to get letters so 14 will go to > 
// as > is 14 + 48 = 62 