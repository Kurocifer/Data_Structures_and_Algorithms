#ifndef FIB_SRCH_H
#define FIB_SRCH_H

/**
 * fib_search: Serches for an element in an array using the 
 *              fibonacci search algorithm.
 * 
 * data[]: array searched;
 * size: size of array searched;
 * key: item searched for;
 * 
 * Return- If it findS the key it returns it's index in the data array
 *         else if not returns the value NOT_FOUND which is less than 0.
*/
int fib_srch(int data[], int size, int key);

#endif