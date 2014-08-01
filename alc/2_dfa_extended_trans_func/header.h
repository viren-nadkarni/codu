/* 
 * File:   header.h
 * Author: viren
 *
 * Created on July 12, 2012, 12:44 PM
 */

#ifndef HEADER_H
#define	HEADER_H

#ifdef	__cplusplus
extern "C" 
{
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
#define MAX_ALLOC 32

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

typedef struct Langu_
{
	int * states, num_states;
	char statename;
	
	int * inputs, num_inputs;
	
	int * final_states, num_final_states;
	
	char ** input_strings;
	int num_input_strings;
	int * input_string_correct;
	int * input_string_final_state;
	
	struct Sigma			//transition
	{
		int current, input, next;
	} * transits;
	int num_transits;
	
} Language;

void readFile(Language *);
void printFile(Language *);
void clearFile(void);
void printFileString(char *);
void printLanguage(Language *);

void processLanguage(Language *);
int exTransFunc(Language *, char *, int, int);

void initLanguage(Language *);
void insertState(Language *, char, int);
void insertInput(Language *, int);
void insertTransit(Language *, int, int, int);

int nextState(Language *, int, int);
int isFinalState(Language *, int);

#ifdef	__cplusplus
}
#endif

#endif	/* HEADER_H */

