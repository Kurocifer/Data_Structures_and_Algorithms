#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

#define FULL 1
#define MAXSTACK 100

struct stack_type {
    item_type content[MAXSTACK];
    int top;
};

void terminate(char *message)
{
    fprintf(stderr, "%s", message);
    exit(EXIT_FAILURE);
}

Stack make(void)
{
    Stack s = malloc(sizeof(struct stack_type));

    if(!s)
        terminate("Error: stack could not be created\n");

    s->top = -1;

    return s;
}

int empty(Stack s)
{
    if(s->top < 0)
        return true;

    return false;
}

int push(Stack s, int new)
{
    if(s->top + 1 >= MAXSTACK)
        return FULL;
    
    s->content[++(s->top)] = new;
    return OK;
}

item_type pop(Stack s)
{
    return (s->content[s->top--]);
}

item_type top_of_stack(Stack s)
{
    return (s->content[s->top]);
}


