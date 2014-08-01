//queues - circular (array)
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct queue
{
	int list[MAX];
	int front,rear;
	int full;
} Queue;

void insertq(Queue *,int);
int removeq(Queue *);

void insertq(Queue * q, int num)
{
	if((q->front==0 && q->rear==MAX-1) || (q->front=(q->rear)+1))
	{
		printf("Overflow\n");
		exit(1);
	}
	q->list[(q->rear)++]=num;
	
	if(q->rear==MAX)
		q->rear=0;
		
	if(q->front==q->rear)
		q->full=1;
}

int removeq(Queue * q)
{
	int tmp;
	
	if(q->rear==q->front && q->full!=1)
	{
		printf("Underflow\n");
		exit(1);
	}
	tmp=q->list[(q->front)];
	
	if(q->front+1==MAX)
		q->front=0;
	else 
		(q->front)++;
	
	return (tmp);
	
}
int main()
{
	Queue q;
	q.front=q.rear=0;
	
	char inp;
	int digit;
	
	while(1)
	{
		scanf("%c",&inp);
		if(inp=='q')
			break;
		else if(inp=='i')
		{
			scanf("%d",&digit);
			insertq(&q,digit);
		}
		else if(inp=='r')
		{
			printf("\n%d",removeq(&q));
		}
	}
	
	return 0;
}
	

