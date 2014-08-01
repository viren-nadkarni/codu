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

void insertFront(Node ** start, int x_deg, int y_deg, int z_deg, int coeff)
{
	Node *n;
	n=getnode();
	
	n->x_deg=x_deg;
	n->y_deg=y_deg;
	n->z_deg=z_deg;
	n->coeff=coeff;
	
	if(*start==NULL)
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

void insertEnd(Node ** start, int x_deg, int y_deg, int z_deg, int coeff)
{
	Node *n, *tmp;
	n=getnode();
	
	n->x_deg=x_deg;
	n->y_deg=y_deg;
	n->z_deg=z_deg;
	n->coeff=coeff;
	
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
	
	if(*start==NULL)
	{
		printf("_____underflow\n");
		exit(1);
	}
	
	tmp=(*start)->next;
	
	freenode(*start);
	*start=tmp;
}

void removeEnd(Node **start)
{
	Node *tmp;
		
	if(*start==NULL)
	{
		printf("_____underflow\n");
		exit(1);
	}
	
	tmp=*start;
	
	while(((tmp->next)->next)!=NULL)
		tmp=tmp->next;
	
	freenode(tmp->next);
	(tmp->next)=NULL;
}

void printEqn(Node ** start)
{
	Node * tmp;
	tmp=*start;
	while(tmp!=NULL)
	{
		printf(" %d(x^%d)(y^%d)(z^%d) +",tmp->coeff,tmp->x_deg,tmp->y_deg,tmp->z_deg);
		tmp=tmp->next;
	}
	printf(" 0\n");
}


//remove node at given location
void removeNode(Node ** start, int which, int total_nodes)
{
	int i=0;
	Node *tmp, *n;
	tmp=*start;
	n=NULL;
	
	if(tmp==NULL)
	{
		printf("_____empty\n");
		exit(1);
	}
	else
	{
		if(which==0 && total_nodes==1)
			removeFront(start);
		else if(which==1 && total_nodes==2)
		{
			freenode(tmp->next);
			tmp->next=NULL;
		}
		else
		{
			while(i<which)
			{
				++i;
				if(i+1>=total_nodes)
				{
					printf("_____invalid reference\n");
					exit(1);
				}
				tmp=tmp->next;
			}
				
			n=(tmp->next)->next;
			freenode(tmp->next);
			tmp->next=n;
		}		
	}
}
