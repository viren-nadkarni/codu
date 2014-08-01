#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

char * infixtopostfix(char *);
int gettype(char);
int getprec(char);
int calc(char,int,int);
int eval(char *);

int calc(char opn, int a, int b)
{
	switch(opn)
	{
		case '+':
			return (a+b);
		case '-':
			return (a-b);
		case '*':
			return (a*b);
		case '/':
			return (a/b);
		case '%':
			return (a%b);
	}
}

int eval(char stat[])
{
	int i=0;
	struct int_stack stk;
	stk.top=-1;

	while(stat[i]!='\0')
	{
		if(stat[i]>='0'&&stat[i]<='9')
			int_push(&stk,stat[i++]-48);
		else
			int_push(&stk,calc(stat[i++],int_pop(&stk),int_pop(&stk)));
	}
	return (int_pop(&stk));
}


char * infixtopostfix(char infix[])
{
    int i=0,p=0,type,prec;
    char next;
    struct char_stack stk;
	static char postfix[64];
	stk.top=-1;
	
    while(i<strlen(infix))
    {
        type=gettype(infix[i]);
        switch(type)
        {
			case 1:
				char_push(&stk,infix[i]);
				break;
			case 2:
				while((next=char_pop(&stk))!='(')
					postfix[p++]=next;
				break;
			case 3:
				prec=getprec(infix[i]);
				while(stk.top>-1 && prec <= getprec(stk.items[stk.top]))
					postfix[p++]=char_pop(&stk);
				char_push(&stk,infix[i]);
				break;
			case 4:
				postfix[p++]=infix[i];
				break;
        }
        i++;
    }
    while(stk.top>-1)
        postfix[p++]=char_pop(&stk);		
    postfix[p]='\0';
	
	return (postfix);
}


int gettype(char sym)
{
    switch(sym)
    {
		case '(':
			return(1);
		case ')':
			return(2);
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
			return(3);
		default :
			return(4);
	}
}

int getprec(char sym)
{
    switch(sym)
    {
		case '(':
			return(0);
		case '+':
		case '-':
			return(1);
		case '*':
		case '/':
		case '%':
			return(2);
		default :
			return(9);
    }
}

int main(int argc, char * argv[])
{
	int i=0;
	char stat[32],result[32],ch;
	FILE * file;

	printf("To exit type 'quit'.\n");
	
	if(argc==2)
	{
		file=fopen(argv[1],"r");
		
		if(file==NULL)
		{
			printf("File could not be found\n");
			return (1);
		}
		
		else 
		{
			ch=fgetc(file);
			
			while(ch!=EOF)
			{
				stat[i]=ch;
				ch=fgetc(file);
				i++;
				if(ch=='\n')
				{
					printf("%d\n",eval(infixtopostfix(stat)));
					i=0;
					ch=fgetc(file);
				}				
			}
			fclose(file);
		}
	}

	while(1)
	{
		scanf("%s",stat);
		if(strcmp(stat,"quit"))
			printf("%d\n",eval(infixtopostfix(stat)));
		else 
			break;
	}
		
	return 0;
}
