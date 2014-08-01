//TO DEVELOP EXPERT SYSTEM FOR DIAGNOSIS OF PATIENTS HAVING COMMON SICKNESSES
#include<stdio.h>
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
			     printf("BROCHIAL ASTHMA ");
		      else if(i==3)
			     printf("HAIRLOSS ");
 	              else if(i==4)
			     printf("HEADACHE ");
		      else if(i==5)
 			     printf("FEVER ");
		      else if(i==6)
			     printf("TONSILLITIS ");  
 		      else if(i==7)
			     printf("INFECTION ");
		      else if(i==8)
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
			     printf("\n   FOR BACKACHE \n Massage the affected area gently with warm oil and cover with a cotton cloth. \nAvoid exposure to air or cold wind.");
		      else if(i==2)
			     printf("\n   FOR BRONCHIAL ASTHMA\n Massaging the chest with warm sesame oil mixed with salt helps to loosen the phlegm deposited in the chest, especially, when followed with steam inhalation.");
		     else if(i==3)
			     printf("\n	  FOR HAIR LOSS \n Heat 250 milliliters of coconut oil in a pan, and add 3-4 Indian gooseberries cut into pieces.\n Heat until the gooseberries turn dark brown or black. Use the oil for a hair massage 2-3 times a week.");
		     else if(i==4)
			     printf("\n	  FOR HEADACHE\n Mix a pinch of clove powder in 1 teaspoon of cinnamon oil.\n Apply this mixture on the forehead or temples.");
		     else if(i==5)
			     printf("\n	  FOR FEVER\n Mix half a teaspoon of turmeric powder in a cup of warm milk and one teaspoon honey or some other sweetener.\n Take this decoction twice a day.");
		     else if(i==6)
			     printf("\n   FOR TONSILLITIS\n The leaves of holy basil have also been found helpful in the in curing sore throat.\n Water boiled with basil leaves can be used as a drink, and also used as a gargle to relieve a sore throat ");
		     else if(i==7)
			     printf("\n   FOR INFECTIONS\n Apply Aloe Vera, cod liver oil, lemon juice, vitamin E oil, wheat germ oil, or witch hazel tea to the irritated area.");
		     else if(i==8)
			     printf("\n	  FOR MIGRANE\n Take 1 teblespoon of almond oil and boil it.\n When it cools down,put two drops ineach nostril. ");
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
        
     printf("\n Does the patient have any accidental injuries ?");
     scanf("%d",&a);
     if(a==1)       {      answer[k]=1;   k++;       }

    

     printf("\n Does the patient has any cough or cold ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=2;k++;   }


     printf("\n Does the patient has dandruff ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=3;k++;     }

     printf("\n Is the patient having headache ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=4;k++;  }

     printf("\n Does the patient has high temperature and burning eyes ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=5;k++;         }

     printf("\n Does the patient has sore throat ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=6;k++;    }

     printf("\n Is the patient suffering from itching ?");
     scanf("%d",&a);
     if(a==1)       {       answer[k]=7;k++; }

     printf("\n Is the patient doing any routine exercises ?");
     scanf("%d",&a);
     if(a==0)       {       answer[k]=8;k++; }


     refinement(answer,k,result);
     f=problem(result,k);
     if(f==1)
     {
	return;
     }
     printf("\n\n\n\n TO SEE THE SOLUTION TO YOUR PROBLEM, PRESS ENTER");
     solution(result,k,f);
}

int main()
{
	int x;
	do
	{
		printf("\n\n EXPERT SYSTEM FOR COMMON SICKNESSES AMONG PATIENTS");
		printf("\n Enter 1 if your answer is yes and 0 if no");
     
		expertx();
		printf("\n\n Do you want to continue(1/0)? ");
		scanf("%d",&x);
	}while(x!=0);
}
