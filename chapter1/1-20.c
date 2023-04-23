#include <stdio.h> 

/* 
 * Create an array for the input 
 * Store the character 
 * When a tab comes, do an inplace swap 
 */

#define TAB 4 

int main() { 
	int c;
	char arr[1024];
	int i;

	for (i = 0; (c = getchar()) != EOF; ++i) {
		
		if (c == '\t') {
			int spacesUntilNextTabStop = TAB - (i % TAB);

			int NEXT_TAB = i + spacesUntilNextTabStop;

			while (i < NEXT_TAB){
				arr[i] = '.';
				i++;
			}
			i--;
		}
		else { 
			arr[i] = c;
		}

	}		

	printf("%s \n", arr);
}
