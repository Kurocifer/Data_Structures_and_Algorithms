#ifndef BIN_SEARCH_H
#define BIN_SEARCH_H

/**
 * bin_search: Searches an array sorted in asscending order for 
 *             a value.
 * 
 * data[]: array searched;
 * size: size of array searched;
 * key: item searched for;
 * 
 * Return- If it findS the key it returns it's index in the data array
 *         else if not returns the value NOT_FOUND which is less than 0.
*/
int bin_search(int data[], int size, int key);
int bin_search2(int data[], int size, int key);

#endif 