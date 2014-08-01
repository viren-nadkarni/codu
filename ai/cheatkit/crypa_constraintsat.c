#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
int valueArray[26], flagArray[26];

int exists(int);
int exists(int num)
{
	int i;
	for(i=0;i<26; ++i)
		if(valueArray[i] == num)
			return FALSE;
	
	return TRUE;
}

int valueof(char);
int valueof(char c)
{
	if( flagArray['c'-'a'] == 0)
		printf("warning\n");
	return valueArray['c'-'a'];
}

int main()
{
	int nc, nr, i;
	char *t1, *t2, *r;

	for(i=0; i<26; ++i)
	{
		valueArray[i] = -1;
		flagArray[i] = 0;
	}
	
	
	printf("number of chars: ");
	scanf(" %d", &nc);
	
	t1 = (char *) malloc (sizeof(char) * nc);
	t2 = (char *) malloc (sizeof(char) * nc);
	
	
	
	printf("first term separated by spaces:\n");
	for(i = 0; i < nc; i++)
		scanf(" %c", t1 + i);
	for(i = 0; i < nc; i++)
		flagArray[ t1[i] - 'a' ] = 1;
		
	
	
	printf("second term separated by spaces:\n");
	for(i = 0; i < nc; i++)
		scanf(" %c", t2 + i);
	for(i = 0; i < nc; i++)
		flagArray[ t2[i] - 'a' ] = 1;
	
	
	
	printf("number of chars in result: ");
	scanf(" %d", &nr);
	r = (char *) malloc (sizeof(char) * nr);
	printf("result separated by spaces:\n");
	for(i = 0; i < nr; i++)
		scanf(" %c", r + i);
	for(i = 0; i < nc; i++)
		flagArray[ r[i] - 'a' ] = 1;

		
	int tmp;
	srand(time(NULL));
	
	
	int flag = 1;
	printf("please wait");
	do
	{
		//generate new values
		for(i=0; i<26; ++i)
		{
			while(1)
			{
				tmp = rand();
				tmp %= 10;
				if(exists(tmp))
					continue;
				break;
			}	
		}	
		
		//check for constraints
		for(i=1;i<=nc;++i)
		{
			if(valueof(t1[nc-i]) + valueof(t2[nc-i]) == valueof(r[nc-i]))
				flag&=1;
			else
				flag=0;
		}
	} while(flag == 0);
		
		
	for(i = 0; i < 26; ++i)
		if(flagArray[i] == 1)
			printf("%c %d\n", 'a'+i, valueArray[i]);
	
	
	
		
	
		
	return EXIT_SUCCESS;
	
}
