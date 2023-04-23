#include <stdio.h>

#define MAXLINE 1024 /* maximum input line length */

int getline_r(char line[]);

/* print the longest input line */

int main()
{
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = getline_r(line)) > 0) {
        if (len > 5)
            printf("%s \n", line);
    }


    return 0;
}

/* getline_r: read a line into s, return length */
int getline_r(char s[])
{
    int c, i;

    // change it so we count past the limit
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
         s[i] = c;

    s[i] = '\0';


    return i;
}
