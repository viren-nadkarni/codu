//polynomial
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int coeff,degree;
	struct node * next;
} Node;


//backstage functions
Node * getnode();
void freenode(Node *);

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


//list operations
void insertList(Node *,int,int);

void insertList(Node * e, int c, int d)
{
	Node * tmp, *tmp2;
	tmp=getnode();
	
	if((e)==NULL)
		e=tmp;
	else
	{
		tmp2=e;
		while(tmp2!=NULL)
			tmp2=tmp2->next;
		tmp2->next=tmp;
	}
	tmp->coeff=c;
	tmp->degree=d;
	
	
}


//-------------------------------//
int main()
{
	Node * e1, * e2, * e3, * tmp1, *tmp2;
	e1=e2=e3=NULL;
	
	int n,i,c,d;
	
	printf("No. of terms: ");
	scanf("%d",&n);	
	
	printf("Eqn 1:");
	printf("\nEnter terms (coeff  degree):\n");
	for(i=0;i<n;++i)
	{
		int c,d;
		
		printf("\n  %d:: ",i+1);
		scanf("%d %d",&c,&d);
		
		insertList(e1,c,d);
	}
	
	
	printf("\nEnter terms (coeff  degree):\n");
	for(i=0;i<n;++i)
	{
		int c,d;
		
		printf("\n  %d:: ",i+1);
		scanf("%d %d",&c,&d);
		
		insertList(e2,c,d);
	}
	
	tmp1=e1;
	
	
	while(tmp1!=NULL)
	{
		tmp2=e2;
		int g=0;
		while(tmp2!=NULL)
		{
			if(tmp1->degree==tmp2->degree)
				g+=tmp2->degree;
			
			tmp2=tmp2->next;
		}
	
		insertList(e3,g+(tmp1->coeff),tmp1->degree);
		tmp1=tmp1->next;
	}
	
	
	tmp1=e3;
	printf("\n\nSum is:\n");
	while(tmp1!=NULL)
	{
		printf("  %d %d\n",tmp1->coeff,tmp1->degree);
		tmp1=tmp1->next;
	}
	
	return 0;
}


