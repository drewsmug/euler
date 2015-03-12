#include <stdio.h>

#define FIBONACCI 40

int fib(int depth);

int main()
{
	int result;
	result = fib(FIBONACCI);

	printf("Fibonacci to the %dth place is %d\n",FIBONACCI,result);

	return 1;
}

int fib(int depth)
{
	if(depth <= 2)
		return 1;
	else
		return (fib(depth - 1) + fib(depth - 2));
}
