/* quick sort algorithm */
#include "qck_sort1.h"

void qck_sort(int data[], int lo, int hi)
{
    int temp, part_elem, i, j;

    if(hi > lo) {
        part_elem = data[hi];
        i = lo - 1;
        j = hi;

        while(1) {
            while(data[++i] < part_elem)
                ;
            while(data[--j] > part_elem)
                ;
            
            if(i >= j)
                break;
            
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }

        temp = data[i];
        data[i] = data[hi];
        data[hi] = temp;

        qck_sort(data, lo, i - 1);
        qck_sort(data, i + 1, hi);
    }
}

/**
 * Average-case time complexity: O(nlog2 n).
 * Worts-case time complexity: O(n^2).
 * 
 * where n is the number of elements int the array.
*/