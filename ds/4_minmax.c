#include <stdio.h>
#define FUNC <

int minmax(int *, int);
int minmax(int * list, int n)
{
	int a,b;

	if(n==2)
		if(list[0] FUNC list[1])
			return list[0];
		else 
			return list[1];

	a=minmax(list,n/2);
	b=minmax(list+(n/2),n/2);

	if(a FUNC b)
		return (a);
	else 
		return (b);
}

int main()
{
	int list[20]={1,4,7,3,9,0,8,3,11,2,2,16,5,8,10,9,14,17,2,10};

	printf("%d\n",minmax(list, 20));
	
	return 0;
}
