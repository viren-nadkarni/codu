#include <stdio.h>
#include <stdlib.h>

int colours[8];
int adjMatrix[8][8]={ 	0, 1, 0, 0, 1, 1, 0, 0,
						1, 0, 1, 1, 0, 1, 0, 0,
						0, 1, 0, 1, 0, 0, 0, 1,
						0, 1, 1, 0, 0, 0, 1, 1,
						1, 0, 0, 0, 0, 1, 0, 0,
						1, 1, 0, 0, 1, 0, 1, 0,
						0, 0, 0, 1, 0, 1, 0, 1,
						0, 0, 1, 1, 0, 0, 1, 0 };

void colourise(int);
void colourise(int c)
{
	int i, j;
	
	colours[c] = 1;
	
	for(i=0; i<c; i++)
		if( adjMatrix[i][c] != 0 && colours[c] == colours[i] )
			colours[c] = colours[i] + 1;
	
}

int main(int argc, char ** argv)
{
	int i;
	
	colours[0] = 1;
	colours[1] = 2;
	
	for( i=2; i<8; ++i)
		colours[i] = 0;
	
	for( i=2; i<8; ++i)
		colourise( i );
		
	for( i=0; i<8; ++i)
	{
		printf("v%d : ", i+1);
		switch( colours[i] )
		{
			case 1:
				printf("%c\n", 'R');
				break;
			case 2:
				printf("%c\n", 'G');
				break;
			case 3:
				printf("%c\n", 'B');
				break;
			default:
				fprintf(stderr, "Invalid colour");
				exit(2);
		}
	}

	return EXIT_SUCCESS;
}
