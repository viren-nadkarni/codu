//find gcd of two numbers
#include <stdio.h>

int gcd(int,int,int);
int gcd(int m,int n,int g)
{
	if(g==0)
		return 1;
		
	if(m%g==0 && n%g==0)
		return g;
	else
		return gcd(m,n,g-1);
		
}

int main()
{
	int m,n;
	
	printf("Enter two numbers: ");
	scanf("%d %d",&m,&n);
	
	printf("GCD is %d",gcd(m,n,n));
	
	return 0;
}