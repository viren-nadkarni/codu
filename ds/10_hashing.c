#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *next;
} Node;

int findKey(int);
int findKey(int t)
{
	int key;
	key=t%10;

	return(key);
}

int main()
{
	int a[100],i,bucket,key,n,num,foundFlag=0;
	Node *front[10],*rear[10],*tmp1,*tmp2;

	printf("How many numbers? ");
	scanf("%d",&n);
	printf("Enter them: ");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);

	for(i=0; i<10; i++)
		front[i]=NULL;

	for(i=0; i<n; i++)
	{
		bucket=a[i];
		key=findKey(bucket);
		tmp1=(Node *)malloc(sizeof(Node));
		tmp1->data=a[i];
		tmp1->next=NULL;

		if(front[key]==NULL)
		{
			front[key]=tmp1;
			rear[key]=tmp1;
		}
		else
		{
			rear[key]->next=tmp1;
			rear[key]=tmp1;
		}
	}

	printf("Search for? ");
	scanf("%d",&num);

	key=findKey(num);

	tmp2=front[key];
	while(tmp2!=NULL)
	{
		if (tmp2->data==num)
			foundFlag=1;
		tmp2=tmp2->next;
	}

	if (foundFlag)
		printf("Found in bucket %d\n",key);
	else
		printf("Not found\n");
	return 0;
}


 
