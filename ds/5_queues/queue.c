//FILE: queue.c
#include <stdlib.h>
#include "queue.h"

void insertq(struct queue * q, int num)
{
	q->items[++(q->rear)]=num;
}

int removeq(struct queue * q)
{
	if(sizeofq(q)!=0)
		return (q->items[(q->front)++]);
	else 
	{
		printf("\nQueue underflow\n");
		exit(0);
	}
}

int sizeofq(struct queue * q)
{
	return((q->rear)-(q->front)+1);
}
