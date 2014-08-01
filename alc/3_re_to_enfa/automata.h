/* 
 * File:   automata.h
 * Author: viren
 *
 * Created on July 24, 2012, 6:01 PM
 */

#ifndef AUTOMATA_H
#define	AUTOMATA_H

#ifdef	__cplusplus
extern "C"
{
#endif

#define INPUTFILE "input.txt"
#define OUTPUTFILE "output.txt"
#define EXPSIZE 32
	
#define MIN(x,y) (x<y?x:y)
#define MAX(x,y) (x<y?y:x)

#define EE 36
	
typedef struct re_
{
	char ifx[EXPSIZE], pfx[EXPSIZE], inputs[EXPSIZE];
	int num_inputs;
} regex;

typedef struct enfa_
{
	int transits[EXPSIZE][EXPSIZE], num_states/*same as index*/, num_inputs, num_transits;
} enfa;

void readFile(regex *);
void writeFile(enfa *);
void printRegex(regex *);
void printEnfa(enfa *);

int isInput(regex *, char);
void insertTransit(enfa *,int,int,int);

void initStructs(regex *, enfa *);
void regexToEnfa(regex *, enfa *);

#ifdef	__cplusplus
}
#endif

#endif	/* AUTOMATA_H */

