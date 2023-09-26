/* Test for quick sort routine */
#include <stdio.h>
#include "qck_sort1.h"

int main(void)
{
int a[10] = {21, 8, 2, 34, 5, 1, 13, 0, 3, 1};
    int i;

    printf("\n### TEST FOR INSERTION SORT ###\n\n");
    printf("Unsorted array: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    
    /* sort array */
    qck_sort(a, 0, 9);

    printf("\nSorted array: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    
    printf("\n\n");

    return 0;
}