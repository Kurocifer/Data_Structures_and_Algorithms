#include <stdio.h>
#include <time.h>
#include "seq_search.h"

/**
 * report: prints a report message.
 * 
 * *header- A message to be printed above the report.
 * key_index- The index of the searched element.
 * time_used- The time the algorithm searched.
*/
void report(char *header, int key_index, double time_used);

int main(void)
{
    int a[10] = {1, 3, 5, 6, 8, 10, 13, 16, 20, 25};
    int key_index, i;
    clock_t start, end;
    double cpu_time_used;

    printf("searched array: ");
        for(i = 0; i < 10; i++)
            printf("%d ", a[i]);
    
    printf("\nsearching for 4...");

    /* Test for seqeuntial search */
    start = clock();
    key_index = seq_search(a, 10, 4); /* element search is not in the array */
    end = clock();
    report("##### SEQUENTIAL SEARCH #####", key_index, ((double) (end - start)));

    /* Test for ordered linear search */
    start = clock();
    key_index = seq_search2(a, 10, 4);
    end = clock();
    report("##### ORDERED LIST SEARCH #####", key_index, ((double) (end - start)));

    printf("\n");
    return 0;
}

void report(char *header, int key_index, double time_used)
{
    printf("\n\n%s\n", header);
    printf("key index: %d\n", key_index);
    printf("Time used: %fs", time_used);
}