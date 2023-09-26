#ifndef HEAP_H
#define HEAP_H

/**
 * buildheap: Builds the heap. The driving routnine for formheap.
 * 
 * data[]- A pointer to the array to be turned into a heap.
 * size- The size of the array.
*/
void buildheap(int data[], int size);

/**
 * formheap: Forms the heap.
 * 
 * data[]- A pointer to the array to be turned into a heap.
 * lo - The lower bound.
 * hi- The upper bound.
*/
void formheap(int data[], int lo, int hi);

#endif