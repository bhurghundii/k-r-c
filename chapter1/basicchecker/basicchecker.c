#include <stdio.h>

int checkSyntax(char entry, char end, char line[], int score);

void idkwhattocallthis(char start, char end, FILE * filePointer);

// limitations: cba to do the others x  

int main()
{
    FILE *filePointer;
    filePointer = fopen("file.c", "rb");

    idkwhattocallthis('{', '}', filePointer);

}

void idkwhattocallthis(char start, char end, FILE * filePointer) {

    int lineLength = 200;
    char line[lineLength];
    

    int score = 0;

    while (fgets(line, lineLength, filePointer))
    {
        score = checkSyntax(start, end, line, score);
    }

    if (score == 0) {
        printf("Your %c and %c is not fucked \n", start, end);
    } else {
        printf("Your %c and %c is fucked \n", start, end);
    }

    fclose(filePointer);
}

int checkSyntax(char entry, char end, char line[], int score) {
    int i = 0;

    static int FLAG = 0;

    while (line[i] != '\0') {

        if ((line[i] == '/') && (line[i + 1] == '/') ) {

                while (line[i] != '\0') {
                    i++;
                }
            } 
            else { 
            if ((line[i] == '/') && (line[i + 1] == '*') ) {
                FLAG = 1;
            }

            else if ((line[i] == '*') && (line[i + 1] == '/') ) {
                FLAG = 0;
            }

            

            if (FLAG == 0) { 
                if (line[i] == entry){
                    score++;
                }
                else if (line[i] == end){
                    score--;
                }
            }
        

        i++;
            }
    }


    return score;

}