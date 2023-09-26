/* heap sort algorithm */
#include "Heaps/heap.h"
#include "heap_sort.h"

void heap_sort(int data[], int size)
{
    int temp, i;

    buildheap(data, size);

    for(i = size; i > 0; i--) {
        temp = data[0];
        data[0] = data[i];
        data[i] = temp;
        
        formheap(data, 0, i - 1);
    }
}

/* Averge time complexity: O(nlog2 n), where n is the size of array*/