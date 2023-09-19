#include "bin_search.h"

#define HALF(X) ( ((X) + 1) / 2 )
#define NOT_FOUND -1

/* array parsed should be sorted in asscending order */
int bin_search2(int data[], int size, int key)
{
    int middle, delta;

    delta = size / 2;
    middle = delta;

    while(key != data[middle]) {
        if(delta == 0)
            return NOT_FOUND;

        if(key > data[middle])
            middle += HALF(delta);
        else
            middle -= HALF(delta);
        
        delta /= 2;
    }

    return (middle);
}

/* Time complexity: O(log2 n), where n is the size of array searched */