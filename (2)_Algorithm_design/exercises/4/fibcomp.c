/*complement of the fib function*/
#include <stdio.h>

#define MAX_TEST 10

int fibcomp(int n);
int findFibonacciPosition(int fibonacciNumber);

int main(void)
{
    int i;

	for(i = -1; i <= MAX_TEST; i++)
		printf("\ti: %2d\tfib(%2d): %d\n", i, i, fibcomp(i));

	return 0;
    
}

int findFibonacciPosition(int fibonacciNumber) {
    int current = 0;
    int next = 1;
    int position = 1;

    while (current < fibonacciNumber) {
        int temp = current;
        current = next;
        next = temp + current;
        position++;
    }

    if (current == fibonacciNumber) {
        return position;
    } else {
        return -1;  // Fibonacci number not found
    }
}

int fibcomp(int n)
{
    int fibn = 0, fib1 = 1, fib2 = 0;
    int pos = 1;

    while(fibn < n) {
        fib2 = fib1;
        fib1 = fibn;
        fibn = fib1 + fib2;
        pos++;
    }

    if(fibn == n)
        return pos;
    return -1;
}

/*
int fibcomp(int n)
{
    int fibn, fib1, fib2;
    int pos;

    if(n <= 0)
        return -1;
    
    if(n == 0 )
        return 1;

    if((n == 1))
        return 2;
    
    fibn = 0;
    fib1 = 1;
    fib2 = 0;

    for(pos = 3; fibn < n;) {
        fibn = fib1 + fib2;
        fib1 = fibn;
        fib2 = fib1;
        pos++;
    }

    if(fibn == n)
        return pos;
    return -2;
}
*/