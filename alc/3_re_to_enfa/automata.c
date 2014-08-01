#include "automata.h"
#include <stdio.h>
#include <stdlib.h>

void writeFile(enfa * en)
{
	FILE * outputfile;
	int i=0;
	
	outputfile=fopen(OUTPUTFILE,"w");
	
	if(!outputfile)
	{
		fprintf(stderr,"\nError - file open attempt");
		exit(1);
	}

	for(i=0;i<en->num_transits;++i)
		fprintf(outputfile,"N(q%d,%c)=q%d\n",en->transits[i][0],en->transits[i][1],en->transits[i][2]);
	
	fclose(outputfile);
}

void readFile(regex *re)
{
	FILE * inputfile;
	char ch;
	int i=0;
	
	inputfile=fopen(INPUTFILE,"r");
	
	if(!inputfile)
	{
		fprintf(stderr,"\nError - file open attempt");
		exit(1);
	}
	
	while(!feof(inputfile)) 
	{
		ch=fgetc(inputfile);
		
		if(ch==' ')
			continue;
		else if(ch=='\n')
			continue;
		else
		{
			while(ch!='\n' && ch!=EOF)
			{
				re->ifx[i++]=ch;
				
				ch=fgetc(inputfile);			
			}
			re->ifx[i]='\0';
			return;
		}
	}
	fclose(inputfile);
}

void printRegex(regex * re)
{
	printf("Infix string: %s\nPostfix string: %s",re->ifx,re->pfx);	
}

void printEnfa(enfa * en)
{
	int i=0;
	
	printf("\n\nTransition table:\nprev\tinp\tnext");
	for(i=0;i<en->num_transits;++i)
		printf("\nq%d\t\t %c\t q%d",en->transits[i][0],en->transits[i][1],en->transits[i][2]);
}

int isInput(regex * re, char input)
{
	int i;
	
	for(i=0;i<re->num_inputs;++i)
		if(re->inputs[i]==input)
			return 1;
	
	return 0;
}

void initStructs(regex * re, enfa * en)
{
	re->num_inputs=0;
	en->num_inputs=en->num_states=en->num_transits=0;
}

void insertTransit(enfa * en,int init, int inp, int next)
{
	en->transits[en->num_transits][0]=init;
	en->transits[en->num_transits][1]=inp;
	en->transits[en->num_transits][2]=next;
	
	en->num_transits++;
}

void regexToEnfa(regex * re, enfa * en)
{
	int i=0, index=0, k=0;
	
	int first=0, last=0;
	int prev_in_1=-1, prev_in_2=-1, prev_out_1=-1, prev_out_2=-1;/*stores the states on which operations are to be performed*/
	
	/*Find what inputs are present */
	while(re->pfx[i]!='\0')
	{
		if(re->pfx[i]>='a' && re->pfx[i]<='z' && !isInput(re,re->pfx[i]))
			re->inputs[re->num_inputs++]=re->pfx[i];
		i++;
	}
	
	/*loop evaluates each character*/
	while(re->pfx[k]!='\0')
	{
		if(isInput(re,re->pfx[k]))
		{
			insertTransit(en,index,re->pfx[k],index+1);
			
			first=MIN(first,index);
			last=MAX(last,index+1);
			
			if(prev_in_1<0)
				prev_in_1=index;
			else
				prev_in_2=index;			
			
			if(prev_out_1<0)
				prev_out_1=index+1;
			else
				prev_out_2=index+1;			
			
			index+=2;
		}
		else
		{
			switch(re->pfx[k])
			{
				case '.':
				{
					insertTransit(en,MIN(prev_out_1,prev_out_2),EE,MAX(prev_in_1,prev_in_2));
					insertTransit(en,last,EE,index);
					
					index++;
										
					prev_in_1=-2;
					prev_in_2=first;
					prev_out_1=-20;
					prev_out_2=last;
					
					break;
				}
				case '+':
				{	
					first=index++;
					last=index++;
					
					insertTransit(en,first,EE,prev_in_1);
					insertTransit(en,first,EE,prev_in_2);
					
					insertTransit(en,prev_out_1,EE,last);
					insertTransit(en,prev_out_2,EE,last);
					
					prev_in_1=first;
					prev_in_2=first;
					prev_out_1=last;
					prev_out_2=last;
					
					break;
				}
				case '*':
				{	
					insertTransit(en,last,EE,first);
					
					insertTransit(en,index,EE,first);
					first=index;
					index++;
					
					insertTransit(en,last,EE,index);
					last=index;
					index++;
					
					insertTransit(en,first,EE,last);
										
					break;
				}
				case '?':
				{
					insertTransit(en,index,EE,first);
					first=index;
					index++;
					
					insertTransit(en,last,EE,index);
					last=index;
					index++;
					
					insertTransit(en,first,EE,last);
					
					break;
				}
				case '^':
				{
					insertTransit(en,last,EE,first);
					
					insertTransit(en,index,EE,first);
					first=index;
					index++;
					
					insertTransit(en,last,EE,index);
					last=index;
					index++;
					
					break;
				}
			}			
		}
		++k;
		en->num_states=index;
	}	
}

