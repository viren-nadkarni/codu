#include <stdio.h>
#include <stdlib.h>
#define SZ_ALLOC 32

int main()
{
	int i,j,num_p,num_r;
	int alloc_tab[SZ_ALLOC][SZ_ALLOC],max_tab[SZ_ALLOC][SZ_ALLOC];
	int av_res[SZ_ALLOC];
	
	printf("How many processes? ");
	scanf("%d",&num_p);

	printf("How many resources? ");
	scanf("%d",&num_r);	

	
	printf("\nAllocation table:\nproc_id");
	for(i='A';i<'A'+num_r;++i)
		printf("  %c",i);
	printf("\n");
	for(i=0;i<num_p;++i)
	{
		printf("%d\t",i);
		for(j=0;j<num_r;++j)
			scanf("%d",&alloc_tab[i][j]);		
	}
	
	printf("\nMax table:\nproc_id");
	for(i='A';i<'A'+num_r;++i)
		printf("  %c",i);
	printf("\n");
	for(i=0;i<num_p;++i)
	{
		printf("%d\t",i);
		for(j=0;j<num_r;++j)
			scanf("%d",&max_tab[i][j]);		
	}
	
	printf("\nEnter available resources:");
	for(i='A';i<'A'+num_r;++i)
	{
		printf("\n%c: ",i);
		scanf("%d",&av_res[i-'A']);
	}
	
	printf("\nTotal resources: ");
	for(i='A';i<'A'+num_r;++i)
	{
		int tmp=av_res[i-'A'];
		printf("\n%c: ",i);
		for(j=0;j<num_p;++j)
			tmp+=alloc_tab[j][i-'A'];
		printf("%d",tmp);
		
	}
	
	printf("\n\nOrder of execution:");
	
	int has_finished[SZ_ALLOC],k,z=0;
	for(i=0;i<SZ_ALLOC;++i)
		has_finished[i]=0;
		
	while(1)
	{
		int all_finished=1;
		int need[SZ_ALLOC];
		
		//select a process from list	
		for(i=0;i<num_p;++i)
		{
			//determine all_finished flag
			if(has_finished[i])
				continue;
			all_finished=all_finished&&has_finished[i]&&(num_p-1==i);
			
			//find the need
			for(k=0;k<num_r;++k)
				need[k]=max_tab[i][k]-alloc_tab[i][k];
			
			//check if need>avail
			int need_flag=1;
			for(k=0;k<num_r;++k)
			{
				if(av_res[k] < need[k])
					need_flag=0;
				
			}
			if(need_flag!=0)
				break;
			else 
				continue;			
			
		}
		
		//break outer loop if all processes have finished exec
		if(all_finished)
			break;
		
		if(i==num_p)
			--i;
		
		int current_proc=i;
		
		has_finished[i]=1;
				
		for(j=0;j<num_r;++j)
			av_res[j]+=alloc_tab[current_proc][j];
			
		printf("\nprocess %d",current_proc);	
	}
	
	printf("\n\nResources at end of execution\n");
	for(i=0;i<num_r;++i)
		printf("%c: %d\n",i+'A',av_res[i]);
	
	
	system("pause");
	return 0;
}
			
			/*
			How many processes? 5
How many resources? 3

Allocation table:
proc_id  A  B  C
0       0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
1       2       3       4
Max table:
proc_id  A  B  C
0       7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
1       2       3       4
Enter available resources:
A: 3 3 2

B:
C:
Total resources:
A: 10
B: 5
C: 7

Order of execution:
process 1
process 3
process 0
process 2
process 4

Resources at end of execution
A: 10
B: 5
C: 7
Press any key to continue . . .

*/