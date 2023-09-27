#ifndef ORDERED_LINEAR_SEARCH_H
#define ORDERED_LINEAR_SEARCH_H

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

#endif
