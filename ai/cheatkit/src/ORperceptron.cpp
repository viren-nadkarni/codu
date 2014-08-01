#include<stdio.h>
#include<conio.h>
#include<math.h>

int main()
{   float w[3]={0.0, 0.0, 0.0},d[4]={999.0,999.0,999.0,999.0},n,t=0.5,r=0.1,delta,s,e[4],c[3];  
    //t is threshold taken as 0.5;r is learning rate taken as 0.1
    //z is output
    int b=0,count,z[4],i,j,x[4][4]={{1, 0, 0, 0},
                     {1, 0, 1, 1},
                     {1, 1, 0, 1},
                     {1, 1, 1, 1},
                     };                  //b is bais taken as 0; x[0] is extra always taken as 1
    for (int k=0;k<4;k++)
        z[k]=x[k][3];                     

    printf("\tPERCEPTRON LEARNING\n"
           "\t~~~~~~~~~~~~~~~~~~~\n");
    
    while (d[0]>0.0 || d[1]>0.0 || d[2]>0.0 || d[3]>0.0)
    {     for (j=0;j<4;j++)
          {
              for (i=0;i<3;i++)
              {   c[i]=x[j][i]*w[i];
              }
              s=0;
              for (i=0;i<3;i++)
              {    s+=c[i];
              }
              if (s>t)
                 n=1;
              else
                  n=0;
          
              e[j] = z[j] - n;   //error
              d[j] = r * e[j];      //correction
              for (i=0;i<3;i++)
              {    w[i]+=x[j][i]*d[j];
              }
          }
    }
    printf("\n\"THRESHOLD\" is taken as 0.5 .\n\"LEARNING RATE\" is taken as 0.1 ."
                            "\"BAIS\" is taken as 0 .");
    for (int k=0;k<3;k++)
        printf("\n\nWeight w%d for input %d is %.3f .\n",k,k,w[k]);
        
    getch();
    return 0;
}
            
