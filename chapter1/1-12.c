#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c;
    while ((c = getchar()) != EOF){
        if (c == ' '){
            putchar('\n');
        }
        else {
            putchar(c);
        }
    }
    return 0;
}
