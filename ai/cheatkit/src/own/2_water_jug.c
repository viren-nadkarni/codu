/* 
 * File:   main.c
 * Author: viren
 *
 * Created on 17 April 2013, 14:12
 */

#include <stdio.h>
#include <stdlib.h>

/*
 * 
 */

int main(int argc, char * argv[])
{
	int max1, max2, v, a[]={0, 0, 0}, t;
	
	printf("Max capacity of jug 1: ");
	scanf("%d",&max1);
	
	printf("Max capacity of jug 2: ");
	scanf("%d",&max2);
	
	printf("Quantity to be measured: ");
	scanf("%d",&v);
	
	printf("%d\t%d\n", a[0], a[1]);
	
	while(1)
	{
		a[1] = a[1] + max2;
		
		if(a[1] > max2)
			a[1] = max2;

		printf("%d\t%d\n", a[0], a[1]);
		
		t = a[0];
		a[0] = a[1] + a[0];
		
		if(a[0] > max1)
			a[0] = max1;

		a[1] = a[1] - (max1 - t);
		
		if(a[1] < 0)
			a[1] = 0;
		
		printf("%d\t%d\n", a[0], a[1]);
		
		if(a[0] == v)
			break;
		
		if(a[0] == max1)
		{
			a[0] = 0;
			a[0] = a[1];
			a[1] = 0;
			
			printf("%d\t%d\n", a[0], a[1]);
			
			if(a[0] == v)
				break;
		}
	}
	
	printf("Success");
	
	return EXIT_SUCCESS;
}
