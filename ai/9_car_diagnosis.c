/* 
 * File:   main.c
 * Author: viren
 *
 * Created on 24 April 2013, 14:28
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */

typedef struct node
{
	int isQuestion;
	char *string;
	struct node *yes, *no;
} Node;

Node *getnode(int iQ, char *s)
{
	Node *tmp;
	tmp = (Node *)malloc(sizeof(Node));//+sizeof(s)+1);
	
	tmp->string =(char *)malloc(128);/*(char *)malloc(sizeof(s) + 1);*/
	strcpy(tmp->string, s);
	
	tmp->isQuestion = iQ;
	
	tmp->yes = NULL;
	tmp->no = NULL;
	
	return tmp;
}

int main(int argc, char** argv) 
{
	Node *nodeList[33];
	
	//questions
	nodeList[0] = getnode(1, "Starter cranks?");
	nodeList[1] = (nodeList[0]->no = getnode(1, "Engine fires?"));
	nodeList[2] = (nodeList[0]->yes = getnode(1, "Does spinner start?"));
	nodeList[3] = (nodeList[1]->no = getnode(1, "Does battery read over 12V?"));
	nodeList[4] = (nodeList[2]->no = getnode(1, "Sparks to plug?"));
	nodeList[5] = (nodeList[2]->yes = getnode(1, "Starts and stalls?"));
	nodeList[6] = (nodeList[3]->yes = getnode(1, "Are terminals clean?"));
	nodeList[7] = (nodeList[4]->yes = getnode(1, "Fuel reaches the filter?"));
	nodeList[8] = (nodeList[5]->yes = getnode(1, "Check OBD, blink code?"));
	nodeList[9] = (nodeList[7]->yes = getnode(1, "Is fuel injected?"));
	nodeList[10] = (nodeList[8]->yes = getnode(1, "Stalls on key release to run?"));
	nodeList[11] = (nodeList[4]->no = getnode(1, "Sparks from coil?"));
	nodeList[12] = (nodeList[10]->no = getnode(1, "Stalls on rail?"));
	nodeList[13] = (nodeList[11]->yes = getnode(1, "Mechanical distributer?"));
	nodeList[14] = (nodeList[11]->no = getnode(1, "+12V at coil primary?"));
	nodeList[15] = (nodeList[12]->no = getnode(1, "Stalls warm?"));
	
	//solutions
	nodeList[16] = (nodeList[1]->yes = getnode(0, "Solenoid stuck/not powered or missing teeth on flywheel"));
	nodeList[17] = (nodeList[5]->no = getnode(0, "Ignition timing and fuel problem. Cranking too slow. Problem with battery or starter"));
	nodeList[18] = (nodeList[6]->yes = getnode(0, "With car in neutral, use heavy jumper or screwdriver to bypass starter relay solenoid. Test starter"));
	nodeList[19] = (nodeList[3]->no = getnode(0, "Jump start and check if battery is charging"));
	nodeList[20] = (nodeList[7]->no = getnode(0, "Problem with vapour lock or fuel pump blockage"));
	nodeList[21] = (nodeList[8]->no = getnode(0, "Read OBD or OBD II and check blink code access"));
	nodeList[22] = (nodeList[6]->no = getnode(0, "Clean battery terminals, connectors and engine ground"));
	nodeList[23] = (nodeList[9]->yes = getnode(0, "With single point engine, check throttle body. With multi point, diagnose separately"));
	nodeList[24] = (nodeList[10]->yes = getnode(0, "Ignition \"run\" circuit or column key switch failure. Ring out with meter"));
	nodeList[25] = (nodeList[9]->no = getnode(0, "Try starter spray in carb, throttle open"));
	nodeList[26] = (nodeList[12]->yes = getnode(0, "Check cracked coil, distributer. Check visible electrical arcing running in dark"));
	nodeList[27] = (nodeList[13]->yes = getnode(0, "Check condenser, points, or magnetic pick-up, rotor, or cap damage"));
	nodeList[28] = (nodeList[14]->yes = getnode(0, "Test coil for internal short. Check secondary wire output resistance"));
	nodeList[29] = (nodeList[13]->no = getnode(0, "For electronic distribution, check model manual for diagnostics"));
	nodeList[30] = (nodeList[14]->no = getnode(0, "Check ignition system wiring, voltage regulator"));
	nodeList[31] = (nodeList[15]->yes = getnode(0, "Adjust idle, blow-out fuel filter, check fuel pump output. Check vacuum leak or sensor failure"));
	nodeList[32] = (nodeList[15]->no = getnode(0, "On cold stalling, check for stuck choke, EGR. Also check for vacuum leak"));
	
	
	
	char ans;
	Node *currentNode = nodeList[0];
	while(currentNode->isQuestion)
	{
		printf("\n%s (y/n): ", currentNode->string);
		scanf(" %c", &ans);
		if(ans == 'y')
			currentNode = currentNode->yes;
		else if(ans == 'n')
			currentNode = currentNode->no;
	}
	printf("\n%s", currentNode->string);	
	
	return (EXIT_SUCCESS);
}

