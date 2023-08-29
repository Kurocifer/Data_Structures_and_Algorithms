#ifndef STACK_H
#define STACK_H

#define MAXSTACK 100
#define OK 0

typedef int item_type; /*item_type is to be changed to correspond to type to be stored in stack*/
typedef struct stack_type *Stack;

Stack make(void);
int empty(Stack s);
int push(Stack s, item_type new);
item_type pop(Stack s);
item_type top_of_stk(Stack s);

#endif
