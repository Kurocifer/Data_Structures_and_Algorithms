#ifndef SEQ_SEARCH_H
#define SEQ_SEARCH_H

/**
 * seq_search: search a table of records for a particular key.
 * 
 * data[]- table(array) to be searched
 * size- size of the table(array)
 * key- item searched for.
 * 
 * Return- Returns the array index of the key else if not found returns -1.
*/
int seq_search(int data[], int size, int key);

/**
 * seq_search2: An ordered linear search through the array.
 * 
 * data[]- table(array) to be searched
 * size- size of the table(array)
 * key- item searched for.
 * 
 * Return- Returns the array index of the key else if not found returns -1.
*/
int seq_search2(int data[], int size, int key);

#endif
