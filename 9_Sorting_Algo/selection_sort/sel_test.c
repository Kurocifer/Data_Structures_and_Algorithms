/* test for selection sort function*/
#include <stdio.h>
#include "sel_sort.h"

int main(void)
{
    int a[10] = {21, 8, 2, 34, 5, 1, 13, 0, 3, 1};
    int i;

    printf("\n###TEST FOR SELECTION SORT ###\n\n");
    printf("Unsorted array: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    
    /* sort array */
    sel_sort(a, 10);

    printf("\nSorted array: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    
    printf("\n\n");

    return 0;
}