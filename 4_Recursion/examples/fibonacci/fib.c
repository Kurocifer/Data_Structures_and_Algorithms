#include <stdio.h>

int fib_recur(int n);

int main(void)
{
    int num;

    printf("Position to get fibonacci number: ");
    scanf("%d", &num);

    printf("f(%d) = %d\n", num, fib_recur(num));
    return 0;

}

int fib_recur(int n)
{
    if(n < 0)
        return -1;  /*bad arguement*/
    
    if(n == 0 || n == 1)
        return n;
    
    return(fib_recur(n - 1) + fib_recur(n - 2));
}