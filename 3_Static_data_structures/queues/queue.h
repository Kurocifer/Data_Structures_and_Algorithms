#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

#define MAXQUEUE 100
#define OK 0
#define QUEUE_FULL -1
#define QUEUE_EMPTY -2

typedef struct queue_type *Queue;
typedef int item_type;  /*item_type is to be changed to correspond to type to be stored in queue*/

/* functions */
Queue qcreate(void);
item_type cir_addq(Queue q, int element);
item_type cir_delq(Queue q);
item_type cir_empty(Queue q);
item_type queuesize(Queue q);
bool qempty(Queue q);

#endif

