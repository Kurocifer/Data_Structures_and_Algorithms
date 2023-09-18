/* index sequential search algo */
#include "seq_search.h"

struct index {
    int val;    /* The key value each element represent */
    int slot;   /* The index that points into the main table */
};

int index_search(int key, Index idx[], int idx_size, 
                    int data[], int data_size) 
{
    int i, size, key_index;

    if(key < data[0])       /* Initial test for non existing key */
        return NOT_FOUND;

    /* Scan index for key */
    for(i = 0; i < idx_size && key >= idx[i + 1].val; i++)
        ;

    /* determine segment size */
    if(i == idx_size)
        size = size - idx[i].slot;
    else
        size = idx[i + 1].slot - idx[i].slot;
    
    /* scan data table */
    key_index = seq_search2(data[idx[i].slot], size; key);

    if(key_index >= 0)
        key_index += idx[i].slot;
    
    return key_index;
}