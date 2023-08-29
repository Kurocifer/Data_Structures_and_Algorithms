#define MAXQUEUE 100
#define NEXT(x) ((x + 1) % MAXQUEUE)
#define OK 0
#define QUEUE_FULL -1
#define QUEUE_EMPTY -2

int queue[MAXQUEUE];
int rear = 0, front = 0;

int cir_addq(int element)
{
	if( NEXT(rear) == front )
		return (OUT_OF_SPACE);
	rear = NEXT(rear);
	queue[rear] = element;
	return (OK);
}

int cir_delq()
{
	rear = NEXT(front);
	return (queue[front]);
}

int cir_empty()
{
	if( front == rear )
		return(QUEUE_EMPTY);
	return (OK);
}

int queuesize()
{
	return ( ((front - rear) + MAXQUEUE) % MAXQUEUE);
}

