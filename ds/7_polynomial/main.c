#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
#define MAXNUM 64

int main()
{
	Node *eqn1, *eqn2;
	eqn1=eqn2=NULL;
	
	int x_deg, y_deg, z_deg, coeff, eqn1_terms, eqn2_terms, i, j;
	
	/*
	//input for eqn 1
	printf("Equation 1:\nHow many terms? ");
	scanf("%d",&eqn1_terms);
	printf("Values? coeff, x_deg, y_deg, z_deg\n");
	*/
	eqn1_terms=4;
	for(i=0;i<eqn1_terms;++i)
	{
		//printf("Term %d: ",i+1);
		//scanf("%d %d %d %d",&coeff, &x_deg, &y_deg, &z_deg);
		//insertEnd(&eqn1, x_deg, y_deg, z_deg, coeff);
		insertEnd(&eqn1, i+1,i+1,i+1,i+1);
	}
	printEqn(&eqn1);
	removeNode(&eqn1,0,eqn1_terms);
	printEqn(&eqn1);
	removeNode(&eqn1,1,eqn1_terms);
	printEqn(&eqn1);
	
	/*
	printf("\nEquation 2:\nHow many terms? ");
	scanf("%d",&eqn2_terms);
	printf("Values? coeff, x_deg, y_deg, z_deg\n");
	
	for(i=0;i<eqn1_terms;++i)
	{
		printf("Term %d: ",i+1);
		scanf("%d %d %d %d",&coeff, &x_deg, &y_deg, &z_deg);
		insertEnd(&eqn2, x_deg, y_deg, z_deg, coeff);
	}
	*/
	
	
	
	
	
	
	return 0;
}
