#include <stdbool.h>
#include <stdio.h>
#include "stack.h"


int top = -1;

int empty(void)
{
    if(top < 0)
        return true;

    return false;
}
int push(int new)
{
    if(top + 1 >= MAXSTACK)
        return FULL;
    
    stack[++top] = new;
    return OK;
}

int pop(void)
{
    return (stack[top--]);
}

