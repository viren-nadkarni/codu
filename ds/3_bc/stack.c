//FILE: stack.c
#include <stdlib.h>
#include "stack.h"

//char stack
void char_push(struct char_stack * tmp, char op)
{
	if((tmp->top)>64)
    {
        printf("\nStack is full\n");
        exit(0);
    }
    else
        tmp->items[++(tmp->top)]=op;
}

char char_pop(struct char_stack * tmp)
{
	if((tmp->top)<=-1)
    {
        printf("\nStack is empty\n");
        exit(0);
    }
    else
        return (tmp->items[(tmp->top)--]);	
}

//integer stack
void int_push(struct int_stack * tmp, int op)
{
	if((tmp->top)>64)
    {
        printf("\nStack is full\n");
        exit(0);
    }
    else
        tmp->items[++(tmp->top)]=op;
}

int int_pop(struct int_stack * tmp)
{
	if((tmp->top)<=-1)
    {
        printf("\nStack is empty\n");
        exit(0);
    }
    else
        return (tmp->items[(tmp->top)--]);	
}
