//doubly linked list
#include <stdio.h>

struct node 
{
	int data;
	struct node * next, * prev;
} Node;

//backstage functions
Node * getnode();
void freenode(Node *);

Node * getnode()
{
	Node *tmp;
	tmp=(Node *)malloc(sizeof(Node));
	tmp->next=tmp->prev=NULL;
	return tmp;
}
void freenode(Node * tmp)
{
	free(tmp);
}	

//operations
void insertDLL(Node **,int,int);
void insertDLL(Node ** list, int pos, int data)
{
	int i;
	Node * start, * tmpnode;
	start=*list;
	
	tmpnode=getnode();
	tmpnode->data=data;
	
	if(start==NULL)
	{
		*list=tmpnode;
		return;
	}
	
	if(pos==0)
	{
		tmpnode->next=*list;
		*list->prev=tmpnode;
		
		*tmp=tmpnode;
	}
	else
	{
		i=0;
		
		while(start->next!=NULL && i<pos)
		{
			i++;
			start=start->next;
		}
		
		if(start->next==NULL)
		{
			tmpnode->prev=start;
			start->next=tmpnode;
		}
		else
		{
			Node *a,*c;
			
			a=start;
			c=start->next;
			
			start->next=tmpnode;
			tmpnode->next=c;
			c->prev=tmpnode;
			tmpnode->prev=a;
			
		}
	}
}


	
	

