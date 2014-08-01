#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<iomanip.h>

float output(float x[])
{
 float val;

 val = (x[1] || (x[0] && x[2]));

 return val;

}

float func(float w[],float x[])
{
 float val=0.0;

 for(int i=0;i<3;i++)
  val+=w[i]*x[i];

 return val;

}

int calc(float w[],float wt[])
{
 for(int i=0;i<3;i++)
  {
   if(w[i]!=wt[i])
    return 0;
  }

 return 1;
}

void per_learn()
{
 //B OR (A AND C)
 float w[3];
 float wt[3];
 float r,y,t;
 float x[3];

 int input,rem,i,j;
 int o[8]={0,1,10,11,100,101,110,111};

 //w[i] values are 0 or very small random no.
 cout<<"\n Enter initial w[i] values : ";
 for(i=0;i<3;i++)
  cin>>w[i];

 //r lies between 0 and 1
 cout<<"\n Enter the learning rate : ";
 cin>>r;


 do
 {
  for(i=0;i<3;i++)
   wt[i]=w[i];

  for(i=0;i<8;i++)
   {
     j=3;
     input=o[i];
     x[0]=x[1]=x[2]=0.0;

     while(input)
      {
       rem=input%10;
       x[j-1]=rem*1.0;
       input=input/10;
       j--;
      }

    t=output(x);

    y=func(w,x);

    if(y!=t)
     {
      for(j=0;j<3;j++)
       w[j]+=(r*(t-y)*x[j])/2;
     }
   }

 }while(!calc(w,wt));

 //Output w[i]

 for(i=0;i<3;i++)
  {
   cout<<"\n w["<<i+1<<"] = "<<w[i];
  }

 //Display

  cout<<"\n\n";

  for(i=0;i<8;i++)
   {
     cout<<"\n";

     j=3;
     input=o[i];
     x[0]=x[1]=x[2]=0.0;

     while(input)
      {
       rem=input%10;
       x[j-1]=rem*1.0;
       input=input/10;
       j--;
      }

     t=output(x);
     y=func(w,x);

     endl;

     for(j=0;j<3;j++)
      cout<<" x["<<j+1<<"] = "<<x[j];

     cout<<" t = "<<t;
     printf(" rounded (y) = %1.0f",y);
     cout<<" actual (y) = "<<y;

   }
}

void main()
{
 clrscr();
 per_learn();
 getch();
}