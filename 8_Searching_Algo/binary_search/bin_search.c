/* binary search algo */
#include "bin_search.h"

#define NOT_FOUND -1

/*array parsed should be sorted in asscending order */
int bin_search(int data[], int size, int key)
{
    int lower, middle, upper;

    lower = 0;
    upper = size - 1;

    while(lower <= upper) {
        middle = (upper + lower) / 2;

        if(key == data[middle])
            return middle;
        else if(key < data[middle])
            upper = middle - 1;
        else
            lower = middle + 1;

    }

    return NOT_FOUND;
}

/* Time complexity: O(log2 n) */