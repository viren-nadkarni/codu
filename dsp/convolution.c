#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	char st1[] = "1,2,3,4", st2[] = "0,1,1";				//<----- the two signals
	//char st1[32], st2[32];
	int p1 = 0, p2 = 0;										//<----- start point of the signals
	int n1 = 0, s1[16], n2 = 0, s2[16], i, j, great;
	int res[16], r = 0, mid[32], m = 0;
	
	for( i = 0; i < 32; ++i)
		mid[ i ] = 0;
	
//read the signals and tokenise the string
	//printf("Signal 1: ");
	//scanf("%s", st1);
	
	for(i = 0; st1[i] != '\0'; ++i)
		if( st1[i] != ',' )
			s1[n1++] = st1[i] - 48;
	
	//printf("Signal 2: ");
	//scanf("%s", st2);
	
	for(i = 0; st2[i] != '\0'; ++i)
		if( st2[i] != ',' )
			s2[n2++] = st2[i] - 48;
	
//print table range
	printf("\n\n");
	great = n1 > n2 ? n1 : n2;
	for(i = -great; i <= great; ++i)
		printf("%d\t", i);
	printf("\n");
	
//print signal 1
	for(i = -great; i < 0 + p1; ++i)
	{
		printf("\t");
		mid[ m++ ] == 0;
	}
	for(i = 0; i < n1; ++i)
	{
		printf("%d\t", s1[i]);
		mid[ m++ ] = s1[i];
	}
	printf("\n");
	
//print signal 2
	for(i = -great; i < 0 + p2; ++i)
		printf("\t");
	for(i = 0; i < n2; ++i)
		printf("%d\t", s2[i]);
	printf("\n");

	int tmp_sum = 0, index = 0;
	
//print negative signal 2
	for(i = 0; i < great - n2 + 1 - p2; ++i)
	{
		printf("\t");
		index++;
	}
	for(i = n2 - 1; i >= 0; --i)
	{
		printf("%d\t", s2[i]);
//		tmp_sum += s2[i] * mid[ index++ ];
	}
	printf("\n");
//	printf("\n--------------------------------------------------\n");
//	printf("\t\t{%d}\n", tmp_sum);
	
//	res[ r++ ] = tmp_sum;
	
	for(j = 0; j < n1 + n2 - 1; ++j)
	{
		tmp_sum = 0, index = 1 + i;
		
//		for(i = 0; i < great + 2 + j - n2 - p2; ++i)
		for(i = 0; i < great - n2 + j + p2 + 1; ++ i)
		{
			printf("\t");
			index++;
		}
		for(i = n2 - 1; i >= 0; --i)
		{
			printf("%d\t", s2[i]);
			tmp_sum += s2[i] * mid[ index++ ];
		}
//		printf("\t\t{%d}\n", tmp_sum);
		printf("\n");
		res[ r++ ] = tmp_sum;	
	}
	
	printf("\n\nResult: y={");
	for(i = 0; i < r; ++i)
		printf("%d,", res[i] );
	printf("}\n");	
	
	
	return EXIT_SUCCESS;
}	
