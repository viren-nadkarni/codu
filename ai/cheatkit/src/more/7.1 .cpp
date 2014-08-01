#include <stdio.h>
#include <conio.h>
#include <string.h>
void main()
{     char name[50];
      int age;
      char sex[8];
      char answer[5];
      int count=0;
      int a;
      int b;
      int c;
      int d;
      int e;
      int f;
      int g;
      int h;
      clrscr();

      printf("\nEnter the name ");
      scanf("%s",name);

      printf("\nEnter the age");
      scanf("%d",&age);

      printf("\nEnter the sex");
      flushall();
      scanf("%s",sex);

      printf("\nDO you have a runny nose ?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
	a=1;
      }

      printf("\nDO you have a brownish rash ?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
	 b=1;
      }

       printf("\nDO you have high,fast rising temperature ?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
      c=1;
      }

       printf("\nDO you have harsh,hacking cough ?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
      d=1;
      }

       printf("\nDO you have bloodshot eyes ?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
      e=1;
      }

       printf("\nDO you have conjunctivitis ?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
      f=1;
      }

      printf("\nDO you have white spots inside cheeks?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
      g=1;
      }

      printf("\nDO you have intolerance to light?");
      scanf("%s",answer);

      if(strcmp(answer,"yes")==0)
      {  count++;
      h=1;
      }
      clrscr();
      printf("\nNAME %s",name);
      printf("\nAGE %d",age);
      printf("\nSEX %s",sex);

      if((count==8) && (a&&b&&c&&d&&e&&f&&g&&h)==1)
      {  printf("\nYOU ARE SUFFERING FROM MEASLES");
      }
      else if(((count==2) &&(a && c))==1)
      {  printf("\nYOU ARE SUFFERING FROM FLU");
      }
      else if((count==1)&& a==1)
      {  printf("\nYOU ARE SUFFERING FROM A COMMON COLD");
      }
      else
      printf("u do not have common cold ,flu and measles");


    getch();
}