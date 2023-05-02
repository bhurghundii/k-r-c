/* Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s,t) copies the string t to the end of s. */
#include <stdio.h>

void str_cat(char *s, char *v);

int main(void)
{

    char *a; // THIS IS A POINTER
    char *b;

    char as[100] = "now is the time";
    char bs[100] = " to dance d";

    a = as;
    b = bs;

    str_cat(a, b);
    printf("Concatenated string: %s \n", a);
    return 0;
}

void str_cat(char *s, char *t)
{
    // step 1: get to the end of s 
    for (; *s != '\0'; s++)
        ;
        
    // step 2: add to s what ever is in t 
    while ((*s = *t) != '\0'){
        s++;
        t++;
    }
        
}