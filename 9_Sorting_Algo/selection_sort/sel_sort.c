/* selection sort algorithm */
#include "sel_sort.h"

void sel_sort(int data[], int no_elems)
{
    int i, j, temp, min_index;

    for(i = 0; i < no_elems; i++) {
        min_index = i;

        for(j = i + 1; j < no_elems; j++) {
           if(data[j] < data[min_index])
                min_index = j;
        }
        
        temp = data[i];
        data[i] = data[min_index];
        data[min_index] = temp;   
    }
}

/* Average time complexity: O(n^2). Where n is no_elems */