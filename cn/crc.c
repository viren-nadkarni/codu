#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 16

enum boolean{ false, true };

int *doXor(int *, int *, int, int *);
int *doXor(int p1[], int p2[], int n, int res[])
{
	int i = 0;
	
	for(i = 0; i < n; ++i)
		res[i] = p1[i] ^ p2[i];
}

int main(int argc, char *argv[]) 
{
	if(argc < 2)
	{
		printf("Usage: crc <word to encode> <generator polynomial>");
		printf("\nNo argument specified\n");
	
		exit(1);
	}
	
	int inp_len, poly_len, inp[MAX], poly[MAX];
	int i, j, k;
	
	inp_len = strlen(argv[1]);
	poly_len = strlen(argv[2]);
	
	for(i = 0; i < inp_len; ++i)
		inp[i] = ( argv[1][i] == '0' ) ? 0 : 1;
		
	for(i = 0; i < poly_len - 1; ++i)
		inp[inp_len + i] = 0;
	inp_len += poly_len - 1;
	
	
	for(i = 0; i < poly_len; ++i)
		poly[i] = ( argv[2][i] == '0' ) ? 0 : 1;
	
	int res[MAX] = {0}, inp_index = 0;
	
	for(k = 0; inp_index != strlen(argv[1]); ++k)
	{
		doXor(inp + inp_index, poly, poly_len, res);
		
		for(j = 0; j < poly_len; ++j)
			inp[inp_index + j] = res[j];		
		inp_index = 0;
		for(j = 0; inp[j] == 0 ; ++j, inp_index++);
	}
	for(j = 0; inp[j] == 0; ++j);
	for(; j < inp_len; ++j)
			printf("%d", inp[j]);
	
	printf("\n");
	return EXIT_SUCCESS;
}


/*
$ gcc crc.c 
$ ./a.out 
Usage: crc <word to encode> <generator polynomial>
No argument specified
$ ./a.out 111111111 10110
1010
$ 

*/

