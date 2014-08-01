#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<graphics.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void crypt()
{
  char a[80],b[10];
  long int count=0,flag=0;
  long int x[10],n[10];
  long int i,j,k,no;

  for(i=0;i<80;i++)
  a[i]=13;

  for(i=0;i<10;i++)
  b[i]=13;

  cout<<"\n\n     Enter the entire string  : ";
  gets(a);

  j=0;
  for(i=0;i<strlen(a);i++)
   {
    flag=0;
    toupper(a[i]);
    if(a[i]>64&&a[i]<91)
      {
       for(k=0;k<count;k++)
	{
	 if(a[i]==b[k])
	  {
	   flag=1;
	   break;
	  }
	}
       if(flag==0)
	{
	 b[count]=a[i];
	 count++;
	}
      }
   }

  for(k=0;k<count;k++)
   n[k]=k;


  n[0]=5;

  int c=0;

  if(count<=10)
   {
    while(1)
    {

     flag=0;

     for(j=0;j<count;j++)
     if(n[j]!=9)
       {
	flag=1;
	break;
       }

     if(flag==0)
     {
      for(j=0;j<count;j++)
      cout<<n[j];
      cout<<"  -  "<<count;
      getch();
      exit(0);
     }

     flag=0;

     j=1;
     for(i=count-1;i>=0;i--)
       {
	int qou=(n[i]+j)/10;
	if(j==1)
	 {
	  n[i]=(n[i]+j)%10;
	  j=qou;
	 }
	else break;
       }

     for(i=0;i<count-1;i++)
       {
	for(j=i+1;j<count;j++)
	 if(n[i]==n[j])
	  {
	   flag=1;
	   break;
	  }
	if(flag==1)
	 break;
       }

     if(flag==1)
       continue;

     no=0;k=0;
     for(i=0;i<strlen(a);i++)
      {
       if(a[i]>64&&a[i]<91)
       for(j=0;j<count;j++)
	{
	 if(a[i]==b[j])
	  {
	   if((c==0)&&(n[j]==0))
	    {
	     no=999999;
	     break;
	    }
	   no=10*no+n[j];
	   c++;
	  }
	}
       if(a[i]=='+'||a[i]=='=')
	{
	 x[k]=no;
	 k++;
	 no=0;
	 c=0;
	}
      }
     x[k]=no;
     no=0;
     for(i=0;i<k;i++)
       {
	no+=x[i];
       }
     if(no==x[k])
      {
       for(j=0;j<count;j++)
	cout<<"\n\n     "<<b[j]<<" = "<<n[j];
       getch();
       exit(0);
      }
    }
   }
}



void main()
{
 clrscr();
 crypt();

}