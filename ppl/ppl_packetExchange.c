/*exchange of packets*/
#include <stdio.h>

int main()
{
	int pA[3], pB[3], loopA, loopB, totalA=0, totalB=0, count, tmp, a_tmp, b_tmp;

	/*input */
	for (loopA=1;loopA<=3;loopA++)
	{
		printf("Enter the weight of packet %d in truck A: ", loopA);
		scanf("%d",&pA[loopA]);
	}
	printf("\n");
	for (loopB=1;loopB<=3;loopB++)
	{
		printf("Enter the weight of packet %d in truck B: ", loopB);
		scanf("%d",&pB[loopB]);
	}
	printf("\n");
	
	/*finds the total weight in each truck */
	for(count=1;count<=3;count++)
	{
		totalA=pA[count]+totalA;
	}
	for(count=1;count<=3;count++)
	{
		totalB=pB[count]+totalB;
	}
	printf("Total weight in truck A = %d\n",totalA);
	printf("Total weight in truck B = %d\n",totalB);
	tmp=(totalA+totalB)/2;
	printf("\nFinding packets which can be exchanged...\n\n");

	/*main algorithm*/
	for(loopA=1;loopA<=3;loopA++)
	{
		totalA=0;
		totalB=0;

		for(loopB=1;loopB<=3;loopB++)
		{
			/*exchanges the packets*/
			a_tmp=pA[loopA];
			b_tmp=pB[loopB];
			pB[loopB]=a_tmp;
			pA[loopA]=b_tmp;

			/*calculates new total weights*/
			for(count=1;count<=3;count++)
			{
				totalA=pA[count]+totalA;
			}
			for(count=1;count<=3;count++)
			{
				totalB=pB[count]+totalB;
			}
			
			/*breaks the loop if suitable set of packages are found*/
			if(totalA==tmp && totalB==tmp && pB[loopB]!=pA[loopA])
			{
				break;
			}

			/*restores initial values of packets for other iterations*/
			pA[loopA]=a_tmp;
			pB[loopB]=b_tmp;
			totalA=0;
			totalB=0;
		}

		if(totalA==tmp&&totalB==tmp)
			break;
	}
	
	/*output*/
	if(loopA==4 && loopB==4)
		printf("No possible pair found\n");
    else
		printf("Packets exchanged\nPacket %d in A <===> Packet %d in B",loopA,loopB);

	return 0;
}
