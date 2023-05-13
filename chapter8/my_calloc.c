#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *my_calloc(unsigned n, size_t size);

// 2 steps: 1) allocate memory 2) fill it out with 0s

int main(){ // lazy so stole this from clc wiki
    
  int *p = NULL;
  int i = 0;

  p = my_calloc(100, sizeof *p);
  if(NULL == p)
  {
    printf("mycalloc returned NULL.\n");
  }
  else
  {
    for(i = 0; i < 100; i++)
    {
      printf("%08X ", p[i]);
      if(i % 8 == 7)
      {
	printf("\n");
      }
    }
    printf("\n");
    free(p);
  }

  return 0;
}

void *my_calloc(unsigned n, size_t size){
    void * objects = NULL;
    unsigned mem = n * size;
    objects = malloc(mem);

    if (objects != NULL)
        // neat trick 
        memset(objects, 0, mem);
    
    return objects;
}