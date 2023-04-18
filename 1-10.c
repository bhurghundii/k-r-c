#include <stdio.h>

void printSpecialCharacter(char c);

int main()
{
    int c;

    while ( (c=getchar()) != EOF) {

        if (c == '\t') {
            printSpecialCharacter('t');
        }
        else if (c == 8) {
           printSpecialCharacter('b');
        }
         elseif (c == '\\') {
            printSpecialCharacter('\\');
        }
        else { 
            putchar(c); 
        }       
    }
    return 0;
}

void printSpecialCharacter(char c){
    putchar('\\');
    putchar(c);
}

