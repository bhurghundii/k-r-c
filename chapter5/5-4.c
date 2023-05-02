/* Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s,t) copies the string t to the end of s. */
#include <stdio.h>
#include <string.h>

int str_end(char *s, char *t);

int main(void)
{

    char *a; // THIS IS A POINTER
    char *b;

    char as[100] = "now is the time"; // this is a array
    char bs[100] = "time";

    a = as;
    b = bs;

    printf("%d \n", str_end(a, b));

    return 0;
}

int str_end(char *s, char *t)
{
    // take us to the point in the s array where t sits at the end
    for (int i = 0; i < (strlen(s) - strlen(t)); s++)
        ;

    // increment thru s and t checking they r the same
    while (*s++ == *t++)
    {
        // if they r over, return 1
        if (*s == '\0' && *t == '\0')
        {
            return 1;
        }
    }
    return 0;
}