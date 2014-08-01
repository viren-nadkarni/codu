#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int val[3][3],goal[3]={0,0,1},top[3]={1,0,0},n;
int next[3],cur[3],tstate[10][3],p[3],tp[3];
int state[10][3];
struct toh
{
	int f,g,h,config[3],nstate[10][3],np[3];
	struct toh *parent,*next;
}*open=NULL,*close=NULL,*BESTNODE=NULL,*BACK=NULL;
typedef struct toh node;




int check(int i,int j)
{
	node *temp,*newnode;
	int flag=0;
	temp=close;
	int g,h,f;
	while(temp)
	{    
		for(int v=0;v<n;v++)
		{	
			for(int z=0;z<3;z++)
			{	if(tstate[v][z]==temp->nstate[v][z])
			       flag=1;
				else
				{   flag=0;
					break;
				}
			}
			if(flag==0)
				break;
			
		}
	
		if(flag)
		{
			return(1);
		}
		else
			temp=temp->next;
	}


	temp=open;
	flag=0;

		while(temp)
		{
			for(int v=0;v<n;v++)
			{
				
				for(int z=0;z<3;z++)
				{	if(tstate[v][z]==temp->nstate[v][z])
						flag=1;
					else
					{   flag=0;
						break;
					}
				}
				if(flag==0)
					break;
			}
		
			if(flag)
			{
				g=(BESTNODE->g)+val[i][j];
				if(g<((temp->parent->g)+val[i][j]))
				{	temp->parent=BESTNODE;
					temp->g=g;
					temp->f=temp->g+temp->h;
				}
				return(2);
			}
			else
				temp=temp->next;
		}
	newnode=new node;
	temp=open;
	while(temp->next!=NULL)
		temp=temp->next;
	temp->next=newnode;
	newnode->parent=BESTNODE;
	newnode->g=BESTNODE->g+val[i][j];

	newnode->h=0;
	newnode->f=newnode->g+newnode->h;
	
	newnode->next=NULL;
	for(int k=0;k<n;k++)
		for(int l=0;l<3;l++)
			newnode->nstate[k][l]=tstate[k][l];
	for(k=0;k<3;k++)
	{
		newnode->config[k]=cur[k];
		newnode->np[k]=tp[k];
	}


	return(3);
}

void getsucc()
{
	int tdisc,flag=0,m;
	node *temp;
	for(int k=0;k<3;k++)
	{
		cur[k]=top[k];
		tp[k]=p[k];
	}
	for(k=0;k<n;k++)
		for(int l=0;l<3;l++)
			tstate[k][l]=state[k][l];
	int nodeinfo;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{       if(flag==1)
			{
				for(k=0;k<3;k++)
				{
					cur[k]=top[k];
					tp[k]=p[k];
				}
				for(k=0;k<n;k++)
					for(int l=0;l<3;l++)
						tstate[k][l]=state[k][l];

			}
			if(i==j)
				continue;
			else
			{       flag=0;
				if((cur[i]<cur[j] || cur[j]==0) && cur[i]!=0)
				{

						
						tstate[tp[i]][i]=0;
						tstate[tp[j]-1][j]=cur[i];
						tp[i]=tp[i]+1;
						tp[j]=tp[j]-1;
						cur[j]=cur[i];
						if(tp[i]==n)
							cur[i]=tstate[n-1][i];
						else
							cur[i]=tstate[tp[i]][i];
						
					
						

					

					
						m=check(i,j);
						flag=1;
				}
			}
		}
	}
	temp=open;
	node *tclose,*prev;
	tclose=close;
	while(temp)
	{
		if(open==BESTNODE)
		{
			open=open->next;
			if(tclose==NULL)
			{	close=BESTNODE;
				BESTNODE->next=NULL;
			}
			else
			{
				while(tclose->next!=NULL)
					tclose=tclose->next;
				tclose->next=BESTNODE;
				BESTNODE->next=NULL;
			}
			break;

		}
		else
		{
			if(temp->next==BESTNODE)
			{
				while(tclose->next!=NULL)
					tclose=tclose->next;
				tclose->next=BESTNODE;
				temp->next=BESTNODE->next;
				BESTNODE->next=NULL;
				break;
			}

		}
		temp=temp->next;
	}
}










void insopen()
{
	node *temp;
	temp=new node;
	open=temp;
	temp->g=0;
	temp->h=0;
	temp->f=0;
	temp->parent=NULL;
	temp->next=NULL;
	for(int k=0;k<n;k++)
		for(int l=0;l<3;l++)
			temp->nstate[k][l]=state[k][l];
	for(k=0;k<3;k++)
	{
		temp->config[k]=top[k];
		temp->np[k]=p[k];
	}
}
int fgoal()
{
	int flag1=0;

	printf("\n");
	for(int j=0;j<3;j++)
		printf("%d ",top[j]);
	for(j=0;j<3;j++)
	{
		if(top[j]==goal[j])
			flag1=1;
		else
		{	flag1=0;
			break;
		}
	}
	if(flag1==0)
		return(0);
	else
		return(1);

	
}
void getbestnode()
{
	node *temp,*prev,*tclose;
	temp=open;
	tclose=close;
	int fvalue;
	BESTNODE=temp;
	fvalue=temp->f;
	while(temp!=NULL)
	{
		
		if((temp->f)<fvalue)
		{
	
			BESTNODE=temp;
			fvalue=temp->f;
		}
		temp=temp->next;
	}


	for(int k=0;k<n;k++)
		for(int l=0;l<3;l++)
			state[k][l]=BESTNODE->nstate[k][l];
	for(k=0;k<3;k++)
	{
		top[k]=BESTNODE->config[k];
		p[k]=BESTNODE->np[k];
	}

}


void funct()
{
	int num=0;
	if(n%2==0)
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{	val[i][j]=num;
				if(j!=2)
					num++;
				num=num%3;
			}
	}
	else
	{
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{	val[j][i]=num;
				if(j!=2)
					num++;
				num=num%3;
			}
	}


	for(int i=0;i<n;i++)
	{
		
		for(int j=0;j<3;j++)
		{	

			
			if(j==0)
				state[i][j]=i+1;
			else
				state[i][j]=0;
		}
	}

	for(i=0;i<3;i++)
	{
		if(i==0)
			{
				tp[i]=0;
				p[i]=0;
			}
			else
			{
				tp[i]=n;
				p[i]=n;
			}
	}


	

}

void main()
{
	

	

	cout<<"\nEnter the number of disc";
	cin>>n;

	funct();

	node *temp;
	


	insopen();
	int soln;
	while(1)
	{
		
		getbestnode();
		temp=open;
		printf("\nOPEN:-");
	/*	while(temp)
		{   printf("["); 
			for(int k=0;k<3;k++)
				printf("%d,",temp->config[k]);
			printf("]->");
			temp=temp->next;
		}
		temp=close;
		printf("\nCLOSE:-");
		while(temp)
		{   printf("["); 
			for(int k=0;k<3;k++)
				printf("%d,",temp->config[k]);
			printf("]->");
			temp=temp->next;
		}*/
	

		printf("\nBESTNODE");
		for(int j=0;j<3;j++)
			printf("%d ",BESTNODE->config[j]);
		printf("\nBESTNODE f=%d",BESTNODE->f);
	

		if(fgoal()==1)
			break;
		getsucc();
		
	}
	printf("\nOUT");
	int count=1;

	while(BESTNODE!=NULL)
	{
		printf("\n\n");
		for(int p=0;p<n;p++)
		{
			
				printf("\n%d %d %d",BESTNODE->nstate[p][0],BESTNODE->nstate[p][1],BESTNODE->nstate[p][2]);
		}
		BESTNODE=BESTNODE->parent;
		if(BESTNODE==NULL)
			printf("\n------GO ABOVE TO REACH THE GOAL------");

	}


	getch();
}







