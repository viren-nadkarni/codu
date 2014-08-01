/* 
 * File:   main.c
 * Author: viren
 *
 * Created on July 11, 2012, 5:11 PM
 */

#include "header.h"

/*
 * 
 */

int main(int argc, char** argv) 
{
	Language lang;
	initLanguage(&lang);		//initialize structure
			
	readFile(&lang);			//read contents of the file
	printLanguage(&lang);		//print structure on screen
	
	clearFile();				//clear the contents of output file
	
	processLanguage(&lang);		//evaluate the language and strings
	printFile(&lang);			//print results on file
		
	return (EXIT_SUCCESS);
}

