#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
	int i, counter = 0, length = strlen(argv[1]);
	char *inp;
	
	if(argc < 2)
	{
		printf("Argument not specified\n");
		exit(1);
	}

	inp = (char *)malloc(sizeof(char) * length);
	strcpy(inp, argv[1]);
	
	for(i = 0; i < length; ++i)
	{
		if(counter == 5)
                {
                        counter = 0;
                        printf("%c",'0');
                }

		printf("%c", inp[i]);

		if(inp[i] == '1' && inp[i+1] == '1')
			counter++;
		else
			counter = 0;
		fflush(stdout);
	}

	printf("\n");

	return EXIT_SUCCESS;
}
