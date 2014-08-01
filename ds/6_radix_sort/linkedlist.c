#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node * getnode()
{
	Node *tmp;
	tmp=(Node *)malloc(sizeof(Node));
	tmp->next=NULL;
	return tmp;
}

void freenode(Node * tmp)
{
	free(tmp);
}	

void insertFront(Node ** start, int value)
{
	Node *n;
	n=getnode();
	n->data=value;
	if(*start==NULL)		//List is empty
	{
		*start=n;
		n->next=NULL;
	}
	else
	{
		n->next=*start;
		*start=n;
	}
	
}

void insertEnd(Node ** start, int value)
{
	Node *n, *tmp;
	n=getnode();
	n->data=value;
	if(*start!=NULL)
	{
		tmp=*start;

		while((tmp->next)!=NULL)
			tmp=tmp->next;
		
		tmp->next=n;
	}
	else
	{
		*start=n;
		n->next=NULL;
	}
	
}

void removeFront(Node **start)
{
	Node *tmp;
	tmp=(*start)->next;
	
	if(*start==NULL)
	{
		printf("_underflow\n");
		exit(1);
	}
	
	freenode(*start);
	*start=tmp;
}

void removeEnd(Node **start)
{
	Node *tmp;
	tmp=*start;
	
	while(((tmp->next)->next)!=NULL)
		tmp=tmp->next;
	
	freenode(tmp->next);
	(tmp->next)=NULL;
}

void printList(Node *start)
{
	printf("\n");
	while(start!=NULL)
	{
		printf("%d ",start->data);
		start=start->next;
	}
	printf("\n");
}

int returnFront(Node **start)
{
	Node *tmp;
	int val;
	
	if((*start)==NULL)
	{
		printf("_underflow\n");
		exit(1);
	}
	
	tmp=(*start)->next;
	val=(*start)->data;
	freenode(*start);
	*start=tmp;
	
	return val;
}
	
int valueFront(Node **start)
{
	int tmp;
	tmp=returnFront(start);
	insertFront(start,tmp);
	return tmp;
}
