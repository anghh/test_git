#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

#include <mcheck.h>  

#include<assert.h>
int main(void) {

	assert(!setenv("MALLOC_TRACE","output",1)) ;
	mtrace();  

	char * text = ( char * ) malloc (sizeof(char) * 100);  
	memset(text, 0, 100);  
	memcpy(text,"hello,world!",12);  
	printf("%s\n", text);  

	if(text)
		free(text);
	return 0;  
}
