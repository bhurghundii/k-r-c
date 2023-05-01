#include <stdio.h>
#include <string.h>

// how lucky - two execercise ONE file

#define MAXLEN 100

void itoa(int n, char s[], int i);
void reverse(char s[], int i, int j);

int main()
{
  int n = 3245;
  char s[MAXLEN];

  int i, sign;

  if ((sign = n) < 0)  // record sign
    n = -n;            // make n positive

  itoa(n, s, 0);

  if (sign < 0)
    s[i++] = '-';

  printf("%s\n", s);

  return 0;
}

/* itoa: convert n to characters on s */
void itoa(int n, char s[], int i)
{
  if ((n / 10) > 0){
    s[i] = n % 10 + '0';
    n /= 10;
    itoa(n,  s, ++i);
  } else { 
    // lmfao we got an off by one error
    s[i++] = n + '0';
    s[i++] = '\0';
    reverse(s, 0, strlen(s) - 1);
  }

}

void reverse(char s[], int i, int j)
{
  char c;

  if (i < j) {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
      reverse (s, ++i, --j);
  }
}


/* 
Process 6026 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x0000000100003f2c a.out`reverse(s="5423", i=0, j=4) at 4-12-13.c:60:14
   57  
   58     if (i < j) {
   59         c = s[i];
-> 60         s[i] = s[j];
   61         s[j] = c;
   62         reverse (s, ++i, --j);
   63     }
Target 0: (a.out) stopped.
(lldb) fr v
(char *) s = 0x000000016fdfef24 "5423"
(int) i = 0
(int) j = 4
(char) c = '5'
(lldb) step
Process 6026 stopped
* thread #1, queue = 'com.apple.main-thread', stop reason = step in
    frame #0: 0x0000000100003f4c a.out`reverse(s="", i=0, j=4) at 4-12-13.c:61:14
   58     if (i < j) {
   59         c = s[i];
   60         s[i] = s[j];
-> 61         s[j] = c;
   62         reverse (s, ++i, --j);
   63     }
   64   }
Target 0: (a.out) stopped.
(lldb) fr v 
(char *) s = 0x000000016fdfef24 ""
(int) i = 0
(int) j = 4
(char) c = '5'

*/