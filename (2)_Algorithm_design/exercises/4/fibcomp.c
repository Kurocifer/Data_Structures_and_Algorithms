/*complement of the fib function*/
#include <stdio.h>

#define MAX_TEST 10

int fibcomp(int n);

int main(void)
{
    int i;

	for(i = -1; i <= MAX_TEST; i++)
		printf("\ti: %2d\tfib(%2d): %d\n", i, i, fibcomp(i));

	return 0;
    
}

int fibcomp(int n)
{
    int fibn, fib1, fib2;
    int pos;

    if(n < 0)
        return -1;
    
    if(n == 0)
        return 1;

    if(n == 1)
        return 2;
    
    pos = 3;
    fibn = 0;
    fib1 = 1;
    fib2 = 0;

    while(fibn < n) {
        fibn = fib1 + fib2;
        fib1 = fibn;
        fib2 = fib1;
        pos++;
    }
}