//tower of hanoi
#include <stdio.h>
#include <stdlib.h>

void hanoi(int,char,char,char);
void hanoi(int n, char source, char aux, char dest)
{
	if(n==1)
		printf("Move peg from %c to %c\n",source,dest);
	else
	{
		hanoi(n-1,source,dest,aux);
		printf("Move peg from %c to %c\n",source,dest);
		hanoi(n-1,aux,source,dest);
	}
}

int main()
{
	int n;
	
	printf("How many pegs? ");
	scanf("%d",&n);
	
	hanoi(n,'A','B','C');
	
	return 0;
}
