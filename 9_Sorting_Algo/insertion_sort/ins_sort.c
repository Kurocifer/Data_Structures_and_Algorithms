/* Insertion sort algorithm */
#include "ins_sort.h"

void ins_sort(int data[], int no_elems)
{
    int i, j, temp;

    for(i = 1; i < no_elems; i++) {
        temp = data[i];
        
        for(j = i - 1; (data[j] > temp) && (j >= 0); j--) {
            data[j + 1] = data[j];
            data[j] = temp;
        }
        
    }
}


/* Average time complexity: O(n^2), where n is no_elems*/
