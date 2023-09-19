#include <stdio.h>
#include <time.h>
#include "bin_search.h"

int main(void)
{
    int a[10] = {2, 4, 6, 8, 10, 12, 13, 15, 17, 19};
    int i, key_index;
    clock_t start, stop;

    printf("Array to be sorted: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    
    /* searching for 17 */
    start = clock();
    key_index = bin_search(a, 10, 17);
    stop = clock();

    printf("\nkey index: %d\n", key_index);
    printf("search time: %fs\n", ((double) (stop - start)));

    return 0;
}