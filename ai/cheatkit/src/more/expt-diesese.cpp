//TO DEVELOP EXPERT SYSTEM FOR DIAGNOSIS OF PATIENTS HAVING COMMON SICKNESSES
#include<stdio.h>
#include<conio.h>

void refinement(int a[100],int n,int b[100])
{
	int i,j,k;
	for(i=0;i<n;i++)
		b[i]=a[i];
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
		{
			if(b[i]==b[j])
			{
				n=n-1;
				for(k=j;k<n;k++)
					b[k]=b[k+1];
				j=j-1;
			}
		}
}

int problem(int symptoms[100],int n)
{
     int i,j,f;
     int flag[100];
     for(i=0;i<n;i++)
	if(symptoms[i]==0)
	{
		printf("\n YOU ARE OBSOLUTELY FINE");
		return;
	}

     printf("\n The patient may be suffering from\n");
     for(j=0;j<n;j++)
     {
		     i=symptoms[j];
		     if(i==1)
			     printf("BACKACHE ");
		     else if(i==2)
			     printf("ANOREXIA ");
		     else if(i==3)
			     printf("OSTEOARTHRITIS ");
		     else if(i==4)
			     printf("BROCHIAL ASTHMA ");
		     else if(i==5)
			     printf("HAIRLOSS ");
		     else if(i==6)
			     printf("HEADACHE ");
		     else if(i==7)
			     printf("FEVER ");
		     else if(i==8)
			     printf("COUGH AND COLD ");
		     else if(i==9)
			     printf("DIARRHOEA ");
		     else if(i==10)
			     printf("TONSILLITIS ");
		     else if(i==11)
			     printf("HEART ATTACK ");
		     else if(i==12)
			     printf("INFECTION ");
		     else if(i==13)
			     printf("OBESITY AND ANEMIA ");
		     else if(i==14)
			     printf("WEAKNESS");
		     else if(i==15)
			     printf("MIGRAINE");
		     else flag[j]=1;
     }
     for(j=0;j<n;j++)
     {
	   if(flag[j]==1)
		f=1;
	   else
	   {
		f=0;
		break;
	   }
     }
     if(f==1)
     {
	   clrscr();
	   printf("   YOU ARE OBSOLUTELY FINE");
     }
     return f;
}

void solution(int disease[100],int n,int flag)
{
     int i,j;
     if(flag==1)
	return;
     printf("\n The patient should take the following medications: \n");
     for(j=0;j<n;j++)
     {
		     i=disease[j];
		     if(i==1)
			     printf("\n   FOR BACKACHE \n Massage the affected area gently with warm sesame oil and cover with a cotton cloth. Avoid exposure to air or cold wind.");
		     else if(i==2)
			     printf("\n   FOR ANOREXIA\n Prepare a mixture of ¼ teaspoon of ginger juice, ¼ teaspoon of lime juice and a pinch of rock salt. This is one dose. Have this preparation 15 minutes before meals, twice a day.");
		     else if(i==3)
			     printf("\n	  FOR OSTEOARTHRITIS\n Equal quantities of powdered fenugreek seeds, turmeric and ginger powder can be mixed together. One teaspoon can be taken in the morning and evening.");
		     else if(i==4)
			     printf("\n   FOR BRONCHIAL ASTHMA\n Massaging the chest with warm sesame oil mixed with salt helps to loosen the phlegm deposited in the chest, especially, when followed with steam inhalation.");
		     else if(i==5)
			     printf("\n	  FOR HAIR LOSS \n Heat 250 milliliters of coconut oil in a pan, and add 3-4 Indian gooseberries cut into pieces. Heat until the gooseberries turn dark brown or black. Use the oil for a hair massage 2-3 times a week.");
		     else if(i==6)
			     printf("\n	  FOR HEADACHE\n Mix a pinch of clove powder in 1 teaspoon of cinnamon oil. Apply this mixture on the forehead or temples.");
		     else if(i==7)
			     printf("\n	  FOR FEVER\n Mix half a teaspoon of turmeric powder in a cup of warm milk and one teaspoon honey or some other sweetener. Take this decoction twice a day.");
		     else if(i==8)
			     printf("\n	  FOR COUGH AND COLD\n Half a cup of warm water mixed with one teaspoon of lemon juice and one teaspoon of honey can be taken several times a day.");
		     else if(i==9)
			     printf("\n   FOR DIARRHOEA\n One teaspoon of fresh mint juice, mixed with a teaspoon each of lime juice and honey, can be given thrice daily with brilliant results in the treatment of this disease.");
		     else if(i==10)
			     printf("\n   FOR TONSILLITIS\n The leaves of holy basil have also been found helpful in the in curing sore throat. Water boiled with basil leaves can be used as a drink, and also used as a gargle to relieve a sore throat ");
		     else if(i==11)
			     printf("\n   FOR HEART ATTACKS\n A prolonged immersion bath at room temperature taken at bedtime on alternative days is very useful for the heart patients.");
		     else if(i==12)
			     printf("\n   FOR INFECTIONS\n Apply Aloe Vera, cod liver oil, lemon juice, vitamin E oil, wheat germ oil, or witch hazel tea to the irritated area.");
		     else if(i==13)
			     printf("\n   FOR OBESITY AND ANEMIA\n Seven almonds should be drenched in water for about two hours and ground into a paste after removing the thin red skin. This paste may be eaten once every day in the morning for three months. And for Obesity start doing exercises to keep your body fit and healthy");
		     else if(i==14)
			     printf("\n   FOR WEAKNESS\n Add 1 teaspoon of turmeric powder to one glass of warm milk and take twice daily");
		     else if(i==15)
			     printf("\n	  FOR MIGRANE\n Take 1 teblespoon of almond oil and boil it. When it cools down,put two drops ineach nostril. ");
     }
}

void expertx()
{
     int a;
     int k=0;
     int f=0,i;
     int answer[100];
     int result[100];
     for(i=0;i<100;i++)
	answer[i]=0;
     clrscr();
     printf("\n Enter 1 if your answer is yes and 0 if no");
     printf("\n Is the patient below the age of 20 ?");
     scanf("%d",&a);

     printf("\n Is patient having inadequate nutrition ?");
     scanf("%d",&a);
     if(a==1)       {      answer[k]=2;k++;  }

     printf("\n Does the patient have any accidental injuries ?");
     scanf("%d",&a);
     if(a==1)       {      answer[k]=1;   k++;       }

     printf("\n Does the patient has any stress ?");
     scanf("%d",&a);
     if(a==1)       {      answer[k]=9;k++;      }

     getch();
     clrscr();
     printf("\n Enter 1 if your answer is yes and 0 if no");

     printf("\n Is the patient doing any routine exercises ?");
     scanf("%d",&a);
     if(a==0)       {       answer[k]=14;k++; }

     printf("\n Does the patient has any cough or cold ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=4;k++;   }

     printf("\n Does the patient has sinusitis problem ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=15;k++;   }

     printf("\n Is the patient suffering from hypertension ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=6;k++;  }

     getch();
     clrscr();
     printf("\n Enter 1 if your answer is yes and 0 if no");

     printf("\n Does the patient has high temperature and burning eyes ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=7;k++;         }

     printf("\n Is the patient has weak digestion ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=8;k++;      }

     printf("\n Does the patient has sore throat ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=10;k++;    }

     printf("\n Does the patient has sollen joints ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=3;k++;       }

     getch();
     clrscr();
     printf("\n Enter 1 if your answer is yes and 0 if no");

     printf("\n Does the patient loses consciousness ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=11;k++;        }

     printf("\n Does the patient has dandruff ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=5;k++;     }

     printf("\n Is the patient suffering from itching ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=12;k++; }

     printf("\n Does patient has shortness of breadth ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=13;k++; }

     getch();
     clrscr();
     refinement(answer,k,result);
     f=problem(result,k);
     if(f==1)
     {
	getch();
	return;
     }
     printf("\n\n\n\n TO SEE THE SOLUTION TO YOUR PROBLEM, PRESS ENTER");
     getch();
     clrscr();
     solution(result,k,f);
}

void main()
{
	int x;
	do
	{
		clrscr();
		printf("\n SOLUTIONS FOR COMMON SICKNESSES AMONG PATIENTS");
		printf("\n\n\n THE COMPUTER WILL ASK YOU SOME QUESTION,YOU NEED TO ANSWER THEM IN YES OR NO");
		printf("\n\n\n\n\n PRESS ENTER WHEN YOU ARE READY");
		getch();
		expertx();
		printf("\n Do you want to continue(1/0)? ");
		scanf("%d",&x);
	}while(x!=0);
	getch();
}
