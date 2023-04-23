#include <stdio.h>

#define REMOVE_COMMENTS = 0
#define BALANCE_PARENTHESIS = 0
#define BALANCE_BRACES = 0
#define BALANCE_BRACKETS = 0

int checkParenthesis(char line[], int score);
int removeComments(char line[], int insideMultilineComment);

int main()
{
    FILE *filePointer;
    int lineLength = 1024;
    char line[lineLength];

    char code[lineLength];

    fclose(fopen("tmp.txt", "w"));

    // Scrub comments cause we don't care

    filePointer = fopen("file.c", "r");

    int insideMultilineComment = 0;

    while (fgets(line, lineLength, filePointer))
    {
        insideMultilineComment = removeComments(line, insideMultilineComment);
    }

    fclose(filePointer);

    // Check parenthesis
    FILE *filePointer1;

    filePointer1 = fopen("tmp.txt", "r");

    int score = 0;
    while (fgets(line, lineLength, filePointer1))
    {
        score = checkParenthesis(line, score);
    }

    printf("%d", score);

    if (score == 0){
        printf("Parenthesis isn't fucked \n");
    } else {
        printf("Parenthesis is fucked \n");
    }

    fclose(filePointer1);
}

int removeComments(char line[], int insideMultilineComment)
{
    FILE *pFile;
    pFile=fopen("tmp.txt", "a");

    int SKIP = 0;
    
    int lineIndex = 0;
    while (line[lineIndex] != '\0')
    {
        
        if ((line[lineIndex] == '/') && (line[lineIndex + 1] == '*') )
        {
            insideMultilineComment = 1;
        } 

        else if ((line[lineIndex] == '/') && (line[lineIndex + 1] == '/')){
            

            while (line[lineIndex] != '\0')
            {
                ++lineIndex;
            }
            --lineIndex;
            SKIP = 1;
        }
    
        else if (line[lineIndex] == '*' && line[lineIndex + 1] == '/'){
            insideMultilineComment = 0;
            SKIP = 1;
        }

        else  if (insideMultilineComment == 1){
            insideMultilineComment = 1;
        }
        else {
            if (SKIP == 1){
                SKIP = 0;
            } else {

                fprintf(pFile, "%c", line[lineIndex]);

                
            }
        }

    ++lineIndex;

    } 
    fclose(pFile);   
    return insideMultilineComment;
}

int checkParenthesis(char line[], int score) {
    int i = 0;

    while (line[i] != EOF) {

        if (line[i] == '{'){
             printf("Found a {");
             score++;
        }
        else if (line[i] == '}'){
             printf("Found a }");
             score--;
        }

        i++;
    }

    return score;

}