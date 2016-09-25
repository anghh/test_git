#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  

#include <mcheck.h>
#include<assert.h>

int main(void)
{
	assert(!setenv("MALLOC_TRACE","./taoge.log",1)) ;
    mtrace();

	int *p = NULL;
    p = (int *)malloc(2 * sizeof(int));
	
	if(p)
		free(p);

    return 0;
}
