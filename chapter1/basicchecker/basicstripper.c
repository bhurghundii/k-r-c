#include <stdio.h>

#define REMOVE_COMMENTS = 0
#define BALANCE_PARENTHESIS = 0
#define BALANCE_BRACES = 0
#define BALANCE_BRACKETS = 0

int getMultiLineComments(char line[], int insideMultilineComment);

int main()
{
    FILE *filePointer;
    int lineLength = 1024;
    char line[lineLength];

    filePointer = fopen("file.c", "r");

    int insideMultilineComment = 0;

    while (fgets(line, lineLength, filePointer))
    {
        insideMultilineComment = getMultiLineComments(line, insideMultilineComment);
        
    }

    fclose(filePointer);
}

int getMultiLineComments(char line[], int insideMultilineComment)
{
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
                printf("%c", line[lineIndex]);
            }
        }

    ++lineIndex;

    }    
    return insideMultilineComment;
}