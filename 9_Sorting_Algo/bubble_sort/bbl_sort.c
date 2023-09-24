/* implementation of the bubble sort algorithm */
#include "bbl_sort.h"

void bbl_sort(int data[], int no_elems)
{
    int temp, top, flag, i;

    top = no_elems;

    do {
        flag = 0;
        top--;
        
        for(i = 0; i < top; i++) {
            if(data[i] > data[i + 1]) {
                temp = data[i];
                data[i] = data[i + 1];
                data[i + 1] = temp;
                flag++;
            }
        }
    }while(flag > 0);
}