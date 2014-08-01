#include <stdio.h>
#define left(i) (2*i)+1
#define right(i) (2*i)+2
#define parent(i) (i-1)/2

int heapSize,heapNum;

void print(int a[])
{
	int i;

	printf("\n");
	for(i=0;i<heapNum;i++)
		printf("%d ",a[i]);
}

void heapify(int a[], int i)
{
	int l=left(i),great;
	int r=right(i);
	
	if((a[l]>a[i]) && (l<heapSize))
		great=l;
	else
		great=i;

	if((a[r]>a[great]) && (r<heapSize))
		great=r;

	if(great!=i)
	{
		int temp=a[i];
		a[i]=a[great];
		a[great]=temp;
		heapify(a,great);
	}
}

void BuildMaxHeap(int a[])
{
	int i;
	for(i=(heapSize-1)/2;i>=0;i--)
		heapify(a,i);
}

void HeapSort(int a[])
{
	int i;
	BuildMaxHeap(a);
	for(i=(heapSize-1);i>=0;i--)
	{
		int temp=a[0];
		a[0]=a[heapSize-1];
		a[heapSize-1]=temp;
		heapSize=heapSize-1;
		heapify(a, 0);
	}
}

int main()
{
	int arr[64],i;
	
	printf("How many numbers? ");
	scanf("%d",&heapSize);
	heapNum=heapSize;
	
	printf("Enter them: ");
	for(i=0;i<heapNum;i++)
		scanf("%d",&arr[i]);
	
	HeapSort(arr);
	print(arr);
	printf("\n");
	
	return 0;
} 
