#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pfxconvert.h"

void char_push(struct char_stack * tmp, char op)
{
	if((tmp->top)>64)
    {
        fprintf(stderr,"\nStack overflow - check expression");
        exit(1);
    }
    else
        tmp->items[++(tmp->top)]=op;
}

char char_pop(struct char_stack * tmp)
{
	if((tmp->top)<=-1)
    {
        fprintf(stderr,"\nStack underflow - check expression");
        exit(1);
    }
    else
        return (tmp->items[(tmp->top)--]);	
}

void int_push(struct int_stack * tmp, int op)
{
	if((tmp->top)>64)
    {
        fprintf(stderr,"\nStack overflow - check expression");
        exit(1);
    }
    else
        tmp->items[++(tmp->top)]=op;
}

int int_pop(struct int_stack * tmp)
{
	if((tmp->top)<=-1)
    {
        fprintf(stderr,"\nStack underflow - check expression");
        exit(1);
    }
    else
        return (tmp->items[(tmp->top)--]);	
}

char * infixToPostfix(char postfix[], char infix[])
{
    int i=0,p=0,type,prec;
    char next;
    struct char_stack stk;
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
		case '.':
		case '*':
		case '?':
		case '^':
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
			return(1);
		case '.':
			return(2);
		case '*':
		case '?':
		case '^':
			return(3);
		default :
			return(9);
    }
}

