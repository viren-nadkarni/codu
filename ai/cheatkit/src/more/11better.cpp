#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<ctype.h>

char s[30],temp[20],subst[50];

struct pred
{
	int num;              //No. of arguments
	char symb[10];        //Predicate symbols
	char arg[15][15];     //Arguments
}p[2];

void input()
{
	for(int i=0;i<2;i++)
	{
		printf("\nEnter first predicate symbol: ");
		 scanf("%s",&p[i].symb);
		printf("\nEnter no. of arguments: ");
		 scanf("%d",&p[i].num);
		printf("\nEnter the arguments: ");
		for(int j=0;j<p[i].num;j++)
			scanf("%s",&p[i].arg[j]);
	}
}

void display()
{
	for(int i=0;i<2;i++)
	{
		printf("\nTHE PREDICATES ARE %d:%s(",i+1,p[i].symb);
		for(int j=0;j<p[i].num;j++)
		printf("%s,",p[i].arg[j]);
		printf("\b)\n\n");
	}
}

void fail()
{
	 printf("FAIL!!!! CANNOT FIND SOLUTION!!!");
	 getch();
	 exit(1);
}

	void unification()
{
	int k,j;
	char p1_c,p2_c;
	char temp1[10],temp2[10];
	for(int i=0;i<p[0].num;i++)
	{   printf("\nPREDICATES:-\n\n");
		display();

		p1_c=p[0].arg[i][0];
		p2_c=p[1].arg[i][0];
		if(!strcmp(p[0].arg[i],p[1].arg[i]))
			continue;
		else if(islower(p1_c)&&isupper(p2_c))
		{ strcpy(temp1,p[1].arg[i]);
		  strcpy(temp2,p[0].arg[i]);}

		 else if(islower(p2_c)&&isupper(p1_c))
		{ strcpy(temp1,p[0].arg[i]);
		  strcpy(temp2,p[1].arg[i]); }

		 else if(islower(p1_c)&&islower(p2_c))
		 { strcpy(temp1,p[0].arg[i]);
		 strcpy(temp2,p[1].arg[i]); }

		else if(isupper(p1_c)&&isupper(p2_c)&&strcmp(p[0].arg[i],p[1].arg[i])!=0)
		{ fail(); }

		 strcat(subst,"(");
		 strcat(subst,temp1);
		 strcat(subst,",");
		 strcat(subst,temp2);
		 strcat(subst,")");
			for(int k=0;k<2;k++)
			{
			 for(int j=0;j<p[k].num;j++)
			  if(!strcmp(p[k].arg[j],temp2))
			   strcpy(p[k].arg[j],temp1);
			}
	  }
}


void main()
{
	input();
    printf("\nUNIFICATION ALGORITHM\n\n");
	
	if(strcmp(p[0].symb,p[1].symb))
		fail();
	if(p[0].num!=p[1].num)
		fail();
	//Unification
	unification();
	printf("%s",subst);
	getch();
}
