/* heap data structure routines */
#include "heap.h"

void buildheap(int data[], int size)
{
    int i;

    for(i = size / 2; i >= 0; i--)
        formheap(data, i, size);
        
}

void formheap(int data[], int lo, int hi)
{
    int temp, desc;

    if(2 * (lo + 1) - 1 > hi)
        return;             /* Nothing to do */
    
    if((2 * (lo + 1)) <= hi && (data[2 * (lo + 1)] > data[2 * (lo + 1) - 1]))
        desc = (2 * (lo + 1));      /* Right child */
    else   
        desc = (2 * (lo + 1) - 1);  /* Left child */
    
    if(data[lo] < data[desc]) {
        temp = data[lo];
        data[lo] = data[desc];
        data[desc] = temp;
        
        formheap(data, desc, hi);
    }
}