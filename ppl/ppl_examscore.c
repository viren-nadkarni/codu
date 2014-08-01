#include<stdio.h>

int main()
{
	int conf,total,sub,var,loop,mks,failflag;
	do
	{
		conf=0;
		total=0;
		sub=1;
		var=0;
		mks=0;
		loop=0;
		failflag=0;
		
        do
		{
			printf ("Enter marks in subject %d\n",sub);
			do
			{
				var=0;
				scanf ("%d",&mks);
				if(mks>=0&&mks<=100)
				{
					if(mks<40)
					{
						failflag=1;
					}
					var=1;
					sub++;
				}
				else
				printf("Invalid marks entered. Please try again\nEnter marks in subject %d\n",sub);
			}while(var==0);
		total=total+mks;
		loop++;
		}while(loop<6);

	printf("Total marks:%d\nGrade:",total);

	if(total<=600&&total>500&&failflag==0)
	printf("Distinction\n\n");
	else if(total<=500&&total>400&&failflag==0)
	printf("First class\n\n");
	else if(total<=400&&total>300&&failflag==0)
	printf("Second Class\n\n");
	else if(total>=240&&failflag==0)
	printf("Pass Class\n\n");
	else
	printf("Fail\n\n");

	sub=1;

	printf("Calculate another set? (1 for yes)\n");
	scanf ("%d",&conf);

	}while (conf==1);
return 0;
}
