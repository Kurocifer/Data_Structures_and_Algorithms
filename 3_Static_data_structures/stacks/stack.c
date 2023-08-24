#include <stdbool.h>
#include <stdio.h>
#include "stack.h"


int top = -1;
int stack[MAXSTACK];

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
    
    stack[++item] = new;
    return OK;
}

int pop(void)
{
    return (stack[top--]);
}

