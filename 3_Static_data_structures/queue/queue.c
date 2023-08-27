#define OK 0
#define QUEUE_EMPTY -1 
#define OUT_OF_SPACE -2
#define MAXQUEUE 100

int queue[MAXQUEUE];
int rear = -1, front = -1;

int addqueue(int element)
{
	if( (rear + 1) >= MAXQUEUE )
		return (OUT_OF_SPACE);
	queue[++rear] = element;
	return (OK);
}

int delqueue()
{
	return ( queue[++front] );
}

int q_empty()
{
	if( front == rear )
		return(QUEUE_EMPTY);
	return (OK);
}

int queuesize()
{
	return ( front - rear );
}

