/* Fibonacci search algo */
#include "fib_srch.h"

#define NOT_FOUND -1

int fibnum(int num)
{
    int i, p, q, tmp;

    if(num == 0)
        return 0;
    if(num == 1)
        return 1;
    
    p = 0;
    q = 1; 
    for (i = 1; p + q <= num; i++) {
        tmp = q;
        q += p;
        p = tmp;
    }

    return i;
}

int fib_srch(int data[], int size, int key)
{
    int tmp, index, adj, fmin2, fmin3;

    tmp = fibnum(size);
    adj = size - fibnum(tmp);
    index = fibnum(tmp - 1);
    fmin2 = fibnum(tmp - 2);
    fmin3 = fibnum(tmp -3);

    if(key > data[index])   /* adj for size != fib number */
        index = index + adj;
    
    while(index >= 0 && index < size) {
        if(key == data[index])
            return index;
        else if(key < data[index]) {
            index = index - fmin3;
            tmp = fmin2;
            fmin2 = fmin3;
            fmin3 = tmp -fmin3;
        }
        else {
            index = index + fmin3;
            fmin2 -= fmin3;
            fmin3 -= fmin2;
        }
    }

    return NOT_FOUND;
}