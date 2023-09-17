/* sequential search */

/**
 * seq_search: search a table of records for a particular key.
 * 
 * data[]- table(array) to be searched
 * size- size of the table(array)
 * key- item searched for.
 * 
 * Return- Returns the array index of the key else if not found returns -1.
*/
int seq_search(int data[], int size, int key)
{
    int i;

    i = size - 1;

    for(i = size -1; i >= 0 && data[i] != key; i--)
        ;
    
    return i;
}

/* time complexitry O(n/2)*/