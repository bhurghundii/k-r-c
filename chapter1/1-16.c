#include <stdio.h>

#define MAXLINE 5 /* maximum input line length */

int getline_r(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest input line */

main()
{
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* current line saved here */

    max = 0;
    while ((len = getline_r(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) /* there was a line */
        printf("%s", longest);
    return 0;
}

/* getline_r: read a line into s, return length */
int getline_r(char s[], int lim)
{
    int c, i;

    // change it so we count past the limit
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
         // we've reached the buffer limit. we can stop reading the line into s.
        if (i < lim - 1){
            s[i] = c;
        }

    // if it's not there yet, mark the end 
    if (i < lim - 1) {
       s[i] = '\0';
    }
    else { 
        // since we stopped the buffer before it overflowed, mark the end 
       s[lim - 1] = '\0';
    }


    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}