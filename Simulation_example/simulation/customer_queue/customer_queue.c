/* routines controlling the customer's queue */
#include <stdlib.h>
#include <stdio.h>
#include "customer_queue.h"

struct customer {
    int time_arrived;               /* customer arrival time */
    int time_left;                 /* customer departure time */
    int trans_duration_time;      /* customer transaction duration time */
    struct customer *next;        /* Pointer to the next structure */
};

struct customer *head = NULL;
struct customer *tail = NULL;

/**
 * duration: Generates a random duration time for customers added
 *           to the queue.
 * 
 * Return: The duration time.
*/
int duration()
{
    float p;

    p = (float) rand() / 3276.0;

    if(p <= 0.30) {
        printf("\nReturning 6\n");
        return 6;
    }                      /* 30% chance-type 1 */
    else if(p > 0.30 &&  p <= 0.80) {
        printf("\nReturning 9\n");
        return 9;
    }    /* 50% chance-type 2 */
    else if(p > 0.80 && p <= .95) {
    printf("\nReturning 11\n");
    return 11;
    }      /* 15% chance-type */
    else   {
        printf("\nReturning 16\n");
        return 16;
    }                             /* 5% chance-type */
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
        return QUEUE_EMPTY;
    return
        OK;   
}


