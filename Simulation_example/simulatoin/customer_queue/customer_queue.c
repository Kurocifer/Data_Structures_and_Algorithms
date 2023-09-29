/* routines controlling the customer's queue */
#include <stdlib.h>
#include "customer_queue.h"

struct customer {
    int time_arrived;               /* customer arrival time */
    int time_left;                 /* customer departure time */
    int trans_duration_time;      /* customer transaction duration time */
    struct customer *next;        /* Pointer to the next structure */
};

struct customer *head = NULL;
struct customer *tail = NULL;

int duration()
{
    float p;

    p = (float) rand() / 3276.0;

    if(p <= 0.30)                       /* 30% chance-type 1 */
        return 6;
    else if(p > 0.30 &&  p <= 0.80)     /*50% chance-type 2 */
        return 9;
    else if(p > 0.80 && p <= .95)       /* 15% chance-type 3 */
        return 11;
    else                                /* 5% chance-type 4 */
        return 16;
}

int add_customer_q(int time_arrived)
{
    struct customer *new;

    new = malloc(sizeof(struct customer));
    if(new == NULL)
        return QUEUE_FULL;
    
    new->next = NULL;
    new->time_arrived = time_arrived;
    new->trans_duration_time = duration();

    if(tail == NULL) {   /* First customer */
        tail = new;
        head = tail;
    }
    else {
        tail->next = new;
        tail = new;
    }

    return OK;
}

int del_customer_q(int *trans_time, int *arrival_time)
{
    struct customer *temp;

    temp = head;
    
    if(head == tail)     /* Last customer in queue */
        head = tail = NULL;
    else
        head = head->next;
    
    *arrival_time = temp->time_arrived;
    *trans_time = temp->trans_duration_time;
    free(temp);

    return OK;
}

int queue_empty()
{
    if(head == NULL)
        return QUEUE_FULL;
    return
        OK;   
}


