#include <stdio.h>
#include <stdlib.h>
#define NUM 4

void mergesort(int *,int);
void merge(int *,int,int *,int);

void mergesort(int inp[],int n)
{
	if(n>1)
	{
		mergesort(inp,n/2);
		mergesort(inp+n/2,n-n/2);
		merge(inp,n/2,inp+n/2,n-n/2);	
	}
	
}

void merge(int a[],int na,int b[],int nb)
{
	int tmp[na],i,j,k=0;
	
	for(i=0;i<na;++i)
		tmp[i]=a[i];
	
	i=na;
	j=nb;
	
	while(i>0 || j>0)
	{
		if(i==0)
			a[k++]=b[--j];
		else if(j==0)
			a[k++]=tmp[--i];
		else
		{
			if(tmp[i-1]<b[j-1])
				a[k++]=tmp[--i];
			else 
				a[k++]=b[--j];
		}
	}
	
}

int main()
{
	int inp[NUM],i,n=NUM;
	
	for(i=0;i<n;++i)
		inp[i]=rand()%100;
	
	printf("Unsorted array: ");
	for(i=0;i<n;++i)
		printf("%2d ",inp[i]);
	
	mergesort(inp,n);
	
	printf("\nSorted array:   ");
	for(i=0;i<n;++i)
		printf("%2d ",inp[i]);
	
	return 0;
}
