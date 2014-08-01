#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
aim
theory 
alg
prog
output
concl
*/

char *klist[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};
int kflag[197], klistSize = 31;

int dlist[] = {40, 41, 44, 91, 93, 123, 125, 59}, dlistSize = 8;
int dflag[] = {0, 0, 0, 0, 0, 0, 0, 0};

int oplist[] = { '+', '-', '*', '/', '&', '|', '=' }, oplistSize = 7;
int opflag[] = { 0, 0, 0, 0, 0, 0, 0 };

int alreadyPrinted[128], alreadyPrintedItems = 0;
int isAlreadyPrinted( char );
void insertAlreadyPrinted( char);

int isAlreadyPrinted( char c)
{
	int w = 0;
	for(; w < alreadyPrintedItems ; ++w)
		if( alreadyPrinted[w] == c)
			return 1;
	return 0;

}

void insertAlreadyPrinted(char c)
{
	alreadyPrinted[ alreadyPrintedItems++ ] = c;
}

int isOperator(char);
int isDelimiter(int);
int isKeyword(char *);
void removeSpaceChar(char *);

/*
 *
 *
 */
 
int main(int argc, char * argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "No file specified\n");
		exit(1);
	}

	FILE *fileptr;
	fileptr = fopen(argv[1], "r");
	
	fseek(fileptr, 0, SEEK_END);
	int fsize = ftell(fileptr);
	fseek(fileptr, 0, SEEK_SET);

	char *buff = malloc(fsize + 1);
	fread(buff, fsize, 1, fileptr);
	fclose(fileptr);
	buff[fsize] = 0;
	
	//delimiter search
	int i=0;
	printf("\nDelimiters: ");
	for(; i < fsize; ++i)
	{
		int p;
		if( p = isDelimiter( buff[i] ) )
			dflag[p-1] = 1;
	}
	for(i = 0; i < dlistSize; ++i)
	{
		if( dflag[i])
			printf("%c ", dlist[i]);
	}
	
	//replace ' ' and dlist by '\n'
	//ignore precompiler statments
	for(i = 0; i < fsize; ++i)
	{
		if(buff[i] == '#' || ( buff[i] == '/' && buff[i+1] == '/'))
			do
			{
				buff[i++] = '\n';
			}while(buff[i] != '\n');
		
		if(buff[i] == ' ' || buff[i] == '\t' || isDelimiter(buff[i]))
			buff[i] = '\n';
	}

	//operator search
	printf("\nOperators: ");
	int k = 0;
	for( i = 0; i < fsize; ++i)
	{
		if( k = isOperator( buff[i] ))
		{
			buff[i] = '\n';
			opflag[k - 1] = 1;
		}
	}
	for(i = 0; i < oplistSize; ++i)
		if(opflag[i] == 1)
			printf("%c ", oplist[i]);
	
	removeSpaceChar(buff);
	//printf("\n\n%s", buff);
	//printf("\n\n%s", klist);
	
	//keyword search
	printf("\nKeywords: ");
	char *tmp, q = 0, mid[256];
	strcpy(mid, buff);
	for(i = 0; i < klistSize; ++i)
		kflag[i] = 0;
	tmp = strtok(mid, "\n");
	while(tmp != NULL)
	{
		if( q = isKeyword(tmp) )
		{
			kflag[q] = 1;

			int len = 0;
			char *ind = strstr(buff, tmp);
			len = strlen(tmp);
			for( k = 0; k < len; ++k)
				*(ind+k) = '\n';
			
		}
		tmp = strtok(NULL, "\n");
		q++;
	}
	for(i = 0; i < klistSize; ++i)
		if(kflag[i] == 1)
			printf("%s ", klist[i]);
	
//	printf("\n%s\n", buff);

	//constant search
	printf("\nConstants: ");
	for(i = 0; i < fsize; ++ i)
	{	
		if( buff[i] >= '0' && buff[i] <= '9' && (buff[i+1] == '\n' && buff[i-1] == '\n' ) )
		{
			
			if( !isAlreadyPrinted( buff[i]) )
			{
				printf("%c ", buff[i]);
				insertAlreadyPrinted(buff[i]);
			}
			buff[i] = '\n';
		}
	}

	//identifier search
	printf("\nIdentifiers: ");
	removeSpaceChar(buff);
	strcpy(mid, buff);
	tmp = strtok(mid, "\n");
	while(tmp != NULL)
	{
		printf("%s ", tmp);
		tmp = strtok(NULL, "\n");
	}


	printf("\n");
	return EXIT_SUCCESS;
}

/*
 *
 *
 *
 *
 */
 
 
int isDelimiter(int a)
{
	int i = 0;
	for(; i < dlistSize; ++i)
		if( dlist[i] == a)
			return i+1;
	return 0;
}

int isOperator(char a)
{
	int i = 0;
	for(; i < oplistSize; ++i)
		if( oplist[i] == a)
			return i+1;
	return 0;
}


int isKeyword(char * word)
{
	int i;
	for(i = 0; i < klistSize; ++i)
	{
		if(strcmp( word, klist[i]) == 0)
			return i;
	}
	return 0;

}

void removeSpaceChar(char *buff)
{
	int m = 0, n = 0;
	
	while(buff[n] != '\0')
	{
		if(buff[n] == '\n' && buff[n+1] == '\n')
			n++;
		else
			buff[m++] = buff[n++];
	}
	buff[m] = '\0';
}


