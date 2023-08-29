#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
/*NEXT: helps so that queue should rap arround when
		q->rear == MAXQUEUE -1*/
#define NEXT(x) ((x + 1) % MAXQUEUE)

struct queue_type {
	item_type queue[MAXQUEUE];
	int rear;
	int front;
};

void qterminate(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(EXIT_FAILURE);

}

Queue qcreate(void)
{	
	Queue q = malloc(sizeof(struct queue_type));

	if (!q)
		qterminate("Error: Unable to create queue.");
	
	q->front = q->rear = 0;

	return q;
}

item_type cir_addq(Queue q, int element)
{
	if( NEXT(q->rear) == q->front )
		return (QUEUE_FULL);
	q->rear = NEXT(q->rear);
	q->queue[q->rear] = element;
	return (OK);
}

item_type cir_delq(Queue q)
{
	if(qempty(q))
		return 0; 
	q->front = NEXT(q->front);
	return (q->queue[q->front]);
}

item_type cir_empty(Queue q)
{
	if( q->front == q->rear )
		return(QUEUE_EMPTY);
	return (OK);
}

item_type queuesize(Queue q)
{
	return ( ((q->front - q->rear) + MAXQUEUE) % MAXQUEUE);
}

bool qempty(Queue q)
{
	if(q->front == q->rear)
		return true;
	
	return false;
}

