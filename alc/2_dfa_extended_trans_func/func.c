/* 
 * File:   func.c
 * Author: viren
 *
 * Created on July 12, 2012, 12:45 PM
 */

#include "header.h"
#define SIZE_STATES 32
#define SIZE_INPUTS 16

/*
 * 
 */

void initLanguage(Language * lang)
{
	int i;
	
	lang->states=(int *)malloc(sizeof(int)*SIZE_STATES);
	lang->num_states=0;
	
	lang->inputs=(int *)malloc(sizeof(int)*SIZE_INPUTS);
	lang->num_inputs=0;
	
	lang->transits=(struct Sigma *)malloc(sizeof(struct Sigma)*SIZE_STATES*SIZE_INPUTS);
	lang->num_transits=0;	
	
	lang->final_states=(int *)malloc(sizeof(int)*SIZE_STATES);
	lang->num_final_states=0;
	
	lang->input_strings=(char **)malloc(sizeof(char)*SIZE_INPUTS);
	for(i=0;i<SIZE_INPUTS;++i)
		lang->input_strings[i]=(char *)malloc(sizeof(char)*SIZE_INPUTS*2);
	lang->num_input_strings=0;
	
	lang->input_string_correct=(int *)malloc(sizeof(int)*SIZE_INPUTS);
	for(i=0;i<SIZE_INPUTS;++i)		//init all flags to zero
		lang->input_string_correct[i]=0;
	
	lang->input_string_final_state=(int *)malloc(sizeof(int)*SIZE_INPUTS);
	
}

void insertState(Language * lang, char name, int value)
{
	lang->statename=name;
	lang->states[lang->num_states++]=value;
}

void insertInput(Language * lang, int input)
{
	lang->inputs[lang->num_inputs++]=input;
}

void insertTransit(Language * lang, int current_value, int next_value, int input)
{
	lang->transits[lang->num_transits].current=current_value;
	lang->transits[lang->num_transits].next=next_value;
	lang->transits[lang->num_transits].input=input;
	
	lang->num_transits++;
}

/*
 * 
 */

void readFile(Language * lang)
{
	FILE * inpfile;
	char ch;
	
	inpfile=fopen(INPUT_FILE,"r");
	
	if(!inpfile)
	{
		printf("\nCould not open input file");
		exit(1);
	}
	
	while(ch!=EOF)
	{
		ch=fgetc(inpfile);		
		switch(ch)
		{
            case '#':
            {
                //comments
                while(ch!='\n')
                    ch=fgetc(inpfile);
                break;
            }
            case 'Q':
			{
				//states
				if(fgetc(inpfile)=='=' && fgetc(inpfile)=='{')
				{
					while(ch!='}')
					{
						if(ch>='a' && ch<='z')
							lang->statename=ch;
						
						if(ch>='0' && ch<='9')
							lang->states[lang->num_states++]=atoi(&ch);
						
						ch=fgetc(inpfile);
					}
				}
				else
				{
					printf("\nFile syntax error q1");
					exit(1);
				}
				break;
			}
			case 'I':
			{
				//input values
				if(fgetc(inpfile)=='=' && fgetc(inpfile)=='{')
				{
					while(ch!='}')
					{
						if(ch>='0' && ch<='9')
							lang->inputs[lang->num_inputs++]=atoi(&ch);
						ch=fgetc(inpfile);
					}
				}
				else
				{
					printf("\nFile syntax error i1");
					exit(1);
				}
				break;
			}
			case 'F':
			{
				//final states
				if(fgetc(inpfile)=='=' && fgetc(inpfile)=='{')
				{
					while(ch!='}')
					{
						if(ch>='0' && ch<='9')
							lang->final_states[lang->num_final_states++]=atoi(&ch);
						ch=fgetc(inpfile);
					}
				}
				else
				{
					printf("\nFile syntax error f1");
					exit(1);
				}
				break;
			}
			case 'N':
			{
				//transitions
				int current,input,next;
				char ch;
				
				if(fgetc(inpfile)=='(' && fgetc(inpfile)==lang->statename)
				{
					ch=fgetc(inpfile);
					current=atoi(&ch);
					
					if(fgetc(inpfile)==',')
					{
						ch=fgetc(inpfile);
						input=atoi(&ch);
						
						if(fgetc(inpfile)==')' && fgetc(inpfile)=='=' && fgetc(inpfile)==lang->statename)
						{
							ch=fgetc(inpfile);
							next=atoi(&ch);
						}
						else
							printf("\nFile syntax error n3");
					}
					else
						printf("\nFile syntax error n2");
				}
				else
					printf("\nFile syntax error n1");
				
				while(fgetc(inpfile)!='\n')
				{}
				
				insertTransit(lang,current,next,input);

				break;
			}			
		}		
		if(ch=='0' || ch=='1')
		{
			//input string that is to be checked
			int i=0;
			
			while(ch=='0' || ch=='1')
			{
				lang->input_strings[lang->num_input_strings][i++]=ch;
				ch=fgetc(inpfile);
			}
			lang->input_strings[lang->num_input_strings][i]='\0';
			lang->num_input_strings++;
		}
	}
	return;
}

void printFile(Language * lang)
{
	FILE * outfile;
	int i;
	
	outfile=fopen(OUTPUT_FILE,"a");
	
	if(outfile==NULL)
	{
		printf("\nCould not open output file");
		exit(1);
	}

	fprintf(outfile,"%s","\n\n");
	
	for(i=0;i<lang->num_input_strings;++i)
	{
		fputs(lang->input_strings[i],outfile);
		fputs(" -> ",outfile);
		if(lang->input_string_correct[i])
			fputs("valid",outfile);
		else
			fputs("invalid",outfile);
		fputc('\n',outfile);
	}		
}

void printLanguage(Language * lang)
{
	int i;
	
	printf("\nStates : ");
	for(i=0;i<lang->num_states;++i)		
		printf("%c%d ",lang->statename, lang->states[i]);
	
	printf("\nInputs : ");
	for(i=0;i<lang->num_inputs;++i)
		printf("%d ",lang->inputs[i]);
	
	printf("\nFinal states : ");
	for(i=0;i<lang->num_final_states;++i)
		printf("%c%d ",lang->statename, lang->final_states[i]);
		
	printf("\nTransitions <current> <input> <next>:\n");
	for(i=0;i<lang->num_transits;++i)
		printf("%c%d  %d  %c%d\n", lang->statename, lang->transits[i].current, lang->transits[i].input, lang->statename, lang->transits[i].next);
	
	printf("\nInput strings:\n");
	for(i=0;i<lang->num_input_strings;++i)
		printf("%s\n",lang->input_strings[i]);
}

void processLanguage(Language * lang)
{
	int i;
	char cache[32]="",buffer[64]="";
	
	for(i=0;i<lang->num_input_strings;++i)
	{
		printf("\n\nS(%c0,%s)\n",lang->statename,lang->input_strings[i]);
		sprintf(cache,"\n\nS(%c0,%s)\n\0",lang->statename,lang->input_strings[i]);
		strcat(buffer,cache);
		printFileString(buffer);
		strcpy(cache,"");
		strcpy(buffer,"");
			
		lang->input_string_final_state[i]=exTransFunc(lang, lang->input_strings[i], strlen(lang->input_strings[i])-1, 0);
		
		if(isFinalState(lang,lang->input_string_final_state[i]))
			lang->input_string_correct[i]=1;		
	}
	return;
}

int exTransFunc(Language * lang, char input_string[], int len, int current_state)
{
	int i,j,k;
	char buffer[64]="",cache[32]="";
	j=strlen(input_string);
	
	if(len==0)
	{
		printf("=");
		strcat(buffer,"=");
				
		for(i=0;i<j-len-1;++i)
		{
			printf("S(");
			strcat(buffer,"S(");
		}
		
		printf("%c%d",lang->statename, nextState(lang,current_state,input_string[len]-48));
		sprintf(cache,"%c%d",lang->statename, nextState(lang,current_state,input_string[len]-48));
		strcat(buffer,cache);
		
		for(i=0;i<j-len-1;++i)
		{
			printf(",%c)",input_string[i+1]);
			sprintf(cache,",%c)",input_string[i+1]);
			strcat(buffer,cache);		
		}
		
		printf("\n");
		sprintf(cache,"\n\0");
		strcat(buffer,cache);	
		
		printFileString(buffer);
		
		return nextState(lang,current_state,input_string[len]-48);
	}
	else
	{
		
		printf("=");
		strcat(buffer,"=");		
				
		for(i=0;i<j-len+1;++i)
		{
			printf("S(");
			strcat(buffer,"S(");		
		}
		
		printf("%c0,",lang->statename);
		sprintf(cache,"%c0,",lang->statename);
		strcat(buffer,cache);		
				
		for(i=0;i<len;++i)
		{
			printf("%c",input_string[i]);
			sprintf(cache,"%c",input_string[i]);
			strcat(buffer,cache);		
		}
		
		for(i=0;i<j-len;++i)
		{
			printf("),%c",input_string[i+len]);
			sprintf(cache,"),%c",input_string[i+len]);
			strcat(buffer,cache);		
		}
		
		printf(")\n");
		sprintf(cache,")\n\0");
		strcat(buffer,cache);		
		printFileString(buffer);
		strcpy(buffer,"");
		strcpy(cache,"");
		
		k=nextState(lang, exTransFunc(lang, input_string, len-1, current_state), input_string[len]-48);
				
		printf("=");
		strcat(buffer,"=");		
		
		for(i=0;i<j-len-1;++i)
		{
			printf("S(");
			strcat(buffer,"S(");		
		}
		
		printf("%c%d",lang->statename, k);
		sprintf(cache,"%c%d",lang->statename, k);
		strcat(buffer,cache);		
		
		for(i=0;i<j-len-1;++i)
		{
			printf(",%c)",input_string[len+i+1]);
			sprintf(cache,",%c)",input_string[len+i+1]);
			strcat(buffer,cache);		
		}
		
		printf("\n");
		sprintf(cache,"\n\0");
		strcat(buffer,cache);		
		
		printFileString(buffer);
		
		return k;
	}
}

int nextState(Language * lang, int current, int input)
{
	/* This function return the next state number corresponding to parameters
	 * In case of error, returns -1
	 */	
	int i;
	
	for(i=0;i<lang->num_transits;++i)
	{
		if(current==lang->transits[i].current && input==lang->transits[i].input)
			return lang->transits[i].next;		
	}
	
	printf("\nWarning, next state not found");
	return -1;
}

int isFinalState(Language * lang, int st)
{
	int i=0;
	
	for(i=0;i<lang->num_final_states;++i)
		if(st==lang->final_states[i])
			return 1;
	
	return 0;	
}

void printFileString(char str[])
{
	FILE * inpfile;
		
	inpfile=fopen(OUTPUT_FILE,"a");
	
	fprintf(inpfile,str);
	
	fclose(inpfile);
	
	return;
}

void clearFile(void)
{
	FILE * inpfile;
	
	inpfile=fopen(OUTPUT_FILE,"w");
	
	fclose(inpfile);
	
	return;
}

