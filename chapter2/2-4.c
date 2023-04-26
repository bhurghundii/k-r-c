#include <stdio.h>

void squeeze(char s1[], int c);

// this is such a cracked way of doing lmao 

int main()
{
    char line1[100] = "hello";

    char remove[100] = "e";
    for (int i = 0; remove[i] != '\0'; i++){
        squeeze(line1, remove[i]);
    }
    printf("%s\n", line1);
}

void squeeze(char s[], int c)
{
      int i, j;
      for (i = j = 0; s[i] != '\0'; i++)
          if (s[i] != c) {
              s[j] = s[i];
              j++;
          }
      s[j] = '\0';
}