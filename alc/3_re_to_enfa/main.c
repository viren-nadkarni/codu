/* 
 * File:   main.c
 * Author: viren
 *
 * Created on July 24, 2012, 6:01 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "automata.h"
#include "pfxconvert.h"

/*
 * 
 */
int main(int argc, char** argv)
{
	regex re;
	enfa en;
	
	initStructs(&re,&en);		
	readFile(&re);
	
	infixToPostfix(re.pfx,re.ifx);	
	regexToEnfa(&re,&en);
	
	printRegex(&re);
	printEnfa(&en);
	writeFile(&en);
		
	return (EXIT_SUCCESS);
}

