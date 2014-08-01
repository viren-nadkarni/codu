#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define MAXNUM 64

int main()
{
	int n, i, j, max, tmp, digits=0;
	Node * q[10], *list;
	list=NULL;
	
	for(i=0;i<10;++i)
		q[i]=NULL;
	
	printf("How many items? ");
	scanf("%d",&n);
	printf("List them: ");
	for(i=0;i<n;++i)
	{
		scanf("%d",&tmp);
		insertEnd(&list,tmp);
	}
	
	max=valueFront(&list);
	
	for(i=0;i<n;++i)
	{
		tmp=returnFront(&list);
		if(tmp>max)
			max=tmp;	
		insertEnd(&list,tmp);
	}
	
	while(max>0)
	{
		digits++;
		max/=10;
	}
		
	for(i=0;i<digits;++i)
	{
		for(j=0;j<n;++j)
		{
			tmp=returnFront(&list);
			max=tmp/pow(10,i);
			max%=10;
			insertEnd(&q[max],tmp);
		}
		for(j=0;j<10;++j)
		{
			while(q[j]!=NULL)
			{
				tmp=returnFront(&q[j]);
				insertEnd(&list,tmp);
				
			}
		}	
	}	
		
	printList(list);
	return 0;
}
