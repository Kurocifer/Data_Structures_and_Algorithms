/* sequential search */

int seq_search(int data[], int size, int key)
{
    int i;

    i = size - 1;

    for(i = size -1; i >= 0 && data[i] != key; i--)
        ;

    return i;
}

/* Average time complexitry O(n/2) where n is the size of array */