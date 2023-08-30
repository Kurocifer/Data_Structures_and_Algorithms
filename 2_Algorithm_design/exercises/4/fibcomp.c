/*complement of the fib function*/
#include <stdio.h>

#define MAX_TEST 10

int fibposition(int n);

int main(void)
{
    int i;

	for(i = -1; i <= MAX_TEST; i++)
		printf("\ti: %2d\tfib(%2d): %d\n", i, i, fibpositon(i));

	return 0;
    
}

/*fibpositon: Takes a fibonancci number, and returns
               it's position in the series.
n- number to search for position
Return- position if number is of the series, -1 if not*/
int fibpositon(int n)
{
    int fibn = 0, fib1 = 1, fib2 = 0;
    int pos = 1;

    while(fibn < n) {
        fib2 = fib1;
        fib1 = fibn;
        fibn = fib1 + fib2;
        pos++;
    }

    if(fibn == n) {
        return pos;
    }
    return -1;
}

