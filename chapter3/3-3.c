#include <stdio.h>
#include <stdlib.h>


// cba to do it any futher - 3.4 looks more fun

void expand(char s1, char s2);

int main() {
expand('a', 'z');
expand('1', '9');

}

void expand(char s1, char s2){
    for (int i = (int)(s1); i <= (int)(s2); i++){
        printf("%c", i);
    }
}
