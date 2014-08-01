#include<iostream.h>
#include<conio.h>
#include<stdio.h>
int arr[10][10];

int city=4;

void main()
{
	for(int i=0;i<city;i++)
	{

		for(int j=0;j<city;j++)
		{
			if(i==j)
				arr[i][j]=100;
			else
			{
				cout<<"\nEnter the distance between city "<<i+1<<" and "<<j+1;
				cin>>arr[i][j];
			}
		}
	}


	cout<<"\n\nEnter the number of starting city: ";
	int n;
	cin>>n;
	int n1;
	n1=n;
	int visit[4],count=0;
	
	int min=50,index,flag=0;
	
	int k=0;
	for(i=n-1;;i++)
	{
		if(i==city)
			i=0;

	//	printf("\n\ni=%d",i);
		min=50;
		for(int j=0;j<city;j++)
		{	flag=0;
			for(int l=0;l<count;l++)
			{
				if(j==visit[l])
				{
					flag=1;
					break;
				}
			}
			if(flag==1)
				continue;
			else
				{
					if(arr[i][j]<min)
					{   if(j!=n-1)
						{
							index=j;
							min=arr[i][j];
						}
					}
				}
			
		}
	//	printf("\nIndex=%d min=%d",index,min);
		visit[count++]=index;
		if(k==city-1)
			break;
		

		k++;
	}
	visit[city-1]=n1-1;
	printf("\n");

	for(i=0;i<city;i++)
	{	
		printf(" %d ",visit[i]+1);
	}

	getch();
}