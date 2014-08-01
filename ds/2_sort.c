#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int itemnos(int);
int itemnos(int x)
{
	int n;
	switch(x)
	{
		case 0:	n=10;
			break;		
		case 1:	n=50;
			break;
		case 2:	n=100;
			break;
		case 3:	n=500;
			break;
		case 4:	n=1000;
			break;
		case 5:	n=5000;
			break;
		case 6:	n=10000;
			break;
		case 7:	n=20000;
			break;
		case 8: n=40000;
			break;
		case 9: n=0;
			break;
	}
	return (n);
}

//initializes array
void initarray(int *,int);
void initarray(int inp[],int n)
{
	int i=0;
	for(i=0;i<1000;++i)
		//inp[i]=rand()%100;	//average case - random values in array
		inp[i]=1000-i;		//worst case - values reverse sorted
}

//bubble sort function
void bubble(volatile int *, volatile int);
void bubble(volatile int inp[], volatile int n)
{
	volatile int v=0,tmp,swapped=1;
	
	while(swapped==1)
	{
		swapped=0;
		for(v=0;v<n-1;++v)
		{
			if(inp[v]>inp[v+1])
			{
				tmp=inp[v];
				inp[v]=inp[v+1];
				inp[v+1]=tmp;
				swapped=1;
			}
		}
	}
}


//insertion sort function
/* pseudocode
for i=0;i<n
	j=i
	while j>0 and A[j]<A[j-1]
		swap(A[j],A[j-1])
		j=j-1
*/
void insertion(volatile int *, volatile int);
void insertion(volatile int inp[], volatile int n)
{
	int i,j,hand;
	
	for(i=1;i<n;i++)
	{
		hand=inp[i];
		j = i-1;
		while(hand<inp[j] && j>=0)
		{
			inp[j+1] = inp[j];
			j = j-1;
		}
		inp[j+1] = hand;
	}
}

//selection sort
/* pseudocode
for i=0;i<n
	j=i=k
	while k<n
		if A[k]<A[j]
			j=k
		k=k+1
	swap(A[j],A[k])
	
*/
void selection(volatile int *, volatile int);
void selection(volatile int inp[], volatile int n)
{
	int i,j,k,tmp;
	
	for(i=0;i<n;i++)
	{
		j=k=i;
		while(k<n)
		{
			if(inp[k]<inp[j])
				j=k;
			k++;
		}
		tmp=inp[j];
		inp[j]=inp[i];
		inp[i]=tmp;
	}
}


int main()
{
	int inp[40000];
	int i=0,j=0,n=10,k=0;
	clock_t begin=0,end=0;
	double bubbletime[9],insertiontime[9],selectiontime[9];
	
	printf("Timing sort algorithms, please wait...\n");
	
	for(i=0;i<9;++i)
	{
		k=0;
		initarray(inp,n);
		begin=clock();		
		do
		{
			bubble(inp,n);		
			end=clock();
			k++;
		} while((double)(end-begin)==0);
		bubbletime[i]=(double)(end-begin)/k;		
	
		k=0;
		initarray(inp,n);
		begin=clock();	
		do
		{
			insertion(inp,n);
			end=clock();	
			k++;
		} while((double)(end-begin)==0);
		insertiontime[i]=(double)(end-begin)/k;
		
		k=0;
		initarray(inp,n);
		begin=clock();	
		do
		{
			selection(inp,n);
			end=clock();	
			k++;
		} while((double)(end-begin)==0);
		selectiontime[i]=(double)(end-begin)/k;
		
		n=itemnos(i+1);
	}
		
	printf("\n\t\t\t   Time\n");
	printf("No. of items\t     Bubble\t   Insertion\t   Selection\n");
	for(i=0;i<9;++i)
		printf("%5d \t\t%10.3f \t%10.3f \t%10.3f\n",itemnos(i),bubbletime[i],insertiontime[i],selectiontime[i]);
	
	return 0;
}
	
	
