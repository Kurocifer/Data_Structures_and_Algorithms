/* Test for insertion sort routine */
#include <stdio.h>
#include "ordered_linear_search.h"

int main(void)
{
    int a[10] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34};
    int key_index, i;

    printf("searched array: ");
        for(i = 0; i < 10; i++)
            printf("%d ", a[i]);
    
    printf("\nsearching for 7...\n");
    key_index = seq_search2(a, 10, 4);
    printf("key index: %d", key_index);

    printf("\n");
    return 0;
}