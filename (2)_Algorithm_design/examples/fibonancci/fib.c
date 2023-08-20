/*prints the first n members of the fibonanicci series*/
#include <stdio.h>

#define MAX_TEST 10

int fib(int n);

int main(void)
{
	int i;

	for(i = -1; i <= MAX_TEST; i++)
		printf("\ti: %2d\tfib(%2d): %d\n", i, i, fib(i));

	return 0;
}

int fib(int n)
{
	int i;
	int fibn, fib1, fib2;

	if(n < 0)
		return -1;
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;

	fibn = 0;
	fib2 = 0;	/*F(n - 2)*/
	fib1 = 1;	/* F(n - 1)*/

	for(i = 2; i <= n; i++) {
		fibn = fib1 + fib2;
		fib2 = fib1;
		fib1 = fibn;
	}
	return fibn;
}
