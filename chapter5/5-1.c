#include <stdio.h>
#include <ctype.h> /* for isdigit(c), etc. */

#define MAX 10

int getint(int *pn);
int getch(void);
void ungetch(int);

int bufp = 0;
int buf[MAX];

// test input: +1

// compile with getch.c
int main()
{
	int n, array[MAX], getint(int *);

	for (n = 0; n < MAX; n++)
		array[n] = 0;
	
	for (n = 0; n < MAX && getint(&array[n]) != EOF; n++)
		;
	
	for (n = 0; n < MAX; n++)
		printf("%d ", array[n]);

	printf("\n");
	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch()))
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	// if (c == '+' || c == '-') {
	// 	c = getch();
	// 	if (!isdigit(c)) {
	// 		ungetch(sign == 1 ? '+' : '-');
	// 		return 0;
	// 	}
	// }

    // we r collecting + / - from above so just ignore the inputs
    while(!isdigit(c)){
        c = getchar();
    }

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);
	return c;
}

int getch(void)
{
	return bufp > 0 ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp < MAX)
		buf[bufp++] = c;
}