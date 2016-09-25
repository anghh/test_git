#include<stdio.h>
#include<stdlib.h>
#include<mcheck.h>
#include<assert.h>

int main()
{


	assert(!setenv("MALLOC_TRACE","./malloc.log",1)) ;
	mtrace();
	int *p = malloc(100*sizeof(int));

	if(p)
		free(p);

	return 0;
}

// gcc -g test.c -o test
// ./test
// mtrace test malloc.log
