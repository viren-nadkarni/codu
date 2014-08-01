#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct node
{
	char name[32];
	struct node *next;
};
typedef struct node NODE;

int main()
{
	NODE *head,*tail,*t1,*t2,*p,*q;
	char mid[32];
	int ch,n,i;

	head=tail=t1=t2=p=q=NULL;
	int flag=0;

	printf("Enter names of soldiers in sequence. Enter 'X' when finished..\n");
	while(1)
	{
		scanf("%s",mid);
		
		if(strcmp(mid,"X")==0 || strcmp(mid,"x")==0)
			break;
		else		
		{
			if(head==NULL)
			{
				tail=(NODE*)malloc(sizeof(NODE));
				strcpy((tail->name),mid);
				tail->next=NULL;
				head=tail;
			}

			else
			{
				tail->next=(NODE *)malloc(sizeof(NODE));
				strcpy(tail->next->name,mid);
				tail->next->next=head;
				tail=tail->next;
			}
		}
	}	
	
	printf("\nThe soldiers are:");
	t1=head;

	while(t1!=t2)
	{
		printf("\n%s",t1->name);
		t1=t1->next;
		t2=head;
	}

	printf("\n\nWhat's the number? ");
	scanf("%d",&n);
	printf("\nSoldiers are eliminated in following order:");
	p=head;

	while(p->next!=p)
	{ 
		for(i=0;i<n-1;i++)
		{
			q=p;
			p=p->next;
		}           
		q->next=p->next;
		printf("\n%s",p->name);
		free(p);
		p=q->next;
	}

	printf("\n\nThe lucky soldier is %s!\n",p->name);

	return 0;
}

