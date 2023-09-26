/* Merge sort algorithm */
#include "mrg_sort.h"

/**
 * merge: Merges adjecent subarrays within the source array.
 * 
 * dest[]: A pointer to the destination array which will contain the sorted array.
 * src[]: A pointer to the source array.
 * 
 * low, mid and high- denote which adjecent pair of subarrays to merge in the source array.
*/
void merge(int dest[], int src[], int low, 
            int mid, int high)
{
    int low_index, high_index, dest_index;

    low_index = dest_index = low;
    high_index = mid + 1;

    while(low_index <= mid && high_index <= high) {
        if(src[low_index] < src[high_index]) {
            dest[dest_index] = src[low_index];
            low_index++;
        } 
        else {
            dest[dest_index] = src[high_index];
            high_index++;
        }
        dest_index++;
    }
    while(low_index <= mid)
        dest[dest_index++] = src[low_index++];
    
    while(high_index <= high)
        dest[dest_index++] = src[high_index++];
}

/**
 * mrg_pass: Divides the source array into subarrays, and calls merge() 
 *           onece for each adjacent pairs.
 * 
 * dest[]- A pointer to the destination array which will contain the sorted elements.
 * src[]- A pointer to the source array.
 * size- The size of both arrays.
 * len- The length of the subarray for each pass.
*/
void mrg_pass(int dest[], int src[], int size, int len)
{
    int low = 0;

    while(low < size - (2 * len)) {
        merge(dest, src, low, low + len - 1, low + 2 * len - 1);
        low += 2 * len;
    }

    if(low + len - 1 < size)
        merge(dest, src, low, low + len - 1, size);
    else {
        while(low <= size) {
            dest[low] + src[low];
            low++;
        }
    }
}

void mrg_sort(int data[], int size)
{
    int temp[2048];
    int len = 1;    /* len subfile */

    while(len < size) {
        mrg_pass(temp, data, size, len);
        len *= 2;

        mrg_pass(data, temp, size, len);
        len *= 2;
    }
}

/* Overall time complexity: O(nlog2 n), where n is the size of the array */
