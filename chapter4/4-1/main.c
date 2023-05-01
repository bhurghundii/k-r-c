#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline_old(char s[], int lim);
int strrindex(char s[], char t[]);

char pattern[] = "ould"; /* pattern to search for */
/* find all lines matching pattern */

int main()
{
    char line[MAXLINE];
    int found = 0;
    while (getline_old(line, MAXLINE) > 0)
    {
        if (strrindex(line, pattern) >= 0)
        {
            int i = strrindex(line, pattern);
            printf("%d \n", i);
            found++;
        }
    }
    return found;
}