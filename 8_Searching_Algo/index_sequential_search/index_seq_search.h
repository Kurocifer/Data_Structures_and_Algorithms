#ifndef INDEX_SEQ_SEARCH_H
#define INDEX_SEQ_SEARCH_H

typedef struct index Index;

/**
 * index_search: An indexed search through the array.
 * 
 * key- item searched for.
 * idx[]- The index array.
 * data[]- The array to be searched.
 * data_size- The size of the arry to be searched.
 * 
 * Return- If it findS the key it returns it's index in the data array
 *         else if not returns the value NOT_FOUND which is less than 0.
*/
int index_search(int key, Index idx[], int idx_size, 
                    int data[], int data_size);

#endif
