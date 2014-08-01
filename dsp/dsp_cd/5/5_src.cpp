#include <stdio.h>
#include <conio.h>
#include <math.h>

int main()
{
    int N,k,i,n,x[20];
    float SumX[20];

    printf("\n Enter N : ");
    scanf("%d",&N);

    printf("\n Enter size of input , n : ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n x(%d) = ",i);
        scanf("%d",&x[i]);
    }

    SumX[0]=0;

    for(i=0;i<n;i++)
    {
        SumX[0]+=x[i];
    }

    printf("\n\n X(0) = %f",SumX[0]);
    float t,ct[20],st[20]; 

    for(k=1;k<N;k++)
    {
        SumX[k]=x[0];

        for(i=1;i<n;i++)
        {
            t=i*k*2*3.14/(N*1.0);
            ct[i]=cos(t);
            st[i]=sin(t);
        }

        int j;
        float tempR,tempI=0;
        
        for(j=1;j<n;j++)
        {
            tempR=x[j]*ct[j];
            tempI+=x[j]*st[j];
            SumX[k]+=tempR;
        }

        if(tempI>0)
            printf("\n\nX(%d)= %f %fj",k,SumX[k],tempI*-1.0);
        else
            printf("\n\nX(%d)= %f +%fj",k,SumX[k],tempI*-1.0);
    }
    getch();
    return 0;
}
