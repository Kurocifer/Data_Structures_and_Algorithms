#ifndef SEQ_SEARCH_H
#define SEQ_SEARCH_H

#define NOT_FOUND -2

typedef struct index Index;
/**
 * seq_search: search a table of records for a particular key.
 * 
 * data[]- array to be searched.
 * size- size of the array to be searched.
 * key- item searched for.
 * 
 * Return- Returns the array index of the key else if not found returns -1.
*/
int seq_search(int data[], int size, int key);

/**
 * seq_search2: An ordered linear search through the array.
 * 
 * data[]- table(array) to be searched
 * size- size of the array to be searched
 * key- item searched for.
 * 
 * Return- If it finds the key, it returns it's index else returns
 *         the value NOT_FOUND which is less than 0.
*/
int seq_search2(int data[], int size, int key);

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
