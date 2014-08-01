#include<iostream.h>
#include<stdio.h>
#include<conio.h>

void bayes()
{
 int s,fn,si,fni,i,e,j,n=52,m,d[52],q;

 float p[60],pe[60],prob=0.0,sum=0.0;

 for(j=0;j<n;j++)
  d[j]=0;

 //Already drawn card

 cout<<"\n Enter the number of cards already drawn ";
 cin>>q;

 for(j=0;j<q;j++)
 {
  cout<<"\n Enter the card which is already drawn : ";
  cout<<"\n\n Enter the suit : ";
  cout<<"\n\n 1:Heart 2:Diamond 3:Club 4:Spade \n\n  ";

  do
   {
    cin>>s;
    if(s<1||s>4)
     cout<<" \n Invalid suit \n\n Enter again : ";
   }while(s<1||s>4);

  cout<<"\n\n Enter the face or number on the card : ";
  cout<<"\n\n 1:A 2:2 3:3 4:4 5:5 6:6 7:7 8:8 9:9 10:10 11:J 12:Q 13:K \n\n  ";

  do
   {
    cin>>fn;
    if(fn<1||fn>13)
     cout<<" \n Invalid face or number \n\n Enter again : ";
   }while(fn<1||fn>13);

  e = 13*(s-1)+fn;
  d[e-1] = 1;
 }


 for (j=0; j<n; j++)
  {
   p[j]=1.0/52;
   //cout<<"  "<<p[j];
  }

 //Card/s whose probability is to be found

 cout<<"\n Enter the number of cards whose probability is to be found ";
 cin>>m;

 for(j=0;j<m;j++)
  {
    cout<<"\n\n Enter the card whose probability is to be found : ";
    cout<<"\n\n Enter the suit : ";
    cout<<"\n\n 1:Heart 2:Diamond 3:Club 4:Spade \n\n  ";

    do
     {
      cin>>si;
      if(si<1||si>4)
       cout<<" \n Invalid suit \n\n Enter again : ";
     }while(si<1||si>4);

    cout<<"\n\n Enter the face or number on the card : ";
    cout<<"\n\n 1:A 2:2 3:3 4:4 5:5 6:6 7:7 8:8 9:9 10:10 11:J 12:Q 13:K \n\n  ";

    do
     {
      cin>>fni;
      if(fni<1||fni>13)
       cout<<" \n Invalid face or number \n\n Enter again : ";
     }while(fni<1||fni>13);

    i = 13*(si-1)+fni;
    d[i-1] = 2;

  }

 for (j=0; j<n; j++)
 {
  if(d[j]!=1)
   pe[j]=1.0/13;
  else
   pe[j]=0;
  //cout<<"  "<<pe[j];
 }

 for (j=0; j<n; j++)
 {
  sum=sum+pe[j]*p[j];
 }

 //cout<<sum;
 for(j=0;j<n;j++)
  {
   if(d[j]==2)
    prob+=pe[j]*p[j]/sum;
  }

 cout<<"\n\n The probability is "<<prob;

}

void main()
{
 clrscr();
 bayes();
 getch();
}