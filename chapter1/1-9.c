#include <stdio.h>

main()
{
    int c, o;
    while ((c = getchar()) != EOF){
        if (c == ' '){
            // empty statement at the end to register other blanks
            while ((c = getchar()) == ' ');

            putchar(' ');
            
        }
        putchar(c);
    }
}