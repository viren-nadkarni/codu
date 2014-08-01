#include<stdio.h>
#include<stdlib.h>

int a,b,q,c;
	
struct wstate
{
	int jug1,jug2;
};
typedef struct wstate state;
state initial={0,0},goal,current,newstate;

struct wnode
{
	state w;
	struct wnode *link;
};
typedef struct wnode node;

struct rulenode
{
	state left,right;
	struct rulenode *link;
};
typedef struct rulenode ruletype;

ruletype *rulelist,*lastrulenode;


int checkequal(state w1,state w2)
{
if(w1.jug1!=w2.jug1)
return 0;
if(w1.jug2!=w2.jug2)
return 0;

return 1;
}


ruletype *getrulenode(state l,state r)
{
	ruletype *temprulenode;
	temprulenode=(ruletype*)malloc(sizeof(ruletype));
	if(temprulenode==NULL)
	{
		printf("No memory\n");
		exit(0);
	}
	temprulenode->left.jug1=l.jug1;
	temprulenode->left.jug2=l.jug2;
	temprulenode->right.jug1=r.jug1;
	temprulenode->right.jug2=r.jug2;
	temprulenode->link=NULL;
	return(temprulenode);
}
void insertrulenode(state p,state q)
{
	ruletype *temprulenode;
	temprulenode=getrulenode(p,q);
	if(rulelist==NULL)
	{
		rulelist=lastrulenode=temprulenode;
	}
	else {
	        lastrulenode->link=temprulenode;
		lastrulenode=temprulenode;
             }

}







void initialiserulelist()
{
	state leftpart,rightpart;

	//Rule 1
	leftpart.jug1=0;
	leftpart.jug2=0;
	rightpart.jug1=a;
	rightpart.jug2=0;
	insertrulenode(leftpart,rightpart);
	//Rule 2
	/*leftpart.jug1=0;
	leftpart.jug2=0;
	rightpart.jug1=0;
	rightpart.jug2=b;
*/
	//insertrulenode(leftpart,rightpart);
//rule3

	/*leftpart.jug1=a;
	leftpart.jug2=0;
	rightpart.jug1=a;
	rightpart.jug2=b;
	insertrulenode(leftpart,rightpart);

*/
//rule4
	leftpart.jug1=a;
	leftpart.jug2=0;
	rightpart.jug1=a-b;
	rightpart.jug2=b;
	insertrulenode(leftpart,rightpart);

//rule5
	/*leftpart.jug1=a;
	leftpart.jug2=0;
	rightpart.jug1=0;
	rightpart.jug2=b;
	insertrulenode(leftpart,rightpart);

//rule6
	leftpart.jug1=a-b;
	leftpart.jug2=b;
	rightpart.jug1=a;
	rightpart.jug2=b;
	insertrulenode(leftpart,rightpart);

//rule7

	leftpart.jug1=a-b;
	leftpart.jug2=b;
	rightpart.jug1=0;
	rightpart.jug2=b;
	insertrulenode(leftpart,rightpart);
*/
//rule8
	leftpart.jug1=a-b;
	leftpart.jug2=b;
	rightpart.jug1=a-b;
	rightpart.jug2=0;
	insertrulenode(leftpart,rightpart);
//rule9

/*
	leftpart.jug1=0;
	leftpart.jug2=b;
	rightpart.jug1=b;
	rightpart.jug2=0;
	insertrulenode(leftpart,rightpart);

*/
	//rule10

	leftpart.jug1=a-b;
	leftpart.jug2=0;
	rightpart.jug1=0;
	rightpart.jug2=a-b;
	insertrulenode(leftpart,rightpart);
//rule11
	leftpart.jug1=0;
	leftpart.jug2=a-b;
	rightpart.jug1=a;
	rightpart.jug2=a-b;
	insertrulenode(leftpart,rightpart);
//rule12
	int t;
	t=a-b;
	leftpart.jug1=a;
	leftpart.jug2=a-b;
	rightpart.jug1=b-t;
	rightpart.jug2=b;
	insertrulenode(leftpart,rightpart);
//rule13
	int t1;
	t1=a-b;
	leftpart.jug1=b-t1;
	leftpart.jug2=b;
	rightpart.jug1=b-t1;
	rightpart.jug2=0;
	insertrulenode(leftpart,rightpart);
//rule14
	int t2;
	t2=a-b;
	leftpart.jug1=b-t2;
	leftpart.jug2=0;
	rightpart.jug1=0;
	rightpart.jug2=b-t2;
	insertrulenode(leftpart,rightpart);

//rule15
}

state searchandapply(state t)
{
	ruletype *rulenode;
	state returnstate={-1,-1};
	int found=0;
	rulenode=rulelist;
	while(!found && rulenode)
	{
		if((rulenode->left.jug1==t.jug1)&&(rulenode->left.jug2==t.jug2))
		{
			returnstate.jug1=rulenode->right.jug1;
			returnstate.jug2=rulenode->right.jug2;
			found=1;
			printf("\n%d %d->",rulenode->left.jug1,rulenode->left.jug2);
			printf("%d %d \n",rulenode->right.jug1,rulenode->right.jug2);
		}
		rulenode=rulenode->link;
	}
	if(rulenode)
		rulelist=rulenode;
       else 
            rulelist = NULL;
	return(returnstate);
}

int checkgoal(state t)
{
	if((t.jug1==0) &&(t.jug2==2))

	return 1;
	else
	return 0;
}

void assign(state *s1,state *s2)
{
	(*s1).jug1=(*s2).jug1;
	(*s1).jug2=(*s2).jug2;
}

int main()
{
	ruletype *masterlist;
	int solution=1;
	int temp;
	printf("\nEnter the quantity of water in the 2 jugs : ");
	printf("\nJUG 1 : ");
	scanf("%d",&a);
	printf("\nJUG 2 : ");
	scanf("%d",&b);
	printf("\nEnter the quantity of water required in JUG 1 : ");
	scanf("%d",&q);
	if(b>a)
	{
	temp=a;
	a=b;
	b=temp;	
	}
	if(a-b==1 && b-c==1)
	{
              solution=0;
              printf("Rules are not defined");
    }
	//goal={q,0};
	//final goal states
	goal.jug1=q;
	goal.jug2=0;
	if(checkequal(initial,goal))
	{
	solution=0;
	printf("\nStart State is the goal state\n");
	}	
	initialiserulelist();
	masterlist=rulelist;
	current=initial;
	while(solution)
	{

		rulelist=masterlist;
		while(rulelist)
		{
			newstate=searchandapply(current);
			if(checkgoal(newstate))
			{
			solution=0;
			break;
			}	
			assign(&current,&newstate);
			if(checkequal(current,goal))
			{
			solution=0;
			break;
			}
		}

	}
}
