#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int doXor(char *, int diff);
int doXor(char dat[], int diff)
{
	int len = strlen(dat), result = dat[diff - 2] - 48, i, j = 0, flag = 0;
	
	printf("\n_for P%d", diff - 1);
	for( i = diff; i < len; i+=diff )
	{
		for( j = 0; j < diff - 1; ++j)
		{
			result = result ^ (dat[i + j] - 48);
			flag = 1;
			printf("\n_checking bit %d", i+j);
		}
		i += j - 1 ;
	}
	printf("_result is %d", !result);
	if(!flag)
		return result;
	else return !(result);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		printf("No argument specified\n");
		exit(1);
	}
	
	int l1, l2, i, j, tmp;
	l1 = strlen(argv[1]);
	
	for(i = 0; i < 16; ++i)
	{
		tmp = pow(2, i);
		
		if( i == 15 )
			exit(2);
		
		if( l1 + i + 1 <= tmp )
		{
			l2 = i;
			break;
		}
	}
	
	int *p, index = 0;
	p = (int *)malloc( sizeof(int) * (l1 + l2) );
	for( i = 0; i < l1 + l2 ; ++i)
	{
		if( i == 0 || i == 1 || i == 3 || i == 7 || i == 15 || i == 31 )
		{
			p[i] = doXor(argv[1], i + 2);
		}
		else
			p[i] = argv[1][index++] - 48;
	}
	
	printf("\n");
	for(i = 0; i < l1 + l2; ++i)
	{
		printf("%d", p[i]);
		if( (i + 1) % 4 == 0 )
			printf(" ");
	}
	printf("\n");
		
	return EXIT_SUCCESS;
}

/*
$ gcc hamming_code.c
$ ./a.out 00110011
1000 0111 0011 
$ 

*/
