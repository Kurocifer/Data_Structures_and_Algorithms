#include <stdio.h>
#include <time.h>
#include "bin_search.h"

void report(char *header, int key_index, double time_used);

int main(void)
{
    int a[10] = {2, 4, 6, 8, 10, 12, 13, 15, 17, 19};
    int i, key_index;
    clock_t start, stop;

    printf("Array to be sorted: ");
    for(i = 0; i < 10; i++)
        printf("%d ", a[i]);
    
    printf("\nSearching for 17...\n");

    /* test for bin_search() */
    start = clock();
    key_index = bin_search(a, 10, 17);
    stop = clock();
    report("### BINARY SEARCH 1 ###", key_index, ((double) (stop - start)));

    /* test for bin_search2() */
    start = clock();
    key_index = bin_search2(a, 10, 17);
    stop = clock();
    report("### BINARY SEARCH 2 ###", key_index, ((double) (stop - start)));

    return 0;
}

void report(char *header, int key_index, double time_used)
{
    printf("\n\n%s\n", header);
    printf("key index: %d\n", key_index);
    printf("Time used: %fs\n", time_used);
}