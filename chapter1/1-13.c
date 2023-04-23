#include <stdio.h>
#define LENGTH_MAX 5
/* 
Write a program to print a histogram of the lengths of words in its input. 
It is easy to draw the histogram with the bars horizontal; 
a vertical orientation is more challenging.
*/
void printLines(int length);

int main(int argc, char const *argv[])
{
    int c, n = 0;
    int lengths[LENGTH_MAX];

    // Initialise the array

    for (int i = 0; i < LENGTH_MAX; ++i)
            lengths[i] = 0;

    while ((c = getchar()) != EOF){
        
        if (c == ' '){
            ++lengths[n];
            n = 0;
        } else { 
            n++;
        }

    }

    // We have just EOF'd so grab the last word...
    ++lengths[n];

    printf("\n");

    for (int i = 0; i < LENGTH_MAX; i++){
        printf("Length %i: ", i);
        printLines(lengths[i]);
        printf("\n");
    }
    return 0;
}

void printLines(int length){
    for (int i = 0; i < length; i++){
        printf("-");
    }
    printf("\n");
}