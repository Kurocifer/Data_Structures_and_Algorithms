#include <stdio.h>
#include "fib_srch.h"

int main(void)
{
    int a[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int key_index, i;

    printf("searched array: ");
        for(i = 0; i < 10; i++)
            printf("%d ", a[i]);
    
    printf("\nsearching for 21...\n");

    key_index = fib_srch(a, 10, 21);

    
    printf("key index: ");
    if(key_index >= 0)
        printf("%d\n", key_index);
    else
        printf("not found\n");
        
    return 0;
}