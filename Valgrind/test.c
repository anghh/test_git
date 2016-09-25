#include <stdlib.h>
void f(void)
{

	int *x = NULL;
	x = malloc(12 * sizeof(int));
	x[11] = 0; //问题1: 数组下标越界

	if(x)
		free(x);
} //问题2: 内存没有释放

int main(void)
{
	f();
	return 0;
}

//valgrind --tool=memcheck --leak-check=full ./test
