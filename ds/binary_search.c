//binary search
#include <stdio.h>
#include <stdlib.h>

void bs(int,int,int,int *);
void bs(int term, int low, int high, int array[])
{
	int mid=(low+high)/2;
	
	if(high<low)
		printf("Term not found");
	else
	{
		if(term<array[mid])
			bs(term,low,mid-1,array);
		else if(term>array[mid])
			bs(term,mid+1,high,array);
		else
			printf("\nFound! Term index: %d", mid);
	
	}
		
}

int main()
{
	int array[30],i,term;
	
	for(i=0;i<30;++i)
		array[i]=2*i;
		
	printf("Enter term to search for: ");
	scanf("%d",&term);
	
	bs(term,0,29,array);
	
	return 0;
}
	