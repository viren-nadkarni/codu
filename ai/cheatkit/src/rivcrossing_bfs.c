#include<stdio.h>
#include<stdlib.h>

int times =0;
struct statenode
{
       int M,C,B;
};
typedef struct statenode STATE;

struct queuenode
{
       STATE s;
       struct queuenode *link;
};
typedef struct queuenode QTYPE;

QTYPE *NodeQ, *rear;

struct rulenode
{
       STATE left,right;
       struct rulenode *link;
};
typedef struct rulenode RULETYPE;

RULETYPE *rulelist,*lastrulenode;



QTYPE *GetQueueNode(STATE snew)
{
      QTYPE *temp;
      temp=(QTYPE *)malloc(sizeof(QTYPE));
      if(temp==NULL)
      {
               printf("No Memory\n");
               exit(0);
      }
      temp->s.M=snew.M;
      temp->s.C=snew.C;
      temp->s.B=snew.B;
      temp->link=NULL;
      return temp;
}

void InsertQueue(STATE s)
{
     QTYPE *t;
     t=GetQueueNode(s);
     if(NodeQ==NULL)
     {
               NodeQ=rear=t;
     }
     else
     {
         rear->link=t;
         rear=t;
     }
}

STATE DeleteQueue()
{
      QTYPE *temp;
      STATE returnstate={-1,-1,-1};
    //  STATE result;
      if(NodeQ!=NULL)
      {              
                      temp=NodeQ;
                      NodeQ=NodeQ->link;
                      returnstate.M=temp->s.M;
                      returnstate.C=temp->s.C;
                      returnstate.B=temp->s.B;
                      free(temp);
    
    }
    return (returnstate);
}

RULETYPE *GetRuleNode(STATE l,STATE r)
{
         RULETYPE *tempnode;
         tempnode=(RULETYPE *)malloc(sizeof(RULETYPE));
         if(tempnode==NULL)
         {
                      printf("No Memory\n");
                      exit(0);
         }
         else
         {
             tempnode->left.M=l.M;
             tempnode->left.C=l.C;
             tempnode->left.B=l.B;
             tempnode->right.M=r.M;
             tempnode->right.C=r.C;
             tempnode->right.B=r.B;
             tempnode->link=NULL;
         }
         return(tempnode);
}         

void Insertrulenode(STATE left,STATE right)
{
     RULETYPE *tempnode;
     tempnode=GetRuleNode(left,right);
     if(rulelist==NULL)
     {
                  rulelist=lastrulenode=tempnode;
     }
     else
     {
         lastrulenode->link=tempnode;
         lastrulenode=tempnode;
     }
}


void DisplayQ()
{
 QTYPE *tempnode=NodeQ;
 while(tempnode!=NULL)
 {
  printf("(%d,%d,%d),",tempnode->s.M,tempnode->s.C,tempnode->s.B);
  tempnode=tempnode->link;
 }
printf("\n");
}

void InitialiseRuleList()
{
	STATE leftpart,rightpart;
      //rule1

		leftpart.M=9; leftpart.C=2; leftpart.B=1;
		rightpart.M=9; rightpart.C=0;rightpart.B=0;
		Insertrulenode(leftpart,rightpart);
 //rule2

		leftpart.M=9; leftpart.C=0; leftpart.B=0;
		rightpart.M=9; rightpart.C=1;rightpart.B=1;
		Insertrulenode(leftpart,rightpart);

 //rule3

		leftpart.M=9; leftpart.C=1; leftpart.B=1;
		rightpart.M=8; rightpart.C=1;rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


//rule4

		leftpart.M=8; leftpart.C=1; leftpart.B=0;
		rightpart.M=8; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


//rule5

		leftpart.M=8; leftpart.C=2; leftpart.B=1;
		rightpart.M=8; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);

	//rule6

		leftpart.M=8; leftpart.C=0; leftpart.B=0;
		rightpart.M=8; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);

	//rule6

		leftpart.M=8; leftpart.C=1; leftpart.B=1;
		rightpart.M=7; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);

	//rule7
		leftpart.M=7; leftpart.C=1; leftpart.B=0;
		rightpart.M=7; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);

//rule7
		leftpart.M=7; leftpart.C=2; leftpart.B=1;
		rightpart.M=7; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);

//rule7
		leftpart.M=7; leftpart.C=0; leftpart.B=1;
		rightpart.M=7; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);
//rule6

		leftpart.M=7; leftpart.C=1; leftpart.B=0;
		rightpart.M=6; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule8

		leftpart.M=6; leftpart.C=0; leftpart.B=0;
		rightpart.M=6; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule9

		leftpart.M=6; leftpart.C=1; leftpart.B=1;
		rightpart.M=6; rightpart.C=2; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule10

		leftpart.M=6; leftpart.C=2; leftpart.B=0;
		rightpart.M=6; rightpart.C=0; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule11

		leftpart.M=6; leftpart.C=0; leftpart.B=1;
		rightpart.M=6; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule12

		leftpart.M=6; leftpart.C=1; leftpart.B=0;
		rightpart.M=5; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule13
		leftpart.M=5; leftpart.C=1; leftpart.B=1;
		rightpart.M=4; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


//rule14

		leftpart.M=4; leftpart.C=1; leftpart.B=0;
		rightpart.M=4; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


//rule15

		leftpart.M=4; leftpart.C=2; leftpart.B=1;
		rightpart.M=4; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);

	//rule16

		leftpart.M=4; leftpart.C=0; leftpart.B=0;
		rightpart.M=4; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule17
		leftpart.M=4; leftpart.C=1; leftpart.B=1;
		rightpart.M=3; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule18

		leftpart.M=3; leftpart.C=1; leftpart.B=0;
		rightpart.M=3; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule19

		leftpart.M=3; leftpart.C=2; leftpart.B=1;
		rightpart.M=3; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule20

		leftpart.M=3; leftpart.C=0; leftpart.B=0;
		rightpart.M=3; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule21

		leftpart.M=3; leftpart.C=1; leftpart.B=1;
		rightpart.M=2; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule22

		leftpart.M=2; leftpart.C=1; leftpart.B=0;
		rightpart.M=2; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule23
		leftpart.M=2; leftpart.C=2; leftpart.B=1;
		rightpart.M=2; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);



//rule24

		leftpart.M=2; leftpart.C=0; leftpart.B=0;
		rightpart.M=2; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


//rule25

		leftpart.M=2; leftpart.C=1; leftpart.B=1;
		rightpart.M=1; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);

	//rule26

		leftpart.M=1; leftpart.C=1; leftpart.B=0;
		rightpart.M=1; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule27
		leftpart.M=1; leftpart.C=2; leftpart.B=1;
		rightpart.M=1; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule28

		leftpart.M=1; leftpart.C=0; leftpart.B=0;
		rightpart.M=1; rightpart.C=1; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule29

		leftpart.M=1; leftpart.C=1; leftpart.B=1;
		rightpart.M=0; rightpart.C=1; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);


	//rule30

		leftpart.M=0; leftpart.C=1; leftpart.B=0;
		rightpart.M=0; rightpart.C=2; rightpart.B=1;
		Insertrulenode(leftpart,rightpart);


	//rule31

		leftpart.M=0; leftpart.C=2; leftpart.B=1;
		rightpart.M=0; rightpart.C=0; rightpart.B=0;
		Insertrulenode(leftpart,rightpart);



}



/*void DisplayRules()
 {
	RULETYPE *tempnode=rulelist;

	while(rulelist) {
	   printf("( %d, %d,%d)  --->  ( %d, %d , %d)\n", rulelist->left.M, rulelist->left.C,rulelist->left.B,rulelist->right.M,rulelist->right.C,rulelist->right.B);
	   rulelist = rulelist->link;
	}
}*/


void time(STATE t)
{
	RULETYPE *rulenode;
	rulenode=rulelist; 
	if(rulenode->left.M==0 && rulenode->right.C==2)
	{
	times=times+5;
	}	
	else if (rulenode->left.C==1 || rulenode->right.C==1)
	{
	times=times+10;
	}	
	else
	{
	times=times+7;
	}
}


STATE SearchAndApplyRules(STATE t)
{
	RULETYPE *rulenode;
	STATE returnstate={-1,-1,-1};
	int found=0;
	rulenode=rulelist;
	while(!found && rulenode)
	{
		if((rulenode->left.M==t.M)&&(rulenode->left.C==t.C)&&(rulenode->left.B==t.B))
		{
			returnstate.M=rulenode->right.M;
			returnstate.C=rulenode->right.C;
			returnstate.B=rulenode->right.B;
			found=1;
			time(t);
			printf("\n%d %d %d------>",rulenode->left.M,rulenode->left.C,rulenode->left.B);
			printf("%d %d %d\n",rulenode->right.M,rulenode->right.C,rulenode->left.B);
			
		}
		rulenode=rulenode->link;
	}
	if(rulenode)
		rulelist=rulenode;
       else 
            rulelist = NULL;
	return(returnstate);
}
int checkgoal(STATE t)
{
	if((t.M==0) &&(t.C==0) && (t.B==1))

	return 1;
	else
	return 0;
}


int main()
{
    STATE initial ={9,2,1},current,newstate;
    int found=0,kkk;
    RULETYPE *masterlist;
    NodeQ=rear=NULL;
    printf("\n RULES::WHEN THE BOAT GOES FROM LEFT TO RIGHT.... THE VALUE OF B IS 1 ELSE 0\n\n");
    rulelist=lastrulenode=NULL;
    
    InitialiseRuleList();
   masterlist=rulelist;
    InsertQueue(initial);
    while(masterlist!=NULL)
    {
                    current=DeleteQueue();
                    rulelist=masterlist;
                   // updatevisited(current);
                   while(rulelist)
                   {
                                  newstate=SearchAndApplyRules(current);
                     if(checkgoal(newstate))
                      {
                                          printf("Solution Found\n"); 
                                          found=1;
                                          break; 
                       } 
    	      if(newstate.M != -1)
		      InsertQueue(newstate);

	}
	masterlist=masterlist->link;

	if(found)
	{
	break;
	}


}

printf("\nTIME TAKEN : %d",times);
	
if(NodeQ!=NULL)
{
printf("No solution\n");
}
else
{
printf("\nSolution Found\n\n");
}



}

