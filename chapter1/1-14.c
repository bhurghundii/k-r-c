#include <stdio.h>
#define LENGTH_MAX 1024
/* 
Write a program to print a histogram of the lengths of words in its input. 
It is easy to draw the histogram with the bars horizontal; 
a vertical orientation is more challenging.
*/
void printLines(int length);

int main(int argc, char const *argv[])
{
    int c;
    int lengths[LENGTH_MAX];

    // Initialise the array

    for (int i = 0; i < LENGTH_MAX; ++i)
            lengths[i] = 0;

    while ((c = getchar()) != EOF){
        
        ++lengths[c];

    }

    ++lengths[c];

    printf("\n");

    for (int i = 0; i < LENGTH_MAX; i++){
        if (lengths[i] != 0){
            printf("Length of ");
            char d = i;
            printf("%c", d);
            printf(": ");

            printLines(lengths[i]);
            printf("\n");
        }
    }
    return 0;
}

void printLines(int length){
    for (int i = 0; i < length; i++){
        printf("-");
    }
    printf("\n");
}
