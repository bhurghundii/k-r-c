#include <stdio.h>
#include <math.h>

#define MAXLINE 1024 /* maximum input line length */

int getline_r(char line[]);

int main()
{
    int len; 
    char line[MAXLINE]; 

    signed int d = 2900;

    printf("%d", d);

    int decimal = 0;

    while ((len = getline_r(line)) > 0) {
        for (int i = len - 1; i >= 0; i--){

            unsigned int tmp = 0;
            switch(line[i]){
                case '0':
                    tmp = 0;
                    break;
                case '1':
                    tmp = 1;
                    break;
                case '2':
                    tmp = 2;
                    break;
                case '3':
                    tmp = 3;
                    break;
                case '4':
                    tmp = 4;
                    break;
                case '5':
                    tmp = 5;
                    break;
                case '6':
                    tmp = 6;
                    break;
                case '7':
                    tmp = 7;
                    break;
                case '8':
                    tmp = 8;
                    break;
                case '9':
                    tmp = 9;
                    break;
                case 'A':
                    tmp = 10;
                    break;
                case 'B':
                    tmp = 11;
                    break;
                case 'C':
                    tmp = 12;
                    break;
                case 'D':
                    tmp = 13;
                    break;
                case 'E':
                    tmp = 14;
                    break;
                case 'F':
                    tmp = 15;
                    break;
                default:
                    tmp = 0;
                    break;
            }
            printf("%d * %d", tmp, (int) pow (16, (len - i - 1)));
            decimal += (tmp * (int) pow (16, (len - i - 1)));
        }
    }

    printf("\n %d \n", decimal);

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
