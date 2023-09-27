/* ordered linear search. An improvement to the sequential search algo */
#include "seq_search.h"


/* The array searched should be sorted */
int seq_search2(int data[], int size, int key)
{
    int i;

    for(i = size - 1; i >= 0 && data[i] != key; i--) {

        if(data[i] < key)
            return NOT_FOUND;
        
    }
    
    return i;
}

/* Average time complexity O(n/2) where n is the size of the array */