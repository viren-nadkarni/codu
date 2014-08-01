//FILE: main.c
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define NUMOFCUST 6
#define TIMEDURATION 15

int min(struct queue *, struct queue *);
int shortline(struct queue *, struct queue *, struct queue *, struct queue *);

int min(struct queue * a, struct queue * b)
{
	if(sizeofq(a)<=sizeofq(b))
		return (1);
	else
		return(0);
}

int shortline(struct queue * a, struct queue * b, struct queue * c, struct queue * d)
{
	if(min(a,b) && min(a,c) && min(a,d))
		return (1);
	else if(min(b,a) && min(b,c) && min(b,d))
		return (2);
	else if(min(c,a) && min(c,b) && min(c,d))
		return (3);
	else
		return (4);
}

int main()
{
	int time,cust,i,k;
	float avg_time_spent=0;
	struct queue A,B,C,D;
	A.front=B.front=C.front=D.front=0;
	A.rear=B.rear=C.rear=D.rear=-1;
	
	int entry_time[NUMOFCUST]={0,0,1,0,1,4};
	int duration[NUMOFCUST] = {2,5,7,6,4,4};
	int time_spent[NUMOFCUST];
	
	printf("time\t tellers\n\tA  B  C  D\n");
	
	for(time=0;time<TIMEDURATION;++time)
	{
		for(cust=0;cust<NUMOFCUST;++cust)
		{
			if(entry_time[cust]==time)
			{
				switch(shortline(&A,&B,&C,&D))
				{
					case 1:
						time_spent[cust]=duration[cust]+sizeofq(&A);
						for(k=0;k<duration[cust];++k)
							insertq(&A,cust+1);
						break;
					case 2:
						time_spent[cust]=duration[cust]+sizeofq(&B);
						for(k=0;k<duration[cust];++k)
							insertq(&B,cust+1);
						break;
					case 3:
						time_spent[cust]=duration[cust]+sizeofq(&C);
						for(k=0;k<duration[cust];++k)
							insertq(&C,cust+1);
						break;
					default:
						time_spent[cust]=duration[cust]+sizeofq(&D);
						for(k=0;k<duration[cust];++k)
							insertq(&D,cust+1);
						break;
				}
			}			
		}
		
		printf("\n%2d\t",time);
		
		if(sizeofq(&A)!=0)
			printf("%d  ",removeq(&A));
		else printf("-  ");
			
		if(sizeofq(&B)!=0)
			printf("%d  ",removeq(&B));
		else printf("-  ");
			
		if(sizeofq(&C)!=0)
			printf("%d  ",removeq(&C));
		else printf("-  ");
			
		if(sizeofq(&D)!=0)
			printf("%d ",removeq(&D));
		else printf("-  ");		
	}
	
	for(i=0;i<NUMOFCUST;i++)
	{	
		printf("\nCustomer %d spends %d min(s)",i+1,time_spent[i]);
		avg_time_spent+=time_spent[i];
	}
	avg_time_spent/=6;
	
	printf("\nAn average customer spends %.2f min(s) in the bank\n",avg_time_spent);
	
	return 0;
}
