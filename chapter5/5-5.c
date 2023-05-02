/* Write a pointer version of the function strcat that we showed in Chapter 2:
   strcat(s,t) copies the string t to the end of s. */
#include <stdio.h>
#include <string.h>

void strncpy_old(char *s, char *t, int n);
void strncat_old(char *s, char *t, int n);
void strncmp_old(char *s, char *t, int n);

int main(void)
{

    char *a; // THIS IS A POINTER
    char *b;

    char as[100] = "now is the time"; // this is a array
    char bs[100] = "time";

    a = as;
    b = bs;

    strncat_old(a, b, 4);

    printf("%s \n", a);


    char *c; // THIS IS A POINTER
    char *d;

    char cs[100] = "now is the time"; // this is a array
    char ds[100];

    c = cs;
    d = ds;

    strncpy_old(c, d, 5);
    printf("%s \n", d);

    return 0;
}

void strncat_old(char * s, char *t, int n)
{
    // step 1: get to position n
    for (int i = 0; i < n; s++)
        i++;

    // step 2: add to s what ever is in t
    while ((*s) != '\0')
    {
        if (*t != '\0')
            *s = *t;
        s++;
        t++;
    }

}

void strncpy_old(char * s, char *t, int n)
{
    for (int i = 0; i < n; i++) {
        *t++ = *s++;
    }
}


void strncmp_old(char *s, char *t, int n) {
	int i;

	for (i = 0; *s == *t; i++) {
		if ((n > 0 && i >= n-1) || (*s == '\0')){
			return 0;
        }
        s++;
        t++;
    }

	return *s-*t;

}