#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "6-5.c"
#include "getword.c"
#include "6.h"

void trim(char * s) {
    char * p = s;
    int l = strlen(p);

    while(isspace(p[l - 1])) p[--l] = 0;
    while(* p && isspace(* p)) ++p, --l;

    memmove(s, p, l + 1);
}   

int main(void)
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    char *token;
    char *src;
    char *dst;

    fp = fopen("test.c", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1)
    {
        
        if (strstr(line, "#define") != NULL)
        {
            // this line has a #define - break it up and get the parts
            token = strtok(line, " ");

            src = strtok(NULL, " ");
            
            trim(src);

            dst = strtok(NULL, " ");
            trim(dst);

            install(src, dst);

        }
        else
        {
            token = strtok(line, " ");
            // if not a define statement, check the words in a line if they exist
            while (token != NULL)
            {
               
                struct nlist *np1;
                
                 if ((np1 = lookup(token)) != NULL) {
                    printf("%s", np1->defn);
                 } else {
                    printf("%s ", token);
                 }

                token = strtok(NULL, " ");
            }
        }
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

