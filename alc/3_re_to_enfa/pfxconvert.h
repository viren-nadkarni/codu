/* 
 * File:   pfxconvert.h
 * Author: viren
 *
 * Created on July 24, 2012, 6:10 PM
 */

#ifndef PFXCONVERT_H
#define	PFXCONVERT_H

#ifdef	__cplusplus
extern "C"
{
#endif

struct char_stack
{
	int top;
	char items[32];
};
void char_push(struct char_stack *, char);
char char_pop(struct char_stack *);

struct int_stack
{
	int top;
	int items[32];
};
void int_push(struct int_stack *, int);
int int_pop(struct int_stack *);

char * infixToPostfix(char *, char *);
int gettype(char);
int getprec(char);

#ifdef	__cplusplus
}
#endif

#endif	/* PFXCONVERT_H */

