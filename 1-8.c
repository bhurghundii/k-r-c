#include <stdio.h>
#define BLANK 32
#define NEWLINE 10
#define TAB 9

// newline is 10 because thats ascii 
main()
{
    int c, n1;
    n1 = 0;
    while (c != EOF)
    {
        c = getchar();
        
        if ( (c == BLANK) || (c == NEWLINE) || (c == TAB))
        {
            ++n1;
        }
    }

    printf("\n %d \n", n1);
}